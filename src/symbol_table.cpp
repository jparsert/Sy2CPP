//
// Created by julian on 15.12.22.
//
#include <ranges>
#include "symbol_table.h"
#include "exceptions.h"
#include "typing.h"

namespace Sy2CPP {

    bool symbol_table::add_user_defined_fun(DefineFunCmd &cmd) {
        EitherIdentifier id(cmd.get_identifier());
        std::vector<SortedVar> &rg = cmd.get_arguments();
        std::vector<EitherSort> arg_sorts;
        std::transform(rg.begin(), rg.end(), std::back_inserter(arg_sorts),
                       [](SortedVar &x) { return x.second; });
        EitherSort range_sort = cmd.get_sort();

        auto [_, val] = this->user_defined_funs
                .emplace(id, FunctionDescriptor(id, arg_sorts, range_sort,
                                                FunctionKind::USER_DEFINED, false));
        return val;
    }

    bool symbol_table::add_synth_fun(const EitherIdentifier &id, const std::vector<SortedVar> &arguments,
                                     const EitherSort &range_sort) {
        std::vector<EitherSort> arg_sorts;
        std::transform(arguments.begin(), arguments.end(), std::back_inserter(arg_sorts),
                       [](const SortedVar &x) { return x.second; });

        auto [_, val] = this->synth_fun_funs
                .emplace(id, FunctionDescriptor(id, arg_sorts, range_sort,
                                                FunctionKind::SYNTH_FUN, false));
        return val;
    }

    std::optional<FunctionDescriptor>
    symbol_table::lookup_or_resolve_function(const EitherIdentifier &identifier,
                                             const std::vector<EitherSort> &arg_sorts) const {
        for (auto &res: this->resolvers) {
            std::optional<FunctionDescriptor> descr = res->lookup_or_resolve_function(identifier, arg_sorts);
            if (descr) {
                return descr;
            }
        }

        // lookup function in user defined funs
        auto el = this->user_defined_funs.find(identifier);
        if (el != this->user_defined_funs.end()) {
            return std::make_optional<FunctionDescriptor>(el->second);
        }

        // lookup function in user defined funs
        el = this->synth_fun_funs.find(identifier);
        if (el != this->synth_fun_funs.end()) {
            return std::make_optional<FunctionDescriptor>(el->second);
        }
        return std::nullopt;
    }

    std::optional<SortDescriptor> symbol_table::lookup_sort(const EitherSort &sort) const {
        for (auto &res: this->resolvers) {
            std::optional<SortDescriptor> descr = res->lookup_or_resolve_sort(sort);
            if (descr) {
                return descr;
            }
        }

        auto el = this->sorts.find(sort);
        if (el != this->sorts.end()) {
            return std::make_optional<SortDescriptor>(el->second);
        }

        return std::nullopt;
    }

    void symbol_table::add_resolver(const std::shared_ptr<AbstractResolver> &ptr) {
        resolvers.push_back(ptr);
    }

    std::optional<SymbolDescriptor> symbol_table::resolve_symbol_descriptor(const EitherIdentifier &identifier) const {
        for (auto &i: std::views::reverse(this->symbol_stack)) {
            if (i.get_identifier() == identifier) {
                return std::make_optional<SymbolDescriptor>(i);
            }
        }
        return std::nullopt;
    }

    SymbolDescriptor symbol_table::pop_symbol_stack() {
        SymbolDescriptor res(this->symbol_stack.back());
        this->symbol_stack.pop_back();
        return res;
    }

    void symbol_table::push_symbol_stack(const SymbolDescriptor &descr) {
        this->symbol_stack.push_back(descr);
    }

    std::vector<SymbolDescriptor> symbol_table::pop_symbol_stack(std::size_t n) {
        std::vector<SymbolDescriptor> res;
        for (int i = 0; i < n; ++i) {
            res.push_back(this->pop_symbol_stack());
        }
        return res;
    }

    std::any SymbolTableAstBuilder::visitSimpleIdentifier(SyGuSv21Parser::SimpleIdentifierContext *ctx) {
        SimpleIdentifier id(ctx->symbol()->SYMBOL()->getText());
        return EitherIdentifier(id);
    }

    std::any SymbolTableAstBuilder::visitNumeral(SyGuSv21Parser::NumeralContext *ctx) {
        auto str = ctx->NUMERAL()->getSymbol()->getText();
        auto val = std::strtol(str.c_str(), nullptr, 10);
        return std::static_pointer_cast<Literal>(std::make_shared<Numeral>(val));
    }

    std::any SymbolTableAstBuilder::visitStringConst(SyGuSv21Parser::StringConstContext *ctx) {
        if (ctx->EMPTYSTRING() != nullptr) {
            return std::static_pointer_cast<Literal>(std::make_shared<StringConst>(""));
        } else if (ctx->STRINGCONST() != nullptr) {
            return std::static_pointer_cast<Literal>(std::make_shared<StringConst>(ctx->STRINGCONST()->getText()));
        } else {
            throw UnsupportedFeature("Strong Const is neither constant nor empty.");
        }
    }

    std::any SymbolTableAstBuilder::visitConstraintCmd(SyGuSv21Parser::ConstraintCmdContext *ctx) {
        {
            auto term = std::any_cast<TermPtr>(ctx->term()->accept(this));

            //typecheck constraint term
            EitherSort term_sort = TypeInference::infer_and_check_type(*this->table, term.get());
            if (!(term_sort == CoreResolver::get_bool_sort())) {
                throw TypingError("Constraint terms must be of sort bool");
            }

            return std::static_pointer_cast<Command>(std::make_shared<ConstraintCmd>(term));
        }
    }

    std::any SymbolTableAstBuilder::visitDefineFun(SyGuSv21Parser::DefineFunContext *ctx) {
        EitherIdentifier id(SimpleIdentifier(ctx->symbol()->SYMBOL()->getText()));
        auto sort = std::any_cast<EitherSort>(ctx->sort()->accept(this));
        std::vector<SortedVar> args;
        for (auto x: ctx->sortedVar()) {
            auto arg_var = std::any_cast<SortedVar>(x->accept(this));
            args.push_back(arg_var);
            this->table->push_symbol_stack(
                    SymbolDescriptor(arg_var.first, arg_var.second, BinderKind::FUNCTION_ARGUMENT));
        }

        auto term = std::any_cast<TermPtr>(ctx->term()->accept(this));

        auto def_cmd = std::make_shared<DefineFunCmd>(id, args, sort, term);

        // Add new Symbol to user defined functions
        this->table->add_user_defined_fun(*def_cmd);
        // Type-check afterwards so that in case of recursion
        EitherSort term_sort = TypeInference::infer_and_check_type(*this->table, term.get());

        this->table->pop_symbol_stack(args.size());

        if (term_sort != def_cmd->get_sort()) {
            throw TypingError(
                    "Sort of term does not match function range sort in definition of function " + to_string(id));
        }

        return std::static_pointer_cast<Command>(def_cmd);
    }

    std::any SymbolTableAstBuilder::visitExistsTerm(SyGuSv21Parser::ExistsTermContext *ctx) {
        std::vector<SortedVar> vars{};
        for (auto x: ctx->sortedVar()) {
            auto sorted_var = std::any_cast<SortedVar>(x->accept(this));
            vars.emplace_back(sorted_var);
            this->table->push_symbol_stack(
                    SymbolDescriptor(sorted_var.first, sorted_var.second, BinderKind::QUANTIFIER));
        }

        auto subterm = std::any_cast<TermPtr>(ctx->term()->accept(this));

        if (TypeInference::infer_and_check_type(*this->table,
                                                subterm.get()) != CoreResolver::get_bool_sort()) {
            throw TypingError("Subterm of quantifier does not match Bool sort.");
        }

        this->table->pop_symbol_stack(vars.size());

        return std::static_pointer_cast<Term>(std::make_shared<ExistsTerm>(vars, subterm));
    }

    std::any SymbolTableAstBuilder::visitForallTerm(SyGuSv21Parser::ForallTermContext *ctx) {
        std::vector<SortedVar> vars{};
        for (auto x: ctx->sortedVar()) {
            auto sorted_var = std::any_cast<SortedVar>(x->accept(this));
            vars.emplace_back(sorted_var);
            this->table->push_symbol_stack(
                    SymbolDescriptor(sorted_var.first, sorted_var.second, BinderKind::QUANTIFIER));
        }

        auto subterm = std::any_cast<TermPtr>(ctx->term()->accept(this));

        if (TypeInference::infer_and_check_type(*this->table, subterm.get()) != CoreResolver::get_bool_sort()) {
            throw TypingError("Subterm of quantifier does not match Bool sort.");
        }

        this->table->pop_symbol_stack(vars.size());

        return std::static_pointer_cast<Term>(std::make_shared<ForallTerm>(vars, subterm));
    }

    std::any SymbolTableAstBuilder::visitLetTerm(SyGuSv21Parser::LetTermContext *ctx) {
        std::vector<VarBinding> bindings{};
        for (auto x: ctx->varBinding()) {
            auto res = std::any_cast<VarBinding>(x->accept(this));
            bindings.push_back(res);
            EitherSort var_type = TypeInference::infer_and_check_type(*this->table, res.second.get());
            this->table->push_symbol_stack(SymbolDescriptor(res.first, var_type,
                                                            BinderKind::LET));
        }

        auto subterm = std::any_cast<TermPtr>(ctx->term()->accept(this));

        this->table->pop_symbol_stack(bindings.size());

        return std::static_pointer_cast<Term>(std::make_shared<LetTerm>(bindings, subterm));
    }

    std::any SymbolTableAstBuilder::visitBfApplicationTerm(SyGuSv21Parser::BfApplicationTermContext *ctx) {
        auto id = std::any_cast<EitherIdentifier>(ctx->identifier()->accept(this));
        std::vector<TermPtr> args{};
        for (auto x: ctx->bfTerm()) {
            std::any res = x->accept(this);

            auto term = std::any_cast<TermPtr>(x->accept(this));
            args.push_back(term);
        }

        auto app = std::static_pointer_cast<Term>(std::make_shared<ApplicationTerm>(id, args));
        return app;
    }

    std::any SymbolTableAstBuilder::visitApplicationTerm(SyGuSv21Parser::ApplicationTermContext *ctx) {
        auto id = std::any_cast<EitherIdentifier>(ctx->identifier()->accept(this));

        std::vector<TermPtr> args{};
        for (auto x: ctx->term()) {
            auto term = std::any_cast<TermPtr>(x->accept(this));
            args.emplace_back(term);
        }
        auto app = std::static_pointer_cast<Term>(std::make_shared<ApplicationTerm>(id, args));
        return {app};
    }

    std::any SymbolTableAstBuilder::visitSynthFunCmd(SyGuSv21Parser::SynthFunCmdContext *ctx) {
        EitherIdentifier id(SimpleIdentifier(ctx->symbol()->SYMBOL()->getText()));
        auto x = ctx->sort()->accept(this);
        auto sort = std::any_cast<EitherSort>(x);

        std::vector<SortedVar> arguments;
        for (SyGuSv21Parser::SortedVarContext *s_var: ctx->sortedVar()) {
            std::any res = s_var->accept(this);
            auto ptr = std::any_cast<SortedVar>(res);
            arguments.push_back(ptr);
            this->table->push_symbol_stack(SymbolDescriptor(ptr.first, ptr.second,
                                                            BinderKind::SYNTH_FUN_ARGUMENT));
        }

        //adding new function to symbol table
        this->table->add_synth_fun(id, arguments, sort);

        auto grammar = std::any_cast<GrammarDef>(ctx->grammarDef()->accept(this));

        this->table->pop_symbol_stack(arguments.size());

        return std::static_pointer_cast<Command>(std::make_shared<SynthFunCmd>(id, arguments, sort,
                                                                               grammar));
    }

    std::any SymbolTableAstBuilder::visitGrammarDef(SyGuSv21Parser::GrammarDefContext *ctx) {
        std::vector<SortedVar> non_terminals;
        for (auto x: ctx->sortedVar()) {
            auto s_var = std::any_cast<SortedVar>(x->accept(this));


            non_terminals.push_back(s_var);
            this->table->push_symbol_stack(
                    SymbolDescriptor(s_var.first, s_var.second, BinderKind::GRAMMAR_NON_TERMINAL));
        }

        std::vector<GroupedRuleList> rules;
        for (auto x: ctx->groupedRuleList()) {
            rules.push_back(std::any_cast<GroupedRuleList>(x->accept(this)));
        }

        this->table->pop_symbol_stack(non_terminals.size());

        return GrammarDef(non_terminals, rules);
    }

    std::any SymbolTableAstBuilder::visitGroupedRuleList(SyGuSv21Parser::GroupedRuleListContext *ctx) {
        EitherIdentifier id(SimpleIdentifier(ctx->symbol()->SYMBOL()->getText()));
        auto sort = std::any_cast<EitherSort>(ctx->sort()->accept(this));

        std::vector<TermPtr> terms;
        for (auto x: ctx->gTerm()) {
            auto ptr = std::any_cast<TermPtr>(x->accept(this));
            EitherSort term_sort = TypeInference::infer_and_check_type(*this->table, ptr.get());
            if (term_sort != sort) {
                throw TypingError("In grammar for non-terminal " + to_string(id) +
                                  " terms did not match type of non-terminal.");
            }
            terms.emplace_back(ptr);
        }

        return GroupedRuleList(id, sort, terms);
    }

    std::any SymbolTableAstBuilder::visitFeature(SyGuSv21Parser::FeatureContext *ctx) {
        if (ctx->GRAMMARS_FEATURE() != nullptr) {
            return Feature::GRAMMARS;
        } else if (ctx->FWD_DECLS_FEATURE() != nullptr) {
            return Feature::FWD_DECLS;
        } else if (ctx->RECURSION_FEATURE() != nullptr) {
            return Feature::RECURSION;
        } else if (ctx->ORACLES_FEATURE() != nullptr) {
            return Feature::ORACLES;
        } else if (ctx->WEIGHTS_FEATURE() != nullptr) {
            return Feature::WEIGHTS;
        } else {
            throw UnsupportedFeature("Feature string not in supported features.");
        }
    }

    std::any SymbolTableAstBuilder::visitProblem(SyGuSv21Parser::ProblemContext *ctx) {
        for (SyGuSv21Parser::CmdContext *x: ctx->cmd()) {
            std::any ret = x->accept(this);
            auto cmd = std::any_cast<std::shared_ptr<Command>>(ret);
            this->problem->add_command(cmd);
        }
        return this->problem;
    }

    std::any SymbolTableAstBuilder::visitDeclareSort(SyGuSv21Parser::DeclareSortContext *ctx) {
        throw UnsupportedFeature("Uninterpreted sorts are not supported yet.");
        //EitherIdentifier id(SimpleIdentifier(ctx->symbol()->SYMBOL()->getText()));
        //auto num = std::any_cast<LiteralPtr>(ctx->numeral()->accept(this));
        //std::shared_ptr<Numeral> numeral = std::static_pointer_cast<Numeral>(num);
        //return std::static_pointer_cast<Command>(std::make_shared<DeclareSort>(id, *numeral));
    }

    std::any SymbolTableAstBuilder::visitDeclareVarCmd(SyGuSv21Parser::DeclareVarCmdContext *ctx) {
        EitherIdentifier id(SimpleIdentifier(ctx->symbol()->SYMBOL()->getText()));
        auto sort = std::any_cast<EitherSort>(ctx->sort()->accept(this));

        SymbolDescriptor descr(id, sort, BinderKind::DECLARE_VAR);
        this->table->push_symbol_stack(descr);

        return std::static_pointer_cast<Command>(std::make_shared<DeclareVarCmd>(id, sort));
    }

    std::any SymbolTableAstBuilder::visitSetFeatureCmd(SyGuSv21Parser::SetFeatureCmdContext *ctx) {
        auto ft = std::any_cast<Feature>(ctx->feature()->accept(this));
        auto val = std::any_cast<std::shared_ptr<BoolConst>>(
                ctx->boolConst()->accept(this));
        return std::static_pointer_cast<Command>(std::make_shared<SetFeatureCmd>(ft, val->get_value()));
    }

    std::any SymbolTableAstBuilder::visitIdentifierTerm(SyGuSv21Parser::IdentifierTermContext *ctx) {
        auto x = std::any_cast<EitherIdentifier>(ctx->identifier()->accept(this));
        auto shared_ptr = std::make_shared<IdentifierTerm>(x);
        return std::static_pointer_cast<Term>(shared_ptr);
    }

    std::any SymbolTableAstBuilder::visitSimpleSort(SyGuSv21Parser::SimpleSortContext *ctx) {
        auto id = std::any_cast<EitherIdentifier>(ctx->identifier()->accept(this));
        EitherSort sort{SimpleSort(id)};
        auto sort_opt = table->lookup_sort(sort);
        if(!sort_opt) {
            throw UnknownSymbol("Symbol " + to_string(id) + " unknown.");
        }
        return sort;
    }

    std::any SymbolTableAstBuilder::visitParametricSort(SyGuSv21Parser::ParametricSortContext *ctx) {
        throw NotImplemented("Parametric Sorts are not supported yet.");
    }

    std::any SymbolTableAstBuilder::visitIndexedIdentifier(SyGuSv21Parser::IndexedIdentifierContext *ctx) {
        SimpleIdentifier id(ctx->symbol()->SYMBOL()->getText());
        std::vector<Index> indices;
        for(auto index: ctx->index()){
            indices.push_back(std::any_cast<Index>(index->accept(this)));
        }
        return EitherIdentifier(IndexedIdentifier(id, indices));
    }

    std::any SymbolTableAstBuilder::visitDecimal(SyGuSv21Parser::DecimalContext *ctx) {
        throw NotImplemented("Decimal constants are not supported yet.");
    }

    std::any SymbolTableAstBuilder::visitBoolConstTrue(SyGuSv21Parser::BoolConstTrueContext *ctx) {
        return std::static_pointer_cast<Literal>(std::make_shared<BoolConst>(true));
    }

    std::any SymbolTableAstBuilder::visitBoolConstFalse(SyGuSv21Parser::BoolConstFalseContext *ctx) {
        return std::static_pointer_cast<Literal>(std::make_shared<BoolConst>(false));
    }

    std::any SymbolTableAstBuilder::visitLiteralTerm(SyGuSv21Parser::LiteralTermContext *ctx) {
        auto x = std::any_cast<std::shared_ptr<Literal>>(ctx->literal()->accept(this));
        return std::static_pointer_cast<Term>(x);
    }

    std::any SymbolTableAstBuilder::visitBfIdentifierTerm(SyGuSv21Parser::BfIdentifierTermContext *ctx) {
        auto x = std::any_cast<EitherIdentifier>(ctx->identifier()->accept(this));
        auto shared_ptr = std::make_shared<IdentifierTerm>(x);
        return {std::static_pointer_cast<Term>(shared_ptr)};
    }

    std::any SymbolTableAstBuilder::visitBfLiteralTerm(SyGuSv21Parser::BfLiteralTermContext *ctx) {
        auto x = std::any_cast<std::shared_ptr<Literal>>(ctx->literal()->accept(this));
        return std::static_pointer_cast<Term>(x);
    }

    std::any SymbolTableAstBuilder::visitSortedVar(SyGuSv21Parser::SortedVarContext *ctx) {
        EitherIdentifier id = get_simple_id_from_str(ctx->symbol()->getText());
        auto sort = std::any_cast<EitherSort>(ctx->sort()->accept(this));
        return SortedVar(id, sort);
    }

    std::any SymbolTableAstBuilder::visitVarBinding(SyGuSv21Parser::VarBindingContext *ctx) {
        std::string symbol = ctx->symbol()->getText();
        EitherIdentifier id = EitherIdentifier(SimpleIdentifier{symbol});
        auto term = std::any_cast<std::shared_ptr<Term>>(ctx->term()->accept(this));
        return VarBinding(id, term);
    }

    std::any SymbolTableAstBuilder::visitCheckSynthCmd(SyGuSv21Parser::CheckSynthCmdContext *ctx) {
        return std::static_pointer_cast<Command>(std::make_shared<CheckSynthCmd>());
    }

    std::any SymbolTableAstBuilder::visitSetLogic(SyGuSv21Parser::SetLogicContext *ctx) {
        std::string s = ctx->symbol()->SYMBOL()->getText();

        // add theory functions
        if (s.find("LIA") != std::string::npos) {
            this->table->add_resolver(std::make_shared<LIAResolver>());
        }

        return std::static_pointer_cast<Command>(std::make_shared<SetLogic>(s));
    }

    std::any SymbolTableAstBuilder::visitSetInfo(SyGuSv21Parser::SetInfoContext *ctx) {
        std::string keyword = ctx->symbol()->SYMBOL()->getText();
        auto lit = std::any_cast<LiteralPtr>(ctx->literal()->accept(this));
        return std::static_pointer_cast<Command>(std::make_shared<SetInfo>(keyword, lit));
    }

    std::any SymbolTableAstBuilder::visitDefineSort(SyGuSv21Parser::DefineSortContext *ctx) {
        EitherIdentifier id(SimpleIdentifier(ctx->symbol()->SYMBOL()->getText()));
        auto sort = std::any_cast<EitherSort>(ctx->accept(this));
        return std::static_pointer_cast<Command>(std::make_shared<DefineSort>(id, sort));
    }

    std::any SymbolTableAstBuilder::visitSetOption(SyGuSv21Parser::SetOptionContext *ctx) {
        std::string keyword = ctx->symbol()->SYMBOL()->getText();
        auto lit = std::any_cast<std::shared_ptr<Literal>>(ctx->literal()->accept(this));
        return std::static_pointer_cast<Command>(std::make_shared<SetOption>(keyword, lit));
    }

    std::any SymbolTableAstBuilder::visitConstantGTerm(SyGuSv21Parser::ConstantGTermContext *ctx) {
        auto sort = std::any_cast<EitherSort>(ctx->sort()->accept(this));
        return std::static_pointer_cast<Term>(std::make_shared<ConstantGTerm>(sort));
    }

    std::any SymbolTableAstBuilder::visitVariableGTerm(SyGuSv21Parser::VariableGTermContext *ctx) {
        auto sort = std::any_cast<EitherSort>(ctx->sort()->accept(this));
        return std::static_pointer_cast<Term>(std::make_shared<VariableGTerm>(sort));
    }

    std::any SymbolTableAstBuilder::visitAssumeCmd(SyGuSv21Parser::AssumeCmdContext *ctx) {
        return std::static_pointer_cast<Command>(
                std::make_shared<AssumeCmd>(std::any_cast<std::shared_ptr<Term>>(
                        ctx->term()->accept(this))));
    }

    std::any SymbolTableAstBuilder::visitNumeralIndex(SyGuSv21Parser::NumeralIndexContext *ctx)  {
        auto lit = std::any_cast<std::shared_ptr<Literal>>(ctx->numeral()->accept(this));
        auto num_ptr = std::static_pointer_cast<Numeral>(lit);
        return Index(*num_ptr);
    }

    std::any SymbolTableAstBuilder::visitSymbolIndex(SyGuSv21Parser::SymbolIndexContext *ctx) {
        return Index(SimpleIdentifier(ctx->getText()));
    }

}
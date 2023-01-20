//
// Created by julian on 15.12.22.
//
#include <ranges>
#include "SymbolTable.h"
#include "../exceptions/UnknownSymbol.h"
#include "../typing.h"

bool SymbolTable::add_user_defined_fun(DefineFunCmd& cmd) {
    EitherIdentifier id(cmd.get_identifier());
    std::vector<SortedVar>& rg = cmd.get_arguments();
    std::vector<EitherSort> arg_sorts;
    std::transform(rg.begin(), rg.end(), std::back_inserter(arg_sorts),
                   [](SortedVar& x) {return x.second;});
    EitherSort range_sort = cmd.get_sort();

    auto [_, val] = this->user_defined_funs.emplace(id, FunctionDescriptor(id, arg_sorts, range_sort, false));
    return val;
}

bool SymbolTable::add_synth_fun(const EitherIdentifier& id, const std::vector<SortedVar>& arguments, const EitherSort& range_sort) {
    std::vector<EitherSort> arg_sorts;
    std::transform(arguments.begin(),arguments.end(), std::back_inserter(arg_sorts),
                   [](const SortedVar& x) {return x.second;});

    auto [_, val] = this->synth_fun_funs.emplace(id, FunctionDescriptor(id, arg_sorts, range_sort, false));
    return val;
}

std::optional<FunctionDescriptor>
SymbolTable::lookup_or_resolve_function(const EitherIdentifier& identifier, const std::vector<EitherSort>& arg_sorts) const {
    for (auto& res : this->resolvers) {
        std::optional<FunctionDescriptor> descr = res->lookup_or_resolve_function(identifier, arg_sorts);
        if(descr) {
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

std::optional<EitherSort> SymbolTable::lookup_sort(const EitherSort& sort) const {
    for (auto& res : this->resolvers) {
        std::optional<EitherSort> descr = res->lookup_sort(sort);
        if(descr) {
            return descr;
        }
    }

    if (this->sorts.contains(sort)) {
        return std::make_optional<EitherSort>(sort);
    }
    return std::nullopt;
}

void SymbolTable::add_resolver(const std::shared_ptr<AbstractResolver> &ptr)  {
    resolvers.push_back(ptr);
}

std::optional<SymbolDescriptor> SymbolTable::resolve_symbol_descriptor(const EitherIdentifier &identifier) const {
    for (auto& i : std::views::reverse(this->symbol_stack)) {
        if (i.get_identifier() == identifier) {
            return std::make_optional<SymbolDescriptor>(i);
        }
    }
    return std::nullopt;
}

SymbolDescriptor SymbolTable::pop_symbol_stack() {
    SymbolDescriptor res(this->symbol_stack.back());
    this->symbol_stack.pop_back();
    return res;
}

void SymbolTable::push_symbol_stack(const SymbolDescriptor &descr) {
    this->symbol_stack.push_back(descr);
}

std::vector<SymbolDescriptor> SymbolTable::pop_symbol_stack(std::size_t n) {
    std::vector<SymbolDescriptor> res;
    for (int i = 0; i < n; ++i) {
        res.push_back(this->pop_symbol_stack());
    }
    return res;
}

std::any symbol_table_ast_builder::visitSimpleIdentifier(SyGuSv21Parser::SimpleIdentifierContext *ctx)
{
    SimpleIdentifier id(ctx->symbol()->SYMBOL()->getText());
    return EitherIdentifier(id);
}

std::any symbol_table_ast_builder::visitNumeral(SyGuSv21Parser::NumeralContext *ctx) {
    auto str = ctx->NUMERAL()->getSymbol()->getText();
    auto val = std::strtol(str.c_str(), nullptr, 10);
    return std::static_pointer_cast<Literal>(std::make_shared<Numeral>(val));
}

std::any symbol_table_ast_builder::visitStringConst(SyGuSv21Parser::StringConstContext *ctx)  {
    if (ctx->EMPTYSTRING() != nullptr) {
        return std::static_pointer_cast<Literal>(std::make_shared<StringConst>(""));
    } else  if (ctx->STRINGCONST() != nullptr) {
        return std::static_pointer_cast<Literal>(std::make_shared<StringConst>(ctx->STRINGCONST()->getText()));
    } else {
        throw unsupported_feature("Strong Const is neither constant nor empty.");
    }
}

std::any symbol_table_ast_builder::visitConstraintCmd(SyGuSv21Parser::ConstraintCmdContext *ctx) {
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

std::any symbol_table_ast_builder::visitDefineFun(SyGuSv21Parser::DefineFunContext *ctx)  {
    EitherIdentifier id(SimpleIdentifier(ctx->symbol()->SYMBOL()->getText()));
    auto sort = std::any_cast<EitherSort>(ctx->sort()->accept(this));
    std::vector<SortedVar> args;
    for(auto x: ctx->sortedVar()) {
        auto arg_var = std::any_cast<SortedVar>(x->accept(this));
        args.push_back(arg_var);
        this->table->push_symbol_stack(SymbolDescriptor(arg_var.first, arg_var.second, BinderKind::FUNCTION_ARGUMENT));
    }

    auto term = std::any_cast<TermPtr>(ctx->term()->accept(this));

    auto def_cmd = std::make_shared<DefineFunCmd>(id, args, sort, term);

    // Add new Symbol to user defined functions
    this->table->add_user_defined_fun(*def_cmd);
    // Type-check afterwards so that in case of recursion
    EitherSort term_sort = TypeInference::infer_and_check_type(*this->table, term.get());

    this->table->pop_symbol_stack(args.size());

    if (term_sort != def_cmd->get_sort()) {
        throw TypingError("Sort of term does not match function range sort in definition of function " + to_string(id));
    }

    return std::static_pointer_cast<Command>(def_cmd);
}

std::any symbol_table_ast_builder::visitExistsTerm(SyGuSv21Parser::ExistsTermContext *ctx) {
    std::vector<SortedVar> vars{};
    for (auto x : ctx->sortedVar()) {
        auto sorted_var = std::any_cast<SortedVar>(x->accept(this));
        vars.emplace_back(sorted_var);
        this->table->push_symbol_stack(SymbolDescriptor(sorted_var.first, sorted_var.second, BinderKind::QUANTIFIER));
    }

    auto subterm = std::any_cast<TermPtr>(ctx->term()->accept(this));

    if (TypeInference::infer_and_check_type(*this->table, subterm.get()) != CoreResolver::get_bool_sort())  {
        throw TypingError("Subterm of quantifier does not match Bool sort.");
    }

    this->table->pop_symbol_stack(vars.size());

    return std::static_pointer_cast<Term>(std::make_shared<ExistsTerm>(vars, subterm));
}

std::any symbol_table_ast_builder::visitForallTerm(SyGuSv21Parser::ForallTermContext *ctx) {
    std::vector<SortedVar> vars{};
    for (auto x : ctx->sortedVar()) {
        auto sorted_var = std::any_cast<SortedVar>(x->accept(this));
        vars.emplace_back(sorted_var);
        this->table->push_symbol_stack(SymbolDescriptor(sorted_var.first, sorted_var.second, BinderKind::QUANTIFIER));
    }

    auto subterm = std::any_cast<TermPtr>(ctx->term()->accept(this));

    if (TypeInference::infer_and_check_type(*this->table, subterm.get()) != CoreResolver::get_bool_sort())  {
        throw TypingError("Subterm of quantifier does not match Bool sort.");
    }

    this->table->pop_symbol_stack(vars.size());

    return std::static_pointer_cast<Term>(std::make_shared<ForallTerm>(vars, subterm));
}

std::any symbol_table_ast_builder::visitLetTerm(SyGuSv21Parser::LetTermContext *ctx) {
    std::vector<VarBinding> bindings{};
    for (auto x : ctx->varBinding()) {
        auto res = std::any_cast<VarBinding>(x->accept(this));
        bindings.push_back(res);
        EitherSort var_type = TypeInference::infer_and_check_type(*this->table, res.second.get());
        this->table->push_symbol_stack(SymbolDescriptor(res.first, var_type, BinderKind::LET));
    }

    auto subterm = std::any_cast<TermPtr>(ctx->term()->accept(this));

    this->table->pop_symbol_stack(bindings.size());

    return std::static_pointer_cast<Term>(std::make_shared<LetTerm>(bindings, subterm));
}

std::any symbol_table_ast_builder::visitBfApplicationTerm(SyGuSv21Parser::BfApplicationTermContext *ctx)  {
    auto id = std::any_cast<EitherIdentifier>(ctx->identifier()->accept(this));
    std::vector<TermPtr> args{};
    for (auto x : ctx->bfTerm()) {
        std::any res = x->accept(this);

        auto term = std::any_cast<TermPtr>(x->accept(this));
        args.push_back(term);
    }

    auto app = std::static_pointer_cast<Term>(std::make_shared<ApplicationTerm>(id, args));
    return app;
}

std::any symbol_table_ast_builder::visitApplicationTerm(SyGuSv21Parser::ApplicationTermContext *ctx) {
    auto id = std::any_cast<EitherIdentifier>(ctx->identifier()->accept(this));

    std::vector<TermPtr> args{};
    for (auto x : ctx->term()) {
        auto res = x->accept(this);
        auto term = std::any_cast<TermPtr>(x->accept(this));
        args.emplace_back(term);
    }
    auto app = std::static_pointer_cast<Term>(std::make_shared<ApplicationTerm>(id, args));
    return {app};
}

std::any symbol_table_ast_builder::visitSynthFunCmd(SyGuSv21Parser::SynthFunCmdContext *ctx)  {
    EitherIdentifier id(SimpleIdentifier(ctx->symbol()->SYMBOL()->getText()));
    auto x = ctx->sort()->accept(this);
    auto sort = std::any_cast<EitherSort>(x);

    std::vector<SortedVar> arguments;
    for (SyGuSv21Parser::SortedVarContext* s_var : ctx->sortedVar()) {
        std::any res = s_var->accept(this);
        auto ptr = std::any_cast<SortedVar>(res);
        arguments.push_back(ptr);
        this->table->push_symbol_stack(SymbolDescriptor(ptr.first, ptr.second, BinderKind::SYNTH_FUN_ARGUMENT));
    }

    //adding new function to symbol table
    this->table->add_synth_fun(id, arguments, sort);

    auto grammar = std::any_cast<GrammarDef>(ctx->grammarDef()->accept(this));

    this->table->pop_symbol_stack(arguments.size());

    return std::static_pointer_cast<Command>(std::make_shared<SynthFunCmd>(id, arguments, sort, grammar));
}

std::any symbol_table_ast_builder::visitGrammarDef(SyGuSv21Parser::GrammarDefContext *ctx) {
    std::vector<SortedVar> non_terminals;
    for(auto x: ctx->sortedVar()) {
        auto s_var = std::any_cast<SortedVar>(x->accept(this));
        non_terminals.push_back(s_var);
        this->table->push_symbol_stack(SymbolDescriptor(s_var.first, s_var.second, BinderKind::GRAMMAR_NON_TERMINAL));
    }

    std::vector<GroupedRuleList> rules;
    for(auto x: ctx->groupedRuleList()) {
        rules.push_back(std::any_cast<GroupedRuleList>(x->accept(this)));
    }

    this->table->pop_symbol_stack(non_terminals.size());

    return GrammarDef(non_terminals, rules);
}

std::any symbol_table_ast_builder::visitGroupedRuleList(SyGuSv21Parser::GroupedRuleListContext *ctx) {
    EitherIdentifier id(SimpleIdentifier(ctx->symbol()->SYMBOL()->getText()));
    auto sort = std::any_cast<EitherSort>(ctx->sort()->accept(this));

    std::vector<TermPtr> terms;
    for (auto x : ctx->gTerm()) {
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

std::any symbol_table_ast_builder::visitFeature(SyGuSv21Parser::FeatureContext *ctx) {
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
        throw unsupported_feature("Feature string not in supported features.");
    }
}

std::any symbol_table_ast_builder::visitProblem(SyGuSv21Parser::ProblemContext *ctx) {
    for(SyGuSv21Parser::CmdContext* x: ctx->cmd()) {
        std::any ret = x->accept(this);
        auto cmd = std::any_cast<std::shared_ptr<Command>>(ret);
        this->problem->add_command(cmd);
    }
    return this->problem;
}

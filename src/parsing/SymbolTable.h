//
// Created by julian on 15.12.22.
//

#ifndef PHYSER_SYMBOLTABLE_H
#define PHYSER_SYMBOLTABLE_H

#include <variant>
#include <vector>
#include <iostream>
#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>

#include "SyGuSv21BaseVisitor.h"
#include "../exceptions/not_implemented.h"
#include "../exceptions/unsupported_feature.h"

#include "ast.h"

class SymbolTable {

private:

    // Mapping identifiers to defined functions
    std::unordered_map<ast::EitherIdentifier, std::shared_ptr<FunctionDeclaration>> function_map;

    // Mapping identifiers to synth fun commands
    std::unordered_map<ast::EitherIdentifier, std::shared_ptr<ast::SynthFunCmd>> synth_fun_map;

    // A set containing all present sorts
    std::unordered_set<ast::SortPtr> all_sorts;

    std::unordered_map<ast::EitherIdentifier, std::shared_ptr<ast::DeclareVarCmd>> declared_vars;


public:

    // adding bool sorts and default boolean functions
    SymbolTable() : all_sorts{ast::get_simple_sort_from_str("Bool")}, function_map{default_boolean_functions()}
    {  }

    bool sort_exists(const ast::SortPtr& ptr) {
        if (this->all_sorts.contains(ptr)) {
            return true;
        }
        return false;
    }

    bool identifier_exists(const ast::EitherIdentifier& id) {
        if (this->function_map.contains(id)) {
            return true;
        } else if (this->synth_fun_map.contains(id)) {
            return true;
        } else if (this->declared_vars.contains(id)) {
            return true;
        }
        return false;
    }

    bool symbol_exists(std::string& s) {
        if (this->sort_exists(ast::get_simple_sort_from_str(s))){
            return true;
        }
        ast::EitherIdentifier id = ast::get_simple_id_from_str(s);
        if (this->identifier_exists(id)) {
            return true;
        }
        return false;
    }

    bool add_synth_fun_cmd(std::shared_ptr<ast::SynthFunCmd>& cmd) {
        ast::EitherIdentifier id(cmd->get_identifier());
        auto [_, val] = this->synth_fun_map.insert({id, cmd});
        return val;
    }

    bool add_function_declaration(ast::EitherIdentifier id,
                                  std::vector<ast::SortPtr> arguments,
                                  std::shared_ptr<ast::EitherSort> sort);

    bool add_function_declaration(const ast::EitherIdentifier& id,
                                  std::shared_ptr<FunctionDeclaration>& fd);

    bool add_declared_var(std::shared_ptr<ast::DeclareVarCmd>& decl);

    ast::SortPtr resolve_sort_by_string(std::string &s);
    ast::SortPtr resolve_sort_by_string(std::string &&s);

    //adding sort
    bool add_sort(const ast::SortPtr& srt) {
        auto [_, flag] = this->all_sorts.insert(srt);
        return flag;
    }

    // Functions
    static std::unordered_map<ast::EitherIdentifier, std::shared_ptr<FunctionDeclaration>>  default_boolean_functions();
    static std::unordered_map<ast::EitherIdentifier, std::shared_ptr<FunctionDeclaration>>  default_lia_functions();

};

class symbol_table_ast_builder: public SyGuSv21BaseVisitor {
private:
    std::shared_ptr<SymbolTable> table;
    std::shared_ptr<ast::Problem> problem;

    // maybe make private so we have a static builder class
    symbol_table_ast_builder() {
        table = std::make_shared<SymbolTable>();
        problem = std::make_shared<ast::Problem>();
    }

public:


    std::any visitSimpleIdentifier(SyGuSv21Parser::SimpleIdentifierContext *ctx) override {
        ast::SimpleIdentifier id(ctx->symbol()->SYMBOL()->getText());
        return ast::EitherIdentifier(id);
    }

    std::any visitIndexedIdentifier(SyGuSv21Parser::IndexedIdentifierContext *ctx) override {
        throw not_implemented("IndextedIdentififers are not supported yet.");
    }

    std::any visitNumeral(SyGuSv21Parser::NumeralContext *ctx) override {
        auto str = ctx->NUMERAL()->getSymbol()->getText();
        auto val = std::strtol(str.c_str(), nullptr, 10);
        return std::static_pointer_cast<ast::Literal>(std::make_shared<ast::Numeral>(val));

    }

    std::any visitDecimal(SyGuSv21Parser::DecimalContext *ctx) override {
        throw not_implemented("Decimal constants are not supported yet.");
    }

    std::any visitBoolConstTrue(SyGuSv21Parser::BoolConstTrueContext *ctx) override {
        return  std::static_pointer_cast<ast::Literal>(std::make_shared<ast::BoolConst>(true));
    }

    std::any visitBoolConstFalse(SyGuSv21Parser::BoolConstFalseContext *ctx) override {
        return  std::static_pointer_cast<ast::Literal>(std::make_shared<ast::BoolConst>(false));
    }

    std::any visitHexConst(SyGuSv21Parser::HexConstContext *ctx) override {
        throw not_implemented("Decimal constants are not supported yet.");
    }

    std::any visitBinConst(SyGuSv21Parser::BinConstContext *ctx) override {
        throw not_implemented("Decimal constants are not supported yet.");
    }

    std::any visitStringConst(SyGuSv21Parser::StringConstContext *ctx) override {
        if (ctx->EMPTYSTRING() != nullptr) {
            return std::static_pointer_cast<ast::Literal>(std::make_shared<ast::StringConst>(""));
        } else  if (ctx->STRINGCONST() != nullptr) {
            return std::static_pointer_cast<ast::Literal>(std::make_shared<ast::StringConst>(ctx->STRINGCONST()->getText()));
        } else {
            throw unsupported_feature("Strong Const is neither constant nor empty.");
        }
    }

    std::any visitIndex(SyGuSv21Parser::IndexContext *ctx) override {
        throw not_implemented("Indexes are not supported yet.");
    }

    std::any visitSimpleSort(SyGuSv21Parser::SimpleSortContext *ctx) override {
        auto id = std::any_cast<ast::EitherIdentifier>(ctx->identifier()->accept(this));
        std::shared_ptr<ast::SimpleSort> simple_sort = std::make_shared<ast::SimpleSort>(id);
        return std::make_shared<ast::EitherSort>(simple_sort);
    }

    std::any visitParametricSort(SyGuSv21Parser::ParametricSortContext *ctx) override {
        throw not_implemented("Parametric Sorts are not supported yet.");
    }

    std::any visitIdentifierTerm(SyGuSv21Parser::IdentifierTermContext *ctx) override {
        auto x = std::any_cast<ast::EitherIdentifier>(ctx->identifier()->accept(this));
        auto shared_ptr = std::make_shared<ast::IdentifierTerm>(x);
        return std::static_pointer_cast<ast::Term>(shared_ptr);
    }

    std::any visitLiteralTerm(SyGuSv21Parser::LiteralTermContext *ctx) override {
        auto x = std::any_cast<std::shared_ptr<ast::Literal>>(ctx->literal()->accept(this));
        return std::static_pointer_cast<ast::Term>(x);
    }

    std::any visitApplicationTerm(SyGuSv21Parser::ApplicationTermContext *ctx) override {
        auto id = std::any_cast<ast::EitherIdentifier>(ctx->identifier()->accept(this));
        std::vector<ast::TermPtr> args{};
        for (auto x : ctx->term()) {
            auto res = x->accept(this);
            auto term = std::any_cast<ast::TermPtr>(x->accept(this));
            args.emplace_back(term);
        }
        auto app = std::static_pointer_cast<ast::Term>(std::make_shared<ast::ApplicationTerm>(id, args));
        return app;
    }

    std::any visitExistsTerm(SyGuSv21Parser::ExistsTermContext *ctx) override {
        std::vector<std::shared_ptr<ast::SortedVar>> vars{};
        for (auto x : ctx->sortedVar()) {
            auto sorted_var = std::any_cast<std::shared_ptr<ast::SortedVar>>(x->accept(this));
            vars.emplace_back(sorted_var);
        }
        auto subterm = std::any_cast<ast::TermPtr>(ctx->term()->accept(this));
        auto  x = std::static_pointer_cast<ast::Term>(std::make_shared<ast::ExistsTerm>(vars, subterm));
        return x;
    }

    std::any visitForallTerm(SyGuSv21Parser::ForallTermContext *ctx) override {
        std::vector<std::shared_ptr<ast::SortedVar>> vars{};
        for (auto x : ctx->sortedVar()) {
            auto sorted_var = std::any_cast<std::shared_ptr<ast::SortedVar>>(x->accept(this));
            vars.emplace_back(sorted_var);
        }
        auto subterm = std::any_cast<ast::TermPtr>(ctx->term()->accept(this));
        auto  x = std::static_pointer_cast<ast::Term>(std::make_shared<ast::ForallTerm>(vars, subterm));
        return x;
    }

    std::any visitLetTerm(SyGuSv21Parser::LetTermContext *ctx) override {
        std::vector<std::shared_ptr<ast::VarBinding>> bindings{};
        for (auto x : ctx->varBinding()) {
            auto res = std::any_cast<std::shared_ptr<ast::VarBinding>>(x);
            bindings.push_back(res);
        }
        auto subterm = std::any_cast<ast::TermPtr>(ctx->term()->accept(this));
        auto  x = std::static_pointer_cast<ast::Term>(std::make_shared<ast::LetTerm>(bindings, subterm));
        return x;
    }

    std::any visitBfIdentifierTerm(SyGuSv21Parser::BfIdentifierTermContext *ctx) override {
        auto x = std::any_cast<ast::EitherIdentifier>(ctx->identifier()->accept(this));
        auto shared_ptr = std::make_shared<ast::IdentifierTerm>(x);
        return std::static_pointer_cast<ast::Term>(shared_ptr);
    }

    std::any visitBfLiteralTerm(SyGuSv21Parser::BfLiteralTermContext* ctx) override{
        auto x = std::any_cast<std::shared_ptr<ast::Literal>>(ctx->literal()->accept(this));
        return std::static_pointer_cast<ast::Term>(x);
    }

    std::any visitBfApplicationTerm(SyGuSv21Parser::BfApplicationTermContext *ctx) override {
        auto id = std::any_cast<ast::EitherIdentifier>(ctx->identifier()->accept(this));
        std::vector<ast::TermPtr> args{};
        for (auto x : ctx->bfTerm()) {
            std::any res = x->accept(this);

            auto term = std::any_cast<ast::TermPtr>(x->accept(this));
            args.push_back(term);
        }

        auto app = std::static_pointer_cast<ast::Term>(std::make_shared<ast::ApplicationTerm>(id, args));
        return app;
    }

    std::any visitSortedVar(SyGuSv21Parser::SortedVarContext *ctx) override {
        std::string symbol = ctx->symbol()->getText();
        auto sort = std::any_cast<std::shared_ptr<ast::EitherSort>>(ctx->sort()->accept(this));
        ast::EitherIdentifier id = ast::EitherIdentifier(ast::SimpleIdentifier{symbol});
        return std::make_shared<ast::SortedVar>(id, sort);
    }

    std::any visitVarBinding(SyGuSv21Parser::VarBindingContext *ctx) override {
        std::string symbol = ctx->symbol()->getText();
        ast::EitherIdentifier id = ast::EitherIdentifier(ast::SimpleIdentifier{symbol});
        auto term = std::any_cast<std::shared_ptr<ast::Term>>(ctx->term()->accept(this));
        return std::make_shared<ast::VarBinding>(id, term);
    }

    std::any visitFeature(SyGuSv21Parser::FeatureContext *ctx) override {
        if (ctx->GRAMMARS_FEATURE() != nullptr) {
            return ast::Feature::GRAMMARS;
        } else if (ctx->FWD_DECLS_FEATURE() != nullptr) {
            return ast::Feature::FWD_DECLS;
        } else if (ctx->RECURSION_FEATURE() != nullptr) {
            return ast::Feature::RECURSION;
        } else if (ctx->ORACLES_FEATURE() != nullptr) {
            return ast::Feature::ORACLES;
        } else if (ctx->WEIGHTS_FEATURE() != nullptr) {
            return ast::Feature::WEIGHTS;
        } else {
            throw unsupported_feature("Feature string not in supported features.");
        }
    }

    std::any visitSetFeatureCmd(SyGuSv21Parser::SetFeatureCmdContext *ctx) override {
        auto ft = std::any_cast<ast::Feature>(ctx->feature()->accept(this));
        auto val = std::any_cast<std::shared_ptr<ast::BoolConst>>(ctx->boolConst()->accept(this));
        return std::static_pointer_cast<ast::Command>(std::make_shared<ast::SetFeatureCmd>(ft, val->get_value()));
    }

    std::any visitCheckSynthCmd(SyGuSv21Parser::CheckSynthCmdContext *ctx) override {
        return std::static_pointer_cast<ast::Command>(std::make_shared<ast::CheckSynthCmd>());
    }

    std::any visitConstraintCmd(SyGuSv21Parser::ConstraintCmdContext *ctx) override {
        auto term = std::any_cast<ast::TermPtr>(ctx->term()->accept(this));
        return std::static_pointer_cast<ast::Command>(std::make_shared<ast::ConstraintCmd>(term));
    }

    // TODO add to symbol Table
    std::any visitDeclareVarCmd(SyGuSv21Parser::DeclareVarCmdContext *ctx) override {
        ast::EitherIdentifier id(ast::SimpleIdentifier(ctx->symbol()->SYMBOL()->getText()));
        auto sort = std::any_cast<std::shared_ptr<ast::EitherSort>>(ctx->sort()->accept(this));
        return std::static_pointer_cast<ast::Command>(std::make_shared<ast::DeclareVarCmd>(id, sort));
    }

    // TODO add to symbol Table
    std::any visitSynthFunCmd(SyGuSv21Parser::SynthFunCmdContext *ctx) override {
        ast::EitherIdentifier id(ast::SimpleIdentifier(ctx->symbol()->SYMBOL()->getText()));
        auto x = ctx->sort()->accept(this);
        auto sort = std::any_cast<std::shared_ptr<ast::EitherSort>>(x);

        std::vector<std::shared_ptr<ast::SortedVar>> arguments;
        for (SyGuSv21Parser::SortedVarContext* s_var : ctx->sortedVar()) {
            std::any res = s_var->accept(this);
            auto ptr = std::any_cast<std::shared_ptr<ast::SortedVar>>(res);
            arguments.push_back(ptr);
        }

        auto grammar = std::any_cast<std::shared_ptr<ast::GrammarDef>>(ctx->grammarDef()->accept(this));
        return std::static_pointer_cast<ast::Command>(std::make_shared<ast::SynthFunCmd>(id, arguments, sort, grammar));
    }

    std::any visitDeclareDatatype(SyGuSv21Parser::DeclareDatatypeContext *ctx) override {
        throw not_implemented("DeclareDatatypes are not implemented yet.");
    }

    std::any visitDeclareDatatypes(SyGuSv21Parser::DeclareDatatypesContext *ctx) override {
        throw not_implemented("DeclareDatatypes are not implemented yet.");
    }

    // TODO add to symbol Table
    std::any visitDeclareSort(SyGuSv21Parser::DeclareSortContext *ctx) override {
        ast::EitherIdentifier id(ast::SimpleIdentifier(ctx->symbol()->SYMBOL()->getText()));
        auto num = std::any_cast<std::shared_ptr<ast::Numeral>>(ctx->numeral()->accept(this)) ;
        return std::static_pointer_cast<ast::Command>(std::make_shared<ast::DeclareSort>(id, num)) ;
    }

    // TODO add to symbol Table
    std::any visitDefineFun(SyGuSv21Parser::DefineFunContext *ctx) override {
        ast::EitherIdentifier id(ast::SimpleIdentifier(ctx->symbol()->SYMBOL()->getText()));
        auto sort = std::any_cast<std::shared_ptr<ast::EitherSort>>(ctx->sort()->accept(this));
        std::vector<std::shared_ptr<ast::SortedVar>> args;
        for(auto x: ctx->sortedVar()) {
            args.push_back(std::any_cast<std::shared_ptr<ast::SortedVar>>(x->accept(this)));
        }
        auto term = std::any_cast<ast::TermPtr>(ctx->term()->accept(this));
        return std::static_pointer_cast<ast::Command>(std::make_shared<ast::DefineFun>(id, args, sort, term));
    }

    // TODO add to symbol Table
    std::any visitDefineSort(SyGuSv21Parser::DefineSortContext *ctx) override {
        ast::EitherIdentifier id(ast::SimpleIdentifier(ctx->symbol()->SYMBOL()->getText()));
        auto sort = std::any_cast<std::shared_ptr<ast::EitherSort>>(ctx->accept(this));
        return std::static_pointer_cast<ast::Command>(std::make_shared<ast::DefineSort>(id, sort));
    }

    std::any visitSetInfo(SyGuSv21Parser::SetInfoContext *ctx) override {
        std::string keyword = ctx->symbol()->SYMBOL()->getText();
        auto lit = std::any_cast<std::shared_ptr<ast::Literal>>(ctx->literal()->accept(this));
        return std::static_pointer_cast<ast::Command>(std::make_shared<ast::SetInfo>(keyword, lit));
    }

    std::any visitSetLogic(SyGuSv21Parser::SetLogicContext *ctx) override {
        std::string s = ctx->symbol()->SYMBOL()->getText();
        if (s.find("LIA") != std::string::npos) {   // We havea a LIA substring
            this->table->add_sort(ast::get_simple_sort_from_str("Int"));
            for (std::pair<ast::EitherIdentifier, std::shared_ptr<FunctionDeclaration>> x : SymbolTable::default_lia_functions()) {
                this->table->add_function_declaration(x.first, x.second);
            }
        }

        return std::static_pointer_cast<ast::Command>(std::make_shared<ast::SetLogic>(s));
    }

    std::any visitSetOption(SyGuSv21Parser::SetOptionContext *ctx) override {
        std::string keyword = ctx->symbol()->SYMBOL()->getText();
        auto lit = std::any_cast<std::shared_ptr<ast::Literal>>(ctx->literal()->accept(this));
        return std::static_pointer_cast<ast::Command>(std::make_shared<ast::SetOption>(keyword, lit));
    }

    std::any visitSortDecl(SyGuSv21Parser::SortDeclContext *ctx) override {
        throw not_implemented("DeclareDatatypes are not implemented yet.");
    }

    std::any visitDtDecl(SyGuSv21Parser::DtDeclContext *ctx) override {
        throw not_implemented("DeclareDatatypes are not implemented yet.");
    }

    std::any visitDtConsDecl(SyGuSv21Parser::DtConsDeclContext *ctx) override {
        throw not_implemented("DeclareDatatypes are not implemented yet.");
    }

    std::any visitGrammarDef(SyGuSv21Parser::GrammarDefContext *ctx) override {
        std::vector<std::shared_ptr<ast::SortedVar>> vars;
        for(auto x: ctx->sortedVar()) {
            vars.push_back(std::any_cast<std::shared_ptr<ast::SortedVar>>(x->accept(this)));
        }

        std::vector<std::shared_ptr<ast::GroupedRuleList>> rules;
        for(auto x: ctx->groupedRuleList()) {
            rules.push_back(std::any_cast<std::shared_ptr<ast::GroupedRuleList>>(x->accept(this)));
        }
        return std::make_shared<ast::GrammarDef>(vars, rules);
    }

    std::any visitGroupedRuleList(SyGuSv21Parser::GroupedRuleListContext *ctx) override {
        ast::EitherIdentifier id(ast::SimpleIdentifier(ctx->symbol()->SYMBOL()->getText()));
        auto sort = std::any_cast<std::shared_ptr<ast::EitherSort>>(ctx->sort()->accept(this));

        std::vector<ast::TermPtr> terms{};
        for (auto x : ctx->gTerm()) {
            auto res = x->accept(this);
            auto ptr = std::any_cast<ast::TermPtr>(res);
            terms.emplace_back(ptr);
        }
        return std::make_shared<ast::GroupedRuleList>(id, sort, terms);
    }

    std::any visitConstantGTerm(SyGuSv21Parser::ConstantGTermContext *ctx) override {
        auto sort = std::any_cast<std::shared_ptr<ast::EitherSort>>(ctx->sort()->accept(this));
        return std::static_pointer_cast<ast::Term>(std::make_shared<ast::ConstantGTerm>(sort));
    }

    std::any visitVariableGTerm(SyGuSv21Parser::VariableGTermContext *ctx) override {
        auto sort = std::any_cast<std::shared_ptr<ast::EitherSort>>(ctx->sort()->accept(this));
        return std::static_pointer_cast<ast::Term>(std::make_shared<ast::VariableGTerm>(sort));
    }

    std::any visitProblem(SyGuSv21Parser::ProblemContext *ctx) override {
        for(SyGuSv21Parser::CmdContext* x: ctx->cmd()) {
            std::any ret = x->accept(this);
            auto cmd = std::any_cast<std::shared_ptr<ast::Command>>(ret);
            this->problem->add_command(cmd);
        }
        return this->problem;
    }

    std::any visitAssumeCmd(SyGuSv21Parser::AssumeCmdContext* ctx) override {
        return std::static_pointer_cast<ast::Command>(std::make_shared<ast::AssumeCmd>(std::any_cast<std::shared_ptr<ast::Term>>(ctx->term()->accept(this))));
    }

    static
    std::pair<std::shared_ptr<SymbolTable>, std::shared_ptr<ast::Problem>>
    build_symbol_table_and_ast(SyGuSv21Parser::ProblemContext* problem)
    {
        symbol_table_ast_builder builder{};
        problem->accept(&builder);

        return {builder.table, builder.problem};
    }

};

#endif //PHYSER_SYMBOLTABLE_H

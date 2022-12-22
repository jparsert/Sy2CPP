//
// Created by julian on 12.12.22.
//

#ifndef PHYSER_SYGUS_SMT_REP_H
#define PHYSER_SYGUS_SMT_REP_H

#include <z3++.h>
#include "SyGuSv21BaseVisitor.h"
#include "../exceptions/not_implemented.h"
#include "../exceptions/unsupported_feature.h"
#include <memory>
#include <stack>

struct variable {
    // Some variable type enum needs to be added
    // i.e. function quantifier, let, function_argument, synt_fun_argument

    //
    std::string identifier;
};

struct sort {
    std::string identifier;
    constexpr explicit sort(std::string&& s): identifier{s} {}
};

//constexpr std::map<int,int> default_sorts{std::pair<sort, sort>(3,4)};
//constexpr std::map<sort,z3::sort> default_sorts = {std::pair<sort, z3::sort>()};

/* *
 *
 * This class represents a SyGuS problem in an SMT environment.
 * This will include "check solution" functions and should also incorporate CEGIS loops.
 *
 * This object should not keep addresses of heap objects, as it may be moved into different processes etc.
 * */
class sygus_smt_rep {

    z3::context ctx ;
    z3::solver solver{ctx};

    std::string logic;

    // Constraints from SyGuS unchanged. These are not negated
    std::vector<z3::expr> sygus_constraints{};

    std::stack<variable> variable_stack{};

    std::map<std::string,sort> sort_map{};


public:

    sygus_smt_rep() = default;

    z3::context& get_context();

    [[nodiscard]] std::string get_logic() const;
    void set_logic(const std::string& logic);

};


class sygus_smt_rep_builder : SyGuSv21BaseVisitor {

    std::shared_ptr<sygus_smt_rep> ss_repr;

    sygus_smt_rep_builder() {
        ss_repr = std::make_shared<sygus_smt_rep>();
    }

public:

    std::any visitNumeral(SyGuSv21Parser::NumeralContext *ctx) override {
        //We only support int for now
        auto str = ctx->NUMERAL()->getSymbol()->getText();
        auto val = std::strtol(str.c_str(), nullptr, 10);
        return this->ss_repr->get_context().int_val(val);
    }

    std::any visitDecimal(SyGuSv21Parser::DecimalContext *ctx) override {
        throw not_implemented("We have not implemented decimals.");
    }

    std::any visitBoolConstTrue(SyGuSv21Parser::BoolConstTrueContext *ctx) override {
        return this->ss_repr->get_context().bool_val(true);
    }

    std::any visitBoolConstFalse(SyGuSv21Parser::BoolConstFalseContext *ctx) override {
        return this->ss_repr->get_context().bool_val(false);
    }

    std::any visitHexConst(SyGuSv21Parser::HexConstContext *ctx) override {
        throw not_implemented("We have not implemented HexConsts.");
    }

    std::any visitBinConst(SyGuSv21Parser::BinConstContext *ctx) override {
        throw not_implemented("We have not implemented Binary Constants.");
    }

    std::any visitStringConst(SyGuSv21Parser::StringConstContext *ctx) override {
        if (ctx->STRINGCONST() != nullptr) {
            return this->ss_repr->get_context().string_const(ctx->STRINGCONST()->getSymbol()->getText().c_str());
        } else if (ctx->EMPTYSTRING() != nullptr) {
            return this->ss_repr->get_context().string_const("");
        } else {
            throw unsupported_feature("String Const should be either a string or empty");
        }
    }

    std::any visitIndexedIdentifier(SyGuSv21Parser::IndexedIdentifierContext *ctx) override {
        throw not_implemented("Indexed identifiers are not supported");
    }

    std::any visitIndex(SyGuSv21Parser::IndexContext *ctx) override {
        throw not_implemented("Indexes are not supported.");
    }

    virtual std::any visitSimpleSort(SyGuSv21Parser::SimpleSortContext *ctx) override  {
        //this->ss_repr->get_context().datatype_sort();
        //this->ss_repr->get_context().tuple_sort();
        //this->ss_repr->get_context().uninterpreted_sort();
        //this->ss_repr->get_context();

        return std::any{};
    }

    virtual std::any visitParametricSort(SyGuSv21Parser::ParametricSortContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitApplicationTerm(SyGuSv21Parser::ApplicationTermContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitExistsTerm(SyGuSv21Parser::ExistsTermContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitForallTerm(SyGuSv21Parser::ForallTermContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitLetTerm(SyGuSv21Parser::LetTermContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitBfApplicationTerm(SyGuSv21Parser::BfApplicationTermContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitSortedVar(SyGuSv21Parser::SortedVarContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitVarBinding(SyGuSv21Parser::VarBindingContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitFeature(SyGuSv21Parser::FeatureContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitCmd(SyGuSv21Parser::CmdContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitAssumeCmd(SyGuSv21Parser::AssumeCmdContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitCheckSynthCmd(SyGuSv21Parser::CheckSynthCmdContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitConstraintCmd(SyGuSv21Parser::ConstraintCmdContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitDeclareVarCmd(SyGuSv21Parser::DeclareVarCmdContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitSetFeatureCmd(SyGuSv21Parser::SetFeatureCmdContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitSynthFunCmd(SyGuSv21Parser::SynthFunCmdContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitSmtCmd(SyGuSv21Parser::SmtCmdContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitDeclareDatatype(SyGuSv21Parser::DeclareDatatypeContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitDeclareDatatypes(SyGuSv21Parser::DeclareDatatypesContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitDeclareSort(SyGuSv21Parser::DeclareSortContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitDefineFun(SyGuSv21Parser::DefineFunContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitDefineSort(SyGuSv21Parser::DefineSortContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitSetInfo(SyGuSv21Parser::SetInfoContext *ctx) override {
        return visitChildren(ctx);
    }

    std::any visitSetLogic(SyGuSv21Parser::SetLogicContext *ctx) override {
        ss_repr->set_logic(ctx->symbol()->getText());
        return {};
    }

    virtual std::any visitSetOption(SyGuSv21Parser::SetOptionContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitSortDecl(SyGuSv21Parser::SortDeclContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitDtDecl(SyGuSv21Parser::DtDeclContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitDtConsDecl(SyGuSv21Parser::DtConsDeclContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitGrammarDef(SyGuSv21Parser::GrammarDefContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitGroupedRuleList(SyGuSv21Parser::GroupedRuleListContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitConstantGTerm(SyGuSv21Parser::ConstantGTermContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitVariableGTerm(SyGuSv21Parser::VariableGTermContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitBfGTerm(SyGuSv21Parser::BfGTermContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitSymbol(SyGuSv21Parser::SymbolContext *ctx) override {
        return visitChildren(ctx);
    }

    static std::shared_ptr<sygus_smt_rep> build_sygus_smt_repr(SyGuSv21Parser::ProblemContext* ctx) {
        sygus_smt_rep_builder builder;
        ctx->accept(&builder);
        return builder.ss_repr;
    }

};



#endif //PHYSER_SYGUS_SMT_REP_H

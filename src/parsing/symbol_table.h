//
// Created by julian on 15.12.22.
//

#ifndef PHYSER_SYMBOL_TABLE_H
#define PHYSER_SYMBOL_TABLE_H

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


class identifier {

public:
    [[nodiscard]] virtual std::size_t get_hash() const = 0;
};

class simple_identifier : public identifier {
    std::string symbol;

public:

    explicit simple_identifier(std::string symb): symbol{std::move(symb)} {}

    std::string get_symbol() {
        return this->symbol;
    }

    bool operator==(simple_identifier& other) {
        return this->symbol == other.get_symbol();
    }

    [[nodiscard]] std::size_t get_hash() const override {
        return std::hash<std::string>()(this->symbol);
    }
};

class indexed_identifier : public identifier {
public:
    explicit indexed_identifier() {
        throw not_implemented("Indexed identifiers are not supported yet.");
    }

    [[nodiscard]] std::size_t get_hash() const override {
        throw unsupported_feature("We do not support indexed identifiers yet.");
    }

};

using identifierEither = std::variant<identifier, indexed_identifier>;

namespace  std {
    template<>
    struct hash<identifier> {
        std::size_t operator()(const identifier& id) {
            return id.get_hash();
        }
    };

    template<>
    struct hash<indexed_identifier> {
        std::size_t operator()(const indexed_identifier& id) {
            return id.get_hash();
        }
    };
}


class symbol_table {

private:


public:

    symbol_table(){
        std::unordered_set<std::variant<simple_identifier,indexed_identifier>> sort_map;

    }

};

class symbol_table_builder: public SyGuSv21BaseVisitor {
private:
    std::shared_ptr<symbol_table> table;

public:
    // maybe make private so we have a static builder class
    symbol_table_builder() {
        //table = std::make_shared<symbol_table>();
    }

    std::any visitSimpleIdentifier(SyGuSv21Parser::SimpleIdentifierContext *ctx) override {
        return simple_identifier(ctx->symbol()->SYMBOL()->getText());

    }

    std::any visitIndexedIdentifier(SyGuSv21Parser::IndexedIdentifierContext *ctx) override {
        throw not_implemented("IndextedIdentififers are not supported yet.");
    }

    // virtual std::any visitSymbol(SyGuSv21Parser::SymbolContext *ctx) override {
    //    return visitChildren(ctx);
    // }

    virtual std::any visitIndex(SyGuSv21Parser::IndexContext *ctx) override {
        throw not_implemented("Indexes are not supported yet.");
    }

    // Check if sort exists in SymbolTable
    std::any visitSimpleSort(SyGuSv21Parser::SimpleSortContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitParametricSort(SyGuSv21Parser::ParametricSortContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitTerm(SyGuSv21Parser::TermContext *ctx) override {
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

    virtual std::any visitBfTerm(SyGuSv21Parser::BfTermContext *ctx) override {
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

    virtual std::any visitSetLogic(SyGuSv21Parser::SetLogicContext *ctx) override {
        return visitChildren(ctx);
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

};

#endif //PHYSER_SYMBOL_TABLE_H

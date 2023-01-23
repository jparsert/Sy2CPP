//
// Created by julian on 23.01.23.
//

#ifndef SY2CPP_SYMBOL_TABLE_AST_BUILDER_H
#define SY2CPP_SYMBOL_TABLE_AST_BUILDER_H


#include <variant>
#include <vector>
#include <iostream>
#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>

#include "SyGuSv21BaseVisitor.h"
#include "exceptions.h"
#include "symbol_table.h"
#include "ast.h"
#include "resolvers.h"

namespace Sy2CPP {

    class SymbolTableAstBuilder : public SyGuSv21BaseVisitor {
    private:
        std::shared_ptr<SymbolTable> table;
        std::shared_ptr<Problem> problem;

        // maybe make private so we have a static builder class
        SymbolTableAstBuilder() {
            table = std::make_shared<SymbolTable>();
            problem = std::make_shared<Problem>();
        }

    public:


        std::any visitSimpleIdentifier(SyGuSv21Parser::SimpleIdentifierContext *ctx) override;

        std::any visitIndexedIdentifier(SyGuSv21Parser::IndexedIdentifierContext *ctx) override;

        std::any visitNumeral(SyGuSv21Parser::NumeralContext *ctx) override;

        std::any visitDecimal(SyGuSv21Parser::DecimalContext *ctx) override;

        std::any visitBoolConstTrue(SyGuSv21Parser::BoolConstTrueContext *ctx) override;

        std::any visitBoolConstFalse(SyGuSv21Parser::BoolConstFalseContext *ctx) override;

        std::any visitHexConst(SyGuSv21Parser::HexConstContext *ctx) override {
            throw NotImplemented("Decimal constants are not supported yet.");
        }

        std::any visitBinConst(SyGuSv21Parser::BinConstContext *ctx) override {
            throw NotImplemented("Decimal constants are not supported yet.");
        }

        std::any visitStringConst(SyGuSv21Parser::StringConstContext *ctx) override;

        std::any visitNumeralIndex(SyGuSv21Parser::NumeralIndexContext *ctx) override;

        std::any visitSymbolIndex(SyGuSv21Parser::SymbolIndexContext *ctx) override;

        std::any visitSimpleSort(SyGuSv21Parser::SimpleSortContext *ctx) override;

        std::any visitParametricSort(SyGuSv21Parser::ParametricSortContext *ctx) override;

        std::any visitIdentifierTerm(SyGuSv21Parser::IdentifierTermContext *ctx) override;

        std::any visitLiteralTerm(SyGuSv21Parser::LiteralTermContext *ctx) override;

        std::any visitApplicationTerm(SyGuSv21Parser::ApplicationTermContext *ctx) override;

        std::any visitExistsTerm(SyGuSv21Parser::ExistsTermContext *ctx) override;

        std::any visitForallTerm(SyGuSv21Parser::ForallTermContext *ctx) override;

        std::any visitLetTerm(SyGuSv21Parser::LetTermContext *ctx) override;

        std::any visitBfIdentifierTerm(SyGuSv21Parser::BfIdentifierTermContext *ctx) override;

        std::any visitBfLiteralTerm(SyGuSv21Parser::BfLiteralTermContext *ctx) override;

        std::any visitBfApplicationTerm(SyGuSv21Parser::BfApplicationTermContext *ctx) override;

        std::any visitSortedVar(SyGuSv21Parser::SortedVarContext *ctx) override;

        std::any visitVarBinding(SyGuSv21Parser::VarBindingContext *ctx) override;

        std::any visitFeature(SyGuSv21Parser::FeatureContext *ctx) override;

        std::any visitSetFeatureCmd(SyGuSv21Parser::SetFeatureCmdContext *ctx) override;

        std::any visitCheckSynthCmd(SyGuSv21Parser::CheckSynthCmdContext *ctx) override;

        std::any visitConstraintCmd(SyGuSv21Parser::ConstraintCmdContext *ctx) override;

        std::any visitDeclareVarCmd(SyGuSv21Parser::DeclareVarCmdContext *ctx) override;

        std::any visitSynthFunCmd(SyGuSv21Parser::SynthFunCmdContext *ctx) override;

        std::any visitDefineFun(SyGuSv21Parser::DefineFunContext *ctx) override;

        std::any visitDeclareDatatype(SyGuSv21Parser::DeclareDatatypeContext *ctx) override {
            throw NotImplemented("DeclareDatatypes are not implemented yet.");
        }

        std::any visitDeclareDatatypes(SyGuSv21Parser::DeclareDatatypesContext *ctx) override {
            throw NotImplemented("DeclareDatatypes are not implemented yet.");
        }

        // TODO add to symbol Table
        std::any visitDeclareSort(SyGuSv21Parser::DeclareSortContext *ctx) override;

        // TODO add to symbol Table
        std::any visitDefineSort(SyGuSv21Parser::DefineSortContext *ctx) override;

        std::any visitSetInfo(SyGuSv21Parser::SetInfoContext *ctx) override;

        std::any visitSetLogic(SyGuSv21Parser::SetLogicContext *ctx) override;

        std::any visitSetOption(SyGuSv21Parser::SetOptionContext *ctx) override;

        std::any visitSortDecl(SyGuSv21Parser::SortDeclContext *ctx) override {
            throw NotImplemented("DeclareDatatypes are not implemented yet.");
        }

        std::any visitDtDecl(SyGuSv21Parser::DtDeclContext *ctx) override {
            throw NotImplemented("DeclareDatatypes are not implemented yet.");
        }

        std::any visitDtConsDecl(SyGuSv21Parser::DtConsDeclContext *ctx) override {
            throw NotImplemented("DeclareDatatypes are not implemented yet.");
        }

        std::any visitGrammarDef(SyGuSv21Parser::GrammarDefContext *ctx) override;

        std::any visitGroupedRuleList(SyGuSv21Parser::GroupedRuleListContext *ctx) override;

        std::any visitConstantGTerm(SyGuSv21Parser::ConstantGTermContext *ctx) override;

        std::any visitVariableGTerm(SyGuSv21Parser::VariableGTermContext *ctx) override;

        std::any visitProblem(SyGuSv21Parser::ProblemContext *ctx) override;

        std::any visitAssumeCmd(SyGuSv21Parser::AssumeCmdContext *ctx) override;

        static
        std::pair<std::shared_ptr<SymbolTable>, std::shared_ptr<Problem>>
        build_symbol_table_and_ast(SyGuSv21Parser::ProblemContext *problem) {
            SymbolTableAstBuilder builder{};
            problem->accept(&builder);

            return {builder.table, builder.problem};
        }

    };

}

#endif //SY2CPP_SYMBOL_TABLE_AST_BUILDER_H

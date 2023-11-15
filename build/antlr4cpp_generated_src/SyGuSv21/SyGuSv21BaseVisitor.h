
// Generated from /home/julian/coding/Sy2CPP/src/SyGuSv21.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "SyGuSv21Visitor.h"


/**
 * This class provides an empty implementation of SyGuSv21Visitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SyGuSv21BaseVisitor : public SyGuSv21Visitor {
public:

  virtual std::any visitProblem(SyGuSv21Parser::ProblemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFailSolution(SyGuSv21Parser::FailSolutionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSuccSolution(SyGuSv21Parser::SuccSolutionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral(SyGuSv21Parser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumeral(SyGuSv21Parser::NumeralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBvConst(SyGuSv21Parser::BvConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecimal(SyGuSv21Parser::DecimalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBoolConstTrue(SyGuSv21Parser::BoolConstTrueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBoolConstFalse(SyGuSv21Parser::BoolConstFalseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHexConst(SyGuSv21Parser::HexConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinConst(SyGuSv21Parser::BinConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringConst(SyGuSv21Parser::StringConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleIdentifier(SyGuSv21Parser::SimpleIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndexedIdentifier(SyGuSv21Parser::IndexedIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumeralIndex(SyGuSv21Parser::NumeralIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSymbolIndex(SyGuSv21Parser::SymbolIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleSort(SyGuSv21Parser::SimpleSortContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParametricSort(SyGuSv21Parser::ParametricSortContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifierTerm(SyGuSv21Parser::IdentifierTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteralTerm(SyGuSv21Parser::LiteralTermContext *ctx) override {
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

  virtual std::any visitBfIdentifierTerm(SyGuSv21Parser::BfIdentifierTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBfLiteralTerm(SyGuSv21Parser::BfLiteralTermContext *ctx) override {
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

  virtual std::any visitSymbol(SyGuSv21Parser::SymbolContext *ctx) override {
    return visitChildren(ctx);
  }


};


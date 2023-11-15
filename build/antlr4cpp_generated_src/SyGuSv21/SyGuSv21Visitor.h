
// Generated from /home/julian/coding/Sy2CPP/src/SyGuSv21.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "SyGuSv21Parser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SyGuSv21Parser.
 */
class  SyGuSv21Visitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SyGuSv21Parser.
   */
    virtual std::any visitProblem(SyGuSv21Parser::ProblemContext *context) = 0;

    virtual std::any visitFailSolution(SyGuSv21Parser::FailSolutionContext *context) = 0;

    virtual std::any visitSuccSolution(SyGuSv21Parser::SuccSolutionContext *context) = 0;

    virtual std::any visitLiteral(SyGuSv21Parser::LiteralContext *context) = 0;

    virtual std::any visitNumeral(SyGuSv21Parser::NumeralContext *context) = 0;

    virtual std::any visitBvConst(SyGuSv21Parser::BvConstContext *context) = 0;

    virtual std::any visitDecimal(SyGuSv21Parser::DecimalContext *context) = 0;

    virtual std::any visitBoolConstTrue(SyGuSv21Parser::BoolConstTrueContext *context) = 0;

    virtual std::any visitBoolConstFalse(SyGuSv21Parser::BoolConstFalseContext *context) = 0;

    virtual std::any visitHexConst(SyGuSv21Parser::HexConstContext *context) = 0;

    virtual std::any visitBinConst(SyGuSv21Parser::BinConstContext *context) = 0;

    virtual std::any visitStringConst(SyGuSv21Parser::StringConstContext *context) = 0;

    virtual std::any visitSimpleIdentifier(SyGuSv21Parser::SimpleIdentifierContext *context) = 0;

    virtual std::any visitIndexedIdentifier(SyGuSv21Parser::IndexedIdentifierContext *context) = 0;

    virtual std::any visitNumeralIndex(SyGuSv21Parser::NumeralIndexContext *context) = 0;

    virtual std::any visitSymbolIndex(SyGuSv21Parser::SymbolIndexContext *context) = 0;

    virtual std::any visitSimpleSort(SyGuSv21Parser::SimpleSortContext *context) = 0;

    virtual std::any visitParametricSort(SyGuSv21Parser::ParametricSortContext *context) = 0;

    virtual std::any visitIdentifierTerm(SyGuSv21Parser::IdentifierTermContext *context) = 0;

    virtual std::any visitLiteralTerm(SyGuSv21Parser::LiteralTermContext *context) = 0;

    virtual std::any visitApplicationTerm(SyGuSv21Parser::ApplicationTermContext *context) = 0;

    virtual std::any visitExistsTerm(SyGuSv21Parser::ExistsTermContext *context) = 0;

    virtual std::any visitForallTerm(SyGuSv21Parser::ForallTermContext *context) = 0;

    virtual std::any visitLetTerm(SyGuSv21Parser::LetTermContext *context) = 0;

    virtual std::any visitBfIdentifierTerm(SyGuSv21Parser::BfIdentifierTermContext *context) = 0;

    virtual std::any visitBfLiteralTerm(SyGuSv21Parser::BfLiteralTermContext *context) = 0;

    virtual std::any visitBfApplicationTerm(SyGuSv21Parser::BfApplicationTermContext *context) = 0;

    virtual std::any visitSortedVar(SyGuSv21Parser::SortedVarContext *context) = 0;

    virtual std::any visitVarBinding(SyGuSv21Parser::VarBindingContext *context) = 0;

    virtual std::any visitFeature(SyGuSv21Parser::FeatureContext *context) = 0;

    virtual std::any visitCmd(SyGuSv21Parser::CmdContext *context) = 0;

    virtual std::any visitAssumeCmd(SyGuSv21Parser::AssumeCmdContext *context) = 0;

    virtual std::any visitCheckSynthCmd(SyGuSv21Parser::CheckSynthCmdContext *context) = 0;

    virtual std::any visitConstraintCmd(SyGuSv21Parser::ConstraintCmdContext *context) = 0;

    virtual std::any visitDeclareVarCmd(SyGuSv21Parser::DeclareVarCmdContext *context) = 0;

    virtual std::any visitSetFeatureCmd(SyGuSv21Parser::SetFeatureCmdContext *context) = 0;

    virtual std::any visitSynthFunCmd(SyGuSv21Parser::SynthFunCmdContext *context) = 0;

    virtual std::any visitSmtCmd(SyGuSv21Parser::SmtCmdContext *context) = 0;

    virtual std::any visitDeclareDatatype(SyGuSv21Parser::DeclareDatatypeContext *context) = 0;

    virtual std::any visitDeclareDatatypes(SyGuSv21Parser::DeclareDatatypesContext *context) = 0;

    virtual std::any visitDeclareSort(SyGuSv21Parser::DeclareSortContext *context) = 0;

    virtual std::any visitDefineFun(SyGuSv21Parser::DefineFunContext *context) = 0;

    virtual std::any visitDefineSort(SyGuSv21Parser::DefineSortContext *context) = 0;

    virtual std::any visitSetInfo(SyGuSv21Parser::SetInfoContext *context) = 0;

    virtual std::any visitSetLogic(SyGuSv21Parser::SetLogicContext *context) = 0;

    virtual std::any visitSetOption(SyGuSv21Parser::SetOptionContext *context) = 0;

    virtual std::any visitSortDecl(SyGuSv21Parser::SortDeclContext *context) = 0;

    virtual std::any visitDtDecl(SyGuSv21Parser::DtDeclContext *context) = 0;

    virtual std::any visitDtConsDecl(SyGuSv21Parser::DtConsDeclContext *context) = 0;

    virtual std::any visitGrammarDef(SyGuSv21Parser::GrammarDefContext *context) = 0;

    virtual std::any visitGroupedRuleList(SyGuSv21Parser::GroupedRuleListContext *context) = 0;

    virtual std::any visitConstantGTerm(SyGuSv21Parser::ConstantGTermContext *context) = 0;

    virtual std::any visitVariableGTerm(SyGuSv21Parser::VariableGTermContext *context) = 0;

    virtual std::any visitBfGTerm(SyGuSv21Parser::BfGTermContext *context) = 0;

    virtual std::any visitSymbol(SyGuSv21Parser::SymbolContext *context) = 0;


};


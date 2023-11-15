
// Generated from /home/julian/coding/Sy2CPP/src/SyGuSv21.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  SyGuSv21Parser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, WS = 25, COMMENT = 26, 
    NUMERAL = 27, HEXCONST = 28, BINCONST = 29, BVCONST = 30, TRUE = 31, 
    FALSE = 32, FAIL = 33, GRAMMARS_FEATURE = 34, FWD_DECLS_FEATURE = 35, 
    RECURSION_FEATURE = 36, ORACLES_FEATURE = 37, WEIGHTS_FEATURE = 38, 
    EMPTYSTRING = 39, STRINGCONST = 40, SYMBOL = 41
  };

  enum {
    RuleProblem = 0, RuleSolution = 1, RuleLiteral = 2, RuleNumeral = 3, 
    RuleBvConst = 4, RuleDecimal = 5, RuleBoolConst = 6, RuleHexConst = 7, 
    RuleBinConst = 8, RuleStringConst = 9, RuleIdentifier = 10, RuleIndex = 11, 
    RuleSort = 12, RuleTerm = 13, RuleBfTerm = 14, RuleSortedVar = 15, RuleVarBinding = 16, 
    RuleFeature = 17, RuleCmd = 18, RuleAssumeCmd = 19, RuleCheckSynthCmd = 20, 
    RuleConstraintCmd = 21, RuleDeclareVarCmd = 22, RuleSetFeatureCmd = 23, 
    RuleSynthFunCmd = 24, RuleSmtCmd = 25, RuleDeclareDatatype = 26, RuleDeclareDatatypes = 27, 
    RuleDeclareSort = 28, RuleDefineFun = 29, RuleDefineSort = 30, RuleSetInfo = 31, 
    RuleSetLogic = 32, RuleSetOption = 33, RuleSortDecl = 34, RuleDtDecl = 35, 
    RuleDtConsDecl = 36, RuleGrammarDef = 37, RuleGroupedRuleList = 38, 
    RuleGTerm = 39, RuleSymbol = 40
  };

  explicit SyGuSv21Parser(antlr4::TokenStream *input);

  SyGuSv21Parser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~SyGuSv21Parser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProblemContext;
  class SolutionContext;
  class LiteralContext;
  class NumeralContext;
  class BvConstContext;
  class DecimalContext;
  class BoolConstContext;
  class HexConstContext;
  class BinConstContext;
  class StringConstContext;
  class IdentifierContext;
  class IndexContext;
  class SortContext;
  class TermContext;
  class BfTermContext;
  class SortedVarContext;
  class VarBindingContext;
  class FeatureContext;
  class CmdContext;
  class AssumeCmdContext;
  class CheckSynthCmdContext;
  class ConstraintCmdContext;
  class DeclareVarCmdContext;
  class SetFeatureCmdContext;
  class SynthFunCmdContext;
  class SmtCmdContext;
  class DeclareDatatypeContext;
  class DeclareDatatypesContext;
  class DeclareSortContext;
  class DefineFunContext;
  class DefineSortContext;
  class SetInfoContext;
  class SetLogicContext;
  class SetOptionContext;
  class SortDeclContext;
  class DtDeclContext;
  class DtConsDeclContext;
  class GrammarDefContext;
  class GroupedRuleListContext;
  class GTermContext;
  class SymbolContext; 

  class  ProblemContext : public antlr4::ParserRuleContext {
  public:
    ProblemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<CmdContext *> cmd();
    CmdContext* cmd(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProblemContext* problem();

  class  SolutionContext : public antlr4::ParserRuleContext {
  public:
    SolutionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    SolutionContext() = default;
    void copyFrom(SolutionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FailSolutionContext : public SolutionContext {
  public:
    FailSolutionContext(SolutionContext *ctx);

    antlr4::tree::TerminalNode *FAIL();
    antlr4::tree::TerminalNode *EOF();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SuccSolutionContext : public SolutionContext {
  public:
    SuccSolutionContext(SolutionContext *ctx);

    antlr4::tree::TerminalNode *EOF();
    std::vector<DefineFunContext *> defineFun();
    DefineFunContext* defineFun(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  SolutionContext* solution();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumeralContext *numeral();
    DecimalContext *decimal();
    BoolConstContext *boolConst();
    HexConstContext *hexConst();
    BinConstContext *binConst();
    StringConstContext *stringConst();
    BvConstContext *bvConst();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();

  class  NumeralContext : public antlr4::ParserRuleContext {
  public:
    NumeralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMERAL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumeralContext* numeral();

  class  BvConstContext : public antlr4::ParserRuleContext {
  public:
    BvConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BVCONST();
    antlr4::tree::TerminalNode *NUMERAL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BvConstContext* bvConst();

  class  DecimalContext : public antlr4::ParserRuleContext {
  public:
    DecimalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NumeralContext *> numeral();
    NumeralContext* numeral(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DecimalContext* decimal();

  class  BoolConstContext : public antlr4::ParserRuleContext {
  public:
    BoolConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    BoolConstContext() = default;
    void copyFrom(BoolConstContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BoolConstTrueContext : public BoolConstContext {
  public:
    BoolConstTrueContext(BoolConstContext *ctx);

    antlr4::tree::TerminalNode *TRUE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BoolConstFalseContext : public BoolConstContext {
  public:
    BoolConstFalseContext(BoolConstContext *ctx);

    antlr4::tree::TerminalNode *FALSE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  BoolConstContext* boolConst();

  class  HexConstContext : public antlr4::ParserRuleContext {
  public:
    HexConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEXCONST();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  HexConstContext* hexConst();

  class  BinConstContext : public antlr4::ParserRuleContext {
  public:
    BinConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BINCONST();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BinConstContext* binConst();

  class  StringConstContext : public antlr4::ParserRuleContext {
  public:
    StringConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRINGCONST();
    antlr4::tree::TerminalNode *EMPTYSTRING();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringConstContext* stringConst();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    IdentifierContext() = default;
    void copyFrom(IdentifierContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SimpleIdentifierContext : public IdentifierContext {
  public:
    SimpleIdentifierContext(IdentifierContext *ctx);

    SymbolContext *symbol();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IndexedIdentifierContext : public IdentifierContext {
  public:
    IndexedIdentifierContext(IdentifierContext *ctx);

    SymbolContext *symbol();
    std::vector<IndexContext *> index();
    IndexContext* index(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  IdentifierContext* identifier();

  class  IndexContext : public antlr4::ParserRuleContext {
  public:
    IndexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    IndexContext() = default;
    void copyFrom(IndexContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NumeralIndexContext : public IndexContext {
  public:
    NumeralIndexContext(IndexContext *ctx);

    NumeralContext *numeral();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SymbolIndexContext : public IndexContext {
  public:
    SymbolIndexContext(IndexContext *ctx);

    SymbolContext *symbol();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  IndexContext* index();

  class  SortContext : public antlr4::ParserRuleContext {
  public:
    SortContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    SortContext() = default;
    void copyFrom(SortContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ParametricSortContext : public SortContext {
  public:
    ParametricSortContext(SortContext *ctx);

    IdentifierContext *identifier();
    std::vector<SortContext *> sort();
    SortContext* sort(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SimpleSortContext : public SortContext {
  public:
    SimpleSortContext(SortContext *ctx);

    IdentifierContext *identifier();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  SortContext* sort();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TermContext() = default;
    void copyFrom(TermContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IdentifierTermContext : public TermContext {
  public:
    IdentifierTermContext(TermContext *ctx);

    IdentifierContext *identifier();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LiteralTermContext : public TermContext {
  public:
    LiteralTermContext(TermContext *ctx);

    LiteralContext *literal();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ForallTermContext : public TermContext {
  public:
    ForallTermContext(TermContext *ctx);

    TermContext *term();
    std::vector<SortedVarContext *> sortedVar();
    SortedVarContext* sortedVar(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LetTermContext : public TermContext {
  public:
    LetTermContext(TermContext *ctx);

    TermContext *term();
    std::vector<VarBindingContext *> varBinding();
    VarBindingContext* varBinding(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ApplicationTermContext : public TermContext {
  public:
    ApplicationTermContext(TermContext *ctx);

    IdentifierContext *identifier();
    std::vector<TermContext *> term();
    TermContext* term(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExistsTermContext : public TermContext {
  public:
    ExistsTermContext(TermContext *ctx);

    TermContext *term();
    std::vector<SortedVarContext *> sortedVar();
    SortedVarContext* sortedVar(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TermContext* term();

  class  BfTermContext : public antlr4::ParserRuleContext {
  public:
    BfTermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    BfTermContext() = default;
    void copyFrom(BfTermContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BfLiteralTermContext : public BfTermContext {
  public:
    BfLiteralTermContext(BfTermContext *ctx);

    LiteralContext *literal();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BfIdentifierTermContext : public BfTermContext {
  public:
    BfIdentifierTermContext(BfTermContext *ctx);

    IdentifierContext *identifier();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BfApplicationTermContext : public BfTermContext {
  public:
    BfApplicationTermContext(BfTermContext *ctx);

    IdentifierContext *identifier();
    std::vector<BfTermContext *> bfTerm();
    BfTermContext* bfTerm(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  BfTermContext* bfTerm();

  class  SortedVarContext : public antlr4::ParserRuleContext {
  public:
    SortedVarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolContext *symbol();
    SortContext *sort();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SortedVarContext* sortedVar();

  class  VarBindingContext : public antlr4::ParserRuleContext {
  public:
    VarBindingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolContext *symbol();
    TermContext *term();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarBindingContext* varBinding();

  class  FeatureContext : public antlr4::ParserRuleContext {
  public:
    FeatureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GRAMMARS_FEATURE();
    antlr4::tree::TerminalNode *FWD_DECLS_FEATURE();
    antlr4::tree::TerminalNode *RECURSION_FEATURE();
    antlr4::tree::TerminalNode *ORACLES_FEATURE();
    antlr4::tree::TerminalNode *WEIGHTS_FEATURE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FeatureContext* feature();

  class  CmdContext : public antlr4::ParserRuleContext {
  public:
    CmdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssumeCmdContext *assumeCmd();
    CheckSynthCmdContext *checkSynthCmd();
    ConstraintCmdContext *constraintCmd();
    DeclareVarCmdContext *declareVarCmd();
    SetFeatureCmdContext *setFeatureCmd();
    SynthFunCmdContext *synthFunCmd();
    SmtCmdContext *smtCmd();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CmdContext* cmd();

  class  AssumeCmdContext : public antlr4::ParserRuleContext {
  public:
    AssumeCmdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssumeCmdContext* assumeCmd();

  class  CheckSynthCmdContext : public antlr4::ParserRuleContext {
  public:
    CheckSynthCmdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CheckSynthCmdContext* checkSynthCmd();

  class  ConstraintCmdContext : public antlr4::ParserRuleContext {
  public:
    ConstraintCmdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstraintCmdContext* constraintCmd();

  class  DeclareVarCmdContext : public antlr4::ParserRuleContext {
  public:
    DeclareVarCmdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolContext *symbol();
    SortContext *sort();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclareVarCmdContext* declareVarCmd();

  class  SetFeatureCmdContext : public antlr4::ParserRuleContext {
  public:
    SetFeatureCmdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FeatureContext *feature();
    BoolConstContext *boolConst();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetFeatureCmdContext* setFeatureCmd();

  class  SynthFunCmdContext : public antlr4::ParserRuleContext {
  public:
    SynthFunCmdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolContext *symbol();
    SortContext *sort();
    std::vector<SortedVarContext *> sortedVar();
    SortedVarContext* sortedVar(size_t i);
    GrammarDefContext *grammarDef();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SynthFunCmdContext* synthFunCmd();

  class  SmtCmdContext : public antlr4::ParserRuleContext {
  public:
    SmtCmdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclareDatatypeContext *declareDatatype();
    DeclareDatatypesContext *declareDatatypes();
    DeclareSortContext *declareSort();
    DefineFunContext *defineFun();
    DefineSortContext *defineSort();
    SetInfoContext *setInfo();
    SetLogicContext *setLogic();
    SetOptionContext *setOption();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SmtCmdContext* smtCmd();

  class  DeclareDatatypeContext : public antlr4::ParserRuleContext {
  public:
    DeclareDatatypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolContext *symbol();
    DtDeclContext *dtDecl();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclareDatatypeContext* declareDatatype();

  class  DeclareDatatypesContext : public antlr4::ParserRuleContext {
  public:
    DeclareDatatypesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SortDeclContext *> sortDecl();
    SortDeclContext* sortDecl(size_t i);
    std::vector<DtDeclContext *> dtDecl();
    DtDeclContext* dtDecl(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclareDatatypesContext* declareDatatypes();

  class  DeclareSortContext : public antlr4::ParserRuleContext {
  public:
    DeclareSortContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolContext *symbol();
    NumeralContext *numeral();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclareSortContext* declareSort();

  class  DefineFunContext : public antlr4::ParserRuleContext {
  public:
    DefineFunContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolContext *symbol();
    SortContext *sort();
    TermContext *term();
    std::vector<SortedVarContext *> sortedVar();
    SortedVarContext* sortedVar(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefineFunContext* defineFun();

  class  DefineSortContext : public antlr4::ParserRuleContext {
  public:
    DefineSortContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolContext *symbol();
    SortContext *sort();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefineSortContext* defineSort();

  class  SetInfoContext : public antlr4::ParserRuleContext {
  public:
    SetInfoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolContext *symbol();
    LiteralContext *literal();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetInfoContext* setInfo();

  class  SetLogicContext : public antlr4::ParserRuleContext {
  public:
    SetLogicContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolContext *symbol();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetLogicContext* setLogic();

  class  SetOptionContext : public antlr4::ParserRuleContext {
  public:
    SetOptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolContext *symbol();
    LiteralContext *literal();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetOptionContext* setOption();

  class  SortDeclContext : public antlr4::ParserRuleContext {
  public:
    SortDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolContext *symbol();
    NumeralContext *numeral();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SortDeclContext* sortDecl();

  class  DtDeclContext : public antlr4::ParserRuleContext {
  public:
    DtDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DtConsDeclContext *> dtConsDecl();
    DtConsDeclContext* dtConsDecl(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DtDeclContext* dtDecl();

  class  DtConsDeclContext : public antlr4::ParserRuleContext {
  public:
    DtConsDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolContext *symbol();
    std::vector<SortedVarContext *> sortedVar();
    SortedVarContext* sortedVar(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DtConsDeclContext* dtConsDecl();

  class  GrammarDefContext : public antlr4::ParserRuleContext {
  public:
    GrammarDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SortedVarContext *> sortedVar();
    SortedVarContext* sortedVar(size_t i);
    std::vector<GroupedRuleListContext *> groupedRuleList();
    GroupedRuleListContext* groupedRuleList(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GrammarDefContext* grammarDef();

  class  GroupedRuleListContext : public antlr4::ParserRuleContext {
  public:
    GroupedRuleListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolContext *symbol();
    SortContext *sort();
    std::vector<GTermContext *> gTerm();
    GTermContext* gTerm(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GroupedRuleListContext* groupedRuleList();

  class  GTermContext : public antlr4::ParserRuleContext {
  public:
    GTermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    GTermContext() = default;
    void copyFrom(GTermContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  VariableGTermContext : public GTermContext {
  public:
    VariableGTermContext(GTermContext *ctx);

    SortContext *sort();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConstantGTermContext : public GTermContext {
  public:
    ConstantGTermContext(GTermContext *ctx);

    SortContext *sort();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BfGTermContext : public GTermContext {
  public:
    BfGTermContext(GTermContext *ctx);

    BfTermContext *bfTerm();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  GTermContext* gTerm();

  class  SymbolContext : public antlr4::ParserRuleContext {
  public:
    SymbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYMBOL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SymbolContext* symbol();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};


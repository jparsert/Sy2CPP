
// Generated from /home/julian/coding/Sy2CPP/src/SyGuSv21.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  SyGuSv21Lexer : public antlr4::Lexer {
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

  explicit SyGuSv21Lexer(antlr4::CharStream *input);

  ~SyGuSv21Lexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};


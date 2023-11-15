
// Generated from /home/julian/coding/Sy2CPP/src/SyGuSv21.g4 by ANTLR 4.13.1


#include "SyGuSv21Visitor.h"

#include "SyGuSv21Parser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct SyGuSv21ParserStaticData final {
  SyGuSv21ParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SyGuSv21ParserStaticData(const SyGuSv21ParserStaticData&) = delete;
  SyGuSv21ParserStaticData(SyGuSv21ParserStaticData&&) = delete;
  SyGuSv21ParserStaticData& operator=(const SyGuSv21ParserStaticData&) = delete;
  SyGuSv21ParserStaticData& operator=(SyGuSv21ParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag sygusv21ParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
SyGuSv21ParserStaticData *sygusv21ParserStaticData = nullptr;

void sygusv21ParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (sygusv21ParserStaticData != nullptr) {
    return;
  }
#else
  assert(sygusv21ParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<SyGuSv21ParserStaticData>(
    std::vector<std::string>{
      "problem", "solution", "literal", "numeral", "bvConst", "decimal", 
      "boolConst", "hexConst", "binConst", "stringConst", "identifier", 
      "index", "sort", "term", "bfTerm", "sortedVar", "varBinding", "feature", 
      "cmd", "assumeCmd", "checkSynthCmd", "constraintCmd", "declareVarCmd", 
      "setFeatureCmd", "synthFunCmd", "smtCmd", "declareDatatype", "declareDatatypes", 
      "declareSort", "defineFun", "defineSort", "setInfo", "setLogic", "setOption", 
      "sortDecl", "dtDecl", "dtConsDecl", "grammarDef", "groupedRuleList", 
      "gTerm", "symbol"
    },
    std::vector<std::string>{
      "", "'('", "'_ '", "')'", "'.'", "'exists'", "'forall'", "'let'", 
      "':'", "'assume'", "'check-synth'", "'constraint'", "'declare-var'", 
      "'set-feature'", "'synth-fun'", "'declare-datatype'", "'declare-datatypes'", 
      "'declare-sort'", "'define-fun'", "'define-sort'", "'set-info'", "'set-logic'", 
      "'set-option'", "'Constant'", "'Variable'", "", "", "", "", "", "", 
      "'true'", "'false'", "'fail'", "'grammars'", "'fwd-decls'", "'recursion'", 
      "'oracles'", "'weights'", "'\"\"'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "WS", "COMMENT", "NUMERAL", "HEXCONST", 
      "BINCONST", "BVCONST", "TRUE", "FALSE", "FAIL", "GRAMMARS_FEATURE", 
      "FWD_DECLS_FEATURE", "RECURSION_FEATURE", "ORACLES_FEATURE", "WEIGHTS_FEATURE", 
      "EMPTYSTRING", "STRINGCONST", "SYMBOL"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,41,442,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,1,0,4,0,84,8,0,11,
  	0,12,0,85,1,0,1,0,1,1,1,1,1,1,4,1,93,8,1,11,1,12,1,94,1,1,1,1,3,1,99,
  	8,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,108,8,2,1,3,1,3,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,5,1,5,1,5,1,5,1,6,1,6,3,6,124,8,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,
  	1,10,1,10,1,10,1,10,4,10,137,8,10,11,10,12,10,138,1,10,1,10,3,10,143,
  	8,10,1,11,1,11,3,11,147,8,11,1,12,1,12,1,12,1,12,4,12,153,8,12,11,12,
  	12,12,154,1,12,1,12,3,12,159,8,12,1,13,1,13,1,13,1,13,1,13,4,13,166,8,
  	13,11,13,12,13,167,1,13,1,13,1,13,1,13,1,13,1,13,4,13,176,8,13,11,13,
  	12,13,177,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,4,13,188,8,13,11,13,
  	12,13,189,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,4,13,200,8,13,11,13,
  	12,13,201,1,13,1,13,1,13,1,13,3,13,208,8,13,1,14,1,14,1,14,1,14,1,14,
  	4,14,215,8,14,11,14,12,14,216,1,14,1,14,3,14,221,8,14,1,15,1,15,1,15,
  	1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,
  	1,17,1,17,1,17,3,17,243,8,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,3,18,
  	252,8,18,1,19,1,19,1,19,1,19,1,19,1,20,1,20,1,20,1,20,1,21,1,21,1,21,
  	1,21,1,21,1,22,1,22,1,22,1,22,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,23,
  	1,24,1,24,1,24,1,24,1,24,5,24,285,8,24,10,24,12,24,288,9,24,1,24,1,24,
  	1,24,3,24,293,8,24,1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,
  	3,25,305,8,25,1,26,1,26,1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,27,4,27,
  	317,8,27,11,27,12,27,318,1,27,1,27,1,27,4,27,324,8,27,11,27,12,27,325,
  	1,27,1,27,1,27,1,28,1,28,1,28,1,28,1,28,1,28,1,29,1,29,1,29,1,29,1,29,
  	5,29,342,8,29,10,29,12,29,345,9,29,1,29,1,29,1,29,1,29,1,29,1,30,1,30,
  	1,30,1,30,1,30,1,30,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,32,1,32,1,32,
  	1,32,1,32,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,34,1,34,1,34,1,34,1,34,
  	1,35,1,35,4,35,384,8,35,11,35,12,35,385,1,35,1,35,1,36,1,36,1,36,5,36,
  	393,8,36,10,36,12,36,396,9,36,1,36,1,36,1,37,1,37,4,37,402,8,37,11,37,
  	12,37,403,1,37,1,37,1,37,4,37,409,8,37,11,37,12,37,410,1,37,1,37,1,38,
  	1,38,1,38,1,38,1,38,4,38,420,8,38,11,38,12,38,421,1,38,1,38,1,38,1,39,
  	1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,3,39,438,8,39,1,40,
  	1,40,1,40,0,0,41,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,
  	38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,0,1,
  	1,0,39,40,456,0,83,1,0,0,0,2,98,1,0,0,0,4,107,1,0,0,0,6,109,1,0,0,0,8,
  	111,1,0,0,0,10,117,1,0,0,0,12,123,1,0,0,0,14,125,1,0,0,0,16,127,1,0,0,
  	0,18,129,1,0,0,0,20,142,1,0,0,0,22,146,1,0,0,0,24,158,1,0,0,0,26,207,
  	1,0,0,0,28,220,1,0,0,0,30,222,1,0,0,0,32,227,1,0,0,0,34,242,1,0,0,0,36,
  	251,1,0,0,0,38,253,1,0,0,0,40,258,1,0,0,0,42,262,1,0,0,0,44,267,1,0,0,
  	0,46,273,1,0,0,0,48,279,1,0,0,0,50,304,1,0,0,0,52,306,1,0,0,0,54,312,
  	1,0,0,0,56,330,1,0,0,0,58,336,1,0,0,0,60,351,1,0,0,0,62,357,1,0,0,0,64,
  	364,1,0,0,0,66,369,1,0,0,0,68,376,1,0,0,0,70,381,1,0,0,0,72,389,1,0,0,
  	0,74,399,1,0,0,0,76,414,1,0,0,0,78,437,1,0,0,0,80,439,1,0,0,0,82,84,3,
  	36,18,0,83,82,1,0,0,0,84,85,1,0,0,0,85,83,1,0,0,0,85,86,1,0,0,0,86,87,
  	1,0,0,0,87,88,5,0,0,1,88,1,1,0,0,0,89,90,5,33,0,0,90,99,5,0,0,1,91,93,
  	3,58,29,0,92,91,1,0,0,0,93,94,1,0,0,0,94,92,1,0,0,0,94,95,1,0,0,0,95,
  	96,1,0,0,0,96,97,5,0,0,1,97,99,1,0,0,0,98,89,1,0,0,0,98,92,1,0,0,0,99,
  	3,1,0,0,0,100,108,3,6,3,0,101,108,3,10,5,0,102,108,3,12,6,0,103,108,3,
  	14,7,0,104,108,3,16,8,0,105,108,3,18,9,0,106,108,3,8,4,0,107,100,1,0,
  	0,0,107,101,1,0,0,0,107,102,1,0,0,0,107,103,1,0,0,0,107,104,1,0,0,0,107,
  	105,1,0,0,0,107,106,1,0,0,0,108,5,1,0,0,0,109,110,5,27,0,0,110,7,1,0,
  	0,0,111,112,5,1,0,0,112,113,5,2,0,0,113,114,5,30,0,0,114,115,5,27,0,0,
  	115,116,5,3,0,0,116,9,1,0,0,0,117,118,3,6,3,0,118,119,5,4,0,0,119,120,
  	3,6,3,0,120,11,1,0,0,0,121,124,5,31,0,0,122,124,5,32,0,0,123,121,1,0,
  	0,0,123,122,1,0,0,0,124,13,1,0,0,0,125,126,5,28,0,0,126,15,1,0,0,0,127,
  	128,5,29,0,0,128,17,1,0,0,0,129,130,7,0,0,0,130,19,1,0,0,0,131,143,3,
  	80,40,0,132,133,5,1,0,0,133,134,5,2,0,0,134,136,3,80,40,0,135,137,3,22,
  	11,0,136,135,1,0,0,0,137,138,1,0,0,0,138,136,1,0,0,0,138,139,1,0,0,0,
  	139,140,1,0,0,0,140,141,5,3,0,0,141,143,1,0,0,0,142,131,1,0,0,0,142,132,
  	1,0,0,0,143,21,1,0,0,0,144,147,3,6,3,0,145,147,3,80,40,0,146,144,1,0,
  	0,0,146,145,1,0,0,0,147,23,1,0,0,0,148,159,3,20,10,0,149,150,5,1,0,0,
  	150,152,3,20,10,0,151,153,3,24,12,0,152,151,1,0,0,0,153,154,1,0,0,0,154,
  	152,1,0,0,0,154,155,1,0,0,0,155,156,1,0,0,0,156,157,5,3,0,0,157,159,1,
  	0,0,0,158,148,1,0,0,0,158,149,1,0,0,0,159,25,1,0,0,0,160,208,3,20,10,
  	0,161,208,3,4,2,0,162,163,5,1,0,0,163,165,3,20,10,0,164,166,3,26,13,0,
  	165,164,1,0,0,0,166,167,1,0,0,0,167,165,1,0,0,0,167,168,1,0,0,0,168,169,
  	1,0,0,0,169,170,5,3,0,0,170,208,1,0,0,0,171,172,5,1,0,0,172,173,5,5,0,
  	0,173,175,5,1,0,0,174,176,3,30,15,0,175,174,1,0,0,0,176,177,1,0,0,0,177,
  	175,1,0,0,0,177,178,1,0,0,0,178,179,1,0,0,0,179,180,5,3,0,0,180,181,3,
  	26,13,0,181,182,5,3,0,0,182,208,1,0,0,0,183,184,5,1,0,0,184,185,5,6,0,
  	0,185,187,5,1,0,0,186,188,3,30,15,0,187,186,1,0,0,0,188,189,1,0,0,0,189,
  	187,1,0,0,0,189,190,1,0,0,0,190,191,1,0,0,0,191,192,5,3,0,0,192,193,3,
  	26,13,0,193,194,5,3,0,0,194,208,1,0,0,0,195,196,5,1,0,0,196,197,5,7,0,
  	0,197,199,5,1,0,0,198,200,3,32,16,0,199,198,1,0,0,0,200,201,1,0,0,0,201,
  	199,1,0,0,0,201,202,1,0,0,0,202,203,1,0,0,0,203,204,5,3,0,0,204,205,3,
  	26,13,0,205,206,5,3,0,0,206,208,1,0,0,0,207,160,1,0,0,0,207,161,1,0,0,
  	0,207,162,1,0,0,0,207,171,1,0,0,0,207,183,1,0,0,0,207,195,1,0,0,0,208,
  	27,1,0,0,0,209,221,3,20,10,0,210,221,3,4,2,0,211,212,5,1,0,0,212,214,
  	3,20,10,0,213,215,3,28,14,0,214,213,1,0,0,0,215,216,1,0,0,0,216,214,1,
  	0,0,0,216,217,1,0,0,0,217,218,1,0,0,0,218,219,5,3,0,0,219,221,1,0,0,0,
  	220,209,1,0,0,0,220,210,1,0,0,0,220,211,1,0,0,0,221,29,1,0,0,0,222,223,
  	5,1,0,0,223,224,3,80,40,0,224,225,3,24,12,0,225,226,5,3,0,0,226,31,1,
  	0,0,0,227,228,5,1,0,0,228,229,3,80,40,0,229,230,3,26,13,0,230,231,5,3,
  	0,0,231,33,1,0,0,0,232,233,5,8,0,0,233,243,5,34,0,0,234,235,5,8,0,0,235,
  	243,5,35,0,0,236,237,5,8,0,0,237,243,5,36,0,0,238,239,5,8,0,0,239,243,
  	5,37,0,0,240,241,5,8,0,0,241,243,5,38,0,0,242,232,1,0,0,0,242,234,1,0,
  	0,0,242,236,1,0,0,0,242,238,1,0,0,0,242,240,1,0,0,0,243,35,1,0,0,0,244,
  	252,3,38,19,0,245,252,3,40,20,0,246,252,3,42,21,0,247,252,3,44,22,0,248,
  	252,3,46,23,0,249,252,3,48,24,0,250,252,3,50,25,0,251,244,1,0,0,0,251,
  	245,1,0,0,0,251,246,1,0,0,0,251,247,1,0,0,0,251,248,1,0,0,0,251,249,1,
  	0,0,0,251,250,1,0,0,0,252,37,1,0,0,0,253,254,5,1,0,0,254,255,5,9,0,0,
  	255,256,3,26,13,0,256,257,5,3,0,0,257,39,1,0,0,0,258,259,5,1,0,0,259,
  	260,5,10,0,0,260,261,5,3,0,0,261,41,1,0,0,0,262,263,5,1,0,0,263,264,5,
  	11,0,0,264,265,3,26,13,0,265,266,5,3,0,0,266,43,1,0,0,0,267,268,5,1,0,
  	0,268,269,5,12,0,0,269,270,3,80,40,0,270,271,3,24,12,0,271,272,5,3,0,
  	0,272,45,1,0,0,0,273,274,5,1,0,0,274,275,5,13,0,0,275,276,3,34,17,0,276,
  	277,3,12,6,0,277,278,5,3,0,0,278,47,1,0,0,0,279,280,5,1,0,0,280,281,5,
  	14,0,0,281,282,3,80,40,0,282,286,5,1,0,0,283,285,3,30,15,0,284,283,1,
  	0,0,0,285,288,1,0,0,0,286,284,1,0,0,0,286,287,1,0,0,0,287,289,1,0,0,0,
  	288,286,1,0,0,0,289,290,5,3,0,0,290,292,3,24,12,0,291,293,3,74,37,0,292,
  	291,1,0,0,0,292,293,1,0,0,0,293,294,1,0,0,0,294,295,5,3,0,0,295,49,1,
  	0,0,0,296,305,3,52,26,0,297,305,3,54,27,0,298,305,3,56,28,0,299,305,3,
  	58,29,0,300,305,3,60,30,0,301,305,3,62,31,0,302,305,3,64,32,0,303,305,
  	3,66,33,0,304,296,1,0,0,0,304,297,1,0,0,0,304,298,1,0,0,0,304,299,1,0,
  	0,0,304,300,1,0,0,0,304,301,1,0,0,0,304,302,1,0,0,0,304,303,1,0,0,0,305,
  	51,1,0,0,0,306,307,5,1,0,0,307,308,5,15,0,0,308,309,3,80,40,0,309,310,
  	3,70,35,0,310,311,5,3,0,0,311,53,1,0,0,0,312,313,5,1,0,0,313,314,5,16,
  	0,0,314,316,5,1,0,0,315,317,3,68,34,0,316,315,1,0,0,0,317,318,1,0,0,0,
  	318,316,1,0,0,0,318,319,1,0,0,0,319,320,1,0,0,0,320,321,5,3,0,0,321,323,
  	5,1,0,0,322,324,3,70,35,0,323,322,1,0,0,0,324,325,1,0,0,0,325,323,1,0,
  	0,0,325,326,1,0,0,0,326,327,1,0,0,0,327,328,5,3,0,0,328,329,5,3,0,0,329,
  	55,1,0,0,0,330,331,5,1,0,0,331,332,5,17,0,0,332,333,3,80,40,0,333,334,
  	3,6,3,0,334,335,5,3,0,0,335,57,1,0,0,0,336,337,5,1,0,0,337,338,5,18,0,
  	0,338,339,3,80,40,0,339,343,5,1,0,0,340,342,3,30,15,0,341,340,1,0,0,0,
  	342,345,1,0,0,0,343,341,1,0,0,0,343,344,1,0,0,0,344,346,1,0,0,0,345,343,
  	1,0,0,0,346,347,5,3,0,0,347,348,3,24,12,0,348,349,3,26,13,0,349,350,5,
  	3,0,0,350,59,1,0,0,0,351,352,5,1,0,0,352,353,5,19,0,0,353,354,3,80,40,
  	0,354,355,3,24,12,0,355,356,5,3,0,0,356,61,1,0,0,0,357,358,5,1,0,0,358,
  	359,5,20,0,0,359,360,5,8,0,0,360,361,3,80,40,0,361,362,3,4,2,0,362,363,
  	5,3,0,0,363,63,1,0,0,0,364,365,5,1,0,0,365,366,5,21,0,0,366,367,3,80,
  	40,0,367,368,5,3,0,0,368,65,1,0,0,0,369,370,5,1,0,0,370,371,5,22,0,0,
  	371,372,5,8,0,0,372,373,3,80,40,0,373,374,3,4,2,0,374,375,5,3,0,0,375,
  	67,1,0,0,0,376,377,5,1,0,0,377,378,3,80,40,0,378,379,3,6,3,0,379,380,
  	5,3,0,0,380,69,1,0,0,0,381,383,5,1,0,0,382,384,3,72,36,0,383,382,1,0,
  	0,0,384,385,1,0,0,0,385,383,1,0,0,0,385,386,1,0,0,0,386,387,1,0,0,0,387,
  	388,5,3,0,0,388,71,1,0,0,0,389,390,5,1,0,0,390,394,3,80,40,0,391,393,
  	3,30,15,0,392,391,1,0,0,0,393,396,1,0,0,0,394,392,1,0,0,0,394,395,1,0,
  	0,0,395,397,1,0,0,0,396,394,1,0,0,0,397,398,5,3,0,0,398,73,1,0,0,0,399,
  	401,5,1,0,0,400,402,3,30,15,0,401,400,1,0,0,0,402,403,1,0,0,0,403,401,
  	1,0,0,0,403,404,1,0,0,0,404,405,1,0,0,0,405,406,5,3,0,0,406,408,5,1,0,
  	0,407,409,3,76,38,0,408,407,1,0,0,0,409,410,1,0,0,0,410,408,1,0,0,0,410,
  	411,1,0,0,0,411,412,1,0,0,0,412,413,5,3,0,0,413,75,1,0,0,0,414,415,5,
  	1,0,0,415,416,3,80,40,0,416,417,3,24,12,0,417,419,5,1,0,0,418,420,3,78,
  	39,0,419,418,1,0,0,0,420,421,1,0,0,0,421,419,1,0,0,0,421,422,1,0,0,0,
  	422,423,1,0,0,0,423,424,5,3,0,0,424,425,5,3,0,0,425,77,1,0,0,0,426,427,
  	5,1,0,0,427,428,5,23,0,0,428,429,3,24,12,0,429,430,5,3,0,0,430,438,1,
  	0,0,0,431,432,5,1,0,0,432,433,5,24,0,0,433,434,3,24,12,0,434,435,5,3,
  	0,0,435,438,1,0,0,0,436,438,3,28,14,0,437,426,1,0,0,0,437,431,1,0,0,0,
  	437,436,1,0,0,0,438,79,1,0,0,0,439,440,5,41,0,0,440,81,1,0,0,0,31,85,
  	94,98,107,123,138,142,146,154,158,167,177,189,201,207,216,220,242,251,
  	286,292,304,318,325,343,385,394,403,410,421,437
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  sygusv21ParserStaticData = staticData.release();
}

}

SyGuSv21Parser::SyGuSv21Parser(TokenStream *input) : SyGuSv21Parser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

SyGuSv21Parser::SyGuSv21Parser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  SyGuSv21Parser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *sygusv21ParserStaticData->atn, sygusv21ParserStaticData->decisionToDFA, sygusv21ParserStaticData->sharedContextCache, options);
}

SyGuSv21Parser::~SyGuSv21Parser() {
  delete _interpreter;
}

const atn::ATN& SyGuSv21Parser::getATN() const {
  return *sygusv21ParserStaticData->atn;
}

std::string SyGuSv21Parser::getGrammarFileName() const {
  return "SyGuSv21.g4";
}

const std::vector<std::string>& SyGuSv21Parser::getRuleNames() const {
  return sygusv21ParserStaticData->ruleNames;
}

const dfa::Vocabulary& SyGuSv21Parser::getVocabulary() const {
  return sygusv21ParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SyGuSv21Parser::getSerializedATN() const {
  return sygusv21ParserStaticData->serializedATN;
}


//----------------- ProblemContext ------------------------------------------------------------------

SyGuSv21Parser::ProblemContext::ProblemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SyGuSv21Parser::ProblemContext::EOF() {
  return getToken(SyGuSv21Parser::EOF, 0);
}

std::vector<SyGuSv21Parser::CmdContext *> SyGuSv21Parser::ProblemContext::cmd() {
  return getRuleContexts<SyGuSv21Parser::CmdContext>();
}

SyGuSv21Parser::CmdContext* SyGuSv21Parser::ProblemContext::cmd(size_t i) {
  return getRuleContext<SyGuSv21Parser::CmdContext>(i);
}


size_t SyGuSv21Parser::ProblemContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleProblem;
}


std::any SyGuSv21Parser::ProblemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitProblem(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::ProblemContext* SyGuSv21Parser::problem() {
  ProblemContext *_localctx = _tracker.createInstance<ProblemContext>(_ctx, getState());
  enterRule(_localctx, 0, SyGuSv21Parser::RuleProblem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(82);
      cmd();
      setState(85); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SyGuSv21Parser::T__0);
    setState(87);
    match(SyGuSv21Parser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SolutionContext ------------------------------------------------------------------

SyGuSv21Parser::SolutionContext::SolutionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SyGuSv21Parser::SolutionContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleSolution;
}

void SyGuSv21Parser::SolutionContext::copyFrom(SolutionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FailSolutionContext ------------------------------------------------------------------

tree::TerminalNode* SyGuSv21Parser::FailSolutionContext::FAIL() {
  return getToken(SyGuSv21Parser::FAIL, 0);
}

tree::TerminalNode* SyGuSv21Parser::FailSolutionContext::EOF() {
  return getToken(SyGuSv21Parser::EOF, 0);
}

SyGuSv21Parser::FailSolutionContext::FailSolutionContext(SolutionContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::FailSolutionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitFailSolution(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SuccSolutionContext ------------------------------------------------------------------

tree::TerminalNode* SyGuSv21Parser::SuccSolutionContext::EOF() {
  return getToken(SyGuSv21Parser::EOF, 0);
}

std::vector<SyGuSv21Parser::DefineFunContext *> SyGuSv21Parser::SuccSolutionContext::defineFun() {
  return getRuleContexts<SyGuSv21Parser::DefineFunContext>();
}

SyGuSv21Parser::DefineFunContext* SyGuSv21Parser::SuccSolutionContext::defineFun(size_t i) {
  return getRuleContext<SyGuSv21Parser::DefineFunContext>(i);
}

SyGuSv21Parser::SuccSolutionContext::SuccSolutionContext(SolutionContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::SuccSolutionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitSuccSolution(this);
  else
    return visitor->visitChildren(this);
}
SyGuSv21Parser::SolutionContext* SyGuSv21Parser::solution() {
  SolutionContext *_localctx = _tracker.createInstance<SolutionContext>(_ctx, getState());
  enterRule(_localctx, 2, SyGuSv21Parser::RuleSolution);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(98);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SyGuSv21Parser::FAIL: {
        _localctx = _tracker.createInstance<SyGuSv21Parser::FailSolutionContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(89);
        match(SyGuSv21Parser::FAIL);
        setState(90);
        match(SyGuSv21Parser::EOF);
        break;
      }

      case SyGuSv21Parser::T__0: {
        _localctx = _tracker.createInstance<SyGuSv21Parser::SuccSolutionContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(92); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(91);
          defineFun();
          setState(94); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == SyGuSv21Parser::T__0);
        setState(96);
        match(SyGuSv21Parser::EOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

SyGuSv21Parser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::NumeralContext* SyGuSv21Parser::LiteralContext::numeral() {
  return getRuleContext<SyGuSv21Parser::NumeralContext>(0);
}

SyGuSv21Parser::DecimalContext* SyGuSv21Parser::LiteralContext::decimal() {
  return getRuleContext<SyGuSv21Parser::DecimalContext>(0);
}

SyGuSv21Parser::BoolConstContext* SyGuSv21Parser::LiteralContext::boolConst() {
  return getRuleContext<SyGuSv21Parser::BoolConstContext>(0);
}

SyGuSv21Parser::HexConstContext* SyGuSv21Parser::LiteralContext::hexConst() {
  return getRuleContext<SyGuSv21Parser::HexConstContext>(0);
}

SyGuSv21Parser::BinConstContext* SyGuSv21Parser::LiteralContext::binConst() {
  return getRuleContext<SyGuSv21Parser::BinConstContext>(0);
}

SyGuSv21Parser::StringConstContext* SyGuSv21Parser::LiteralContext::stringConst() {
  return getRuleContext<SyGuSv21Parser::StringConstContext>(0);
}

SyGuSv21Parser::BvConstContext* SyGuSv21Parser::LiteralContext::bvConst() {
  return getRuleContext<SyGuSv21Parser::BvConstContext>(0);
}


size_t SyGuSv21Parser::LiteralContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleLiteral;
}


std::any SyGuSv21Parser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::LiteralContext* SyGuSv21Parser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 4, SyGuSv21Parser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(107);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(100);
      numeral();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(101);
      decimal();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(102);
      boolConst();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(103);
      hexConst();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(104);
      binConst();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(105);
      stringConst();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(106);
      bvConst();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumeralContext ------------------------------------------------------------------

SyGuSv21Parser::NumeralContext::NumeralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SyGuSv21Parser::NumeralContext::NUMERAL() {
  return getToken(SyGuSv21Parser::NUMERAL, 0);
}


size_t SyGuSv21Parser::NumeralContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleNumeral;
}


std::any SyGuSv21Parser::NumeralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitNumeral(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::NumeralContext* SyGuSv21Parser::numeral() {
  NumeralContext *_localctx = _tracker.createInstance<NumeralContext>(_ctx, getState());
  enterRule(_localctx, 6, SyGuSv21Parser::RuleNumeral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    match(SyGuSv21Parser::NUMERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BvConstContext ------------------------------------------------------------------

SyGuSv21Parser::BvConstContext::BvConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SyGuSv21Parser::BvConstContext::BVCONST() {
  return getToken(SyGuSv21Parser::BVCONST, 0);
}

tree::TerminalNode* SyGuSv21Parser::BvConstContext::NUMERAL() {
  return getToken(SyGuSv21Parser::NUMERAL, 0);
}


size_t SyGuSv21Parser::BvConstContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleBvConst;
}


std::any SyGuSv21Parser::BvConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitBvConst(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::BvConstContext* SyGuSv21Parser::bvConst() {
  BvConstContext *_localctx = _tracker.createInstance<BvConstContext>(_ctx, getState());
  enterRule(_localctx, 8, SyGuSv21Parser::RuleBvConst);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    match(SyGuSv21Parser::T__0);
    setState(112);
    match(SyGuSv21Parser::T__1);
    setState(113);
    match(SyGuSv21Parser::BVCONST);
    setState(114);
    match(SyGuSv21Parser::NUMERAL);
    setState(115);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecimalContext ------------------------------------------------------------------

SyGuSv21Parser::DecimalContext::DecimalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SyGuSv21Parser::NumeralContext *> SyGuSv21Parser::DecimalContext::numeral() {
  return getRuleContexts<SyGuSv21Parser::NumeralContext>();
}

SyGuSv21Parser::NumeralContext* SyGuSv21Parser::DecimalContext::numeral(size_t i) {
  return getRuleContext<SyGuSv21Parser::NumeralContext>(i);
}


size_t SyGuSv21Parser::DecimalContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleDecimal;
}


std::any SyGuSv21Parser::DecimalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitDecimal(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::DecimalContext* SyGuSv21Parser::decimal() {
  DecimalContext *_localctx = _tracker.createInstance<DecimalContext>(_ctx, getState());
  enterRule(_localctx, 10, SyGuSv21Parser::RuleDecimal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    numeral();
    setState(118);
    match(SyGuSv21Parser::T__3);
    setState(119);
    numeral();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolConstContext ------------------------------------------------------------------

SyGuSv21Parser::BoolConstContext::BoolConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SyGuSv21Parser::BoolConstContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleBoolConst;
}

void SyGuSv21Parser::BoolConstContext::copyFrom(BoolConstContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BoolConstTrueContext ------------------------------------------------------------------

tree::TerminalNode* SyGuSv21Parser::BoolConstTrueContext::TRUE() {
  return getToken(SyGuSv21Parser::TRUE, 0);
}

SyGuSv21Parser::BoolConstTrueContext::BoolConstTrueContext(BoolConstContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::BoolConstTrueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitBoolConstTrue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolConstFalseContext ------------------------------------------------------------------

tree::TerminalNode* SyGuSv21Parser::BoolConstFalseContext::FALSE() {
  return getToken(SyGuSv21Parser::FALSE, 0);
}

SyGuSv21Parser::BoolConstFalseContext::BoolConstFalseContext(BoolConstContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::BoolConstFalseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitBoolConstFalse(this);
  else
    return visitor->visitChildren(this);
}
SyGuSv21Parser::BoolConstContext* SyGuSv21Parser::boolConst() {
  BoolConstContext *_localctx = _tracker.createInstance<BoolConstContext>(_ctx, getState());
  enterRule(_localctx, 12, SyGuSv21Parser::RuleBoolConst);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(123);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SyGuSv21Parser::TRUE: {
        _localctx = _tracker.createInstance<SyGuSv21Parser::BoolConstTrueContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(121);
        match(SyGuSv21Parser::TRUE);
        break;
      }

      case SyGuSv21Parser::FALSE: {
        _localctx = _tracker.createInstance<SyGuSv21Parser::BoolConstFalseContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(122);
        match(SyGuSv21Parser::FALSE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HexConstContext ------------------------------------------------------------------

SyGuSv21Parser::HexConstContext::HexConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SyGuSv21Parser::HexConstContext::HEXCONST() {
  return getToken(SyGuSv21Parser::HEXCONST, 0);
}


size_t SyGuSv21Parser::HexConstContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleHexConst;
}


std::any SyGuSv21Parser::HexConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitHexConst(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::HexConstContext* SyGuSv21Parser::hexConst() {
  HexConstContext *_localctx = _tracker.createInstance<HexConstContext>(_ctx, getState());
  enterRule(_localctx, 14, SyGuSv21Parser::RuleHexConst);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    match(SyGuSv21Parser::HEXCONST);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BinConstContext ------------------------------------------------------------------

SyGuSv21Parser::BinConstContext::BinConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SyGuSv21Parser::BinConstContext::BINCONST() {
  return getToken(SyGuSv21Parser::BINCONST, 0);
}


size_t SyGuSv21Parser::BinConstContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleBinConst;
}


std::any SyGuSv21Parser::BinConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitBinConst(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::BinConstContext* SyGuSv21Parser::binConst() {
  BinConstContext *_localctx = _tracker.createInstance<BinConstContext>(_ctx, getState());
  enterRule(_localctx, 16, SyGuSv21Parser::RuleBinConst);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(SyGuSv21Parser::BINCONST);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringConstContext ------------------------------------------------------------------

SyGuSv21Parser::StringConstContext::StringConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SyGuSv21Parser::StringConstContext::STRINGCONST() {
  return getToken(SyGuSv21Parser::STRINGCONST, 0);
}

tree::TerminalNode* SyGuSv21Parser::StringConstContext::EMPTYSTRING() {
  return getToken(SyGuSv21Parser::EMPTYSTRING, 0);
}


size_t SyGuSv21Parser::StringConstContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleStringConst;
}


std::any SyGuSv21Parser::StringConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitStringConst(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::StringConstContext* SyGuSv21Parser::stringConst() {
  StringConstContext *_localctx = _tracker.createInstance<StringConstContext>(_ctx, getState());
  enterRule(_localctx, 18, SyGuSv21Parser::RuleStringConst);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    _la = _input->LA(1);
    if (!(_la == SyGuSv21Parser::EMPTYSTRING

    || _la == SyGuSv21Parser::STRINGCONST)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

SyGuSv21Parser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SyGuSv21Parser::IdentifierContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleIdentifier;
}

void SyGuSv21Parser::IdentifierContext::copyFrom(IdentifierContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SimpleIdentifierContext ------------------------------------------------------------------

SyGuSv21Parser::SymbolContext* SyGuSv21Parser::SimpleIdentifierContext::symbol() {
  return getRuleContext<SyGuSv21Parser::SymbolContext>(0);
}

SyGuSv21Parser::SimpleIdentifierContext::SimpleIdentifierContext(IdentifierContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::SimpleIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitSimpleIdentifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IndexedIdentifierContext ------------------------------------------------------------------

SyGuSv21Parser::SymbolContext* SyGuSv21Parser::IndexedIdentifierContext::symbol() {
  return getRuleContext<SyGuSv21Parser::SymbolContext>(0);
}

std::vector<SyGuSv21Parser::IndexContext *> SyGuSv21Parser::IndexedIdentifierContext::index() {
  return getRuleContexts<SyGuSv21Parser::IndexContext>();
}

SyGuSv21Parser::IndexContext* SyGuSv21Parser::IndexedIdentifierContext::index(size_t i) {
  return getRuleContext<SyGuSv21Parser::IndexContext>(i);
}

SyGuSv21Parser::IndexedIdentifierContext::IndexedIdentifierContext(IdentifierContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::IndexedIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitIndexedIdentifier(this);
  else
    return visitor->visitChildren(this);
}
SyGuSv21Parser::IdentifierContext* SyGuSv21Parser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 20, SyGuSv21Parser::RuleIdentifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(142);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SyGuSv21Parser::SYMBOL: {
        _localctx = _tracker.createInstance<SyGuSv21Parser::SimpleIdentifierContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(131);
        symbol();
        break;
      }

      case SyGuSv21Parser::T__0: {
        _localctx = _tracker.createInstance<SyGuSv21Parser::IndexedIdentifierContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(132);
        match(SyGuSv21Parser::T__0);
        setState(133);
        match(SyGuSv21Parser::T__1);
        setState(134);
        symbol();
        setState(136); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(135);
          index();
          setState(138); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == SyGuSv21Parser::NUMERAL

        || _la == SyGuSv21Parser::SYMBOL);
        setState(140);
        match(SyGuSv21Parser::T__2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexContext ------------------------------------------------------------------

SyGuSv21Parser::IndexContext::IndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SyGuSv21Parser::IndexContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleIndex;
}

void SyGuSv21Parser::IndexContext::copyFrom(IndexContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NumeralIndexContext ------------------------------------------------------------------

SyGuSv21Parser::NumeralContext* SyGuSv21Parser::NumeralIndexContext::numeral() {
  return getRuleContext<SyGuSv21Parser::NumeralContext>(0);
}

SyGuSv21Parser::NumeralIndexContext::NumeralIndexContext(IndexContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::NumeralIndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitNumeralIndex(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SymbolIndexContext ------------------------------------------------------------------

SyGuSv21Parser::SymbolContext* SyGuSv21Parser::SymbolIndexContext::symbol() {
  return getRuleContext<SyGuSv21Parser::SymbolContext>(0);
}

SyGuSv21Parser::SymbolIndexContext::SymbolIndexContext(IndexContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::SymbolIndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitSymbolIndex(this);
  else
    return visitor->visitChildren(this);
}
SyGuSv21Parser::IndexContext* SyGuSv21Parser::index() {
  IndexContext *_localctx = _tracker.createInstance<IndexContext>(_ctx, getState());
  enterRule(_localctx, 22, SyGuSv21Parser::RuleIndex);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(146);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SyGuSv21Parser::NUMERAL: {
        _localctx = _tracker.createInstance<SyGuSv21Parser::NumeralIndexContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(144);
        numeral();
        break;
      }

      case SyGuSv21Parser::SYMBOL: {
        _localctx = _tracker.createInstance<SyGuSv21Parser::SymbolIndexContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(145);
        symbol();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SortContext ------------------------------------------------------------------

SyGuSv21Parser::SortContext::SortContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SyGuSv21Parser::SortContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleSort;
}

void SyGuSv21Parser::SortContext::copyFrom(SortContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParametricSortContext ------------------------------------------------------------------

SyGuSv21Parser::IdentifierContext* SyGuSv21Parser::ParametricSortContext::identifier() {
  return getRuleContext<SyGuSv21Parser::IdentifierContext>(0);
}

std::vector<SyGuSv21Parser::SortContext *> SyGuSv21Parser::ParametricSortContext::sort() {
  return getRuleContexts<SyGuSv21Parser::SortContext>();
}

SyGuSv21Parser::SortContext* SyGuSv21Parser::ParametricSortContext::sort(size_t i) {
  return getRuleContext<SyGuSv21Parser::SortContext>(i);
}

SyGuSv21Parser::ParametricSortContext::ParametricSortContext(SortContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::ParametricSortContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitParametricSort(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SimpleSortContext ------------------------------------------------------------------

SyGuSv21Parser::IdentifierContext* SyGuSv21Parser::SimpleSortContext::identifier() {
  return getRuleContext<SyGuSv21Parser::IdentifierContext>(0);
}

SyGuSv21Parser::SimpleSortContext::SimpleSortContext(SortContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::SimpleSortContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitSimpleSort(this);
  else
    return visitor->visitChildren(this);
}
SyGuSv21Parser::SortContext* SyGuSv21Parser::sort() {
  SortContext *_localctx = _tracker.createInstance<SortContext>(_ctx, getState());
  enterRule(_localctx, 24, SyGuSv21Parser::RuleSort);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(158);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<SyGuSv21Parser::SimpleSortContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(148);
      identifier();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SyGuSv21Parser::ParametricSortContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(149);
      match(SyGuSv21Parser::T__0);
      setState(150);
      identifier();
      setState(152); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(151);
        sort();
        setState(154); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == SyGuSv21Parser::T__0

      || _la == SyGuSv21Parser::SYMBOL);
      setState(156);
      match(SyGuSv21Parser::T__2);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

SyGuSv21Parser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SyGuSv21Parser::TermContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleTerm;
}

void SyGuSv21Parser::TermContext::copyFrom(TermContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IdentifierTermContext ------------------------------------------------------------------

SyGuSv21Parser::IdentifierContext* SyGuSv21Parser::IdentifierTermContext::identifier() {
  return getRuleContext<SyGuSv21Parser::IdentifierContext>(0);
}

SyGuSv21Parser::IdentifierTermContext::IdentifierTermContext(TermContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::IdentifierTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitIdentifierTerm(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralTermContext ------------------------------------------------------------------

SyGuSv21Parser::LiteralContext* SyGuSv21Parser::LiteralTermContext::literal() {
  return getRuleContext<SyGuSv21Parser::LiteralContext>(0);
}

SyGuSv21Parser::LiteralTermContext::LiteralTermContext(TermContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::LiteralTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitLiteralTerm(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForallTermContext ------------------------------------------------------------------

SyGuSv21Parser::TermContext* SyGuSv21Parser::ForallTermContext::term() {
  return getRuleContext<SyGuSv21Parser::TermContext>(0);
}

std::vector<SyGuSv21Parser::SortedVarContext *> SyGuSv21Parser::ForallTermContext::sortedVar() {
  return getRuleContexts<SyGuSv21Parser::SortedVarContext>();
}

SyGuSv21Parser::SortedVarContext* SyGuSv21Parser::ForallTermContext::sortedVar(size_t i) {
  return getRuleContext<SyGuSv21Parser::SortedVarContext>(i);
}

SyGuSv21Parser::ForallTermContext::ForallTermContext(TermContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::ForallTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitForallTerm(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LetTermContext ------------------------------------------------------------------

SyGuSv21Parser::TermContext* SyGuSv21Parser::LetTermContext::term() {
  return getRuleContext<SyGuSv21Parser::TermContext>(0);
}

std::vector<SyGuSv21Parser::VarBindingContext *> SyGuSv21Parser::LetTermContext::varBinding() {
  return getRuleContexts<SyGuSv21Parser::VarBindingContext>();
}

SyGuSv21Parser::VarBindingContext* SyGuSv21Parser::LetTermContext::varBinding(size_t i) {
  return getRuleContext<SyGuSv21Parser::VarBindingContext>(i);
}

SyGuSv21Parser::LetTermContext::LetTermContext(TermContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::LetTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitLetTerm(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ApplicationTermContext ------------------------------------------------------------------

SyGuSv21Parser::IdentifierContext* SyGuSv21Parser::ApplicationTermContext::identifier() {
  return getRuleContext<SyGuSv21Parser::IdentifierContext>(0);
}

std::vector<SyGuSv21Parser::TermContext *> SyGuSv21Parser::ApplicationTermContext::term() {
  return getRuleContexts<SyGuSv21Parser::TermContext>();
}

SyGuSv21Parser::TermContext* SyGuSv21Parser::ApplicationTermContext::term(size_t i) {
  return getRuleContext<SyGuSv21Parser::TermContext>(i);
}

SyGuSv21Parser::ApplicationTermContext::ApplicationTermContext(TermContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::ApplicationTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitApplicationTerm(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExistsTermContext ------------------------------------------------------------------

SyGuSv21Parser::TermContext* SyGuSv21Parser::ExistsTermContext::term() {
  return getRuleContext<SyGuSv21Parser::TermContext>(0);
}

std::vector<SyGuSv21Parser::SortedVarContext *> SyGuSv21Parser::ExistsTermContext::sortedVar() {
  return getRuleContexts<SyGuSv21Parser::SortedVarContext>();
}

SyGuSv21Parser::SortedVarContext* SyGuSv21Parser::ExistsTermContext::sortedVar(size_t i) {
  return getRuleContext<SyGuSv21Parser::SortedVarContext>(i);
}

SyGuSv21Parser::ExistsTermContext::ExistsTermContext(TermContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::ExistsTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitExistsTerm(this);
  else
    return visitor->visitChildren(this);
}
SyGuSv21Parser::TermContext* SyGuSv21Parser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 26, SyGuSv21Parser::RuleTerm);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(207);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<SyGuSv21Parser::IdentifierTermContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(160);
      identifier();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SyGuSv21Parser::LiteralTermContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(161);
      literal();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<SyGuSv21Parser::ApplicationTermContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(162);
      match(SyGuSv21Parser::T__0);
      setState(163);
      identifier();
      setState(165); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(164);
        term();
        setState(167); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 3855672672258) != 0));
      setState(169);
      match(SyGuSv21Parser::T__2);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<SyGuSv21Parser::ExistsTermContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(171);
      match(SyGuSv21Parser::T__0);
      setState(172);
      match(SyGuSv21Parser::T__4);
      setState(173);
      match(SyGuSv21Parser::T__0);
      setState(175); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(174);
        sortedVar();
        setState(177); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == SyGuSv21Parser::T__0);
      setState(179);
      match(SyGuSv21Parser::T__2);
      setState(180);
      term();
      setState(181);
      match(SyGuSv21Parser::T__2);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<SyGuSv21Parser::ForallTermContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(183);
      match(SyGuSv21Parser::T__0);
      setState(184);
      match(SyGuSv21Parser::T__5);
      setState(185);
      match(SyGuSv21Parser::T__0);
      setState(187); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(186);
        sortedVar();
        setState(189); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == SyGuSv21Parser::T__0);
      setState(191);
      match(SyGuSv21Parser::T__2);
      setState(192);
      term();
      setState(193);
      match(SyGuSv21Parser::T__2);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<SyGuSv21Parser::LetTermContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(195);
      match(SyGuSv21Parser::T__0);
      setState(196);
      match(SyGuSv21Parser::T__6);
      setState(197);
      match(SyGuSv21Parser::T__0);
      setState(199); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(198);
        varBinding();
        setState(201); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == SyGuSv21Parser::T__0);
      setState(203);
      match(SyGuSv21Parser::T__2);
      setState(204);
      term();
      setState(205);
      match(SyGuSv21Parser::T__2);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BfTermContext ------------------------------------------------------------------

SyGuSv21Parser::BfTermContext::BfTermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SyGuSv21Parser::BfTermContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleBfTerm;
}

void SyGuSv21Parser::BfTermContext::copyFrom(BfTermContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BfLiteralTermContext ------------------------------------------------------------------

SyGuSv21Parser::LiteralContext* SyGuSv21Parser::BfLiteralTermContext::literal() {
  return getRuleContext<SyGuSv21Parser::LiteralContext>(0);
}

SyGuSv21Parser::BfLiteralTermContext::BfLiteralTermContext(BfTermContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::BfLiteralTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitBfLiteralTerm(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BfIdentifierTermContext ------------------------------------------------------------------

SyGuSv21Parser::IdentifierContext* SyGuSv21Parser::BfIdentifierTermContext::identifier() {
  return getRuleContext<SyGuSv21Parser::IdentifierContext>(0);
}

SyGuSv21Parser::BfIdentifierTermContext::BfIdentifierTermContext(BfTermContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::BfIdentifierTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitBfIdentifierTerm(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BfApplicationTermContext ------------------------------------------------------------------

SyGuSv21Parser::IdentifierContext* SyGuSv21Parser::BfApplicationTermContext::identifier() {
  return getRuleContext<SyGuSv21Parser::IdentifierContext>(0);
}

std::vector<SyGuSv21Parser::BfTermContext *> SyGuSv21Parser::BfApplicationTermContext::bfTerm() {
  return getRuleContexts<SyGuSv21Parser::BfTermContext>();
}

SyGuSv21Parser::BfTermContext* SyGuSv21Parser::BfApplicationTermContext::bfTerm(size_t i) {
  return getRuleContext<SyGuSv21Parser::BfTermContext>(i);
}

SyGuSv21Parser::BfApplicationTermContext::BfApplicationTermContext(BfTermContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::BfApplicationTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitBfApplicationTerm(this);
  else
    return visitor->visitChildren(this);
}
SyGuSv21Parser::BfTermContext* SyGuSv21Parser::bfTerm() {
  BfTermContext *_localctx = _tracker.createInstance<BfTermContext>(_ctx, getState());
  enterRule(_localctx, 28, SyGuSv21Parser::RuleBfTerm);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(220);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<SyGuSv21Parser::BfIdentifierTermContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(209);
      identifier();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SyGuSv21Parser::BfLiteralTermContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(210);
      literal();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<SyGuSv21Parser::BfApplicationTermContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(211);
      match(SyGuSv21Parser::T__0);
      setState(212);
      identifier();
      setState(214); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(213);
        bfTerm();
        setState(216); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 3855672672258) != 0));
      setState(218);
      match(SyGuSv21Parser::T__2);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SortedVarContext ------------------------------------------------------------------

SyGuSv21Parser::SortedVarContext::SortedVarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::SymbolContext* SyGuSv21Parser::SortedVarContext::symbol() {
  return getRuleContext<SyGuSv21Parser::SymbolContext>(0);
}

SyGuSv21Parser::SortContext* SyGuSv21Parser::SortedVarContext::sort() {
  return getRuleContext<SyGuSv21Parser::SortContext>(0);
}


size_t SyGuSv21Parser::SortedVarContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleSortedVar;
}


std::any SyGuSv21Parser::SortedVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitSortedVar(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::SortedVarContext* SyGuSv21Parser::sortedVar() {
  SortedVarContext *_localctx = _tracker.createInstance<SortedVarContext>(_ctx, getState());
  enterRule(_localctx, 30, SyGuSv21Parser::RuleSortedVar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222);
    match(SyGuSv21Parser::T__0);
    setState(223);
    symbol();
    setState(224);
    sort();
    setState(225);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarBindingContext ------------------------------------------------------------------

SyGuSv21Parser::VarBindingContext::VarBindingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::SymbolContext* SyGuSv21Parser::VarBindingContext::symbol() {
  return getRuleContext<SyGuSv21Parser::SymbolContext>(0);
}

SyGuSv21Parser::TermContext* SyGuSv21Parser::VarBindingContext::term() {
  return getRuleContext<SyGuSv21Parser::TermContext>(0);
}


size_t SyGuSv21Parser::VarBindingContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleVarBinding;
}


std::any SyGuSv21Parser::VarBindingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitVarBinding(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::VarBindingContext* SyGuSv21Parser::varBinding() {
  VarBindingContext *_localctx = _tracker.createInstance<VarBindingContext>(_ctx, getState());
  enterRule(_localctx, 32, SyGuSv21Parser::RuleVarBinding);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(227);
    match(SyGuSv21Parser::T__0);
    setState(228);
    symbol();
    setState(229);
    term();
    setState(230);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FeatureContext ------------------------------------------------------------------

SyGuSv21Parser::FeatureContext::FeatureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SyGuSv21Parser::FeatureContext::GRAMMARS_FEATURE() {
  return getToken(SyGuSv21Parser::GRAMMARS_FEATURE, 0);
}

tree::TerminalNode* SyGuSv21Parser::FeatureContext::FWD_DECLS_FEATURE() {
  return getToken(SyGuSv21Parser::FWD_DECLS_FEATURE, 0);
}

tree::TerminalNode* SyGuSv21Parser::FeatureContext::RECURSION_FEATURE() {
  return getToken(SyGuSv21Parser::RECURSION_FEATURE, 0);
}

tree::TerminalNode* SyGuSv21Parser::FeatureContext::ORACLES_FEATURE() {
  return getToken(SyGuSv21Parser::ORACLES_FEATURE, 0);
}

tree::TerminalNode* SyGuSv21Parser::FeatureContext::WEIGHTS_FEATURE() {
  return getToken(SyGuSv21Parser::WEIGHTS_FEATURE, 0);
}


size_t SyGuSv21Parser::FeatureContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleFeature;
}


std::any SyGuSv21Parser::FeatureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitFeature(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::FeatureContext* SyGuSv21Parser::feature() {
  FeatureContext *_localctx = _tracker.createInstance<FeatureContext>(_ctx, getState());
  enterRule(_localctx, 34, SyGuSv21Parser::RuleFeature);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(242);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(232);
      match(SyGuSv21Parser::T__7);
      setState(233);
      match(SyGuSv21Parser::GRAMMARS_FEATURE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(234);
      match(SyGuSv21Parser::T__7);
      setState(235);
      match(SyGuSv21Parser::FWD_DECLS_FEATURE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(236);
      match(SyGuSv21Parser::T__7);
      setState(237);
      match(SyGuSv21Parser::RECURSION_FEATURE);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(238);
      match(SyGuSv21Parser::T__7);
      setState(239);
      match(SyGuSv21Parser::ORACLES_FEATURE);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(240);
      match(SyGuSv21Parser::T__7);
      setState(241);
      match(SyGuSv21Parser::WEIGHTS_FEATURE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CmdContext ------------------------------------------------------------------

SyGuSv21Parser::CmdContext::CmdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::AssumeCmdContext* SyGuSv21Parser::CmdContext::assumeCmd() {
  return getRuleContext<SyGuSv21Parser::AssumeCmdContext>(0);
}

SyGuSv21Parser::CheckSynthCmdContext* SyGuSv21Parser::CmdContext::checkSynthCmd() {
  return getRuleContext<SyGuSv21Parser::CheckSynthCmdContext>(0);
}

SyGuSv21Parser::ConstraintCmdContext* SyGuSv21Parser::CmdContext::constraintCmd() {
  return getRuleContext<SyGuSv21Parser::ConstraintCmdContext>(0);
}

SyGuSv21Parser::DeclareVarCmdContext* SyGuSv21Parser::CmdContext::declareVarCmd() {
  return getRuleContext<SyGuSv21Parser::DeclareVarCmdContext>(0);
}

SyGuSv21Parser::SetFeatureCmdContext* SyGuSv21Parser::CmdContext::setFeatureCmd() {
  return getRuleContext<SyGuSv21Parser::SetFeatureCmdContext>(0);
}

SyGuSv21Parser::SynthFunCmdContext* SyGuSv21Parser::CmdContext::synthFunCmd() {
  return getRuleContext<SyGuSv21Parser::SynthFunCmdContext>(0);
}

SyGuSv21Parser::SmtCmdContext* SyGuSv21Parser::CmdContext::smtCmd() {
  return getRuleContext<SyGuSv21Parser::SmtCmdContext>(0);
}


size_t SyGuSv21Parser::CmdContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleCmd;
}


std::any SyGuSv21Parser::CmdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitCmd(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::CmdContext* SyGuSv21Parser::cmd() {
  CmdContext *_localctx = _tracker.createInstance<CmdContext>(_ctx, getState());
  enterRule(_localctx, 36, SyGuSv21Parser::RuleCmd);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(251);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(244);
      assumeCmd();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(245);
      checkSynthCmd();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(246);
      constraintCmd();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(247);
      declareVarCmd();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(248);
      setFeatureCmd();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(249);
      synthFunCmd();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(250);
      smtCmd();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssumeCmdContext ------------------------------------------------------------------

SyGuSv21Parser::AssumeCmdContext::AssumeCmdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::TermContext* SyGuSv21Parser::AssumeCmdContext::term() {
  return getRuleContext<SyGuSv21Parser::TermContext>(0);
}


size_t SyGuSv21Parser::AssumeCmdContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleAssumeCmd;
}


std::any SyGuSv21Parser::AssumeCmdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitAssumeCmd(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::AssumeCmdContext* SyGuSv21Parser::assumeCmd() {
  AssumeCmdContext *_localctx = _tracker.createInstance<AssumeCmdContext>(_ctx, getState());
  enterRule(_localctx, 38, SyGuSv21Parser::RuleAssumeCmd);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    match(SyGuSv21Parser::T__0);
    setState(254);
    match(SyGuSv21Parser::T__8);
    setState(255);
    term();
    setState(256);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CheckSynthCmdContext ------------------------------------------------------------------

SyGuSv21Parser::CheckSynthCmdContext::CheckSynthCmdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SyGuSv21Parser::CheckSynthCmdContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleCheckSynthCmd;
}


std::any SyGuSv21Parser::CheckSynthCmdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitCheckSynthCmd(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::CheckSynthCmdContext* SyGuSv21Parser::checkSynthCmd() {
  CheckSynthCmdContext *_localctx = _tracker.createInstance<CheckSynthCmdContext>(_ctx, getState());
  enterRule(_localctx, 40, SyGuSv21Parser::RuleCheckSynthCmd);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(258);
    match(SyGuSv21Parser::T__0);
    setState(259);
    match(SyGuSv21Parser::T__9);
    setState(260);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstraintCmdContext ------------------------------------------------------------------

SyGuSv21Parser::ConstraintCmdContext::ConstraintCmdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::TermContext* SyGuSv21Parser::ConstraintCmdContext::term() {
  return getRuleContext<SyGuSv21Parser::TermContext>(0);
}


size_t SyGuSv21Parser::ConstraintCmdContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleConstraintCmd;
}


std::any SyGuSv21Parser::ConstraintCmdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitConstraintCmd(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::ConstraintCmdContext* SyGuSv21Parser::constraintCmd() {
  ConstraintCmdContext *_localctx = _tracker.createInstance<ConstraintCmdContext>(_ctx, getState());
  enterRule(_localctx, 42, SyGuSv21Parser::RuleConstraintCmd);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    match(SyGuSv21Parser::T__0);
    setState(263);
    match(SyGuSv21Parser::T__10);
    setState(264);
    term();
    setState(265);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclareVarCmdContext ------------------------------------------------------------------

SyGuSv21Parser::DeclareVarCmdContext::DeclareVarCmdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::SymbolContext* SyGuSv21Parser::DeclareVarCmdContext::symbol() {
  return getRuleContext<SyGuSv21Parser::SymbolContext>(0);
}

SyGuSv21Parser::SortContext* SyGuSv21Parser::DeclareVarCmdContext::sort() {
  return getRuleContext<SyGuSv21Parser::SortContext>(0);
}


size_t SyGuSv21Parser::DeclareVarCmdContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleDeclareVarCmd;
}


std::any SyGuSv21Parser::DeclareVarCmdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitDeclareVarCmd(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::DeclareVarCmdContext* SyGuSv21Parser::declareVarCmd() {
  DeclareVarCmdContext *_localctx = _tracker.createInstance<DeclareVarCmdContext>(_ctx, getState());
  enterRule(_localctx, 44, SyGuSv21Parser::RuleDeclareVarCmd);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    match(SyGuSv21Parser::T__0);
    setState(268);
    match(SyGuSv21Parser::T__11);
    setState(269);
    symbol();
    setState(270);
    sort();
    setState(271);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetFeatureCmdContext ------------------------------------------------------------------

SyGuSv21Parser::SetFeatureCmdContext::SetFeatureCmdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::FeatureContext* SyGuSv21Parser::SetFeatureCmdContext::feature() {
  return getRuleContext<SyGuSv21Parser::FeatureContext>(0);
}

SyGuSv21Parser::BoolConstContext* SyGuSv21Parser::SetFeatureCmdContext::boolConst() {
  return getRuleContext<SyGuSv21Parser::BoolConstContext>(0);
}


size_t SyGuSv21Parser::SetFeatureCmdContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleSetFeatureCmd;
}


std::any SyGuSv21Parser::SetFeatureCmdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitSetFeatureCmd(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::SetFeatureCmdContext* SyGuSv21Parser::setFeatureCmd() {
  SetFeatureCmdContext *_localctx = _tracker.createInstance<SetFeatureCmdContext>(_ctx, getState());
  enterRule(_localctx, 46, SyGuSv21Parser::RuleSetFeatureCmd);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(273);
    match(SyGuSv21Parser::T__0);
    setState(274);
    match(SyGuSv21Parser::T__12);
    setState(275);
    feature();
    setState(276);
    boolConst();
    setState(277);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SynthFunCmdContext ------------------------------------------------------------------

SyGuSv21Parser::SynthFunCmdContext::SynthFunCmdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::SymbolContext* SyGuSv21Parser::SynthFunCmdContext::symbol() {
  return getRuleContext<SyGuSv21Parser::SymbolContext>(0);
}

SyGuSv21Parser::SortContext* SyGuSv21Parser::SynthFunCmdContext::sort() {
  return getRuleContext<SyGuSv21Parser::SortContext>(0);
}

std::vector<SyGuSv21Parser::SortedVarContext *> SyGuSv21Parser::SynthFunCmdContext::sortedVar() {
  return getRuleContexts<SyGuSv21Parser::SortedVarContext>();
}

SyGuSv21Parser::SortedVarContext* SyGuSv21Parser::SynthFunCmdContext::sortedVar(size_t i) {
  return getRuleContext<SyGuSv21Parser::SortedVarContext>(i);
}

SyGuSv21Parser::GrammarDefContext* SyGuSv21Parser::SynthFunCmdContext::grammarDef() {
  return getRuleContext<SyGuSv21Parser::GrammarDefContext>(0);
}


size_t SyGuSv21Parser::SynthFunCmdContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleSynthFunCmd;
}


std::any SyGuSv21Parser::SynthFunCmdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitSynthFunCmd(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::SynthFunCmdContext* SyGuSv21Parser::synthFunCmd() {
  SynthFunCmdContext *_localctx = _tracker.createInstance<SynthFunCmdContext>(_ctx, getState());
  enterRule(_localctx, 48, SyGuSv21Parser::RuleSynthFunCmd);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    match(SyGuSv21Parser::T__0);
    setState(280);
    match(SyGuSv21Parser::T__13);
    setState(281);
    symbol();
    setState(282);
    match(SyGuSv21Parser::T__0);
    setState(286);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SyGuSv21Parser::T__0) {
      setState(283);
      sortedVar();
      setState(288);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(289);
    match(SyGuSv21Parser::T__2);
    setState(290);
    sort();
    setState(292);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SyGuSv21Parser::T__0) {
      setState(291);
      grammarDef();
    }
    setState(294);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SmtCmdContext ------------------------------------------------------------------

SyGuSv21Parser::SmtCmdContext::SmtCmdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::DeclareDatatypeContext* SyGuSv21Parser::SmtCmdContext::declareDatatype() {
  return getRuleContext<SyGuSv21Parser::DeclareDatatypeContext>(0);
}

SyGuSv21Parser::DeclareDatatypesContext* SyGuSv21Parser::SmtCmdContext::declareDatatypes() {
  return getRuleContext<SyGuSv21Parser::DeclareDatatypesContext>(0);
}

SyGuSv21Parser::DeclareSortContext* SyGuSv21Parser::SmtCmdContext::declareSort() {
  return getRuleContext<SyGuSv21Parser::DeclareSortContext>(0);
}

SyGuSv21Parser::DefineFunContext* SyGuSv21Parser::SmtCmdContext::defineFun() {
  return getRuleContext<SyGuSv21Parser::DefineFunContext>(0);
}

SyGuSv21Parser::DefineSortContext* SyGuSv21Parser::SmtCmdContext::defineSort() {
  return getRuleContext<SyGuSv21Parser::DefineSortContext>(0);
}

SyGuSv21Parser::SetInfoContext* SyGuSv21Parser::SmtCmdContext::setInfo() {
  return getRuleContext<SyGuSv21Parser::SetInfoContext>(0);
}

SyGuSv21Parser::SetLogicContext* SyGuSv21Parser::SmtCmdContext::setLogic() {
  return getRuleContext<SyGuSv21Parser::SetLogicContext>(0);
}

SyGuSv21Parser::SetOptionContext* SyGuSv21Parser::SmtCmdContext::setOption() {
  return getRuleContext<SyGuSv21Parser::SetOptionContext>(0);
}


size_t SyGuSv21Parser::SmtCmdContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleSmtCmd;
}


std::any SyGuSv21Parser::SmtCmdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitSmtCmd(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::SmtCmdContext* SyGuSv21Parser::smtCmd() {
  SmtCmdContext *_localctx = _tracker.createInstance<SmtCmdContext>(_ctx, getState());
  enterRule(_localctx, 50, SyGuSv21Parser::RuleSmtCmd);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(304);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(296);
      declareDatatype();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(297);
      declareDatatypes();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(298);
      declareSort();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(299);
      defineFun();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(300);
      defineSort();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(301);
      setInfo();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(302);
      setLogic();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(303);
      setOption();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclareDatatypeContext ------------------------------------------------------------------

SyGuSv21Parser::DeclareDatatypeContext::DeclareDatatypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::SymbolContext* SyGuSv21Parser::DeclareDatatypeContext::symbol() {
  return getRuleContext<SyGuSv21Parser::SymbolContext>(0);
}

SyGuSv21Parser::DtDeclContext* SyGuSv21Parser::DeclareDatatypeContext::dtDecl() {
  return getRuleContext<SyGuSv21Parser::DtDeclContext>(0);
}


size_t SyGuSv21Parser::DeclareDatatypeContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleDeclareDatatype;
}


std::any SyGuSv21Parser::DeclareDatatypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitDeclareDatatype(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::DeclareDatatypeContext* SyGuSv21Parser::declareDatatype() {
  DeclareDatatypeContext *_localctx = _tracker.createInstance<DeclareDatatypeContext>(_ctx, getState());
  enterRule(_localctx, 52, SyGuSv21Parser::RuleDeclareDatatype);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    match(SyGuSv21Parser::T__0);
    setState(307);
    match(SyGuSv21Parser::T__14);
    setState(308);
    symbol();
    setState(309);
    dtDecl();
    setState(310);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclareDatatypesContext ------------------------------------------------------------------

SyGuSv21Parser::DeclareDatatypesContext::DeclareDatatypesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SyGuSv21Parser::SortDeclContext *> SyGuSv21Parser::DeclareDatatypesContext::sortDecl() {
  return getRuleContexts<SyGuSv21Parser::SortDeclContext>();
}

SyGuSv21Parser::SortDeclContext* SyGuSv21Parser::DeclareDatatypesContext::sortDecl(size_t i) {
  return getRuleContext<SyGuSv21Parser::SortDeclContext>(i);
}

std::vector<SyGuSv21Parser::DtDeclContext *> SyGuSv21Parser::DeclareDatatypesContext::dtDecl() {
  return getRuleContexts<SyGuSv21Parser::DtDeclContext>();
}

SyGuSv21Parser::DtDeclContext* SyGuSv21Parser::DeclareDatatypesContext::dtDecl(size_t i) {
  return getRuleContext<SyGuSv21Parser::DtDeclContext>(i);
}


size_t SyGuSv21Parser::DeclareDatatypesContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleDeclareDatatypes;
}


std::any SyGuSv21Parser::DeclareDatatypesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitDeclareDatatypes(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::DeclareDatatypesContext* SyGuSv21Parser::declareDatatypes() {
  DeclareDatatypesContext *_localctx = _tracker.createInstance<DeclareDatatypesContext>(_ctx, getState());
  enterRule(_localctx, 54, SyGuSv21Parser::RuleDeclareDatatypes);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(312);
    match(SyGuSv21Parser::T__0);
    setState(313);
    match(SyGuSv21Parser::T__15);
    setState(314);
    match(SyGuSv21Parser::T__0);
    setState(316); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(315);
      sortDecl();
      setState(318); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SyGuSv21Parser::T__0);
    setState(320);
    match(SyGuSv21Parser::T__2);
    setState(321);
    match(SyGuSv21Parser::T__0);
    setState(323); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(322);
      dtDecl();
      setState(325); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SyGuSv21Parser::T__0);
    setState(327);
    match(SyGuSv21Parser::T__2);
    setState(328);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclareSortContext ------------------------------------------------------------------

SyGuSv21Parser::DeclareSortContext::DeclareSortContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::SymbolContext* SyGuSv21Parser::DeclareSortContext::symbol() {
  return getRuleContext<SyGuSv21Parser::SymbolContext>(0);
}

SyGuSv21Parser::NumeralContext* SyGuSv21Parser::DeclareSortContext::numeral() {
  return getRuleContext<SyGuSv21Parser::NumeralContext>(0);
}


size_t SyGuSv21Parser::DeclareSortContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleDeclareSort;
}


std::any SyGuSv21Parser::DeclareSortContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitDeclareSort(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::DeclareSortContext* SyGuSv21Parser::declareSort() {
  DeclareSortContext *_localctx = _tracker.createInstance<DeclareSortContext>(_ctx, getState());
  enterRule(_localctx, 56, SyGuSv21Parser::RuleDeclareSort);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(330);
    match(SyGuSv21Parser::T__0);
    setState(331);
    match(SyGuSv21Parser::T__16);
    setState(332);
    symbol();
    setState(333);
    numeral();
    setState(334);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefineFunContext ------------------------------------------------------------------

SyGuSv21Parser::DefineFunContext::DefineFunContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::SymbolContext* SyGuSv21Parser::DefineFunContext::symbol() {
  return getRuleContext<SyGuSv21Parser::SymbolContext>(0);
}

SyGuSv21Parser::SortContext* SyGuSv21Parser::DefineFunContext::sort() {
  return getRuleContext<SyGuSv21Parser::SortContext>(0);
}

SyGuSv21Parser::TermContext* SyGuSv21Parser::DefineFunContext::term() {
  return getRuleContext<SyGuSv21Parser::TermContext>(0);
}

std::vector<SyGuSv21Parser::SortedVarContext *> SyGuSv21Parser::DefineFunContext::sortedVar() {
  return getRuleContexts<SyGuSv21Parser::SortedVarContext>();
}

SyGuSv21Parser::SortedVarContext* SyGuSv21Parser::DefineFunContext::sortedVar(size_t i) {
  return getRuleContext<SyGuSv21Parser::SortedVarContext>(i);
}


size_t SyGuSv21Parser::DefineFunContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleDefineFun;
}


std::any SyGuSv21Parser::DefineFunContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitDefineFun(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::DefineFunContext* SyGuSv21Parser::defineFun() {
  DefineFunContext *_localctx = _tracker.createInstance<DefineFunContext>(_ctx, getState());
  enterRule(_localctx, 58, SyGuSv21Parser::RuleDefineFun);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(336);
    match(SyGuSv21Parser::T__0);
    setState(337);
    match(SyGuSv21Parser::T__17);
    setState(338);
    symbol();
    setState(339);
    match(SyGuSv21Parser::T__0);
    setState(343);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SyGuSv21Parser::T__0) {
      setState(340);
      sortedVar();
      setState(345);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(346);
    match(SyGuSv21Parser::T__2);
    setState(347);
    sort();
    setState(348);
    term();
    setState(349);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefineSortContext ------------------------------------------------------------------

SyGuSv21Parser::DefineSortContext::DefineSortContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::SymbolContext* SyGuSv21Parser::DefineSortContext::symbol() {
  return getRuleContext<SyGuSv21Parser::SymbolContext>(0);
}

SyGuSv21Parser::SortContext* SyGuSv21Parser::DefineSortContext::sort() {
  return getRuleContext<SyGuSv21Parser::SortContext>(0);
}


size_t SyGuSv21Parser::DefineSortContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleDefineSort;
}


std::any SyGuSv21Parser::DefineSortContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitDefineSort(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::DefineSortContext* SyGuSv21Parser::defineSort() {
  DefineSortContext *_localctx = _tracker.createInstance<DefineSortContext>(_ctx, getState());
  enterRule(_localctx, 60, SyGuSv21Parser::RuleDefineSort);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(351);
    match(SyGuSv21Parser::T__0);
    setState(352);
    match(SyGuSv21Parser::T__18);
    setState(353);
    symbol();
    setState(354);
    sort();
    setState(355);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetInfoContext ------------------------------------------------------------------

SyGuSv21Parser::SetInfoContext::SetInfoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::SymbolContext* SyGuSv21Parser::SetInfoContext::symbol() {
  return getRuleContext<SyGuSv21Parser::SymbolContext>(0);
}

SyGuSv21Parser::LiteralContext* SyGuSv21Parser::SetInfoContext::literal() {
  return getRuleContext<SyGuSv21Parser::LiteralContext>(0);
}


size_t SyGuSv21Parser::SetInfoContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleSetInfo;
}


std::any SyGuSv21Parser::SetInfoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitSetInfo(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::SetInfoContext* SyGuSv21Parser::setInfo() {
  SetInfoContext *_localctx = _tracker.createInstance<SetInfoContext>(_ctx, getState());
  enterRule(_localctx, 62, SyGuSv21Parser::RuleSetInfo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    match(SyGuSv21Parser::T__0);
    setState(358);
    match(SyGuSv21Parser::T__19);
    setState(359);
    match(SyGuSv21Parser::T__7);
    setState(360);
    symbol();
    setState(361);
    literal();
    setState(362);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetLogicContext ------------------------------------------------------------------

SyGuSv21Parser::SetLogicContext::SetLogicContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::SymbolContext* SyGuSv21Parser::SetLogicContext::symbol() {
  return getRuleContext<SyGuSv21Parser::SymbolContext>(0);
}


size_t SyGuSv21Parser::SetLogicContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleSetLogic;
}


std::any SyGuSv21Parser::SetLogicContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitSetLogic(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::SetLogicContext* SyGuSv21Parser::setLogic() {
  SetLogicContext *_localctx = _tracker.createInstance<SetLogicContext>(_ctx, getState());
  enterRule(_localctx, 64, SyGuSv21Parser::RuleSetLogic);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(364);
    match(SyGuSv21Parser::T__0);
    setState(365);
    match(SyGuSv21Parser::T__20);
    setState(366);
    symbol();
    setState(367);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetOptionContext ------------------------------------------------------------------

SyGuSv21Parser::SetOptionContext::SetOptionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::SymbolContext* SyGuSv21Parser::SetOptionContext::symbol() {
  return getRuleContext<SyGuSv21Parser::SymbolContext>(0);
}

SyGuSv21Parser::LiteralContext* SyGuSv21Parser::SetOptionContext::literal() {
  return getRuleContext<SyGuSv21Parser::LiteralContext>(0);
}


size_t SyGuSv21Parser::SetOptionContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleSetOption;
}


std::any SyGuSv21Parser::SetOptionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitSetOption(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::SetOptionContext* SyGuSv21Parser::setOption() {
  SetOptionContext *_localctx = _tracker.createInstance<SetOptionContext>(_ctx, getState());
  enterRule(_localctx, 66, SyGuSv21Parser::RuleSetOption);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(369);
    match(SyGuSv21Parser::T__0);
    setState(370);
    match(SyGuSv21Parser::T__21);
    setState(371);
    match(SyGuSv21Parser::T__7);
    setState(372);
    symbol();
    setState(373);
    literal();
    setState(374);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SortDeclContext ------------------------------------------------------------------

SyGuSv21Parser::SortDeclContext::SortDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::SymbolContext* SyGuSv21Parser::SortDeclContext::symbol() {
  return getRuleContext<SyGuSv21Parser::SymbolContext>(0);
}

SyGuSv21Parser::NumeralContext* SyGuSv21Parser::SortDeclContext::numeral() {
  return getRuleContext<SyGuSv21Parser::NumeralContext>(0);
}


size_t SyGuSv21Parser::SortDeclContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleSortDecl;
}


std::any SyGuSv21Parser::SortDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitSortDecl(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::SortDeclContext* SyGuSv21Parser::sortDecl() {
  SortDeclContext *_localctx = _tracker.createInstance<SortDeclContext>(_ctx, getState());
  enterRule(_localctx, 68, SyGuSv21Parser::RuleSortDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(376);
    match(SyGuSv21Parser::T__0);
    setState(377);
    symbol();
    setState(378);
    numeral();
    setState(379);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DtDeclContext ------------------------------------------------------------------

SyGuSv21Parser::DtDeclContext::DtDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SyGuSv21Parser::DtConsDeclContext *> SyGuSv21Parser::DtDeclContext::dtConsDecl() {
  return getRuleContexts<SyGuSv21Parser::DtConsDeclContext>();
}

SyGuSv21Parser::DtConsDeclContext* SyGuSv21Parser::DtDeclContext::dtConsDecl(size_t i) {
  return getRuleContext<SyGuSv21Parser::DtConsDeclContext>(i);
}


size_t SyGuSv21Parser::DtDeclContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleDtDecl;
}


std::any SyGuSv21Parser::DtDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitDtDecl(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::DtDeclContext* SyGuSv21Parser::dtDecl() {
  DtDeclContext *_localctx = _tracker.createInstance<DtDeclContext>(_ctx, getState());
  enterRule(_localctx, 70, SyGuSv21Parser::RuleDtDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(381);
    match(SyGuSv21Parser::T__0);
    setState(383); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(382);
      dtConsDecl();
      setState(385); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SyGuSv21Parser::T__0);
    setState(387);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DtConsDeclContext ------------------------------------------------------------------

SyGuSv21Parser::DtConsDeclContext::DtConsDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::SymbolContext* SyGuSv21Parser::DtConsDeclContext::symbol() {
  return getRuleContext<SyGuSv21Parser::SymbolContext>(0);
}

std::vector<SyGuSv21Parser::SortedVarContext *> SyGuSv21Parser::DtConsDeclContext::sortedVar() {
  return getRuleContexts<SyGuSv21Parser::SortedVarContext>();
}

SyGuSv21Parser::SortedVarContext* SyGuSv21Parser::DtConsDeclContext::sortedVar(size_t i) {
  return getRuleContext<SyGuSv21Parser::SortedVarContext>(i);
}


size_t SyGuSv21Parser::DtConsDeclContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleDtConsDecl;
}


std::any SyGuSv21Parser::DtConsDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitDtConsDecl(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::DtConsDeclContext* SyGuSv21Parser::dtConsDecl() {
  DtConsDeclContext *_localctx = _tracker.createInstance<DtConsDeclContext>(_ctx, getState());
  enterRule(_localctx, 72, SyGuSv21Parser::RuleDtConsDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(389);
    match(SyGuSv21Parser::T__0);
    setState(390);
    symbol();
    setState(394);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SyGuSv21Parser::T__0) {
      setState(391);
      sortedVar();
      setState(396);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(397);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GrammarDefContext ------------------------------------------------------------------

SyGuSv21Parser::GrammarDefContext::GrammarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SyGuSv21Parser::SortedVarContext *> SyGuSv21Parser::GrammarDefContext::sortedVar() {
  return getRuleContexts<SyGuSv21Parser::SortedVarContext>();
}

SyGuSv21Parser::SortedVarContext* SyGuSv21Parser::GrammarDefContext::sortedVar(size_t i) {
  return getRuleContext<SyGuSv21Parser::SortedVarContext>(i);
}

std::vector<SyGuSv21Parser::GroupedRuleListContext *> SyGuSv21Parser::GrammarDefContext::groupedRuleList() {
  return getRuleContexts<SyGuSv21Parser::GroupedRuleListContext>();
}

SyGuSv21Parser::GroupedRuleListContext* SyGuSv21Parser::GrammarDefContext::groupedRuleList(size_t i) {
  return getRuleContext<SyGuSv21Parser::GroupedRuleListContext>(i);
}


size_t SyGuSv21Parser::GrammarDefContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleGrammarDef;
}


std::any SyGuSv21Parser::GrammarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitGrammarDef(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::GrammarDefContext* SyGuSv21Parser::grammarDef() {
  GrammarDefContext *_localctx = _tracker.createInstance<GrammarDefContext>(_ctx, getState());
  enterRule(_localctx, 74, SyGuSv21Parser::RuleGrammarDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(399);
    match(SyGuSv21Parser::T__0);
    setState(401); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(400);
      sortedVar();
      setState(403); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SyGuSv21Parser::T__0);
    setState(405);
    match(SyGuSv21Parser::T__2);
    setState(406);
    match(SyGuSv21Parser::T__0);
    setState(408); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(407);
      groupedRuleList();
      setState(410); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SyGuSv21Parser::T__0);
    setState(412);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GroupedRuleListContext ------------------------------------------------------------------

SyGuSv21Parser::GroupedRuleListContext::GroupedRuleListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SyGuSv21Parser::SymbolContext* SyGuSv21Parser::GroupedRuleListContext::symbol() {
  return getRuleContext<SyGuSv21Parser::SymbolContext>(0);
}

SyGuSv21Parser::SortContext* SyGuSv21Parser::GroupedRuleListContext::sort() {
  return getRuleContext<SyGuSv21Parser::SortContext>(0);
}

std::vector<SyGuSv21Parser::GTermContext *> SyGuSv21Parser::GroupedRuleListContext::gTerm() {
  return getRuleContexts<SyGuSv21Parser::GTermContext>();
}

SyGuSv21Parser::GTermContext* SyGuSv21Parser::GroupedRuleListContext::gTerm(size_t i) {
  return getRuleContext<SyGuSv21Parser::GTermContext>(i);
}


size_t SyGuSv21Parser::GroupedRuleListContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleGroupedRuleList;
}


std::any SyGuSv21Parser::GroupedRuleListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitGroupedRuleList(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::GroupedRuleListContext* SyGuSv21Parser::groupedRuleList() {
  GroupedRuleListContext *_localctx = _tracker.createInstance<GroupedRuleListContext>(_ctx, getState());
  enterRule(_localctx, 76, SyGuSv21Parser::RuleGroupedRuleList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(414);
    match(SyGuSv21Parser::T__0);
    setState(415);
    symbol();
    setState(416);
    sort();
    setState(417);
    match(SyGuSv21Parser::T__0);
    setState(419); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(418);
      gTerm();
      setState(421); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3855672672258) != 0));
    setState(423);
    match(SyGuSv21Parser::T__2);
    setState(424);
    match(SyGuSv21Parser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GTermContext ------------------------------------------------------------------

SyGuSv21Parser::GTermContext::GTermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SyGuSv21Parser::GTermContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleGTerm;
}

void SyGuSv21Parser::GTermContext::copyFrom(GTermContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VariableGTermContext ------------------------------------------------------------------

SyGuSv21Parser::SortContext* SyGuSv21Parser::VariableGTermContext::sort() {
  return getRuleContext<SyGuSv21Parser::SortContext>(0);
}

SyGuSv21Parser::VariableGTermContext::VariableGTermContext(GTermContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::VariableGTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitVariableGTerm(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstantGTermContext ------------------------------------------------------------------

SyGuSv21Parser::SortContext* SyGuSv21Parser::ConstantGTermContext::sort() {
  return getRuleContext<SyGuSv21Parser::SortContext>(0);
}

SyGuSv21Parser::ConstantGTermContext::ConstantGTermContext(GTermContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::ConstantGTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitConstantGTerm(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BfGTermContext ------------------------------------------------------------------

SyGuSv21Parser::BfTermContext* SyGuSv21Parser::BfGTermContext::bfTerm() {
  return getRuleContext<SyGuSv21Parser::BfTermContext>(0);
}

SyGuSv21Parser::BfGTermContext::BfGTermContext(GTermContext *ctx) { copyFrom(ctx); }


std::any SyGuSv21Parser::BfGTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitBfGTerm(this);
  else
    return visitor->visitChildren(this);
}
SyGuSv21Parser::GTermContext* SyGuSv21Parser::gTerm() {
  GTermContext *_localctx = _tracker.createInstance<GTermContext>(_ctx, getState());
  enterRule(_localctx, 78, SyGuSv21Parser::RuleGTerm);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(437);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<SyGuSv21Parser::ConstantGTermContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(426);
      match(SyGuSv21Parser::T__0);
      setState(427);
      match(SyGuSv21Parser::T__22);
      setState(428);
      sort();
      setState(429);
      match(SyGuSv21Parser::T__2);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SyGuSv21Parser::VariableGTermContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(431);
      match(SyGuSv21Parser::T__0);
      setState(432);
      match(SyGuSv21Parser::T__23);
      setState(433);
      sort();
      setState(434);
      match(SyGuSv21Parser::T__2);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<SyGuSv21Parser::BfGTermContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(436);
      bfTerm();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SymbolContext ------------------------------------------------------------------

SyGuSv21Parser::SymbolContext::SymbolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SyGuSv21Parser::SymbolContext::SYMBOL() {
  return getToken(SyGuSv21Parser::SYMBOL, 0);
}


size_t SyGuSv21Parser::SymbolContext::getRuleIndex() const {
  return SyGuSv21Parser::RuleSymbol;
}


std::any SyGuSv21Parser::SymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SyGuSv21Visitor*>(visitor))
    return parserVisitor->visitSymbol(this);
  else
    return visitor->visitChildren(this);
}

SyGuSv21Parser::SymbolContext* SyGuSv21Parser::symbol() {
  SymbolContext *_localctx = _tracker.createInstance<SymbolContext>(_ctx, getState());
  enterRule(_localctx, 80, SyGuSv21Parser::RuleSymbol);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(439);
    match(SyGuSv21Parser::SYMBOL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void SyGuSv21Parser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  sygusv21ParserInitialize();
#else
  ::antlr4::internal::call_once(sygusv21ParserOnceFlag, sygusv21ParserInitialize);
#endif
}

grammar SyGuSv21;

problem : (cmd)+ EOF;

// Definitions in similar order as in the language definition pdf

//
// Literals
//
literal : numeral
		| decimal
        | boolConst
        | hexConst
        | binConst
        | stringConst
        ;

numeral : NUMERAL;

decimal : numeral '.' numeral;

boolConst : TRUE                       #boolConstTrue
          | FALSE                      #boolConstFalse
          ;

hexConst : HEXCONST ;

binConst : BINCONST ;

stringConst : STRINGCONST
			| EMPTYSTRING
			;


//
// Identifiers
//
identifier : symbol                              #simpleIdentifier
		   | '(' '_ ' symbol (index)+ ')'         #indexedIdentifier
		   ;

index : numeral                         #numeralIndex
	  | symbol                          #symbolIndex
	  ;


//
// Attributes
//
// Not supported


//
// Sorts
//
sort : identifier                          #simpleSort
	 |  '(' identifier (sort)+ ')'         #parametricSort
	 ;


//
// Terms
//
// No attribute terms atm
term : identifier                                      #identifierTerm
	 | literal                                         #literalTerm
	 | '(' identifier (term)+ ')'                      #applicationTerm
	 | '(' 'exists' '(' (sortedVar)+ ')' term ')'      #existsTerm
	 | '(' 'forall' '(' (sortedVar)+ ')' term ')'      #forallTerm
	 | '(' 'let' '(' (varBinding)+ ')' term ')'        #letTerm
	 ;

// Not attribute terms atm
bfTerm : identifier                                    #bfIdentifierTerm
	 | literal                                         #bfLiteralTerm
	 | '(' identifier (bfTerm)+ ')'                    #bfApplicationTerm
	 ;


sortedVar : '(' symbol sort ')' ;

varBinding : '(' symbol term ')' ;


//
// Features
//
feature : ':' GRAMMARS_FEATURE
		| ':' FWD_DECLS_FEATURE
		| ':' RECURSION_FEATURE
		| ':' ORACLES_FEATURE
		| ':' WEIGHTS_FEATURE
		;


//
// Commands
//

// No chc-constraint, declare-weight, inv-constraint, optimize-synth, Oracle commands
cmd : assumeCmd
    | checkSynthCmd
	| constraintCmd
	| declareVarCmd
	| setFeatureCmd
	| synthFunCmd
	| smtCmd
	;

assumeCmd : '(' 'assume' term ')';
checkSynthCmd : '(' 'check-synth' ')';
constraintCmd : '(' 'constraint' term ')';
declareVarCmd : '(' 'declare-var' symbol sort ')';
setFeatureCmd : '(' 'set-feature' feature boolConst ')';
synthFunCmd : '(' 'synth-fun' symbol '(' (sortedVar)* ')' sort (grammarDef)? ')';

smtCmd : declareDatatype
	   | declareDatatypes
	   | declareSort
	   | defineFun
	   | defineSort
	   | setInfo
	   | setLogic
	   | setOption
	   ;

declareDatatype : '(' 'declare-datatype' symbol dtDecl ')';
declareDatatypes : '(' 'declare-datatypes' '(' (sortDecl)+ ')' '(' (dtDecl)+ ')' ')';
declareSort : '(' 'declare-sort' symbol numeral ')';
defineFun : '(' 'define-fun' symbol '(' (sortedVar)* ')' sort term  ')';
defineSort : '(' 'define-sort' symbol sort ')';
setInfo : '(' 'set-info' ':' symbol literal ')';
setLogic : '(' 'set-logic' symbol ')';
setOption : '(' 'set-option' ':' symbol literal ')';



sortDecl : '(' symbol numeral ')' ;
dtDecl : '(' (dtConsDecl)+ ')' ;
dtConsDecl : '(' symbol (sortedVar)* ')' ;

grammarDef : '('  (sortedVar)+ ')' '(' (groupedRuleList)+ ')' ;
groupedRuleList : '(' symbol sort '(' (gTerm)+ ')' ')' ;

gTerm : '(' 'Constant' sort ')'    #constantGTerm
	  | '(' 'Variable' sort ')'    #variableGTerm
	  | bfTerm                     #bfGTerm
	  ;





//
//   SYMBOLS
//

symbol : SYMBOL
       ; 
       //todo:reserved words

WS : ( ' ' | '\t' | '\f' | '\n' )+ -> skip ;

COMMENT
  : ';'(~('\n')*'\n') -> skip
  ;
//NUMERAL : (('1'..'9') ('0'..'9')*) ;
NUMERAL : ('0'..'9')+ ;

HEXCONST : '#x'([0-9] | [a-f] | [A-F])+ ;

BINCONST : '#b'('0' | '1')+ ;

TRUE : 'true';
FALSE : 'false';

GRAMMARS_FEATURE : 'grammars';
FWD_DECLS_FEATURE: 'fwd-decls';
RECURSION_FEATURE: 'recursion';
ORACLES_FEATURE: 'oracles';
WEIGHTS_FEATURE: 'weights';

EMPTYSTRING : '""';
STRINGCONST : '"' ((~["])|'""')+ '"';

SYMBOL : ([a-z]|[A-Z]|'_'|'+'|'-'|'*'|'&'|'|'|'!'|'~'|'='|'<'|'>'|'/'|'%'|'?'|'.'|'$'|'^')(([a-z]|[A-Z]|'_'|'+'|'-'|'*'|'&'|'|'|'!'|'~'|'='|'<'|'>'|'/'|'%'|'?'|'.'|'$'|'^') | ([0-9]))* ;


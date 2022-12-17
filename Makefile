antlr:
	antlr4 -visitor -Dlanguage=Cpp SyGuSv21.g4

rm_antlr:
	rm -rf SyGuSv21BaseListener.cpp SyGuSv21Lexer.cpp SyGuSv21Listener.cpp SyGuSv21Parser.cpp SyGuSv21Visitor.cpp SyGuSv21BaseVisitor.cpp
	rm -rf SyGuSv21BaseListener.h SyGuSv21Lexer.h SyGuSv21Listener.h SyGuSv21Parser.h SyGuSv21Visitor.h SyGuSv21BaseVisitor.h
	rm -rf SyGuSv21.interp SyGuSv21Lexer.tokens SyGuSv21Lexer.interp SyGuSv21.tokens 
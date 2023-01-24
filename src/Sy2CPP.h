//
// Created by julian on 23.01.23.
//

#ifndef SY2CPP_SY2CPP_H
#define SY2CPP_SY2CPP_H


#include <tuple>

#include "symbol_table_ast_builder.h"
#include "symbol_table.h"
#include "antlr4-runtime/antlr4-runtime.h"
#include "SyGuSv21Lexer.h"
#include "SyGuSv21Parser.h"

namespace Sy2CPP {


    static
    std::pair<std::shared_ptr<SymbolTable>, std::shared_ptr<Problem>>
    get_symbol_table_and_ast_from_file(const std::string& path) {
        std::ifstream stream;
        stream.open(path);
        if (!stream) {
            throw Sy2CPP::IOException("File " + path + " could not be opened.");
        }
        antlr4::ANTLRInputStream input{stream};
        SyGuSv21Lexer lexer{&input};
        antlr4::CommonTokenStream tokens(&lexer);
        SyGuSv21Parser parser{&tokens};
        SyGuSv21Parser::ProblemContext* parse_tree = parser.problem();
        return Sy2CPP::SymbolTableAstBuilder::build_symbol_table_and_ast(parse_tree);
    }

}


#endif //SY2CPP_SY2CPP_H

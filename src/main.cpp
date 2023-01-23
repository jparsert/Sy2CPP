#include <iostream>

#include "antlr4-runtime/antlr4-runtime.h"
#include <SyGuSv21Lexer.h>
#include <SyGuSv21Parser.h>
#include "parsing/AstPrinter.h"
#include "symbol_table.h"
#include "exceptions.h"

using namespace std;



int main(int argc, const char* argv[])
{
    //SyGuSv21Parser::ProblemContext* problem = get_parse_tree("./test/diff.sl");
    std::string path = "./test/diff.sl";
    ifstream stream;
    stream.open(path);
    if (!stream) {
        throw IOException("File " + path + " could not be opened.");
    }
    antlr4::ANTLRInputStream input{stream};
    SyGuSv21Lexer lexer{&input};
    antlr4::CommonTokenStream tokens(&lexer);
    SyGuSv21Parser parser{&tokens};
    //std::shared_ptr<to_string_printer> printer = std::make_shared<to_string_printer>();
    SyGuSv21Parser::ProblemContext* parse_tree = parser.problem();

    auto [symbol_table, ast] = SymbolTableAstBuilder::build_symbol_table_and_ast(parse_tree);
    AstToString printer;
    std::string s = printer.get_string(*ast);
    std::cout << s << std::endl;
    //std::shared_ptr<sygus_smt_rep> rep = sygus_smt_rep_builder::build_sygus_smt_repr(problem);
    return 0;
}

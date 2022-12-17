#include <iostream>

#include "antlr4-runtime/antlr4-runtime.h"
#include <SyGuSv21Lexer.h>
#include <SyGuSv21Parser.h>
#include "verification/sygus_smt_rep.h"
#include "parsing/to_string_printer.h"

using namespace std;

int main(int argc, const char* argv[])
{
    ifstream stream;
    stream.open("./test/diff.sl");

    antlr4::ANTLRInputStream input{stream};
    SyGuSv21Lexer lexer{&input};
    antlr4::CommonTokenStream tokens(&lexer);
    SyGuSv21Parser parser{&tokens};

    SyGuSv21Parser::ProblemContext* problem = parser.problem();

    std::shared_ptr<to_string_printer> printer = std::make_shared<to_string_printer>();

    std::shared_ptr<sygus_smt_rep> rep = sygus_smt_rep_builder::build_sygus_smt_repr(problem);
    std::cout << rep->get_logic() << std::endl;
    return 0;
}

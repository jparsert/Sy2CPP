#include <iostream>

#include "AstPrinter.h"
#include "exceptions.h"
#include "Sy2CPP.h"
#include <filesystem>

using namespace std;


int main(int argc, const char* argv[])
{
    //SyGuSv21Parser::ProblemContext* problem = get_parse_tree("./test/diff.sl");


    std::string path = "../cleaned_sygus_benchmarks/LIA_INV/";
    int i = 0;
    for (const auto & entry : filesystem::directory_iterator(path)) {
        if (! entry.path().string().ends_with(".sl")) {
            continue;
        }
        std::cout << entry.path() << std::endl;
        auto [ast, symbol_table] = Sy2CPP::get_ast_and_symbol_table_from_file(entry.path().string());
        Sy2CPP::AstToString printer;
        std::string s = printer.get_string(*ast);
        std::cout << s << std::endl;
        ++i;
    }

    std::cout << "Ran on " << i <<" files" << std::endl;

    //std::shared_ptr<sygus_smt_rep> rep = sygus_smt_rep_builder::build_sygus_smt_repr(problem);
    return 0;
}

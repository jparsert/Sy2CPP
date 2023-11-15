#include <iostream>

#include "AstPrinter.h"
#include "exceptions.h"
#include "Sy2CPP.h"
#include <filesystem>
#include "utils.h"

using namespace std;



int main(int argc, const char* argv[])
{
    //SyGuSv21Parser::ProblemContext* problem = get_parse_tree("./test/diff.sl");


    std::string path1 = "/home/julian/coding/cleaned_sygus_benchmarks/BV";
    std::string path2 = "/home/julian/coding/cleaned_sygus_benchmarks/LIA";

    std::vector<std::string> res = files_with_suffix_in_dirs({path1, path2}, ".sl");

    for (int i = 0; i < res.size(); ++i) {
        std::cout << i << "/" << res.size() << "\t" << res[i] << std::endl;
        auto [ast, symbol_table] = Sy2CPP::get_ast_and_symbol_table_from_file(res[i]);
        Sy2CPP::AstToString printer;
        std::string s = printer.get_string(*ast);
        //std::cout << s << std::endl;
    }

    //std::shared_ptr<sygus_smt_rep> rep = sygus_smt_rep_builder::build_sygus_smt_repr(problem);
    return 0;
}

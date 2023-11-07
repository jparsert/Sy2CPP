#include <iostream>

#include "AstPrinter.h"
#include "exceptions.h"
#include "Sy2CPP.h"
#include <filesystem>

using namespace std;


std::vector<std::string> files_with_suffix_in_dirs(const std::vector<std::string>& dirs, const std::string& suffix) {
    std::vector<std::string> res;

    for (auto& dir : dirs) {
        if (std::filesystem::is_regular_file(dir)) {
            if (dir.ends_with(suffix)) {
                res.push_back(dir);
            }
            continue;
        } else {
            for (const auto &entry: std::filesystem::recursive_directory_iterator(dir)) {
                if (entry.path().string().ends_with(suffix)) {
                    res.push_back(entry.path().string());
                }
            }
        }
    }

    return res;
}


int main(int argc, const char* argv[])
{
    //SyGuSv21Parser::ProblemContext* problem = get_parse_tree("./test/diff.sl");


    std::string path = "/home/julian/coding/cleaned_sygus_benchmarks/BV";

    std::vector<std::string> res = files_with_suffix_in_dirs({path}, ".sl");

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

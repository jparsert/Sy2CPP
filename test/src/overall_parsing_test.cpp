//
// Created by julian on 15.11.23.
//

#include <iostream>

#include <gtest/gtest.h>

#include "AstPrinter.h"
#include "Sy2CPP.h"
#include "utils.h"


TEST(SimpleParsing, ParsingSmallSet) {

    std::string path1 = "../test/small/";

    std::vector<std::string> res = files_with_suffix_in_dirs({path1}, ".sl");

    for (const auto & re : res) {
        auto [ast, symbol_table] = Sy2CPP::get_ast_and_symbol_table_from_file(re);
        Sy2CPP::AstToString printer;
        std::string s = printer.get_string(*ast);
    }

}

TEST(SimpleParsing, ParseLIATestSet) {

    std::string path1 = "../test/LIA/";

    std::vector<std::string> res = files_with_suffix_in_dirs({path1}, ".sl");

    for (const auto & re : res) {
        auto [ast, symbol_table] = Sy2CPP::get_ast_and_symbol_table_from_file(re);
        Sy2CPP::AstToString printer;
        std::string s = printer.get_string(*ast);
    }

}

TEST(SimpleParsing, ParseBVTestSet) {

    std::string path1 = "../test/BV/";

    std::vector<std::string> res = files_with_suffix_in_dirs({path1}, ".sl");

    for (const auto & re : res) {
        auto [ast, symbol_table] = Sy2CPP::get_ast_and_symbol_table_from_file(re);
        Sy2CPP::AstToString printer;
        std::string s = printer.get_string(*ast);
    }

}
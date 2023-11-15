//
// Created by julian on 15.11.23.
//

#include <iostream>

#include <gtest/gtest.h>

#include "AstPrinter.h"
#include "Sy2CPP.h"
#include "utils.h"


TEST(SimpleParsing, ParsingSmallSet) {

    auto [ast, symbol_table] = Sy2CPP::get_ast_and_symbol_table_from_file("../test/small/large.sl");
    Sy2CPP::AstToString printer;
    std::string s = printer.get_string(*ast);
}

TEST(SimpleParsing, ParseLIATestSet) {
    auto [ast, symbol_table] = Sy2CPP::get_ast_and_symbol_table_from_file("../test/LIA/inv_gen_fig8.sl");
    Sy2CPP::AstToString printer;
    std::string s = printer.get_string(*ast);

}

TEST(SimpleParsing, ParseBVTestSet) {

    auto [ast, symbol_table] = Sy2CPP::get_ast_and_symbol_table_from_file("../test/BV/avg-opt-old.eqn_sygus_iter_39_1.sl");
    Sy2CPP::AstToString printer;
    std::string s = printer.get_string(*ast);

}
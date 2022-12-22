//
// Created by julian on 15.12.22.
//

#include "SymbolTable.h"

std::unordered_map<ast::EitherIdentifier, std::shared_ptr<FunctionDeclaration>> SymbolTable::default_boolean_functions()
{
    std::unordered_map<ast::EitherIdentifier, std::shared_ptr<FunctionDeclaration>> funs;

    std::shared_ptr<ast::EitherSort> bool_sort = ast::get_simple_sort_from_str("Bool");

    std::initializer_list<std::shared_ptr<ast::EitherSort>> arg_lst{bool_sort};
    std::initializer_list<std::shared_ptr<ast::EitherSort>> arg_lst2{bool_sort, bool_sort};
    //std::initializer_list<std::shared_ptr<ast::EitherSort>> arg_lst3{bool_sort, bool_sort, bool_sort};

    // Add NOT operator
    ast::EitherIdentifier notId = ast::get_simple_id_from_str("not");
    funs.insert({notId, std::make_shared<FunctionDeclaration>(notId, arg_lst, bool_sort )});

    // Add AND operator
    ast::EitherIdentifier andOp = ast::get_simple_id_from_str("and");
    funs.insert({notId, std::make_shared<FunctionDeclaration>(andOp, arg_lst2, bool_sort )})     ;

    // Add OR operator
    ast::EitherIdentifier orOp = ast::get_simple_id_from_str("and");
    funs.insert({notId, std::make_shared<FunctionDeclaration>(orOp, arg_lst2, bool_sort )})     ;

    // Add XOR operator
    ast::EitherIdentifier xorOp = ast::get_simple_id_from_str("xor");
    funs.insert({notId, std::make_shared<FunctionDeclaration>(xorOp, arg_lst2, bool_sort )})     ;

    // Add IMPLICATION operator
    ast::EitherIdentifier impl = ast::get_simple_id_from_str("=>");
    funs.insert({notId, std::make_shared<FunctionDeclaration>(impl, arg_lst2, bool_sort )})     ;

    return funs;
}

bool SymbolTable::add_function_declaration(ast::EitherIdentifier id, std::vector<ast::SortPtr> arguments,
                                           std::shared_ptr<ast::EitherSort> sort) {
    auto decl = std::make_shared<FunctionDeclaration>(id, arguments, sort);
    auto [_, val] = function_map.insert({id, decl});
    return val;
}

bool SymbolTable::add_declared_var(std::shared_ptr<ast::DeclareVarCmd> &decl) {
    auto [_, val] = declared_vars.insert({decl->get_identifier(), decl});
    return val;
}

//
// Created by julian on 15.12.22.
//

#include "SymbolTable.h"
#include "../exceptions/UnknownSymbol.h"


ast::SortPtr SymbolTable::resolve_sort_by_string(std::string &s) {
    auto x = all_sorts.find(ast::get_simple_sort_from_str(s));
    if (x != all_sorts.end()) {
        return *x;
    } else {
        throw UnknownSymbol("Could not find sort " + s + " in symbol table.");
    }
}

ast::SortPtr SymbolTable::resolve_sort_by_string(std::string&& s) {
    auto x = all_sorts.find(ast::get_simple_sort_from_str(s));
    if (x != all_sorts.end()) {
        return *x;
    } else {
        throw UnknownSymbol("Could not find sort " + s + " in symbol table.");
    }
}

bool SymbolTable::add_declared_var(std::shared_ptr<ast::DeclareVarCmd> &decl) {
    return false;
}

bool SymbolTable::add_user_defined_fun(std::shared_ptr<ast::DefineFunCmd> &cmd) {
    ast::EitherIdentifier id(cmd->get_identifier());
    std::vector<std::shared_ptr<ast::SortedVar>> rg = cmd->get_arguments();
    std::vector<ast::SortPtr> arg_sorts;
    std::transform(rg.begin(), rg.end(), std::back_inserter(arg_sorts),
                   [](std::shared_ptr<ast::SortedVar>& x) {return x->second;});
    ast::SortPtr range_sort = cmd->get_sort();

    auto [_, val] = this->user_defined_funs
            .insert({id,std::make_shared<FunctionDescriptor>(id, arg_sorts, range_sort, false)});
    return val;
}

bool SymbolTable::add_synth_fun(std::shared_ptr<ast::SynthFunCmd> &cmd) {
    ast::EitherIdentifier id(cmd->get_identifier());
    std::vector<std::shared_ptr<ast::SortedVar>> rg = cmd->get_arguments();
    std::vector<ast::SortPtr> arg_sorts;
    std::transform(rg.begin(),rg.end(), std::back_inserter(arg_sorts),
                   [](std::shared_ptr<ast::SortedVar>& x) {return x->second;});
    ast::SortPtr range_sort = cmd->get_sort();

    auto [_, val] = this->synth_fun_funs
            .insert({id,std::make_shared<FunctionDescriptor>(id, arg_sorts, range_sort, false)});
    return val;
}

std::optional<FunDescrPtr>
SymbolTable::lookup_or_resolve_function(ast::EitherIdentifier &identifier, std::vector<ast::SortPtr>& arg_sorts) {
    for (auto& res : this->resolvers) {
        std::optional<FunDescrPtr> descr = res->lookup_or_resolve_function(identifier, arg_sorts);
        if(descr) {
            return descr;
        }
    }

    // lookup function in user defined funs
    auto el = this->user_defined_funs.find(identifier);
    if (el != this->user_defined_funs.end()) {
        return std::make_optional<FunDescrPtr>(el->second);
    }

    // lookup function in user defined funs
    el = this->synth_fun_funs.find(identifier);
    if (el != this->synth_fun_funs.end()) {
        return std::make_optional<FunDescrPtr>(el->second);
    }
    return std::nullopt;
}


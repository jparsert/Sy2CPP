//
// Created by julian on 28.12.22.
//


#include <optional>
#include "ast.h"
#include "../utils/general_utility.h"

#ifndef PHYSER_RESOLVERS_H
#define PHYSER_RESOLVERS_H


class FunctionDescriptor {

private:
    ast::EitherIdentifier id;
    std::vector<ast::SortPtr> argument_sorts;
    ast::SortPtr range_sort;

    bool chainable;

    // Maybe we need argument names, Body, etc.

public:

    FunctionDescriptor(ast::EitherIdentifier& iden,
                        std::initializer_list<ast::SortPtr>& args,
                        ast::SortPtr& range,
                        bool _chainable) : id{iden}, argument_sorts{args}, range_sort{range}, chainable{_chainable} {}

    FunctionDescriptor(ast::EitherIdentifier& iden,
                        std::vector<ast::SortPtr>& args,
                        ast::SortPtr& range,
                        bool _chainable) : id{iden}, argument_sorts{args}, range_sort{range}, chainable{_chainable} {}

    ast::SortPtr get_range_sort();
    ast::EitherIdentifier get_identifier();
    std::vector<ast::SortPtr> get_argument_sorts();
    [[nodiscard]] bool is_chainable() const {return this->chainable;}

};

using FunDescrPtr = std::shared_ptr<FunctionDescriptor>;


class AbstractResolver {

public:

    virtual std::optional<FunDescrPtr>
            lookup_or_resolve_function(ast::EitherIdentifier& identifier, std::vector<ast::SortPtr> arg_sorts) = 0;

};

class CoreResolver : public AbstractResolver {
private:

    std::unordered_multimap<ast::EitherIdentifier, FunDescrPtr> functions;

    static std::optional<FunDescrPtr>
    resolve_special_functions(ast::EitherIdentifier& identifier, std::vector<ast::SortPtr>& arg_sorts);

public:

    CoreResolver();

    static ast::SortPtr get_bool_sort() {
        return ast::get_simple_sort_from_str("Bool");
    }

    std::optional<FunDescrPtr>
    lookup_or_resolve_function(ast::EitherIdentifier& identifier, std::vector<ast::SortPtr> arg_sorts) override;

};


class LIAResolver : public AbstractResolver {
private:

    std::unordered_multimap<ast::EitherIdentifier, FunDescrPtr> functions;

    static std::optional<FunDescrPtr>
    resolve_special_functions(ast::EitherIdentifier& identifier, std::vector<ast::SortPtr>& arg_sorts);

public:

    LIAResolver();

    static ast::SortPtr get_int_sort() {
        return ast::get_simple_sort_from_str("Int");
    }

    std::optional<FunDescrPtr>
    lookup_or_resolve_function(ast::EitherIdentifier& identifier, std::vector<ast::SortPtr> arg_sorts) override;


};


class SymbolDescriptor {

private:
    std::string symbol;
    ast::SortPtr symbol_sort;

};

using SymbDescrPtr = std::shared_ptr<SymbolDescriptor>;


#endif //PHYSER_RESOLVERS_H

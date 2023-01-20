//
// Created by julian on 28.12.22.
//


#include <optional>
#include <utility>
#include "ast.h"
#include "../utils/general_utility.h"

#ifndef PHYSER_RESOLVERS_H
#define PHYSER_RESOLVERS_H


class FunctionDescriptor {

private:
    EitherIdentifier id;
    std::vector<EitherSort> argument_sorts;
    EitherSort range_sort;

    bool chainable;

    // Maybe we need argument names, Body, etc.

public:

    FunctionDescriptor(EitherIdentifier  iden,
                        const std::initializer_list<EitherSort>& args,
                        EitherSort& range,
                        bool _chainable) : id{std::move(iden)}, argument_sorts{args}, range_sort{range}, chainable{_chainable} {}

    FunctionDescriptor(EitherIdentifier  iden,
                        const std::vector<EitherSort>& args,
                        EitherSort  range,
                        bool _chainable) : id{std::move(iden)}, argument_sorts{args}, range_sort{std::move(range)}, chainable{_chainable} {}

    [[nodiscard]] EitherSort get_range_sort() const;
    [[nodiscard]] EitherIdentifier get_identifier() const;
    [[nodiscard]] std::vector<EitherSort> get_argument_sorts() const;
    [[nodiscard]] bool is_chainable() const {return this->chainable;}

};

class AbstractResolver {

public:

    [[nodiscard]] virtual std::optional<FunctionDescriptor>
    lookup_or_resolve_function(
            const EitherIdentifier& identifier,
            const std::vector<EitherSort>& arg_sorts) const = 0;

    [[nodiscard]] virtual std::optional<EitherSort> lookup_sort(const EitherSort& sort) const = 0;

};

class CoreResolver : public AbstractResolver {
private:

    std::unordered_multimap<EitherIdentifier, FunctionDescriptor> functions;

    static std::optional<FunctionDescriptor>
    resolve_special_functions(const EitherIdentifier& identifier, const std::vector<EitherSort>& arg_sorts);

public:

    CoreResolver();

    static EitherSort get_bool_sort() {
        return get_simple_sort_from_str("Bool");
    }

    std::optional<FunctionDescriptor>
    lookup_or_resolve_function(const EitherIdentifier& identifier, const std::vector<EitherSort>& arg_sorts) const override;

    std::optional<EitherSort> lookup_sort(const EitherSort& sort) const override;
};


class LIAResolver : public AbstractResolver {
private:

    std::unordered_multimap<EitherIdentifier, FunctionDescriptor> functions;

    static std::optional<FunctionDescriptor>
    resolve_special_functions(const EitherIdentifier& identifier, const std::vector<EitherSort>& arg_sorts);

public:

    LIAResolver();

    static EitherSort get_int_sort() {
        return get_simple_sort_from_str("Int");
    }

    std::optional<FunctionDescriptor>
    lookup_or_resolve_function(const EitherIdentifier& identifier, const std::vector<EitherSort>& arg_sorts) const override;

    std::optional<EitherSort> lookup_sort(const EitherSort& sort) const override;


};


enum class BinderKind {
    QUANTIFIER,
    LET,
    FUNCTION_ARGUMENT,
    SYNTH_FUN_ARGUMENT,
    DECLARE_VAR,
    GRAMMAR_NON_TERMINAL,
};


class SymbolDescriptor {

private:
    EitherIdentifier symbol;
    EitherSort symbol_sort;
    BinderKind binder;

public:

    SymbolDescriptor(EitherIdentifier  symb, EitherSort  sort, const BinderKind bind):
        symbol{std::move(symb)}, symbol_sort{std::move(sort)}, binder{bind} {}

    SymbolDescriptor(const EitherIdentifier&& symb, const EitherSort&& sort, const BinderKind bind):
            symbol{symb}, symbol_sort{sort}, binder{bind} {}


    [[nodiscard]] const EitherIdentifier& get_identifier() const;
    [[nodiscard]] const EitherSort &get_symbol_sort() const;
    [[nodiscard]] BinderKind get_binder() const;

};




#endif //PHYSER_RESOLVERS_H

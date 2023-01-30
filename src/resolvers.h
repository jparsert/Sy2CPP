//
// Created by julian on 28.12.22.
//

#ifndef PHYSER_RESOLVERS_H
#define PHYSER_RESOLVERS_H


#include <optional>
#include <utility>
#include "ast.h"



namespace Sy2CPP {

    enum class FunctionKind {
        THEORY,
        SYNTH_FUN,
        USER_DEFINED,
        // Constructor, selector, uninterpreted, etc.
    };

    constexpr const char* to_string(FunctionKind en){
        switch (en) {
            case FunctionKind::THEORY: return "THEORY";
            case FunctionKind::SYNTH_FUN: return "SYNTH_FUN";
            case FunctionKind::USER_DEFINED: return "USER_DEFINED";
            default: throw std::invalid_argument("Unimplemented item");
        }
    }

    class FunctionDescriptor {

    private:
        EitherIdentifier id;
        std::vector<EitherSort> argument_sorts;
        EitherSort range_sort;

        FunctionKind function_kind;

    private:

        bool chainable;

        // Maybe we need argument names, Body, etc.

    public:

        FunctionDescriptor(EitherIdentifier iden,
                           const std::initializer_list<EitherSort> &args,
                           EitherSort &range,
                           const FunctionKind &kind,
                           bool _chainable = false) : id{std::move(iden)}, argument_sorts{args}, range_sort{range},
                                              function_kind{kind}, chainable{_chainable} {}

        FunctionDescriptor(EitherIdentifier iden,
                           const std::vector<EitherSort> &args,
                           EitherSort range,
                           const FunctionKind &kind,
                           bool _chainable = false) : id{std::move(iden)}, argument_sorts{args}, range_sort{std::move(range)},
                                              function_kind{kind}, chainable{_chainable} {}

        [[nodiscard]] EitherSort get_range_sort() const;

        [[nodiscard]] EitherIdentifier get_identifier() const;

        [[nodiscard]] std::vector<EitherSort> get_argument_sorts() const;

        [[nodiscard]] bool is_chainable() const { return this->chainable; }

        [[nodiscard]] FunctionKind get_function_kind() const;

        void set_function_kind(FunctionKind functionKind);

        explicit operator std::string() const;

    };

    bool operator==(const FunctionDescriptor& lhs, const FunctionDescriptor& rhs);

    enum class SortKind {
        PRIMITIVE,
        UNINTERPRETED,
        USER_DEFINED    // Also known as Alias
    };

    class SortDescriptor {
    private:
        EitherSort sort;
        SortKind sort_kind;

    public:
        SortDescriptor(EitherSort srt,
                       const SortKind &sortKind) : sort{std::move(srt)}, sort_kind{sortKind} {}

        [[nodiscard]] const EitherSort &get_sort() const;

        void set_sort(const EitherSort &srt);

        [[nodiscard]] SortKind get_sort_kind() const;

        void set_sort_kind(SortKind sortKind);

    };

    class AbstractResolver {
    public:
        [[nodiscard]] virtual std::optional<FunctionDescriptor>
        lookup_or_resolve_function(
                const EitherIdentifier &identifier,
                const std::vector<EitherSort> &arg_sorts) const = 0;

        [[nodiscard]] virtual std::optional<SortDescriptor>
        lookup_or_resolve_sort(const EitherSort &sort) const = 0;

    };

    class CoreResolver : public AbstractResolver {
    private:
        std::unordered_multimap<EitherIdentifier, FunctionDescriptor> functions;
        static std::optional<FunctionDescriptor>

        resolve_special_functions(const EitherIdentifier &identifier, const std::vector<EitherSort> &arg_sorts);

    public:
        CoreResolver();

        static EitherSort get_bool_sort() {
            return get_simple_sort_from_str("Bool");
        }

        std::optional<FunctionDescriptor>
        lookup_or_resolve_function(const EitherIdentifier &identifier,
                                   const std::vector<EitherSort> &arg_sorts) const override;

        std::optional<SortDescriptor> lookup_or_resolve_sort(const EitherSort &sort) const override;
    };


    class LIAResolver : public AbstractResolver {
    private:
        std::unordered_multimap<EitherIdentifier, FunctionDescriptor> functions;

        static std::optional<FunctionDescriptor>
        resolve_special_functions(const EitherIdentifier &identifier, const std::vector<EitherSort> &arg_sorts);

    public:
        LIAResolver();

        static EitherSort get_int_sort();

        std::optional<FunctionDescriptor>
        lookup_or_resolve_function(const EitherIdentifier &identifier,
                                   const std::vector<EitherSort> &arg_sorts) const override;

        std::optional<SortDescriptor> lookup_or_resolve_sort(const EitherSort &sort) const override;


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
        SymbolDescriptor(EitherIdentifier symb, EitherSort sort, const BinderKind bind) :
                symbol{std::move(symb)}, symbol_sort{std::move(sort)}, binder{bind} {}

        SymbolDescriptor(const EitherIdentifier &&symb, const EitherSort &&sort, const BinderKind bind) :
                symbol{symb}, symbol_sort{sort}, binder{bind} {}

        [[nodiscard]] const EitherIdentifier &get_identifier() const;

        [[nodiscard]] const EitherSort &get_symbol_sort() const;

        [[nodiscard]] BinderKind get_binder() const;

        bool operator==(const SymbolDescriptor& desc) const;

        bool operator!=(const SymbolDescriptor& desc) const;


    };

}

namespace std {

    template<>  struct hash<Sy2CPP::SortDescriptor> {
        std::size_t operator()(const Sy2CPP::SortDescriptor& sd);
    };

    template<>
    struct hash<Sy2CPP::FunctionDescriptor> {
        std::size_t operator()(const Sy2CPP::FunctionDescriptor &fd) const;
    };

    template<>
    struct hash<Sy2CPP::FunctionDescriptor&> {
        std::size_t operator()(const Sy2CPP::FunctionDescriptor &fd) const;
    };

    template<>
    struct hash<Sy2CPP::SymbolDescriptor> {
        std::size_t operator()(const Sy2CPP::SymbolDescriptor &symbD);
    };

}



#endif //PHYSER_RESOLVERS_H

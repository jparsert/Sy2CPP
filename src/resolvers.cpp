//
// Created by julian on 28.12.22.
//

#include <optional>

#include "resolvers.h"
#include "exceptions.h"
#include "general_utility.h"



namespace Sy2CPP {

    EitherSort FunctionDescriptor::get_range_sort() const {
        return this->range_sort;
    }

    std::vector<EitherSort> FunctionDescriptor::get_argument_sorts() const {
        return this->argument_sorts;
    }

    EitherIdentifier FunctionDescriptor::get_identifier() const {
        return this->id;
    }

    FunctionKind FunctionDescriptor::get_function_kind() const {
        return function_kind;
    }

    void FunctionDescriptor::set_function_kind(FunctionKind functionKind) {
        function_kind = functionKind;
    }

    std::optional<FunctionDescriptor>
    CoreResolver::lookup_or_resolve_function(const EitherIdentifier &identifier,
                                             const std::vector<EitherSort> &arg_sorts) const {
        std::optional<FunctionDescriptor> special = CoreResolver::resolve_special_functions(identifier, arg_sorts);


        if (special.has_value()) {
            return special;
        }

        // get all elements with same id
        auto range = this->functions.equal_range(identifier);

        for (auto i = range.first; i != range.second; ++i) {
            const FunctionDescriptor &desc = i->second;
            if (desc.is_chainable()) {
                // check if all arg_sorts are equal
                if (all_elements_equal(arg_sorts)) {
                    if (arg_sorts[0] == desc.get_argument_sorts()[0]) {
                        return std::make_optional<FunctionDescriptor>(i->second);
                    }
                }
            } else { // same identifier (through map)
                if (desc.get_argument_sorts() == arg_sorts) {
                    return std::make_optional<FunctionDescriptor>(i->second);
                }
            }
        }

        return std::nullopt;
    }


    std::optional<FunctionDescriptor>
    CoreResolver::resolve_special_functions(const EitherIdentifier &identifier,
                                            const std::vector<EitherSort> &arg_sorts) {
        if (identifier.index() == 0) { // It is an SimpleIdentifier
            SimpleIdentifier id = std::get<0>(identifier);
            EitherSort bool_sort = CoreResolver::get_bool_sort();

            if (id.get_symbol() == "=" or id.get_symbol() == "distinct") {
                if (arg_sorts.size() < 2) {
                    throw WrongArguments("Less than 2 arguments for function " + id.get_symbol());
                }
                std::initializer_list<EitherSort> arg_lst1{bool_sort};

                if (all_elements_equal(arg_sorts)) {
                    //all are the same sort
                    return std::make_optional<FunctionDescriptor>(identifier, arg_lst1, bool_sort, FunctionKind::THEORY, true);
                }
            } else if (id.get_symbol() == "ite") {
                if (arg_sorts.size() != 3 or arg_sorts[0] != bool_sort or arg_sorts[1] != arg_sorts[2]) {
                    throw WrongArguments("Something went wrong with the types of ITE.");
                }
                return std::make_optional<FunctionDescriptor>(identifier, arg_sorts, arg_sorts[1], FunctionKind::THEORY, false);
            }
        }

        return std::nullopt;
    }

    CoreResolver::CoreResolver() {

        EitherSort bool_sort = CoreResolver::get_bool_sort();
        std::initializer_list<EitherSort> arg_lst1{bool_sort};
        std::initializer_list<EitherSort> arg_lst2{bool_sort, bool_sort};

        // Add NOT operator
        EitherIdentifier notId = get_simple_id_from_str("not");
        functions.emplace(notId, FunctionDescriptor(notId, arg_lst1, bool_sort, FunctionKind::THEORY,false));

        // Add => operator
        EitherIdentifier implId = get_simple_id_from_str("=>");
        functions.emplace(implId, FunctionDescriptor(implId, arg_lst2, bool_sort, FunctionKind::THEORY, false));

        // Add and operator
        EitherIdentifier andId = get_simple_id_from_str("and");
        functions.emplace(andId, FunctionDescriptor(andId, arg_lst1, bool_sort, FunctionKind::THEORY, true));

        // Add or operator
        EitherIdentifier orId = get_simple_id_from_str("or");
        functions.emplace(orId, FunctionDescriptor(orId, arg_lst1, bool_sort, FunctionKind::THEORY, true));

        // Add xor operator
        EitherIdentifier xorId = get_simple_id_from_str("xor");
        functions.emplace(xorId, FunctionDescriptor(xorId, arg_lst1, bool_sort, FunctionKind::THEORY, true));

    }

    std::optional<SortDescriptor> CoreResolver::lookup_or_resolve_sort(const EitherSort &sort) const {
        return sort == CoreResolver::get_bool_sort() ? std::make_optional<SortDescriptor>(CoreResolver::get_bool_sort(), SortKind::PRIMITIVE) : std::nullopt;
    }


    std::optional<FunctionDescriptor>
    LIAResolver::lookup_or_resolve_function(const EitherIdentifier &identifier,
                                            const std::vector<EitherSort> &arg_sorts) const {
        std::optional<FunctionDescriptor> special = LIAResolver::resolve_special_functions(identifier, arg_sorts);
        if (special.has_value()) {
            return special;
        }

        // get all elements with same id
        auto range = this->functions.equal_range(identifier);

        for (auto i = range.first; i != range.second; ++i) {
            const FunctionDescriptor &desc = i->second;
            if (desc.is_chainable()) {
                // check if all arg_sorts are equal
                if (all_elements_equal(arg_sorts)) {
                    if (arg_sorts[0] == desc.get_argument_sorts()[0]) {
                        return std::make_optional<FunctionDescriptor>(desc);
                    }
                }
            } else { // same identifier (through map)
                if (desc.get_argument_sorts() == arg_sorts) {
                    return std::make_optional<FunctionDescriptor>(desc);
                }
            }
        }

        return std::nullopt;

    }

    std::optional<FunctionDescriptor>
    LIAResolver::resolve_special_functions(const EitherIdentifier &identifier,
                                           const std::vector<EitherSort> &arg_sorts) {
        if (identifier.index() == 0) {
            SimpleIdentifier id = std::get<0>(identifier);

            EitherSort int_sort = LIAResolver::get_int_sort();
            std::initializer_list<EitherSort> arg_lst1{int_sort};

            if (id.get_symbol() == "-" and arg_sorts.size() == 1 and arg_sorts[0] == LIAResolver::get_int_sort()) {
                EitherIdentifier uminus = get_simple_id_from_str("-");
                return std::make_optional<FunctionDescriptor>(uminus, arg_lst1, int_sort, FunctionKind::THEORY, false);

            } else if (id.get_symbol() == "-" and
                       arg_sorts.size() > 1 and
                       all_elements_equal(arg_sorts) and
                       arg_sorts[0] == LIAResolver::get_int_sort()) {

                EitherIdentifier minus = get_simple_id_from_str("-");
                return std::make_optional<FunctionDescriptor>(minus, arg_lst1, int_sort, FunctionKind::THEORY, true);

            }
        }
        return std::nullopt;
    }

    LIAResolver::LIAResolver() {
        EitherSort bool_sort = CoreResolver::get_bool_sort();
        EitherSort int_sort = LIAResolver::get_int_sort();
        std::initializer_list<EitherSort> arg_lst1{int_sort};
        std::initializer_list<EitherSort> arg_lst2{int_sort, int_sort};

        // Add unary - operator
        EitherIdentifier uminus = get_simple_id_from_str("-");
        functions.emplace(uminus, FunctionDescriptor(uminus, arg_lst1, int_sort, FunctionKind::THEORY, false));

        // Add multi - operator
        EitherIdentifier minus = get_simple_id_from_str("-");
        functions.emplace(minus, FunctionDescriptor(minus, arg_lst1, int_sort, FunctionKind::THEORY, true));

        // Add abs operator
        EitherIdentifier abs = get_simple_id_from_str("abs");
        functions.emplace(abs, FunctionDescriptor(abs, arg_lst1, int_sort, FunctionKind::THEORY, false));

        // Add mod  operator
        EitherIdentifier mod = get_simple_id_from_str("mod");
        functions.emplace(mod, FunctionDescriptor(mod, arg_lst2, int_sort, FunctionKind::THEORY, false));

        // Add + operator
        EitherIdentifier plus = get_simple_id_from_str("+");
        functions.emplace(plus, FunctionDescriptor(plus, arg_lst1, int_sort, FunctionKind::THEORY, true));

        // Add * operator
        EitherIdentifier times = get_simple_id_from_str("*");
        functions.emplace(times, FunctionDescriptor(times, arg_lst1, int_sort, FunctionKind::THEORY, true));

        // Add div operator
        EitherIdentifier div = get_simple_id_from_str("div");
        functions.emplace(div, FunctionDescriptor(div, arg_lst1, int_sort, FunctionKind::THEORY, true));

        // Add div operator
        EitherIdentifier less = get_simple_id_from_str("<");
        functions.emplace(less, FunctionDescriptor(less, arg_lst1, bool_sort, FunctionKind::THEORY, true));

        // Add div operator
        EitherIdentifier leq = get_simple_id_from_str("<=");
        functions.emplace(leq, FunctionDescriptor(leq, arg_lst1, bool_sort, FunctionKind::THEORY, true));

        // Add div operator
        EitherIdentifier ge = get_simple_id_from_str(">");
        functions.emplace(ge, FunctionDescriptor(ge, arg_lst1, bool_sort, FunctionKind::THEORY, true));

        // Add div operator
        EitherIdentifier geq = get_simple_id_from_str(">=");
        functions.emplace(geq, FunctionDescriptor(geq, arg_lst1, bool_sort, FunctionKind::THEORY, true));

    }

    std::optional<SortDescriptor> LIAResolver::lookup_or_resolve_sort(const EitherSort &sort) const {
        return sort == LIAResolver::get_int_sort() ?
        std::make_optional<SortDescriptor>(LIAResolver::get_int_sort(), SortKind::PRIMITIVE) : std::nullopt;
    }

    EitherSort LIAResolver::get_int_sort()  {
        return get_simple_sort_from_str("Int");
    }

    const EitherIdentifier &SymbolDescriptor::get_identifier() const {
        return symbol;
    }


    const EitherSort &SymbolDescriptor::get_symbol_sort() const {
        return symbol_sort;
    }


    BinderKind SymbolDescriptor::get_binder() const {
        return binder;
    }

    const EitherSort &SortDescriptor::get_sort() const {
        return sort;
    }

    void SortDescriptor::set_sort(const EitherSort &srt) {
        this->sort = srt;
    }

    SortKind SortDescriptor::get_sort_kind() const {
        return sort_kind;
    }

    void SortDescriptor::set_sort_kind(SortKind sortKind) {
        sort_kind = sortKind;
    }
}
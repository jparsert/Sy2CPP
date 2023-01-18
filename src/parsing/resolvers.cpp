//
// Created by julian on 28.12.22.
//

#include "resolvers.h"
#include <optional>
#include "../exceptions/wrong_arguments.h"

ast::SortPtr FunctionDescriptor::get_range_sort() {
    return this->range_sort;
}

std::vector<ast::SortPtr> FunctionDescriptor::get_argument_sorts() {
    return this->argument_sorts;
}

ast::EitherIdentifier FunctionDescriptor::get_identifier() {
    return this->id;
}


std::optional<FunDescrPtr>
CoreResolver::lookup_or_resolve_function(ast::EitherIdentifier &identifier, std::vector<ast::SortPtr> arg_sorts) {
    std::optional<FunDescrPtr> special = CoreResolver::resolve_special_functions(identifier, arg_sorts);
    if (special.has_value()) {
        return special;
    }

    // get all elements with same id
    auto range = this->functions.equal_range(identifier);

    for (auto i = range.first; i != range.second; ++i) {
        FunDescrPtr desc = i->second;
        if (desc->is_chainable()) {
            // check if all arg_sorts are equal
            if (all_shared_ptr_elements_equal(arg_sorts)){
                if (arg_sorts[0] == desc->get_argument_sorts()[0]) {
                    return std::make_optional<FunDescrPtr>(desc);
                }
            }
        } else { // same identifier (through map)
            if (equal_shared_ptr_vectors(desc->get_argument_sorts(), arg_sorts)) {
                return std::make_optional<FunDescrPtr>(desc);
            }
        }
    }

    return std::nullopt;
}


std::optional<FunDescrPtr>
CoreResolver::resolve_special_functions(ast::EitherIdentifier &identifier, std::vector<ast::SortPtr>& arg_sorts) {
    if (identifier.index() == 0) { // It is an ast::SimpleIdentifier
        ast::SimpleIdentifier id = std::get<0>(identifier);
        ast::SortPtr bool_sort = CoreResolver::get_bool_sort();

        if (id.get_symbol() == "=" or id.get_symbol() == "distinct") {
            if (arg_sorts.size() < 2) {
                throw WrongArguments("Less than 2 arguments for function " + id.get_symbol());
            }
            std::initializer_list<ast::SortPtr> arg_lst1{bool_sort};

            if (all_shared_ptr_elements_equal(arg_sorts)){
                //all are the same sort
                return std::make_optional<FunDescrPtr>(
                        std::make_shared<FunctionDescriptor>(identifier, arg_lst1, bool_sort, true));
            }
        } else if (id.get_symbol() == "ite") {
            if (arg_sorts.size() != 3 or arg_sorts[0] != bool_sort or arg_sorts[1] != arg_sorts[2]) {
                throw WrongArguments("Something went wrong with the types of ITE.");
            }
            return std::make_optional<FunDescrPtr>(
                    std::make_shared<FunctionDescriptor>(identifier, arg_sorts, bool_sort, false));
        }
    }

    return std::nullopt;
}

CoreResolver::CoreResolver()
{

    ast::SortPtr bool_sort = CoreResolver::get_bool_sort();
    std::initializer_list<ast::SortPtr> arg_lst1{bool_sort};
    std::initializer_list<ast::SortPtr> arg_lst2{bool_sort, bool_sort};

    // Add NOT operator
    ast::EitherIdentifier notId = ast::get_simple_id_from_str("not");
    functions.insert({notId, std::make_shared<FunctionDescriptor>(notId, arg_lst1, bool_sort, false)});

    // Add => operator
    ast::EitherIdentifier implId = ast::get_simple_id_from_str("=>");
    functions.insert({notId, std::make_shared<FunctionDescriptor>(implId, arg_lst2, bool_sort, false)});

    // Add and operator
    ast::EitherIdentifier andId = ast::get_simple_id_from_str("and");
    functions.insert({notId, std::make_shared<FunctionDescriptor>(andId, arg_lst1, bool_sort, true)});

    // Add or operator
    ast::EitherIdentifier orId = ast::get_simple_id_from_str("or");
    functions.insert({notId, std::make_shared<FunctionDescriptor>(orId, arg_lst1, bool_sort, true)});

    // Add xor operator
    ast::EitherIdentifier xorId = ast::get_simple_id_from_str("xor");
    functions.insert({notId, std::make_shared<FunctionDescriptor>(xorId, arg_lst1, bool_sort, true)});

}



std::optional<FunDescrPtr>
LIAResolver::lookup_or_resolve_function(ast::EitherIdentifier &identifier, std::vector<ast::SortPtr> arg_sorts) {
    std::optional<FunDescrPtr> special = LIAResolver::resolve_special_functions(identifier, arg_sorts);
    if (special.has_value()) {
        return special;
    }

    // get all elements with same id
    auto range = this->functions.equal_range(identifier);

    for (auto i = range.first; i != range.second; ++i) {
        FunDescrPtr desc = i->second;
        if (desc->is_chainable()) {
            // check if all arg_sorts are equal
            if (all_shared_ptr_elements_equal(arg_sorts)){
                if (arg_sorts[0] == desc->get_argument_sorts()[0]) {
                    return std::make_optional<FunDescrPtr>(desc);
                }
            }
        } else { // same identifier (through map)
            if (equal_shared_ptr_vectors(desc->get_argument_sorts(), arg_sorts)) {
                return std::make_optional<FunDescrPtr>(desc);
            }
        }
    }

    return std::nullopt;

}

std::optional<FunDescrPtr>
LIAResolver::resolve_special_functions(ast::EitherIdentifier &identifier, std::vector<ast::SortPtr> &arg_sorts) {
    if (identifier.index() == 0) {
        ast::SimpleIdentifier id = std::get<0>(identifier);

        ast::SortPtr int_sort = LIAResolver::get_int_sort();
        std::initializer_list<ast::SortPtr> arg_lst1{int_sort};

        if (id.get_symbol() == "-" and arg_sorts.size() == 1 and arg_sorts[0] == LIAResolver::get_int_sort()) {
            ast::EitherIdentifier uminus = ast::get_simple_id_from_str("-");
            return std::make_optional<FunDescrPtr>(
                    std::make_shared<FunctionDescriptor>(uminus, arg_lst1, int_sort, false));

        } else if (id.get_symbol() == "-" and
                   arg_sorts.size() > 1 and
                   all_shared_ptr_elements_equal(arg_sorts) and
                   arg_sorts[0] == LIAResolver::get_int_sort()) {

            ast::EitherIdentifier minus = ast::get_simple_id_from_str("-");
            return std::make_optional<FunDescrPtr>(
                    std::make_shared<FunctionDescriptor>(minus, arg_lst1, int_sort, true));

        }
    }
    return std::nullopt;
}

LIAResolver::LIAResolver()
{
    ast::SortPtr bool_sort = CoreResolver::get_bool_sort();
    ast::SortPtr int_sort = LIAResolver::get_int_sort();
    std::initializer_list<ast::SortPtr> arg_lst1{int_sort};
    std::initializer_list<ast::SortPtr> arg_lst2{int_sort, int_sort};

    // Add unary - operator
    ast::EitherIdentifier uminus = ast::get_simple_id_from_str("-");
    functions.insert({uminus, std::make_shared<FunctionDescriptor>(uminus, arg_lst1, int_sort, false)});

    // Add multi - operator
    ast::EitherIdentifier minus = ast::get_simple_id_from_str("-");
    functions.insert({minus, std::make_shared<FunctionDescriptor>(minus, arg_lst1, int_sort, true)});

    // Add abs operator
    ast::EitherIdentifier abs = ast::get_simple_id_from_str("abs");
    functions.insert({abs, std::make_shared<FunctionDescriptor>(abs, arg_lst1, int_sort, false)});

    // Add mod  operator
    ast::EitherIdentifier mod = ast::get_simple_id_from_str("mod");
    functions.insert({mod, std::make_shared<FunctionDescriptor>(mod, arg_lst2, int_sort, false)});

    // Add + operator
    ast::EitherIdentifier plus = ast::get_simple_id_from_str("+");
    functions.insert({plus, std::make_shared<FunctionDescriptor>(plus, arg_lst1, int_sort, true)});

    // Add * operator
    ast::EitherIdentifier times = ast::get_simple_id_from_str("*");
    functions.insert({times, std::make_shared<FunctionDescriptor>(times, arg_lst1, int_sort, true)});

    // Add div operator
    ast::EitherIdentifier div = ast::get_simple_id_from_str("div");
    functions.insert({div, std::make_shared<FunctionDescriptor>(div, arg_lst1, int_sort, true)});

    // Add div operator
    ast::EitherIdentifier less = ast::get_simple_id_from_str("<");
    functions.insert({less, std::make_shared<FunctionDescriptor>(less, arg_lst1, bool_sort, true)});

    // Add div operator
    ast::EitherIdentifier leq = ast::get_simple_id_from_str("<=");
    functions.insert({leq, std::make_shared<FunctionDescriptor>(leq, arg_lst1, bool_sort, true)});

    // Add div operator
    ast::EitherIdentifier ge = ast::get_simple_id_from_str(">");
    functions.insert({ge, std::make_shared<FunctionDescriptor>(ge, arg_lst1, bool_sort, true)});

    // Add div operator
    ast::EitherIdentifier geq = ast::get_simple_id_from_str(">=");
    functions.insert({geq, std::make_shared<FunctionDescriptor>(geq, arg_lst1, bool_sort, true)});

}

//
// Created by julian on 15.12.22.
//
#include <ranges>
#include "symbol_table.h"
#include "exceptions.h"
#include "typing.h"

namespace Sy2CPP {

    bool SymbolTable::add_user_defined_fun(DefineFunCmd &cmd) {
        EitherIdentifier id(cmd.get_identifier());
        std::vector<SortedVar> &rg = cmd.get_arguments();
        std::vector<EitherSort> arg_sorts;
        std::transform(rg.begin(), rg.end(), std::back_inserter(arg_sorts),
                       [](SortedVar &x) { return x.second; });
        EitherSort range_sort = cmd.get_sort();

        auto [_, val] = this->user_defined_funs
                .emplace(id, FunctionDescriptor(id, arg_sorts, range_sort,
                                                FunctionKind::USER_DEFINED, false));
        return val;
    }

    bool SymbolTable::add_synth_fun(const EitherIdentifier &id, const std::vector<SortedVar> &arguments,
                                    const EitherSort &range_sort) {
        std::vector<EitherSort> arg_sorts;
        std::transform(arguments.begin(), arguments.end(), std::back_inserter(arg_sorts),
                       [](const SortedVar &x) { return x.second; });

        auto [_, val] = this->synth_fun_funs
                .emplace(id, FunctionDescriptor(id, arg_sorts, range_sort,
                                                FunctionKind::SYNTH_FUN, false));
        return val;
    }

    std::optional<FunctionDescriptor>
    SymbolTable::lookup_or_resolve_function(const EitherIdentifier &identifier,
                                            const std::vector<EitherSort> &arg_sorts) const {
        for (auto &res: this->resolvers) {
            std::optional<FunctionDescriptor> descr = res->lookup_or_resolve_function(identifier, arg_sorts);
            if (descr) {
                return descr;
            }
        }

        // lookup function in user defined funs
        auto el = this->user_defined_funs.find(identifier);
        if (el != this->user_defined_funs.end()) {
            return std::make_optional<FunctionDescriptor>(el->second);
        }

        // lookup function in user defined funs
        el = this->synth_fun_funs.find(identifier);
        if (el != this->synth_fun_funs.end()) {
            return std::make_optional<FunctionDescriptor>(el->second);
        }
        return std::nullopt;
    }

    std::optional<SortDescriptor> SymbolTable::lookup_sort(const EitherSort &sort) const {
        for (auto &res: this->resolvers) {
            std::optional<SortDescriptor> descr = res->lookup_or_resolve_sort(sort);
            if (descr) {
                return descr;
            }
        }

        auto el = this->sorts.find(sort);
        if (el != this->sorts.end()) {
            return std::make_optional<SortDescriptor>(el->second);
        }

        return std::nullopt;
    }

    void SymbolTable::add_resolver(const std::shared_ptr<AbstractResolver> &ptr) {
        resolvers.push_back(ptr);
    }

    std::optional<SymbolDescriptor> SymbolTable::resolve_symbol_descriptor(const EitherIdentifier &identifier) const {
        for (auto &i: std::views::reverse(this->symbol_stack)) {
            if (i.get_identifier() == identifier) {
                return std::make_optional<SymbolDescriptor>(i);
            }
        }
        return std::nullopt;
    }

    SymbolDescriptor SymbolTable::pop_symbol_stack() {
        SymbolDescriptor res(this->symbol_stack.back());
        this->symbol_stack.pop_back();
        return res;
    }

    void SymbolTable::push_symbol_stack(const SymbolDescriptor &descr) {
        this->symbol_stack.push_back(descr);
    }

    std::vector<SymbolDescriptor> SymbolTable::pop_symbol_stack(std::size_t n) {
        std::vector<SymbolDescriptor> res;
        for (int i = 0; i < n; ++i) {
            res.push_back(this->pop_symbol_stack());
        }
        return res;
    }

}
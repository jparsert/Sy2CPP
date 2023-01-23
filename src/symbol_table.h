//
// Created by julian on 15.12.22.
//

#ifndef PHYSER_SYMBOLTABLE_H
#define PHYSER_SYMBOLTABLE_H

#include <variant>
#include <vector>
#include <iostream>
#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>

#include "SyGuSv21BaseVisitor.h"
#include "exceptions.h"

#include "ast.h"
#include "resolvers.h"

namespace Sy2CPP {

    class SymbolTable {

    private:

        // Mapping identifiers to theory functions
        std::unordered_map<EitherIdentifier, FunctionDescriptor> user_defined_funs;

        // Mapping identifiers to Synthesis functions
        std::unordered_map<EitherIdentifier, FunctionDescriptor> synth_fun_funs;

        // We will need to add Data type functions Constructor/Selector and Tester

        // Theory Resolvers
        std::vector<std::shared_ptr<AbstractResolver>> resolvers;

        // A set containing all present sorts
        std::vector<SymbolDescriptor> symbol_stack;

        //map for defined sorts (note that declared sorts are not here)
        std::unordered_map<EitherSort, SortDescriptor> sorts;

    public:

        // adding bool sorts and default boolean functions
        SymbolTable() {
            this->add_resolver(std::make_shared<CoreResolver>());
        }

        void add_resolver(const std::shared_ptr<AbstractResolver> &ptr);

        bool
        add_synth_fun(const EitherIdentifier &id, const std::vector<SortedVar> &arguments,
                      const EitherSort &range_sort);

        bool add_user_defined_fun(DefineFunCmd &defineFunCmd);

        std::optional<FunctionDescriptor> lookup_or_resolve_function(const EitherIdentifier &identifier,
                                                                     const std::vector<EitherSort> &arg_sorts) const;

        std::optional<SortDescriptor> lookup_sort(const EitherSort &sort) const;

        void push_symbol_stack(const SymbolDescriptor &descr);

        SymbolDescriptor pop_symbol_stack();

        std::vector<SymbolDescriptor> pop_symbol_stack(std::size_t n);

        /**
         * We search the stack for the symbol descriptor that id refers to. By traversing the stack "correctly" we take
         * care of shadowing etc.
         * */
        std::optional<SymbolDescriptor> resolve_symbol_descriptor(const EitherIdentifier &identifier) const;

    };

} // namespace Sy2CPP

#endif //PHYSER_SYMBOLTABLE_H

//
// Created by julian on 18.01.23.
//

#ifndef PHYSER_TYPING_H
#define PHYSER_TYPING_H

#include "parsing/ast.h"
#include "parsing/SymbolTable.h"
#include "parsing/resolvers.h"
#include "exceptions/not_implemented.h"
#include "exceptions/typing_error.h"




class TypeInference : public TermVisitor {
private:

    SymbolTable& table;

public:

    explicit TypeInference(SymbolTable& symbol_tab): table{symbol_tab} {

    }

    std::any visitNumeral(Numeral& numeral) override {
        if (this->table.lookup_sort(LIAResolver::get_int_sort()))  {
            return LIAResolver::get_int_sort();
        } else {
            throw TypingError("LIAResolver is not activated. But we found a numeral.");
        }
    }

    std::any visitDecimal(Decimal& decimal) override {
        throw not_implemented("Typing for decimals is not implemented.");
    }

    std::any visitBoolConst(BoolConst& boolConst) override {
        return CoreResolver::get_bool_sort();
    }

    std::any visitHexConst(HexConst& hex) override {
        throw not_implemented("Typing for hex consts is not implemented.");
    }

    std::any visitBinConst(BinConst& bin) override {
        throw not_implemented("Typing for bin consts is not implemented.");

    }

    std::any visitStringConst(StringConst& s) override{
        throw not_implemented("Typing for string consts is not implemented.");

    }

    std::any visitIdentifierTerm(IdentifierTerm& term) override {
        auto opt = table.resolve_symbol_descriptor(term.get_identifier());
        if (opt.has_value()) {
            return opt->get_symbol_sort();
        } else {
            throw TypingError("Could not infer type of identifier: " + to_string(term.get_identifier())); //TODO string of identifier
        }
    }

    std::any visitApplicationTerm(ApplicationTerm& application) override {
        std::vector<EitherSort> arg_sorts;
        for (const TermPtr& ptr : application.get_arguments()) {
            auto sort = std::any_cast<EitherSort>(ptr->accept(*this));
            arg_sorts.push_back(sort);
        }

        std::optional<FunctionDescriptor> descr =
                table.lookup_or_resolve_function(application.get_identifier(), arg_sorts);

        if (descr.has_value()) {
            return descr->get_range_sort();
        }

        throw TypingError("Could not lookup or resolve function while typing: " + to_string(application.get_identifier()));
    }

    std::any visitExistsTerm(ExistsTerm& exists) override {
        for (SortedVar& var : exists.get_vars()) {
            table.push_symbol_stack(
                    SymbolDescriptor(var.first, var.second, BinderKind::QUANTIFIER));
        }

        auto term_sort = std::any_cast<EitherSort>(exists.get_term()->accept(*this));

        for (int i = 0; i < exists.get_vars().size(); ++i) {
            table.pop_symbol_stack();
        }

        if (!(term_sort == CoreResolver::get_bool_sort())) {
            throw TypingError("Quantifier subterm needs to be Bool.");
        }
        return term_sort;
    }

    std::any visitForallTerm(ForallTerm& forall) override {
        for (SortedVar& var : forall.get_vars()) {
            table.push_symbol_stack(
                    SymbolDescriptor(var.first, var.second, BinderKind::QUANTIFIER));
        }

        auto term_sort = std::any_cast<EitherSort>(forall.get_term()->accept(*this));

        for (int i = 0; i < forall.get_vars().size(); ++i) {
            table.pop_symbol_stack();
        }

        if (!(term_sort == CoreResolver::get_bool_sort())) {
            throw TypingError("Quantifier subterm needs to be Bool.");
        }
        return term_sort;
    }

    std::any visitLetTerm(LetTerm& let) override {
        for (VarBinding& bd : let.get_var_bindings()) {
            auto term_sort = std::any_cast<EitherSort>(bd.second->accept(*this));
            table.push_symbol_stack(SymbolDescriptor(bd.first, term_sort, BinderKind::LET));
        }

        auto term_sort = std::any_cast<EitherSort>(let.get_term()->accept(*this));

        for (int i = 0; i < let.get_var_bindings().size(); ++i) {
            table.pop_symbol_stack();
        }

        return term_sort;
    }

    EitherSort get_sort(Term* term) {
        return std::any_cast<EitherSort>(term->accept(*this));
    }

    static EitherSort infer_and_check_type(SymbolTable& table, Term* term) {
        TypeInference ti(table);
        return std::any_cast<EitherSort>(term->accept(ti));
    }

};




#endif //PHYSER_TYPING_H

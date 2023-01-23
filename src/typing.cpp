//
// Created by julian on 18.01.23.
//

#include "typing.h"

namespace Sy2CPP {


    std::any TypeInference::visitNumeral(Numeral &numeral) {
        if (this->table.lookup_sort(LIAResolver::get_int_sort())) {
            return LIAResolver::get_int_sort();
        } else {
            throw TypingError("LIAResolver is not activated. But we found a numeral.");
        }
    }

    std::any TypeInference::visitDecimal(Decimal &decimal) {
        throw NotImplemented("Typing for decimals is not implemented.");
    }

    std::any TypeInference::visitBoolConst(BoolConst &boolConst) {
        return CoreResolver::get_bool_sort();
    }

    std::any TypeInference::visitIdentifierTerm(IdentifierTerm &term) {
        auto opt = table.resolve_symbol_descriptor(term.get_identifier());
        if (opt.has_value()) {
            return opt->get_symbol_sort();
        } else {
            throw TypingError("Could not infer type of identifier: " +
                              to_string(term.get_identifier())); //TODO string of identifier
        }
    }

    std::any TypeInference::visitApplicationTerm(ApplicationTerm &application) {
        std::vector<EitherSort> arg_sorts;
        for (const TermPtr &ptr: application.get_arguments()) {
            auto sort = std::any_cast<EitherSort>(ptr->accept(*this));
            arg_sorts.push_back(sort);
        }

        std::optional<FunctionDescriptor> descr =
                table.lookup_or_resolve_function(application.get_identifier(), arg_sorts);

        if (descr.has_value()) {
            return descr->get_range_sort();
        }

        throw TypingError(
                "Could not lookup or resolve function while typing: " + to_string(application.get_identifier()));
    }

    std::any TypeInference::visitExistsTerm(ExistsTerm &exists) {
        for (SortedVar &var: exists.get_vars()) {
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

    std::any TypeInference::visitForallTerm(ForallTerm &forall) {
        for (SortedVar &var: forall.get_vars()) {
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

    std::any TypeInference::visitLetTerm(LetTerm &let) {
        for (VarBinding &bd: let.get_var_bindings()) {
            auto term_sort = std::any_cast<EitherSort>(bd.second->accept(*this));
            table.push_symbol_stack(SymbolDescriptor(bd.first, term_sort, BinderKind::LET));
        }

        auto term_sort = std::any_cast<EitherSort>(let.get_term()->accept(*this));

        for (int i = 0; i < let.get_var_bindings().size(); ++i) {
            table.pop_symbol_stack();
        }

        return term_sort;
    }

    EitherSort TypeInference::get_sort(Term *term) {
        return std::any_cast<EitherSort>(term->accept(*this));
    }

    EitherSort TypeInference::infer_and_check_type(symbol_table &table, Term *term) {
        TypeInference ti(table);
        return std::any_cast<EitherSort>(term->accept(ti));
    }

}
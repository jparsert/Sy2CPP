//
// Created by julian on 18.01.23.
//

#ifndef PHYSER_TYPING_H
#define PHYSER_TYPING_H

#include "ast.h"
#include "symbol_table.h"
#include "resolvers.h"
#include "exceptions.h"

namespace Sy2CPP {

    class TypeInference : public TermVisitor {
    private:

        SymbolTable &table;

    public:

        explicit TypeInference(SymbolTable &symbol_tab) : table{symbol_tab} {

        }

        std::any visitNumeral(Numeral &numeral) override;

        std::any visitDecimal(Decimal &decimal) override;

        std::any visitBoolConst(BoolConst &boolConst) override;

        std::any visitHexConst(HexConst &hex) override {
            if (this->table.lookup_sort(BVResolver::get_bv_sort(0))) {
                return BVResolver::get_bv_sort(0);
            } else {
                throw TypingError("BVResolver is not activated. But we found a hex.");
            }
        }

        std::any visitBinConst(BinConst &bin) override {
            if (this->table.lookup_sort(BVResolver::get_bv_sort(0))) {
                return BVResolver::get_bv_sort(0);
            } else {
                throw TypingError("BVResolver is not activated. But we found a bin constant.");
            }
        }

        std::any visitStringConst(StringConst &s) override {
            throw NotImplemented("Typing for string consts is not implemented.");

        }

        std::any visitIdentifierTerm(IdentifierTerm &term) override;

        std::any visitApplicationTerm(ApplicationTerm &application) override;

        std::any visitExistsTerm(ExistsTerm &exists) override;

        std::any visitForallTerm(ForallTerm &forall) override;

        std::any visitLetTerm(LetTerm &let) override;

        EitherSort get_sort(Term *term);

        static EitherSort infer_and_check_type(SymbolTable &table, Term *term);

    };

}


#endif //PHYSER_TYPING_H

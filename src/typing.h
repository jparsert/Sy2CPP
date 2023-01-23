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

        symbol_table &table;

    public:

        explicit TypeInference(symbol_table &symbol_tab) : table{symbol_tab} {

        }

        std::any visitNumeral(Numeral &numeral) override;

        std::any visitDecimal(Decimal &decimal) override;

        std::any visitBoolConst(BoolConst &boolConst) override;

        std::any visitHexConst(HexConst &hex) override {
            throw not_implemented("Typing for hex consts is not implemented.");
        }

        std::any visitBinConst(BinConst &bin) override {
            throw not_implemented("Typing for bin consts is not implemented.");

        }

        std::any visitStringConst(StringConst &s) override {
            throw not_implemented("Typing for string consts is not implemented.");

        }

        std::any visitIdentifierTerm(IdentifierTerm &term) override;

        std::any visitApplicationTerm(ApplicationTerm &application) override;

        std::any visitExistsTerm(ExistsTerm &exists) override;

        std::any visitForallTerm(ForallTerm &forall) override;

        std::any visitLetTerm(LetTerm &let) override;

        EitherSort get_sort(Term *term);

        static EitherSort infer_and_check_type(symbol_table &table, Term *term);

    };

}


#endif //PHYSER_TYPING_H

//
// Created by julian on 18.01.23.
//

#ifndef PHYSER_TYPING_H
#define PHYSER_TYPING_H

#include "ast.h"
#include "symbol_table.h"
#include "resolvers.h"
#include "exceptions.h"
#include "symbol_table_ast_builder.h"

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
            throw NotImplemented("Typing for hex consts is not implemented.");
        }

        std::any visitBinConst(BinConst &bin) override {
            throw NotImplemented("Typing for bin consts is not implemented.");

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

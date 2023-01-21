//
// Created by julian on 13.12.22.
//

#ifndef PHYSER_TO_STRING_PRINTER_H
#define PHYSER_TO_STRING_PRINTER_H

#include <SyGuSv21BaseVisitor.h>
#include <sstream>
#include "../exceptions/unsupported_feature.h"
#include "../exceptions/not_implemented.h"
#include "../ast.h"

namespace Sy2CPP {

    class AstToString : public AstBaseVisitor {

    private:

        std::stringstream result_stream;

        void push_op_bracket() {
            result_stream << "(";
        }

        void push_cl_bracket() {
            result_stream << ")";
        }

        void push_space() {
            result_stream << " ";
        }

        void push_identifier(const EitherIdentifier &&id);

        void push_identifier(const EitherIdentifier &id);

        void push_sort(const EitherSort &sort);

        void push_sort(const EitherSort &&sort);

    public:

        AstToString() = default;

        std::any visitProblem(Problem &problem) override;

        std::any visitNumeral(Numeral &numeral) override {
            this->result_stream << numeral.get_value();
            return {};
        }

        std::any visitDecimal(Decimal &decimal) override {
            throw not_implemented("Decimals are not implemented yet.");
        }

        std::any visitBoolConst(BoolConst &boolConst) override;

        std::any visitHexConst(HexConst &hex) override {
            throw not_implemented("Hex consts are not implemented yet.");
        }

        std::any visitBinConst(BinConst &bin) override {
            throw not_implemented("Bin consts are not implemented yet.");
        }

        std::any visitStringConst(StringConst &s) override {
            this->result_stream << s.get_string();
            return {};
        }

        std::any visitSimpleIdentifier(SimpleIdentifier &identifier) override {
            this->result_stream << identifier.get_symbol();
            return {};
        }

        std::any visitIndexedIdentifier(IndexedIdentifier &context) override {
            throw not_implemented("Indexed identifiers are not implemented yet.");
        }

        std::any visitSimpleSort(SimpleSort &sort) override;

        std::any visitParametricSort(ParametricSort &sort) override {
            throw not_implemented("Parametric sorts are not implemented yet.");
        }

        std::any visitApplicationTerm(ApplicationTerm &application) override;

        std::any visitExistsTerm(ExistsTerm &exists) override;

        std::any visitForallTerm(ForallTerm &forall) override;

        std::any visitLetTerm(LetTerm &let) override;

        std::any visitAssumeCmd(AssumeCmd &assumeCmd) override;

        std::any visitCheckSynthCmd(CheckSynthCmd &context) override;

        std::any visitConstraintCmd(ConstraintCmd &constr) override;

        std::any visitDeclareVarCmd(DeclareVarCmd &decl) override;

        std::any visitSynthFunCmd(SynthFunCmd &synthFun) override;

        std::any visitSetFeatureCmd(SetFeatureCmd &cmd) override;

        std::any visitDeclareDatatype(DeclareDatatype &declDT) override {
            throw not_implemented("DeclareDatatype has not been implemented yet.");
        }

        std::any visitDeclareDatatypes(DeclareDatatypes &context) override {
            throw not_implemented("DeclareDatatypes has not been implemented yet.");
        }

        std::any visitDeclareSort(DeclareSort &cmd) override;

        std::any visitDefineFun(DefineFunCmd &cmd) override;

        std::any visitDefineSort(DefineSort &cmd) override;

        std::any visitSetInfo(SetInfo &cmd) override;

        std::any visitSetLogic(SetLogic &setLogicCmd) override;

        std::any visitSetOption(SetOption &cmd) override;

        std::any visitSortDecl(SortDecl &decl) override {
            throw not_implemented("SortDecl has not been implemented yet.");
        }

        std::any visitDtDecl(DtDecl &decl) override {
            throw not_implemented("DtDecl has not been implemented yet.");
        }

        std::any visitDtConsDecl(DtConsDecl &dtconsdecl) override {
            throw not_implemented("DtConsDecl has not been implemented yet.");
        }

        std::any visitGrammarDef(GrammarDef &gdef) override;

        std::any visitGroupedRuleList(GroupedRuleList &grouped_r_l) override;

        std::any visitConstantGTerm(ConstantGTerm &constGTerm) override;

        std::any visitVariableGTerm(VariableGTerm &variableTerm) override;

        std::string get_string(Problem &problem);

    };
}

#endif //PHYSER_TO_STRING_PRINTER_H

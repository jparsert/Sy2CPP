//
// Created by julian on 13.12.22.
//

#ifndef PHYSER_TO_STRING_PRINTER_H
#define PHYSER_TO_STRING_PRINTER_H

#include <SyGuSv21BaseVisitor.h>
#include <sstream>
#include "../exceptions/unsupported_feature.h"
#include "../exceptions/not_implemented.h"
#include "ast.h"

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

    void push_identifier(const EitherIdentifier&& id) ;

    void push_identifier(const EitherIdentifier& id);

    void push_sort(const EitherSort& sort) ;

    void push_sort(const EitherSort&& sort) ;

public:

    AstToString() = default;

    std::any visitProblem(Problem& problem) override ;

    std::any visitNumeral(Numeral& numeral) override {
        this->result_stream << numeral.get_value();
        return {};
    }

    std::any visitDecimal(Decimal& decimal) override {
        throw not_implemented("Decimals are not implemented yet.");
    }

    std::any visitBoolConst(BoolConst& boolConst) override {
        if (boolConst.get_value()) {
            this->result_stream << "true";
        } else {
            this->result_stream << "false";
        }
        return {};
    }

    std::any visitHexConst(HexConst& hex) override {
        throw not_implemented("Hex consts are not implemented yet.");
    }

    std::any visitBinConst(BinConst& bin) override {
        throw not_implemented("Bin consts are not implemented yet.");
    }

    std::any visitStringConst(StringConst& s) override {
        this->result_stream << s.get_string();
        return {};
    }

    std::any visitSimpleIdentifier(SimpleIdentifier& identifier) override {
         this->result_stream << identifier.get_symbol();
        return {};
    }

    std::any visitIndexedIdentifier(IndexedIdentifier& context) override {
        throw not_implemented("Indexed identifiers are not implemented yet.");
    }

    std::any visitSimpleSort(SimpleSort& sort) override {
        std::visit([&](auto id) mutable {id.accept(*this);}, sort.get_identifier());
        return {};
    }

    std::any visitParametricSort(ParametricSort& sort) override {
        throw not_implemented("Parametric sorts are not implemented yet.");
    }

    std::any visitApplicationTerm(ApplicationTerm& application) override;

    std::any visitExistsTerm(ExistsTerm& exists) override ;

    std::any visitForallTerm(ForallTerm& forall) override;

    std::any visitLetTerm(LetTerm& let) override ;

    std::any visitAssumeCmd(AssumeCmd& assumeCmd) override {
        this->push_op_bracket();
        this->result_stream << "assume";
        this->push_space();
        assumeCmd.get_term()->accept(*this);
        this->push_cl_bracket();
        return {};
    }

    std::any visitCheckSynthCmd(CheckSynthCmd& context) override {
        this->push_op_bracket();
        this->result_stream << "check-synth";
        this->push_cl_bracket();
        return {};
    }

    std::any visitConstraintCmd(ConstraintCmd& constr) override {
        this->push_op_bracket();
        this->result_stream << "assume";
        this->push_space();
        constr.get_term()->accept(*this);
        this->push_cl_bracket();
        return {};
    }

    std::any visitDeclareVarCmd(DeclareVarCmd& decl) override ;

    std::any visitSynthFunCmd(SynthFunCmd& synthFun) override ;

    std::any visitSetFeatureCmd(SetFeatureCmd& cmd) override ;

    std::any visitDeclareDatatype(DeclareDatatype& declDT) override {
        throw not_implemented("DeclareDatatype has not been implemented yet.");
    }

    std::any visitDeclareDatatypes(DeclareDatatypes& context) override {
        throw not_implemented("DeclareDatatypes has not been implemented yet.");
    }

    std::any visitDeclareSort(DeclareSort& cmd) override ;

    std::any visitDefineFun(DefineFunCmd& cmd) override ;

    std::any visitDefineSort(DefineSort& cmd) override {
        this->push_op_bracket();
        this->result_stream << "define-sort";
        this->push_space();

        this->push_identifier(cmd.get_identifier());
        this->push_space();

        this->push_sort(cmd.get_sort());
        this->push_cl_bracket();
        return {};
    }

    std::any visitSetInfo(SetInfo& cmd) override ;

    std::any visitSetLogic(SetLogic& setLogicCmd) override {
        this->push_op_bracket();
        this->result_stream << "set-logic";
        this->push_space();
        this->result_stream << setLogicCmd.get_logic();
        this->push_cl_bracket();
        return {};
    }

    std::any visitSetOption(SetOption& cmd) override {
        this->push_op_bracket();

        this->result_stream << "set-option";
        this->push_space();

        this->result_stream << ":" << cmd.get_keyword();
        this->push_space();

        cmd.get_literal()->accept(*this);

        this->push_cl_bracket();
        return {};
    }

    std::any visitSortDecl(SortDecl& decl) override {
        throw not_implemented("SortDecl has not been implemented yet.");
    }

    std::any visitDtDecl(DtDecl& decl) override {
        throw not_implemented("DtDecl has not been implemented yet.");
    }

    std::any visitDtConsDecl(DtConsDecl& dtconsdecl) override {
        throw not_implemented("DtConsDecl has not been implemented yet.");
    }

    std::any visitGrammarDef(GrammarDef& gdef) override ;

    std::any visitGroupedRuleList(GroupedRuleList& grouped_r_l) override ;

    std::any visitConstantGTerm(ConstantGTerm& constGTerm) override {
        this->push_op_bracket();
        this->result_stream << "Constant";
        this->push_space();
        std::visit([&](auto x) mutable{x.accept(*this);}, constGTerm.get_sort());
        this->push_cl_bracket();
        return {};
    }

    std::any visitVariableGTerm(VariableGTerm& variableTerm) override {
        this->push_op_bracket();
        this->result_stream << "Variable";
        this->push_space();
        std::visit([&](auto x) mutable{x.accept(*this);}, variableTerm.get_sort());
        this->push_cl_bracket();
        return {};
    }

    std::string get_string(Problem& problem) {
        problem.accept(*this);
        return result_stream.str();
    }

};


#endif //PHYSER_TO_STRING_PRINTER_H

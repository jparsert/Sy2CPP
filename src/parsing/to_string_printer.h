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

class AstToString : public ast::AstBaseVisitor {

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

    void push_identifier(ast::EitherIdentifier&& id) {
        std::visit([&](auto id) mutable {id.accept(*this);}, id);
    }

    void push_identifier(ast::EitherIdentifier& id) {
        std::visit([&](auto id) mutable {id.accept(*this);}, id);
    }

    void push_sort(ast::EitherSort& sort) {
        std::visit([&](auto eitheSort) mutable {eitheSort->accept(*this);}, sort);
    }

    void push_sort(ast::EitherSort&& sort) {
        std::visit([&](auto eitheSort) mutable {eitheSort->accept(*this);}, sort);
    }

public:

    AstToString() = default;

    std::any visitProblem(ast::Problem& problem) override {

        for(const auto& x: problem.get_commands()) {

            x->accept(*this);
            this->result_stream << std::endl;
        }
        return {};
    }

    std::any visitNumeral(ast::Numeral& numeral) override {
        this->result_stream << numeral.get_value();
        return {};
    }

    std::any visitDecimal(ast::Decimal& decimal) override {
        throw not_implemented("Decimals are not implemented yet.");
    }

    std::any visitBoolConst(ast::BoolConst& boolConst) override {
        if (boolConst.get_value()) {
            this->result_stream << "true";
        } else {
            this->result_stream << "false";
        }
        return {};
    }

    std::any visitHexConst(ast::HexConst& hex) override {
        throw not_implemented("Hex consts are not implemented yet.");
    }

    std::any visitBinConst(ast::BinConst& bin) override {
        throw not_implemented("Bin consts are not implemented yet.");
    }

    std::any visitStringConst(ast::StringConst& s) override {
        this->result_stream << s.get_string();
        return {};
    }

    std::any visitSimpleIdentifier(ast::SimpleIdentifier& identifier) override {
         this->result_stream << identifier.get_symbol();
        return {};
    }

    std::any visitIndexedIdentifier(ast::IndexedIdentifier& context) override {
        throw not_implemented("Indexed identifiers are not implemented yet.");
    }

    std::any visitSimpleSort(ast::SimpleSort& sort) override {
        std::visit([&](auto id) mutable {id.accept(*this);}, sort.get_identifier());
        return {};
    }

    std::any visitParametricSort(ast::ParametricSort& sort) override {
        throw not_implemented("Parametric sorts are not implemented yet.");
    }

    std::any visitApplicationTerm(ast::ApplicationTerm& application) override {
        this->push_op_bracket();
        std::visit([&](auto id) mutable {id.accept(*this);}, application.get_identifier());

        for (const ast::TermPtr& ptr : application.get_arguments()) {
            this->push_space();
            ptr->accept(*this);
        }
        this->push_cl_bracket();
        return {};
    }


    std::any visitExistsTerm(ast::ExistsTerm& exists) override {
        this->push_op_bracket();
        this->result_stream << "exists";
        this->push_space();
        this->push_op_bracket();

        for (const std::shared_ptr<ast::SortedVar>& x: exists.get_vars()) {
            this->push_space();
            this->push_op_bracket();
            this->result_stream << x->first;
            this->push_space();
            std::visit([&](auto& var) mutable {var->accept(*this);}, *x->second);
            this->push_cl_bracket();
        }
        this->push_cl_bracket();
        this->push_space();

        exists.get_term()->accept(*this);

        this->push_cl_bracket();
        return {};
    }

    std::any visitForallTerm(ast::ForallTerm& forall) override {
        this->push_op_bracket();
        this->result_stream << "forall";
        this->push_space();
        this->push_op_bracket();

        for (const std::shared_ptr<ast::SortedVar> &x: forall.get_vars()) {
            this->push_space();
            this->push_op_bracket();
            this->result_stream << x->first;
            this->push_space();
            std::visit([&](auto &var) mutable { var->accept(*this); }, *x->second);
            this->push_cl_bracket();
        }
        this->push_cl_bracket();
        this->push_space();

        forall.get_term()->accept(*this);

        this->push_cl_bracket();
        return {};
    }

    std::any visitLetTerm(ast::LetTerm& let) override {
        this->push_op_bracket();
        this->result_stream << "let";
        this->push_space();
        this->push_op_bracket();

        for (const std::shared_ptr<ast::VarBinding> &x: let.get_var_bindings()) {
            this->push_space();
            this->push_op_bracket();
            std::visit([&](auto &var) mutable { var.accept(*this); }, x->first);
            this->push_space();
            x->second->accept(*this);
            this->push_cl_bracket();
        }
        this->push_cl_bracket();
        this->push_space();

        let.get_term()->accept(*this);

        this->push_cl_bracket();
        return {};
    }

    std::any visitAssumeCmd(ast::AssumeCmd& assumeCmd) override {
        this->push_op_bracket();
        this->result_stream << "assume";
        this->push_space();
        assumeCmd.get_term()->accept(*this);
        this->push_cl_bracket();
        return {};
    }

    std::any visitCheckSynthCmd(ast::CheckSynthCmd& context) override {
        this->push_op_bracket();
        this->result_stream << "check-synth";
        this->push_cl_bracket();
        return {};
    }

    std::any visitConstraintCmd(ast::ConstraintCmd& constr) override {
        this->push_op_bracket();
        this->result_stream << "assume";
        this->push_space();
        constr.get_term()->accept(*this);
        this->push_cl_bracket();
        return {};
    }

    std::any visitDeclareVarCmd(ast::DeclareVarCmd& decl) override {
        this->push_op_bracket();
        this->result_stream << "declare-var";
        this->push_space();
        std::visit([&](auto id) mutable {id.accept(*this);}, decl.get_identifier());
        this->push_space();
        std::visit([&](auto &var) mutable {var->accept(*this);}, *decl.get_sort());
        this->push_cl_bracket();
        return {};
    }

    std::any visitSynthFunCmd(ast::SynthFunCmd& synthFun) override {
        this->push_op_bracket();
        this->result_stream << "synth-fun";

        this->push_space();
        std::visit([&](auto id) mutable {id.accept(*this);}, synthFun.get_identifier());
        this->push_space();

        this->push_op_bracket();

        for (std::shared_ptr<ast::SortedVar>& x : synthFun.get_arguments()) {
            this->push_op_bracket();
            this->result_stream << x->first;
            this->push_space();
            std::visit([&](auto id) mutable {id->accept(*this);}, *x->second);
            this->push_cl_bracket();
            
        }

        this->push_cl_bracket();

        this->push_space();
        std::visit([&](auto id) mutable {id->accept(*this);}, *synthFun.get_sort());
        this->push_space();

        this->result_stream << std::endl;

        synthFun.get_grammar()->accept(*this);

        this->push_cl_bracket();
        return {};
    }

    std::any visitSetFeatureCmd(ast::SetFeatureCmd& cmd) override {
        this->push_op_bracket();
        this->result_stream << "set-feature";
        this->push_space();
        switch (cmd.get_feature()) {
            case ast::Feature::GRAMMARS:
                this->result_stream << ":grammars";
                break;
            case ast::Feature::FWD_DECLS:
                this->result_stream << ":fwd-decls";
                break;
            case ast::Feature::RECURSION:
                this->result_stream << ":recursion";
                break;
            case ast::Feature::ORACLES:
                this->result_stream << ":oracles";
                break;
            case ast::Feature::WEIGHTS:
                this->result_stream << ":weights";
                break;
        }

        this->push_space();
        if (cmd.get_value()) {
            this->result_stream << "true";
        } else {
            this->result_stream << "false";
        }
        this->push_cl_bracket();
        return {};
    }

    std::any visitDeclareDatatype(ast::DeclareDatatype& declDT) override {
        throw not_implemented("DeclareDatatype has not been implemented yet.");
    }

    std::any visitDeclareDatatypes(ast::DeclareDatatypes& context) override {
        throw not_implemented("DeclareDatatypes has not been implemented yet.");
    }

    std::any visitDeclareSort(ast::DeclareSort& cmd) override {
        this->push_op_bracket();

        this->result_stream << "declare-sort";
        this->push_space();

        std::visit([&](auto id) mutable {id.accept(*this);}, cmd.get_identifier());
        this->push_space();
        cmd.get_numeral()->accept(*this);

        this->push_cl_bracket();
        return {};
    }

    std::any visitDefineFun(ast::DefineFunCmd& cmd) override {
        this->push_op_bracket();
        this->result_stream << "define-fun";
        this->push_space();
        this->push_identifier(cmd.get_identifier());
        this->push_space();

        this->push_op_bracket();
        for (std::shared_ptr<ast::SortedVar>& x : cmd.get_arguments()) {
            this->push_op_bracket();
            this->result_stream << x->first;
            this->push_space();
            this->push_sort(*x->second);
            this->push_cl_bracket();
        }
        this->push_cl_bracket();

        this->push_space();
        this->push_sort(*cmd.get_sort());
        this->push_space();

        cmd.get_term()->accept(*this);

        this->push_cl_bracket();
        return {};
    }

    std::any visitDefineSort(ast::DefineSort& cmd) override {
        this->push_op_bracket();
        this->result_stream << "define-sort";
        this->push_space();

        this->push_identifier(cmd.get_identifier());
        this->push_space();

        this->push_sort(*cmd.get_sort());
        this->push_cl_bracket();
        return {};
    }

    std::any visitSetInfo(ast::SetInfo& cmd) override {
        this->push_op_bracket();

        this->result_stream << "set-info";
        this->push_space();

        this->result_stream << ":" << cmd.get_keyword();
        this->push_space();

        cmd.get_literal()->accept(*this);

        this->push_cl_bracket();
        return {};
    }

    std::any visitSetLogic(ast::SetLogic& setLogicCmd) override {
        this->push_op_bracket();
        this->result_stream << "set-logic";
        this->push_space();
        this->result_stream << setLogicCmd.get_logic();
        this->push_cl_bracket();
        return {};
    }

    std::any visitSetOption(ast::SetOption& cmd) override {
        this->push_op_bracket();

        this->result_stream << "set-option";
        this->push_space();

        this->result_stream << ":" << cmd.get_keyword();
        this->push_space();

        cmd.get_literal()->accept(*this);

        this->push_cl_bracket();
        return {};
    }

    std::any visitSortDecl(ast::SortDecl& decl) override {
        throw not_implemented("SortDecl has not been implemented yet.");
    }

    std::any visitDtDecl(ast::DtDecl& decl) override {
        throw not_implemented("DtDecl has not been implemented yet.");
    }

    std::any visitDtConsDecl(ast::DtConsDecl& dtconsdecl) override {
        throw not_implemented("DtConsDecl has not been implemented yet.");
    }

    std::any visitGrammarDef(ast::GrammarDef& gdef) override {
        this->push_op_bracket();
        for (auto& x: gdef.get_vars()) {
            this->push_op_bracket();
            this->result_stream << x->first;
            this->push_space();
            std::visit([&](auto id) mutable { id->accept(*this); }, *x->second);
            this->push_cl_bracket();
        }
        this->push_cl_bracket();

        this->push_space();
        this->result_stream << std::endl;

        this->push_op_bracket();
        for (std::shared_ptr<ast::GroupedRuleList>& x: gdef.get_rules()) {
            x->accept(*this);
            this->result_stream << std::endl;
        }
        this->push_cl_bracket();
        return {};
    }

    std::any visitGroupedRuleList(ast::GroupedRuleList& grouped_r_l) override {
        this->push_op_bracket();
        std::visit([&](auto id) mutable { id.accept(*this); },
                   grouped_r_l.get_identifier());

        this->push_space();

        std::visit([&](auto id) mutable { id->accept(*this); },
                   *grouped_r_l.get_sort());

        this->push_space();

        this->push_op_bracket();
        for(ast::TermPtr& x : grouped_r_l.get_terms()) {
            x->accept(*this);
            this->push_space();
        }
        this->push_cl_bracket();
        this->push_cl_bracket();
        return {};
    }

    std::any visitConstantGTerm(ast::ConstantGTerm& constGTerm) override {
        this->push_op_bracket();
        this->result_stream << "Constant";
        this->push_space();
        std::visit([&](auto& x) mutable{x->accept(*this);}, *constGTerm.get_sort());
        this->push_cl_bracket();
        return {};
    }

    std::any visitVariableGTerm(ast::VariableGTerm& variableTerm) override {
        this->push_op_bracket();
        this->result_stream << "Variable";
        this->push_space();
        std::visit([&](auto& x) mutable{x->accept(*this);}, *variableTerm.get_sort());
        this->push_cl_bracket();
        return {};
    }

    std::string get_string(ast::Problem& problem) {
        problem.accept(*this);
        return result_stream.str();
    }

};


#endif //PHYSER_TO_STRING_PRINTER_H

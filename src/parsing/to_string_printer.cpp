//
// Created by julian on 13.12.22.
//

#include "to_string_printer.h"

std::any AstToString::visitGrammarDef(GrammarDef &gdef) {
    this->push_op_bracket();
    for (auto& x: gdef.get_non_terminals()) {
        this->push_space();
        this->push_op_bracket();
        this->result_stream << to_string(x.first);
        this->push_space();
        std::visit([&](auto id) mutable { id.accept(*this); }, x.second);
        this->push_cl_bracket();
    }
    this->push_space();
    this->push_cl_bracket();

    this->push_space();
    this->result_stream << std::endl;

    this->push_op_bracket();
    for (GroupedRuleList& x: gdef.get_rules()) {
        x.accept(*this);
        this->result_stream << std::endl;
    }
    this->push_cl_bracket();
    return {};
}

std::any AstToString::visitGroupedRuleList(GroupedRuleList &grouped_r_l) {
    this->push_op_bracket();
    std::visit([&](auto id) mutable { id.accept(*this); },
               grouped_r_l.get_identifier());

    this->push_space();

    std::visit([&](auto id) mutable { id.accept(*this); },
               grouped_r_l.get_sort());

    this->push_space();

    this->push_op_bracket();
    for(TermPtr& x : grouped_r_l.get_terms()) {
        x->accept(*this);
        this->push_space();
    }
    this->push_cl_bracket();
    this->push_cl_bracket();
    return {};
}

std::any AstToString::visitSetInfo(SetInfo &cmd) {
    this->push_op_bracket();

    this->result_stream << "set-info";
    this->push_space();

    this->result_stream << ":" << cmd.get_keyword();
    this->push_space();

    cmd.get_literal()->accept(*this);

    this->push_cl_bracket();
    return {};
}

std::any AstToString::visitDefineFun(DefineFunCmd &cmd) {
    this->push_op_bracket();
    this->result_stream << "define-fun";
    this->push_space();
    this->push_identifier(cmd.get_identifier());
    this->push_space();

    this->push_op_bracket();
    for (SortedVar& x : cmd.get_arguments()) {
        this->push_space();
        this->push_op_bracket();
        this->result_stream << to_string(x.first);
        this->push_space();
        this->push_sort(x.second);
        this->push_cl_bracket();
    }
    this->push_space();
    this->push_cl_bracket();

    this->push_space();
    this->push_sort(cmd.get_sort());
    this->push_space();

    cmd.get_term()->accept(*this);

    this->push_cl_bracket();
    return {};
}

std::any AstToString::visitDeclareSort(DeclareSort &cmd) {
    this->push_op_bracket();

    this->result_stream << "declare-sort";
    this->push_space();

    std::visit([&](auto id) mutable {id.accept(*this);}, cmd.get_identifier());
    this->push_space();
    cmd.get_numeral().accept(*this);

    this->push_cl_bracket();
    return {};
}

std::any AstToString::visitSetFeatureCmd(SetFeatureCmd &cmd) {
    this->push_op_bracket();
    this->result_stream << "set-feature";
    this->push_space();
    switch (cmd.get_feature()) {
        case Feature::GRAMMARS:
            this->result_stream << ":grammars";
            break;
        case Feature::FWD_DECLS:
            this->result_stream << ":fwd-decls";
            break;
        case Feature::RECURSION:
            this->result_stream << ":recursion";
            break;
        case Feature::ORACLES:
            this->result_stream << ":oracles";
            break;
        case Feature::WEIGHTS:
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

std::any AstToString::visitSynthFunCmd(SynthFunCmd &synthFun) {
    this->push_op_bracket();
    this->result_stream << "synth-fun";

    this->push_space();
    std::visit([&](auto id) mutable {id.accept(*this);}, synthFun.get_identifier());
    this->push_space();

    this->push_op_bracket();

    for (SortedVar& x : synthFun.get_arguments()) {
        this->push_space();
        this->push_op_bracket();
        this->result_stream << to_string(x.first);
        this->push_space();
        std::visit([&](auto id) mutable {id.accept(*this);}, x.second);
        this->push_cl_bracket();

    }
    this->push_space();
    this->push_cl_bracket();

    this->push_space();
    std::visit([&](auto id) mutable {id.accept(*this);}, synthFun.get_sort());
    this->push_space();

    this->result_stream << std::endl;

    synthFun.get_grammar().accept(*this);

    this->push_cl_bracket();
    return {};
}

std::any AstToString::visitDeclareVarCmd(DeclareVarCmd &decl) {
    this->push_op_bracket();
    this->result_stream << "declare-var";
    this->push_space();
    std::visit([&](auto id) mutable {id.accept(*this);}, decl.get_identifier());
    this->push_space();
    std::visit([&](auto var) mutable {var.accept(*this);}, decl.get_sort());
    this->push_cl_bracket();
    return {};
}

std::any AstToString::visitLetTerm(LetTerm &let)  {
    this->push_op_bracket();
    this->result_stream << "let";
    this->push_space();
    this->push_op_bracket();

    for (VarBinding &x: let.get_var_bindings()) {
        this->push_space();
        this->push_op_bracket();
        std::visit([&](auto &var) mutable { var.accept(*this); }, x.first);
        this->push_space();
        x.second->accept(*this);
        this->push_cl_bracket();
    }
    this->push_space();
    this->push_cl_bracket();
    this->push_space();

    let.get_term()->accept(*this);

    this->push_cl_bracket();
    return {};
}

std::any AstToString::visitForallTerm(ForallTerm &forall) {
    this->push_op_bracket();
    this->result_stream << "forall";
    this->push_space();
    this->push_op_bracket();

    for (SortedVar &x: forall.get_vars()) {
        this->push_space();
        this->push_op_bracket();
        this->result_stream << to_string(x.first);
        this->push_space();
        std::visit([&](auto &var) mutable { var.accept(*this); }, x.second);
        this->push_cl_bracket();
    }
    this->push_space();

    this->push_cl_bracket();
    this->push_space();

    forall.get_term()->accept(*this);

    this->push_cl_bracket();
    return {};
}

std::any AstToString::visitExistsTerm(ExistsTerm &exists) {
    this->push_op_bracket();
    this->result_stream << "exists";
    this->push_space();
    this->push_op_bracket();

    for (SortedVar& x: exists.get_vars()) {
        this->push_space();
        this->push_op_bracket();
        this->result_stream << to_string(x.first);
        this->push_space();
        std::visit([&](auto& var) mutable {var.accept(*this);}, x.second);
        this->push_cl_bracket();
    }
    this->push_space();

    this->push_cl_bracket();
    this->push_space();

    exists.get_term()->accept(*this);

    this->push_cl_bracket();
    return {};
}

std::any AstToString::visitApplicationTerm(ApplicationTerm &application) {
    this->push_op_bracket();
    std::visit([&](auto id) mutable {id.accept(*this);}, application.get_identifier());

    for (const TermPtr& ptr : application.get_arguments()) {
        this->push_space();
        ptr->accept(*this);
    }
    this->push_cl_bracket();
    return {};
}

void AstToString::push_identifier(const EitherIdentifier &&id) {
    std::visit([&](auto id) mutable {id.accept(*this);}, id);
}

void AstToString::push_identifier(const EitherIdentifier &id)  {
    std::visit([&](auto id) mutable {id.accept(*this);}, id);
}

void AstToString::push_sort(const EitherSort &sort)  {
    std::visit([&](auto eitheSort) mutable {eitheSort.accept(*this);}, sort);
}

void AstToString::push_sort(const EitherSort &&sort) {
    std::visit([&](auto eitheSort) mutable {eitheSort.accept(*this);}, sort);
}

std::any AstToString::visitProblem(Problem &problem) {
    for(const auto& x: problem.get_commands()) {
        x->accept(*this);
        this->result_stream << std::endl;
    }
    return {};
}
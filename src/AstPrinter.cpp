//
// Created by julian on 13.12.22.
//

#include "AstPrinter.h"

namespace Sy2CPP {


    std::string to_string(const EitherIdentifier &ident) {
        return std::visit([](auto &id) mutable { return (std::string) id; }, ident);
    }

    std::string to_string(const EitherSort &ident) {
        return std::visit([](auto &id) mutable { return (std::string) id; }, ident);
    }

    std::string to_string(const SyGuSSolution& sol) {
        if (!sol) {
            return "fail";
        } else {
            std::stringstream result_stream;
            result_stream << "(" << std::endl;
            for (Sy2CPP::DefineFunCmd cmd : sol.value()) {
                result_stream << AstToString::to_string(cmd) << std::endl;
            }
            result_stream << ")";
            result_stream << std::endl;

            return result_stream.str();
        }

    }

    std::string to_string(const TermPtr& ptr) {
        return AstToString::to_string(*ptr.get());
    }



    std::any AstToString::visitGrammarDef(GrammarDef &gdef) {
        this->push_op_bracket();
        for (auto &x: gdef.get_non_terminals()) {
            this->push_space();
            this->push_op_bracket();
            this->result_stream << Sy2CPP::to_string(x.first);
            this->push_space();
            this->visitEitherSort(x.second);
            this->push_cl_bracket();
        }
        this->push_space();
        this->push_cl_bracket();

        this->push_space();
        this->result_stream << std::endl;

        this->push_op_bracket();
        for (GroupedRuleList &x: gdef.get_rules()) {
            x.accept(*this);
            this->result_stream << std::endl;
        }
        this->push_cl_bracket();
        return {};
    }

    std::any AstToString::visitGroupedRuleList(GroupedRuleList &grouped_r_l) {
        this->push_op_bracket();
        this->visitEitherIdentifier(grouped_r_l.get_identifier());

        this->push_space();

        this->visitEitherSort(grouped_r_l.get_sort());

        this->push_space();

        this->push_op_bracket();
        for (TermPtr &x: grouped_r_l.get_terms()) {
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
        for (SortedVar &x: cmd.get_arguments()) {
            this->push_space();
            this->push_op_bracket();
            this->result_stream << Sy2CPP::to_string(x.first);
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

        this->visitEitherIdentifier(cmd.get_identifier());

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
        this->visitEitherIdentifier(synthFun.get_identifier());
        this->push_space();

        this->push_op_bracket();

        for (SortedVar &x: synthFun.get_arguments()) {
            this->push_space();
            this->push_op_bracket();
            this->result_stream << Sy2CPP::to_string(x.first);
            this->push_space();
            this->visitEitherSort(x.second);
            this->push_cl_bracket();

        }
        this->push_space();
        this->push_cl_bracket();

        this->push_space();
        this->visitEitherSort(synthFun.get_sort());
        this->push_space();

        if (synthFun.get_grammar()) { // check if we have grammar or it's just default
            this->result_stream << std::endl;
            synthFun.get_grammar()->accept(*this);
        }

        this->push_cl_bracket();
        return {};
    }

    std::any AstToString::visitDeclareVarCmd(DeclareVarCmd &decl) {
        this->push_op_bracket();
        this->result_stream << "declare-var";
        this->push_space();
        this->visitEitherIdentifier(decl.get_identifier());
        this->push_space();
        this->visitEitherSort(decl.get_sort());
        this->push_cl_bracket();
        return {};
    }

    std::any AstToString::visitLetTerm(LetTerm &let) {
        this->push_op_bracket();
        this->result_stream << "let";
        this->push_space();
        this->push_op_bracket();

        for (VarBinding &x: let.get_var_bindings()) {
            this->push_space();
            this->push_op_bracket();
            this->visitEitherIdentifier(std::get<0>(x));
            this->push_space();
            std::get<2>(x)->accept(*this);
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
            this->visitEitherIdentifier(x.first);
            this->push_space();
            this->visitEitherSort(x.second);
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

        for (SortedVar &x: exists.get_vars()) {
            this->push_space();
            this->push_op_bracket();
            this->visitEitherIdentifier(x.first);
            this->push_space();
            this->visitEitherSort(x.second);
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
        this->visitEitherIdentifier(application.get_identifier());

        for (const TermPtr &ptr: application.get_arguments()) {
            this->push_space();
            ptr->accept(*this);
        }
        this->push_cl_bracket();
        return {};
    }

    void AstToString::push_identifier(EitherIdentifier &&id) {
        this->visitEitherIdentifier(id);
    }

    void AstToString::push_identifier(EitherIdentifier &id) {
        this->visitEitherIdentifier(id);
    }

    void AstToString::push_sort(EitherSort &sort) {
        this->visitEitherSort(sort);
    }

    void AstToString::push_sort(EitherSort &&sort) {
        this->visitEitherSort(sort);
    }

    std::any AstToString::visitProblem(Problem &problem) {
        for (const auto &x: problem.get_commands()) {
            x->accept(*this);
            this->result_stream << std::endl;
        }
        return {};
    }

    std::any AstToString::visitConstantGTerm(ConstantGTerm &constGTerm) {
        this->push_op_bracket();
        this->result_stream << "Constant";
        this->push_space();
        this->visitEitherSort(constGTerm.get_sort());
        this->push_cl_bracket();
        return {};
    }

    std::any AstToString::visitVariableGTerm(VariableGTerm &variableTerm) {
        this->push_op_bracket();
        this->result_stream << "Variable";
        this->push_space();
        this->visitEitherSort(variableTerm.get_sort());
        this->push_cl_bracket();
        return {};
    }

    std::any AstToString::visitSetOption(SetOption &cmd) {
        this->push_op_bracket();

        this->result_stream << "set-option";
        this->push_space();

        this->result_stream << ":" << cmd.get_keyword();
        this->push_space();

        cmd.get_literal()->accept(*this);

        this->push_cl_bracket();
        return {};
    }

    std::any AstToString::visitSetLogic(SetLogic &setLogicCmd) {
        this->push_op_bracket();
        this->result_stream << "set-logic";
        this->push_space();
        this->result_stream << setLogicCmd.get_logic();
        this->push_cl_bracket();
        return {};
    }

    std::any AstToString::visitDefineSort(DefineSort &cmd) {
        this->push_op_bracket();
        this->result_stream << "define-sort";
        this->push_space();

        this->push_identifier(cmd.get_identifier());
        this->push_space();

        this->push_sort(cmd.get_sort());
        this->push_cl_bracket();
        return {};
    }

    std::any AstToString::visitConstraintCmd(ConstraintCmd &constr) {
        this->push_op_bracket();
        this->result_stream << "assume";
        this->push_space();
        constr.get_term()->accept(*this);
        this->push_cl_bracket();
        return {};
    }

    std::any AstToString::visitAssumeCmd(AssumeCmd &assumeCmd) {
        this->push_op_bracket();
        this->result_stream << "assume";
        this->push_space();
        assumeCmd.get_term()->accept(*this);
        this->push_cl_bracket();
        return {};
    }

    std::any AstToString::visitCheckSynthCmd(CheckSynthCmd &context) {
        this->push_op_bracket();
        this->result_stream << "check-synth";
        this->push_cl_bracket();
        return {};
    }

    std::any AstToString::visitBoolConst(BoolConst &boolConst) {
        if (boolConst.get_value()) {
            this->result_stream << "true";
        } else {
            this->result_stream << "false";
        }
        return {};
    }

    std::string AstToString::get_string(Problem &problem) {
        problem.accept(*this);
        return result_stream.str();
    }

    std::any AstToString::visitSimpleSort(SimpleSort &sort) {
        return this->visitEitherIdentifier(sort.get_identifier());
    }

    std::any AstToString::visitIndexedIdentifier(IndexedIdentifier &idx_id) {
        this->result_stream << (std::string) idx_id;
        return {};
    }

    std::any AstToString::visitSimpleIdentifier(SimpleIdentifier &identifier) {
        this->result_stream << (std::string) identifier;
        return {};
    }

    std::any AstToString::visitHexConst(HexConst &hex) {
        this->result_stream << hex.get_value();
        return {};
    }

    std::any AstToString::visitBinConst(BinConst &bin) {
        this->result_stream <<  "#b" << bin.get_value();
        return {};
    }
}
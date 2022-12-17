//
// Created by julian on 13.12.22.
//

#ifndef PHYSER_TO_STRING_PRINTER_H
#define PHYSER_TO_STRING_PRINTER_H

#include <SyGuSv21BaseVisitor.h>
#include <sstream>
#include "../exceptions/unsupported_feature.h"
#include "../exceptions/not_implemented.h"

class to_string_printer : public SyGuSv21BaseVisitor {

    std::stringstream result_stream;

public:

    to_string_printer() = default;

    std::any visitSymbol(SyGuSv21Parser::SymbolContext* ctx) override {
        this->result_stream << ctx->getText();
        return {};
    }

    std::any visitNumeral(SyGuSv21Parser::NumeralContext *ctx) override {
        this->result_stream << ctx->NUMERAL()->getSymbol()->getText();
        return {};
    }

    std::any visitDecimal(SyGuSv21Parser::DecimalContext *ctx) override {
        ctx->numeral(0)->accept(this);
        this->result_stream << ".";
        ctx->numeral(1) ->accept(this);
        return {};
    }

    std::any visitBoolConstTrue(SyGuSv21Parser::BoolConstTrueContext *ctx) override {
        this->result_stream << "true";
        return {};
    }

    std::any visitBoolConstFalse(SyGuSv21Parser::BoolConstFalseContext *ctx) override {
        this->result_stream << "false";
        return {};
    }

    std::any visitHexConst(SyGuSv21Parser::HexConstContext *ctx) override {
        this->result_stream << ctx->HEXCONST()->getText();
        return {};
    }

    std::any visitBinConst(SyGuSv21Parser::BinConstContext *ctx) override {
        this->result_stream << ctx->BINCONST()->getText();
        return {};
    }

    std::any visitStringConst(SyGuSv21Parser::StringConstContext *ctx) override {
        this->result_stream << ctx->STRINGCONST()->getText();
        return {};
    }

    std::any visitIndexedIdentifier(SyGuSv21Parser::IndexedIdentifierContext *ctx) override {
        throw unsupported_feature{"Indexed Identifiers are not supported for now."};
    }

    std::any visitIndex(SyGuSv21Parser::IndexContext *ctx) override {
        throw unsupported_feature{"Indexes are not supported for now."};
    }

    std::any visitParametricSort(SyGuSv21Parser::ParametricSortContext *ctx) override {
        this->result_stream << "(";
        ctx->identifier()->accept(this);
        for (auto x : ctx->sort()) {
            this->result_stream << " ";
            x->accept(this);
        }
        this->result_stream << ")";
        return {};
    }

    std::any visitApplicationTerm(SyGuSv21Parser::ApplicationTermContext *ctx) override {
        this->result_stream << "(";
        ctx->identifier()->accept(this);
        for (auto x : ctx->term()) {
            this->result_stream << " ";
            x->accept(this);
        }
        this->result_stream << ")";
        return {};
    }

    std::any visitExistsTerm(SyGuSv21Parser::ExistsTermContext *ctx) override {
        this->result_stream << "(exists (";
        for (auto x : ctx->sortedVar()) {
            this->result_stream << " ";
            x->accept(this);
        }
        this->result_stream << ") ";
        ctx->term()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitForallTerm(SyGuSv21Parser::ForallTermContext *ctx) override {
        this->result_stream << "(forall (";
        for (auto x : ctx->sortedVar()) {
            this->result_stream << " ";
            x->accept(this);
        }
        this->result_stream << ") ";
        ctx->term()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitLetTerm(SyGuSv21Parser::LetTermContext *ctx) override {
        this->result_stream << "(let (";
        for (auto x : ctx->varBinding()) {
            this->result_stream << " ";
            x->accept(this);
        }
        this->result_stream << ") ";
        ctx->term()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitBfApplicationTerm(SyGuSv21Parser::BfApplicationTermContext *ctx) override {
        this->result_stream << "(";
        ctx->identifier()->accept(this);
        for (auto x : ctx->bfTerm()) {
            this->result_stream << " ";
            x->accept(this);
        }
        this->result_stream << ")";
        return {};
    }

    std::any visitSortedVar(SyGuSv21Parser::SortedVarContext *ctx) override {
        this->result_stream << "(";
        ctx->symbol()->accept(this);
        this->result_stream << " ";
        ctx->sort()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitVarBinding(SyGuSv21Parser::VarBindingContext *ctx) override {
        this->result_stream << "(";
        ctx->symbol()->accept(this);
        this->result_stream << " ";
        ctx->term()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitFeature(SyGuSv21Parser::FeatureContext *ctx) override {
        this->result_stream << ":";
        if (ctx->GRAMMARS_FEATURE() != nullptr) {
            this->result_stream << ":grammars";
        } else if (ctx->FWD_DECLS_FEATURE() != nullptr) {
            this->result_stream << ":fwd-decls";
        } else if (ctx->RECURSION_FEATURE() != nullptr) {
            this->result_stream << ":recursion";
        } else if (ctx->ORACLES_FEATURE() != nullptr) {
            this->result_stream << ":oracles";
        } else if (ctx->WEIGHTS_FEATURE() != nullptr) {
            this->result_stream << ":weights";
        } else {
            throw unsupported_feature("When printing feature we encountered a non existing feature.");
        }
        return {};
    }

    // Commands
    std::any visitAssumeCmd(SyGuSv21Parser::AssumeCmdContext *ctx) override {
        this->result_stream << "(assume ";
        ctx->term()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitCheckSynthCmd(SyGuSv21Parser::CheckSynthCmdContext *ctx) override {
        this->result_stream << "(check-synth)";
        return {};
    }

    std::any visitConstraintCmd(SyGuSv21Parser::ConstraintCmdContext *ctx) override {
        this->result_stream << "(constraint ";
        ctx->term()->accept(this);
        this->result_stream << ")";

        return {};
    }

    std::any visitDeclareVarCmd(SyGuSv21Parser::DeclareVarCmdContext *ctx) override {
        this->result_stream << "(declare-var ";
        ctx->symbol()->accept(this);
        this->result_stream << " ";
        ctx->sort()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitSetFeatureCmd(SyGuSv21Parser::SetFeatureCmdContext *ctx) override {
        this->result_stream << "(set-feature ";
        ctx->feature()->accept(this);
        this->result_stream << " ";
        ctx->boolConst()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitSynthFunCmd(SyGuSv21Parser::SynthFunCmdContext *ctx) override {
        this->result_stream << "(synth-fun ";
        ctx->symbol()->accept(this);
        this->result_stream << " (";
        for (auto x : ctx->sortedVar()) {
            this->result_stream << " ";
            x->accept(this);
        }
        this->result_stream << ") ";
        ctx->sort()->accept(this);
        this->result_stream << " ";
        ctx->grammarDef()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitDeclareDatatype(SyGuSv21Parser::DeclareDatatypeContext *ctx) override {
        this->result_stream << "(declare-datatype ";
        ctx->symbol()->accept(this);
        this->result_stream << " ";
        ctx->dtDecl()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitDeclareDatatypes(SyGuSv21Parser::DeclareDatatypesContext *ctx) override {
        throw not_implemented("DeclareDatatypes has not been implemeneted yet.");
        this->result_stream << "(declare-datatypes ( ";
        //loop
        this->result_stream << ") (";
        //loop
        this->result_stream << "))";
        return {};
    }

    std::any visitDeclareSort(SyGuSv21Parser::DeclareSortContext *ctx) override {
        this->result_stream << "(declare-sort ";
        ctx->symbol()->accept(this);
        this->result_stream << " ";
        ctx->numeral()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitDefineFun(SyGuSv21Parser::DefineFunContext *ctx) override {
        this->result_stream << "(define-fun ";
        ctx->symbol()->accept(this);
        this->result_stream << " (";
        for (auto a : ctx->sortedVar()) {
            this->result_stream << " ";
            a->accept(this);
        }
        this->result_stream << ") ";
        ctx->sort()->accept(this);
        this->result_stream << " ";
        ctx->term()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitDefineSort(SyGuSv21Parser::DefineSortContext *ctx) override {
        this->result_stream << "(define-sort ";
        ctx->symbol()->accept(this);
        this->result_stream << " ";
        ctx->sort()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitSetInfo(SyGuSv21Parser::SetInfoContext *ctx) override {
        this->result_stream << "(set-info ";
        ctx->symbol()->accept(this);
        this->result_stream << " ";
        ctx->literal()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitSetLogic(SyGuSv21Parser::SetLogicContext *ctx) override {
        this->result_stream << "(set-logic ";
        ctx->symbol()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitSetOption(SyGuSv21Parser::SetOptionContext *ctx) override {
        this->result_stream << "(set-option ";
        ctx->symbol()->accept(this);
        this->result_stream << " ";
        ctx->literal()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitSortDecl(SyGuSv21Parser::SortDeclContext *ctx) override {
        this->result_stream << "(";
        ctx->symbol()->accept(this);
        this->result_stream << " ";
        ctx->numeral()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitDtDecl(SyGuSv21Parser::DtDeclContext *ctx) override {
        this->result_stream << "(";
        for (auto x : ctx->dtConsDecl()) {
            this->result_stream << " ";
            x->accept(this);
        }
        this->result_stream << ")";
        return {};
    }

     std::any visitDtConsDecl(SyGuSv21Parser::DtConsDeclContext *ctx) override {
         this->result_stream << "(";
         ctx->symbol()->accept(this);
         this->result_stream << " ";
         for (auto x : ctx->sortedVar()) {
             this->result_stream << " ";
             x->accept(this);
         }
         this->result_stream << ")";
         return {};
    }

    std::any visitGrammarDef(SyGuSv21Parser::GrammarDefContext *ctx) override {
        this->result_stream << "(";
        for (auto x : ctx->sortedVar()) {
            this->result_stream << " ";
            x->accept(this);
        }
        this->result_stream << ")";
        this->result_stream << " ";
        this->result_stream << "(";
        for (auto x : ctx->groupedRuleList()) {
            this->result_stream << " ";
            x->accept(this);
        }
        this->result_stream << ")";
        return {};
    }

    std::any visitGroupedRuleList(SyGuSv21Parser::GroupedRuleListContext *ctx) override {
        this->result_stream << "(";
        ctx->symbol()->accept(this);
        this->result_stream << " ";
        ctx->sort()->accept(this);
        this->result_stream << " (";
        for (auto x: ctx->gTerm()) {
            this->result_stream << " ";
            x->accept(this);
        }
        this->result_stream << "))";
        return {};
    }

    std::any visitConstantGTerm(SyGuSv21Parser::ConstantGTermContext *ctx) override {
        this->result_stream << "(Constant ";
        ctx->sort()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitVariableGTerm(SyGuSv21Parser::VariableGTermContext *ctx) override {
        this->result_stream << "(Variable ";
        ctx->sort()->accept(this);
        this->result_stream << ")";
        return {};
    }

    std::any visitProblem(SyGuSv21Parser::ProblemContext *ctx) override {
        for (auto a : ctx->cmd()) {
            a->accept(this);
            this->result_stream << std::endl;
        }
        return {};
    }

    std::string get_string(SyGuSv21Parser::ProblemContext* ctx) {
        ctx->accept(this);
        return result_stream.str();
    }
};


#endif //PHYSER_TO_STRING_PRINTER_H

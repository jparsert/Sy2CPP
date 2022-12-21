//
// Created by julian on 17.12.22.
//

#ifndef PHYSER_AST_H
#define PHYSER_AST_H

#include <utility>
#include <variant>
#include <vector>
#include <iostream>
#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>

#include "SyGuSv21BaseVisitor.h"
#include "../exceptions/not_implemented.h"
#include "../exceptions/unsupported_feature.h"



namespace ast {

    class AstVisitor;

    class AstNode {
    public:
        virtual std::any accept(std::shared_ptr<AstVisitor> visitor) = 0;

    };

    class SimpleIdentifier;
    class IndexedIdentifier;
    class Problem;
    class Literal;
    class Numeral;
    class Decimal;
    class BoolConst;
    class HexConst;
    class BinConst;
    class StringConst;
    class SimpleSort;
    class ParametricSort;
    class ApplicationTerm;
    class ExistsTerm;
    class ForallTerm;
    class LetTerm;
    class BfApplicationTerm;
    class AssumeCmd;
    class CheckSynthCmd;
    class ConstraintCmd;
    class DeclareVarCmd;
    class SetFeatureCmd;
    class SynthFunCmd;
    class DeclareDatatype;
    class DeclareDatatypes;
    class DeclareSort;
    class DefineFun;
    class DefineSort;
    class SetInfo;
    class SetLogic;
    class SetOption;
    class SortDecl;
    class DtDecl;
    class DtConsDecl;
    class GrammarDef;
    class GroupedRuleList;
    class ConstantGTerm;
    class VariableGTerm;
    class BfGTerm;

    class  AstVisitor {
    public:

        /**
         * Visit parse trees produced by SyGuSv21Parser.
         */
        virtual std::any visitProblem(std::shared_ptr<Problem> problem) = 0;

        virtual std::any visitLiteral(std::shared_ptr<Literal> lit) = 0;

        virtual std::any visitNumeral(std::shared_ptr<Numeral> numeral) = 0;

        virtual std::any visitDecimal(std::shared_ptr<Decimal> decimal) = 0;

        virtual std::any visitBoolConst(std::shared_ptr<BoolConst> boolConst) = 0;

        virtual std::any visitHexConst(std::shared_ptr<HexConst> hex) = 0;

        virtual std::any visitBinConst(std::shared_ptr<BinConst> bin) = 0;

        virtual std::any visitStringConst(std::shared_ptr<StringConst> s) = 0;

        virtual std::any visitSimpleIdentifier(std::shared_ptr<SimpleIdentifier> context) = 0;

        virtual std::any visitIndexedIdentifier(std::shared_ptr<IndexedIdentifier> context) = 0;

        virtual std::any visitSimpleSort(std::shared_ptr<SimpleSort> sort) = 0;

        virtual std::any visitParametricSort(std::shared_ptr<ParametricSort> sort) = 0;

        //virtual std::any visitTerm(std::shared_ptr<ApplicationTerm> application) = 0;

        virtual std::any visitApplicationTerm(std::shared_ptr<ApplicationTerm> application) = 0;

        virtual std::any visitExistsTerm(std::shared_ptr<ExistsTerm> exists) = 0;

        virtual std::any visitForallTerm(std::shared_ptr<ForallTerm> forall) = 0;

        virtual std::any visitLetTerm(std::shared_ptr<LetTerm> let) = 0;

        //virtual std::any visitBfTerm(SyGuSv21Parser::BfTermContext *context) = 0;

        virtual std::any visitBfApplicationTerm(std::shared_ptr<BfApplicationTerm> bfApp) = 0;

        //virtual std::any visitFeature(SyGuSv21Parser::FeatureContext *context) = 0;

        //virtual std::any visitCmd(SyGuSv21Parser::CmdContext *context) = 0;

        virtual std::any visitAssumeCmd(std::shared_ptr<AssumeCmd> assumeCmd) = 0;

        virtual std::any visitCheckSynthCmd(std::shared_ptr<CheckSynthCmd> context) = 0;

        virtual std::any visitConstraintCmd(std::shared_ptr<ConstraintCmd> context) = 0;

        virtual std::any visitDeclareVarCmd(std::shared_ptr<DeclareVarCmd> context) = 0;

        virtual std::any visitSetFeatureCmd(std::shared_ptr<SetFeatureCmd> context) = 0;

        virtual std::any visitSynthFunCmd(std::shared_ptr<SynthFunCmd> synthFun) = 0;

        //virtual std::any visitSmtCmd(std::shared_ptr<SmtCmd> smtCmd) = 0;

        virtual std::any visitDeclareDatatype(std::shared_ptr<DeclareDatatype> declDT) = 0;

        virtual std::any visitDeclareDatatypes(std::shared_ptr<DeclareDatatypes> context) = 0;

        virtual std::any visitDeclareSort(std::shared_ptr<DeclareSort> context) = 0;

        virtual std::any visitDefineFun(std::shared_ptr<DefineFun> context) = 0;

        virtual std::any visitDefineSort(std::shared_ptr<DefineSort> context) = 0;

        virtual std::any visitSetInfo(std::shared_ptr<SetInfo> context) = 0;

        virtual std::any visitSetLogic(std::shared_ptr<SetLogic> context) = 0;

        virtual std::any visitSetOption(std::shared_ptr<SetOption> context) = 0;

        virtual std::any visitSortDecl(std::shared_ptr<SortDecl> context) = 0;

        virtual std::any visitDtDecl(std::shared_ptr<DtDecl> context) = 0;

        virtual std::any visitDtConsDecl(std::shared_ptr<DtConsDecl> context) = 0;

        virtual std::any visitGrammarDef(std::shared_ptr<GrammarDef> context) = 0;

        virtual std::any visitGroupedRuleList(std::shared_ptr<GroupedRuleList> context) = 0;

        virtual std::any visitConstantGTerm(std::shared_ptr<ConstantGTerm> context) = 0;

        virtual std::any visitVariableGTerm(std::shared_ptr<VariableGTerm> context) = 0;

        virtual std::any visitBfGTerm(std::shared_ptr<BfGTerm> context) = 0;

        //virtual std::any visitSymbol(std::shared_ptr<Symbol> context) = 0;


    };

    enum class Feature  {
            GRAMMARS,
            FWD_DECLS,
            RECURSION,
            ORACLES,
            WEIGHTS
    };


    class Command : public AstNode {

    };

    class Term : public AstNode {

    };

    using TermPtr = std::shared_ptr<ast::Term>;


    class Literal : public AstNode {

    };

    // Identifier
    class identifier : public Term {
    public:
        [[nodiscard]] virtual std::size_t get_hash() const = 0;
    };

    class SimpleIdentifier : public identifier {
        std::string symbol;
    public:

        explicit SimpleIdentifier(std::string symb): symbol{std::move(symb)} {}

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitSimpleIdentifier(std::shared_ptr<SimpleIdentifier>(this));
        }

        std::string get_symbol() {
            return this->symbol;
        }

        bool operator==(SimpleIdentifier& other) {
            return this->symbol == other.get_symbol();
        }

        [[nodiscard]] std::size_t get_hash() const override {
            return std::hash<std::string>()(this->symbol);
        }
    };

    class IndexedIdentifier : public identifier {
    public:

        explicit IndexedIdentifier() {
            throw not_implemented("Indexed identifiers are not supported yet.");
        }

        explicit IndexedIdentifier(const std::string& symbol) {
            throw not_implemented("Indexed identifiers are not supported yet.");
        }

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitIndexedIdentifier(std::shared_ptr<IndexedIdentifier>(this));
        }

        bool operator==(IndexedIdentifier& other) {
            throw unsupported_feature("We do not support indexed identifiers yet.");
        }

        [[nodiscard]] std::size_t get_hash() const override {
            throw unsupported_feature("We do not support indexed identifiers yet.");
        }

    };

    using EitherIdentifier = std::variant<ast::SimpleIdentifier, ast::IndexedIdentifier>;



    class Problem : public AstNode {
    private:
        std::vector<std::shared_ptr<Command>> commands;

    public:

        void add_command(std::shared_ptr<Command>& cmd) {
            this->commands.push_back(cmd);
        }

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitProblem(std::shared_ptr<Problem>(this));
        }
    };

    class Numeral : public  Literal {

    private:
        long val;

    public:
        explicit Numeral(long v) : val{v} {}
        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitNumeral(std::shared_ptr<Numeral>(this));
        }
    };

    class Decimal : public  Literal {
    public:

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitDecimal(std::shared_ptr<Decimal>(this));
        }
    };

    class BoolConst : public  Literal {
    private:
        bool val;

    public:

        explicit BoolConst(bool x): val{x}{}

        bool get_value() const {
            return this->val;
        }

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitBoolConst(std::shared_ptr<BoolConst>(this));
        }
    };

    class HexConst : public  Literal {
        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitHexConst(std::shared_ptr<HexConst>(this));
        }
    };

    class BinConst : public  Literal {
        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitBinConst(std::shared_ptr<BinConst>(this));
        }
    };

    class StringConst : public  Literal {
    private:
        std::string str;

    public:

        explicit StringConst(std::string s): str{std::move(s)} {}


        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitStringConst(std::shared_ptr<StringConst>(this));
        }
    };

    class Sort : public AstNode {

    };

    class SimpleSort : public  Sort {
    private:
        EitherIdentifier identifier;

    public:
        explicit SimpleSort(EitherIdentifier& id): identifier(id) {}

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitSimpleSort(std::shared_ptr<SimpleSort>(this));
        }
    };

    class ParametricSort : public  Sort {
        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitParametricSort(std::shared_ptr<ParametricSort>(this));
        }
    };

    using EitherSort = std::variant<std::shared_ptr<ast::SimpleSort>, std::shared_ptr<ast::ParametricSort>>;


    class ApplicationTerm : public  Term {
    private:
        std::variant<SimpleIdentifier, IndexedIdentifier> id;
        std::vector<std::shared_ptr<Term>> arguments;

    public:

        ApplicationTerm(std::variant<SimpleIdentifier, IndexedIdentifier>& iden,
                        std::vector<std::shared_ptr<Term>>& args) :
        id{iden},
        arguments{args}
        { }

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitApplicationTerm(std::shared_ptr<ApplicationTerm>(this));
        }
    };

    using SortedVar = std::pair<ast::EitherIdentifier, std::shared_ptr<ast::EitherSort>>;

    class ExistsTerm : public  Term {
    private:
        std::vector<std::shared_ptr<SortedVar>> vars;
        std::shared_ptr<Term> subterm;

    public:

        ExistsTerm(std::vector<std::shared_ptr<SortedVar>>& v,
                            std::shared_ptr<Term>& t): vars{v}, subterm(t)
                            { }

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitExistsTerm(std::shared_ptr<ExistsTerm>(this));
        }
    };

    class ForallTerm : public  Term {
    private:
        std::vector<std::shared_ptr<SortedVar>> vars;
        std::shared_ptr<Term> subterm;

    public:

        ForallTerm(std::vector<std::shared_ptr<SortedVar>>& v,
                            std::shared_ptr<Term>& t): vars{v}, subterm(t)
        { }

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitForallTerm(std::shared_ptr<ForallTerm>(this));
        }
    };

    using VarBinding = std::pair<EitherIdentifier, std::shared_ptr<Term>>;

    class LetTerm : public  Term {
    private:
        std::vector<std::shared_ptr<VarBinding>> bindings;
        std::shared_ptr<Term> subterm;

    public:

        LetTerm(std::vector<std::shared_ptr<VarBinding>>& bdgs, std::shared_ptr<Term>& t): bindings{bdgs}, subterm(t)
        { }

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitLetTerm(std::shared_ptr<LetTerm>(this));
        }
    };

    class AssumeCmd : public  Command {
    private:
        std::shared_ptr<Term> term;

    public:
        explicit AssumeCmd(std::shared_ptr<Term> t) : term{std::move(t)} {}

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitAssumeCmd(std::shared_ptr<AssumeCmd>(this));
        }
    };

    class CheckSynthCmd : public  Command {
        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitCheckSynthCmd(std::shared_ptr<CheckSynthCmd>(this));
        }
    };

    class ConstraintCmd : public  Command {
    private:
        TermPtr term;

    public:

        explicit ConstraintCmd(TermPtr& ptr): term{ptr} {

        }

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitConstraintCmd(std::shared_ptr<ConstraintCmd>(this));
        }
    };

    class DeclareVarCmd : public  Command {
    private:
        EitherIdentifier id;
        std::shared_ptr<EitherSort> sort;

    public:

        DeclareVarCmd(EitherIdentifier& iden, std::shared_ptr<EitherSort>& srt): id{iden}, sort{srt} {

        }

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitDeclareVarCmd(std::shared_ptr<DeclareVarCmd>(this));
        }
    };

    class SetFeatureCmd : public  Command {

    private:

        Feature feature;
        bool value;

    public:

        SetFeatureCmd(Feature f, bool v): feature{f}, value{v} {}

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitSetFeatureCmd(std::shared_ptr<SetFeatureCmd>(this));
        }
    };

    class SynthFunCmd : public  Command {
    private:

        EitherIdentifier id;

        std::vector<std::shared_ptr<SortedVar>> arguments;

        std::shared_ptr<EitherSort> sort;

        std::shared_ptr<GrammarDef> grammar;

    public:

        SynthFunCmd(EitherIdentifier& iden, std::vector<std::shared_ptr<SortedVar>>& args,
                    std::shared_ptr<EitherSort>& srt, std::shared_ptr<GrammarDef>& grmmr): id{iden}, arguments{args},
                    sort{srt}, grammar{grmmr}{
        }

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitSynthFunCmd(std::shared_ptr<SynthFunCmd>(this));
        }
    };

    class DeclareDatatype : public  Command {
        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitDeclareDatatype(std::shared_ptr<DeclareDatatype>(this));
        }
    };

    class DeclareDatatypes : public  Command {
        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitDeclareDatatypes(std::shared_ptr<DeclareDatatypes>(this));
        }
    };

    class DeclareSort : public  Command {

    private:
        EitherIdentifier id;

        std::shared_ptr<Numeral> numeral;

    public:

        DeclareSort(EitherIdentifier iden, std::shared_ptr<Numeral>& num) : id{std::move(iden)}, numeral{num}{}

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitDeclareSort(std::shared_ptr<DeclareSort>(this));
        }
    };

    class DefineFun : public  Command {

    private:
        EitherIdentifier id;

        std::vector<ast::SortedVar> arguments;

        std::shared_ptr<EitherSort> sort;

        TermPtr term;

    public:
        DefineFun(EitherIdentifier iden, std::vector<ast::SortedVar>& args, std::shared_ptr<EitherSort>& srt, TermPtr& tm): id{std::move(iden)},
        arguments{args}, sort{srt}, term{tm} {}

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitDefineFun(std::shared_ptr<DefineFun>(this));
        }
    };

    class DefineSort : public  Command {
    private:
        EitherIdentifier id;

        std::shared_ptr<EitherSort> sort;

    public:

        DefineSort(EitherIdentifier iden, std::shared_ptr<EitherSort>& srt): id{std::move(iden)}, sort{srt} {}

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitDefineSort(std::shared_ptr<DefineSort>(this));
        }
    };

    class SetInfo : public  Command {

    private:

        std::string keyword;
        std::shared_ptr<Literal> literal;

    public:

        SetInfo(std::string& kw, std::shared_ptr<Literal>& lit): keyword{kw}, literal{lit} {

        }

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitSetInfo(std::shared_ptr<SetInfo>(this));
        }
    };

    class SetLogic : public  Command {

    private:
        std::string logic;

    public:
        explicit SetLogic(std::string& str) : logic{str} {}

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitSetLogic(std::shared_ptr<SetLogic>(this));
        }
    };

    class SetOption : public  Command {
    private:

        std::string keyword;
        std::shared_ptr<Literal> literal;

    public:

        SetOption(std::string& kw, std::shared_ptr<Literal>& lit): keyword{kw}, literal{lit} {

        }
        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitSetOption(std::shared_ptr<SetOption>(this));
        }
    };

    class SortDecl : public  AstNode {
        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitSortDecl(std::shared_ptr<SortDecl>(this));
        }
    };

    class DtDecl : public  AstNode {
        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitDtDecl(std::shared_ptr<DtDecl>(this));
        }
    };

    class DtConsDecl : public  AstNode {
        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitDtConsDecl(std::shared_ptr<DtConsDecl>(this));
        }
    };

    class GroupedRuleList : public  AstNode {
    private:
        EitherIdentifier id;

        std::shared_ptr<EitherSort> sort;

        std::vector<TermPtr> terms;

    public:

        GroupedRuleList(EitherIdentifier iden, std::shared_ptr<EitherSort>& srt, std::vector<TermPtr>& trm):
        id{std::move(iden)}, sort{srt}, terms{trm} {}

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitGroupedRuleList(std::shared_ptr<GroupedRuleList>(this));
        }
    };

    class GrammarDef : public  AstNode {
    private:
        std::vector<std::shared_ptr<ast::SortedVar>> vars;
        std::vector<std::shared_ptr<GroupedRuleList>> rules;

    public:
        GrammarDef(std::vector<std::shared_ptr<ast::SortedVar>>& var,
                   std::vector<std::shared_ptr<GroupedRuleList>>& rule) : vars{var}, rules{rule}{}

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitGrammarDef(std::shared_ptr<GrammarDef>(this));
        }
    };


    class ConstantGTerm : public  AstNode {
    private:
        std::shared_ptr<ast::EitherSort> sort;
    public:

        explicit ConstantGTerm(std::shared_ptr<ast::EitherSort>& srt): sort{srt} {

        }

        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitConstantGTerm(std::shared_ptr<ConstantGTerm>(this));
        }
    };

    class VariableGTerm : public  AstNode {
    private:
        std::shared_ptr<ast::EitherSort> sort;
    public:

        explicit VariableGTerm(std::shared_ptr<ast::EitherSort>& srt): sort{srt} {

        }
        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitVariableGTerm(std::shared_ptr<VariableGTerm>(this));
        }
    };

    class BfGTerm : public  AstNode {
        std::any accept(std::shared_ptr<AstVisitor> visitor) override {
            return visitor->visitBfGTerm(std::shared_ptr<BfGTerm>(this));
        }
    };



} // namespace ast


namespace  std {
    template<>
    struct hash<ast::SimpleIdentifier> {
        std::size_t operator()(const ast::SimpleIdentifier& id) {
            return id.get_hash();
        }
    };

    template<>
    struct hash<ast::IndexedIdentifier> {
        std::size_t operator()(const ast::IndexedIdentifier& id) {
            return id.get_hash();
        }
    };
}


#endif //PHYSER_AST_H

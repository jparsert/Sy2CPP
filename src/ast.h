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
#include <any>
#include <memory>
#include <optional>

#include "exceptions.h"



namespace Sy2CPP {

    class AstVisitor;

    class SimpleIdentifier;
    class IndexedIdentifier;
    class IdentifierTerm;
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
    class AssumeCmd;
    class CheckSynthCmd;
    class ConstraintCmd;
    class DeclareVarCmd;
    class SetFeatureCmd;
    class SynthFunCmd;
    class DeclareDatatype;
    class DeclareDatatypes;
    class DeclareSort;
    class DefineFunCmd;
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


    class AstNode {
    public:
        virtual std::any accept(AstVisitor &visitor) = 0;

    };

    class AstVisitor {
    public:

        virtual std::any visitProblem(Problem &problem) = 0;

        virtual std::any visitNumeral(Numeral &numeral) = 0;

        virtual std::any visitDecimal(Decimal &decimal) = 0;

        virtual std::any visitBoolConst(BoolConst &boolConst) = 0;

        virtual std::any visitHexConst(HexConst &hex) = 0;

        virtual std::any visitBinConst(BinConst &bin) = 0;

        virtual std::any visitStringConst(StringConst &s) = 0;

        virtual std::any visitSimpleIdentifier(SimpleIdentifier &identifier) = 0;

        virtual std::any visitIndexedIdentifier(IndexedIdentifier &indexedIdentifier) = 0;

        virtual std::any visitIdentifierTerm(IdentifierTerm &term) = 0;

        virtual std::any visitSimpleSort(SimpleSort &sort) = 0;

        virtual std::any visitParametricSort(ParametricSort &sort) = 0;

        virtual std::any visitApplicationTerm(ApplicationTerm &application) = 0;

        virtual std::any visitExistsTerm(ExistsTerm &exists) = 0;

        virtual std::any visitForallTerm(ForallTerm &forall) = 0;

        virtual std::any visitLetTerm(LetTerm &let) = 0;

        virtual std::any visitAssumeCmd(AssumeCmd &assumeCmd) = 0;

        virtual std::any visitCheckSynthCmd(CheckSynthCmd &context) = 0;

        virtual std::any visitConstraintCmd(ConstraintCmd &context) = 0;

        virtual std::any visitDeclareVarCmd(DeclareVarCmd &context) = 0;

        virtual std::any visitSetFeatureCmd(SetFeatureCmd &context) = 0;

        virtual std::any visitSynthFunCmd(SynthFunCmd &synthFun) = 0;

        virtual std::any visitDeclareDatatype(DeclareDatatype &declDT) = 0;

        virtual std::any visitDeclareDatatypes(DeclareDatatypes &context) = 0;

        virtual std::any visitDeclareSort(DeclareSort &context) = 0;

        virtual std::any visitDefineFun(DefineFunCmd &context) = 0;

        virtual std::any visitDefineSort(DefineSort &context) = 0;

        virtual std::any visitSetInfo(SetInfo &context) = 0;

        virtual std::any visitSetLogic(SetLogic &context) = 0;

        virtual std::any visitSetOption(SetOption &context) = 0;

        virtual std::any visitSortDecl(SortDecl &context) = 0;

        virtual std::any visitDtDecl(DtDecl &context) = 0;

        virtual std::any visitDtConsDecl(DtConsDecl &context) = 0;

        virtual std::any visitGrammarDef(GrammarDef &context) = 0;

        virtual std::any visitGroupedRuleList(GroupedRuleList &context) = 0;

        virtual std::any visitConstantGTerm(ConstantGTerm &context) = 0;

        virtual std::any visitVariableGTerm(VariableGTerm &context) = 0;

    };


    class TermVisitor : public AstVisitor {

        std::any visitNumeral(Numeral &numeral) override = 0;

        std::any visitDecimal(Decimal &decimal) override = 0;

        std::any visitBoolConst(BoolConst &boolConst) override = 0;

        std::any visitHexConst(HexConst &hex) override = 0;

        std::any visitBinConst(BinConst &bin) override = 0;

        std::any visitStringConst(StringConst &s) override = 0;

        std::any visitIdentifierTerm(IdentifierTerm &term) override = 0;

        std::any visitApplicationTerm(ApplicationTerm &application) override = 0;

        std::any visitExistsTerm(ExistsTerm &exists) override = 0;

        std::any visitForallTerm(ForallTerm &forall) override = 0;

        std::any visitLetTerm(LetTerm &let) override = 0;


        // We don't allow for other ast nodes to be visited in a term visitor

        std::any visitProblem(Problem &problem) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitSimpleIdentifier(SimpleIdentifier &identifier) final{
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitIndexedIdentifier(IndexedIdentifier &indexedIdentifier) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitSimpleSort(SimpleSort &sort) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitParametricSort(ParametricSort &sort) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitAssumeCmd(AssumeCmd &assumeCmd) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitCheckSynthCmd(CheckSynthCmd &context) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitConstraintCmd(ConstraintCmd &context) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitDeclareVarCmd(DeclareVarCmd &context) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitSetFeatureCmd(SetFeatureCmd &context) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitSynthFunCmd(SynthFunCmd &synthFun) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitDeclareDatatype(DeclareDatatype &declDT) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitDeclareDatatypes(DeclareDatatypes &context) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitDeclareSort(DeclareSort &context) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitDefineFun(DefineFunCmd &context) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitDefineSort(DefineSort &context) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitSetInfo(SetInfo &context) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitSetLogic(SetLogic &context) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitSetOption(SetOption &context) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitSortDecl(SortDecl &context) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitDtDecl(DtDecl &context) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitDtConsDecl(DtConsDecl &context) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitGrammarDef(GrammarDef &context) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitGroupedRuleList(GroupedRuleList &context) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitConstantGTerm(ConstantGTerm &context) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }

        std::any visitVariableGTerm(VariableGTerm &context) final {
            throw NotImplemented("Wrong AstNode in Term visitor");
        }
    };


    enum class Feature {
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


    class Literal : public Term {

    };

    using TermPtr = std::shared_ptr<Term>;
    using ComandPtr = std::shared_ptr<Command>;
    using LiteralPtr = std::shared_ptr<Literal>;


    class Numeral : public Literal {

    private:
        long val;

    public:
        explicit Numeral(long v) : val{v} {}

        [[nodiscard]] long get_value() const;

        bool operator==(const Numeral &num) const;

        explicit operator std::string() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitNumeral(*this);
        }
    };

}



namespace Sy2CPP {

    class Decimal : public Literal {
    public:

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitDecimal(*this);
        }
    };

    class BoolConst : public Literal {
    private:
        bool val;

    public:
        explicit BoolConst(bool x) : val{x} {}

        [[nodiscard]] bool get_value() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitBoolConst(*this);
        }
    };

    class HexConst : public Literal {
        std::any accept(AstVisitor &visitor) override {
            return visitor.visitHexConst(*this);
        }
    };

    class BinConst : public Literal {
        std::any accept(AstVisitor &visitor) override {
            return visitor.visitBinConst(*this);
        }
    };

    class StringConst : public Literal {
    private:
        std::string str;

    public:
        explicit StringConst(std::string s) : str{std::move(s)} {}

        [[nodiscard]] std::string get_string() const {
            return str;
        }

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitStringConst(*this);
        }
    };


    // Identifier
    class Identifier : public AstNode {
    public:
        [[nodiscard]] virtual std::size_t get_hash() const = 0;
    };

    class SimpleIdentifier : public Identifier {
    private:
        std::string symbol;

    public:
        explicit SimpleIdentifier(std::string symb) : symbol{std::move(symb)} {}

        std::any accept(AstVisitor &visitor) override;

        [[nodiscard]] std::string get_symbol() const;

        bool operator==(const SimpleIdentifier &other) const;

        bool operator!=(const SimpleIdentifier &other) const;

        [[nodiscard]] std::size_t get_hash() const override;

        explicit operator std::string() const;
    };
}

// Hash functions for numeral and SimpleIdentifier
namespace std {
    template<>
    struct hash<Sy2CPP::Numeral> {
        std::size_t operator()(const Sy2CPP::Numeral& num) {
            return num.get_value();
        }
    };

    template<>
    struct hash<Sy2CPP::SimpleIdentifier> {
        std::size_t operator()(const Sy2CPP::SimpleIdentifier &id) {
            return id.get_hash();
        }
    };
}


namespace Sy2CPP {

    using Index = std::variant<Numeral, SimpleIdentifier>;

    class IndexedIdentifier : public Identifier {
        SimpleIdentifier symbol;
        std::vector<Index> indices;

    public:

        explicit IndexedIdentifier(SimpleIdentifier &symb, const std::vector<Index> &index_)
                : symbol(symb), indices(index_)
        {
            if (indices.empty()) { // A IndexedIdentifier needs at least one index
                throw WrongArguments("Indexed Identifier requires 1 or more arguments.");
            }
        }

        bool operator==(const IndexedIdentifier &other) const;

        bool operator!=(const IndexedIdentifier &other) const;

        [[nodiscard]] std::size_t get_hash() const override;

        explicit operator std::string() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitIndexedIdentifier(*this);
        }

    };

}

// We create hashing functions in the std namespace so that containers like unordered set
namespace  std {

    template<>
    struct hash<Sy2CPP::IndexedIdentifier> {
        std::size_t operator()(const Sy2CPP::IndexedIdentifier &id) {
            return id.get_hash();
        }
    };
}


namespace Sy2CPP {

    using EitherIdentifier = std::variant<SimpleIdentifier, IndexedIdentifier>;

    std::string to_string(const EitherIdentifier &ident);

    inline EitherIdentifier get_simple_id_from_str(const std::string &s) {
        return EitherIdentifier{SimpleIdentifier{s}};
    }

    class IdentifierTerm : public Term {
    private:
        EitherIdentifier identifier;

    public:
        explicit IdentifierTerm(EitherIdentifier &id) : identifier{id} { }

        EitherIdentifier get_identifier();

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitIdentifierTerm(*this);
        }

    };

    class Problem : public AstNode {
    private:
        std::vector<ComandPtr> commands;

    public:
        void add_command(ComandPtr &cmd);

        std::vector<ComandPtr> &get_commands() {
            return this->commands;
        }

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitProblem(*this);
        }

    };


    class Sort : public AstNode {

    public:
        [[nodiscard]] virtual std::size_t get_hash() const = 0;

    };

    class SimpleSort : public Sort {
    private:
        EitherIdentifier identifier;

    public:
        explicit SimpleSort(EitherIdentifier &id) : identifier(id) {}

        explicit SimpleSort(EitherIdentifier &&id) : identifier(id) {}

        [[nodiscard]] std::size_t get_hash() const override;

        bool operator==(const SimpleSort &other) const;

        bool operator!=(const SimpleSort &other) const;

        [[nodiscard]] EitherIdentifier get_identifier() const;

        explicit operator std::string() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitSimpleSort(*this);
        }

    };

    using EitherSort = std::variant<SimpleSort, ParametricSort>;

    class ParametricSort : public Sort {
    private:
        EitherIdentifier identifier;
        std::vector<EitherSort> parameters;

    public:
        ParametricSort(EitherIdentifier &id, std::vector<EitherSort> &params) :
                identifier{id}, parameters{params} {}

        [[nodiscard]] std::size_t get_hash() const override {
            throw NotImplemented("Parametic Sorts hash is not implemented");

        }

        bool operator==(const ParametricSort &other) const {
            return identifier == other.identifier and parameters == other.parameters;
        }

        bool operator!=(const ParametricSort &other) const {
            return !(identifier == other.identifier and parameters == other.parameters);
        }

        explicit operator std::string() const {
            throw NotImplemented("Parametric sort string operator has not been implemented.");
        }

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitParametricSort(*this);
        }
    };

}

namespace std {
    template<>
    struct hash<Sy2CPP::SimpleSort> {
        std::size_t operator()(const Sy2CPP::SimpleSort &sort) {
            return sort.get_hash();
        }
    };

    template<>
    struct hash<Sy2CPP::ParametricSort> {
        std::size_t operator()(const Sy2CPP::ParametricSort &sort) {
            return sort.get_hash();
        }
    };
}

namespace Sy2CPP{

    std::string to_string(const EitherSort &ident);

    inline EitherSort get_simple_sort_from_str(const std::string &s) {
        return {SimpleSort(get_simple_id_from_str(s))};

    }

    class ApplicationTerm : public Term {
    private:
        EitherIdentifier id;
        std::vector<TermPtr> arguments;

    public:
        ApplicationTerm(std::variant<SimpleIdentifier, IndexedIdentifier> &iden,
                        std::vector<TermPtr> &args) :
                id{iden},
                arguments{args} {}

        [[nodiscard]] EitherIdentifier get_identifier() const;

        std::vector<TermPtr> &get_arguments();

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitApplicationTerm(*this);
        }
    };

    using SortedVar = std::pair<EitherIdentifier, EitherSort>;

    class ExistsTerm : public Term {
    private:
        std::vector<SortedVar> vars;
        TermPtr subterm;

    public:

        ExistsTerm(std::vector<SortedVar> &v, TermPtr &t) : vars{v}, subterm(t) {}

        [[nodiscard]] std::vector<SortedVar> get_vars() const;

        [[nodiscard]] TermPtr get_term() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitExistsTerm(*this);
        }
    };

    class ForallTerm : public Term {
    private:
        std::vector<SortedVar> vars;
        TermPtr subterm;

    public:

        ForallTerm(std::vector<SortedVar> &v,
                   TermPtr &t) : vars{v}, subterm(t) {}

        [[nodiscard]] std::vector<SortedVar> get_vars() const;

        [[nodiscard]] TermPtr get_term() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitForallTerm(*this);
        }
    };

    using VarBinding = std::pair<EitherIdentifier, TermPtr>;

    class LetTerm : public Term {
    private:
        std::vector<VarBinding> bindings;
        TermPtr subterm;

    public:

        LetTerm(std::vector<VarBinding> &bdgs, TermPtr &t) : bindings{bdgs}, subterm(t) {}

        [[nodiscard]] std::vector<VarBinding> get_var_bindings() const;

        [[nodiscard]] TermPtr get_term() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitLetTerm(*this);
        }
    };

    class AssumeCmd : public Command {
    private:
        TermPtr term;

    public:
        explicit AssumeCmd(TermPtr t) : term{std::move(t)} {}

        [[nodiscard]] TermPtr get_term() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitAssumeCmd(*this);
        }
    };

    class CheckSynthCmd : public Command {
        std::any accept(AstVisitor &visitor) override {
            return visitor.visitCheckSynthCmd(*this);
        }
    };

    class ConstraintCmd : public Command {
    private:
        TermPtr term;

    public:

        explicit ConstraintCmd(TermPtr &ptr) : term{ptr} { }

        [[nodiscard]] TermPtr get_term() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitConstraintCmd(*this);
        }
    };

    class DeclareVarCmd : public Command {
    private:
        EitherIdentifier id;
        EitherSort sort;

    public:
        DeclareVarCmd(EitherIdentifier &iden, EitherSort &srt) : id{iden}, sort{srt} { }

        [[nodiscard]] EitherIdentifier get_identifier() const;

        [[nodiscard]] EitherSort get_sort() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitDeclareVarCmd(*this);
        }


    };

    class SetFeatureCmd : public Command {
    private:
        Feature feature;
        bool value;

    public:
        SetFeatureCmd(Feature f, bool v) : feature{f}, value{v} {}

        Feature get_feature();

        [[nodiscard]] bool get_value() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitSetFeatureCmd(*this);
        }
    };


    class GroupedRuleList : public AstNode {
    private:
        EitherIdentifier id;
        EitherSort sort;
        std::vector<TermPtr> terms;

    public:
        GroupedRuleList(EitherIdentifier iden, EitherSort &srt, std::vector<TermPtr> &trm) :
                id{std::move(iden)}, sort{srt}, terms{trm} {}

        [[nodiscard]] EitherIdentifier get_identifier() const;

        [[nodiscard]] EitherSort get_sort() const;

        [[nodiscard]] std::vector<TermPtr> get_terms() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitGroupedRuleList(*this);
        }
    };

    class GrammarDef : public AstNode {

    private:
        std::vector<SortedVar> non_terminals;
        std::vector<GroupedRuleList> rules;

    public:
        GrammarDef(std::vector<SortedVar> &var, std::vector<GroupedRuleList> &rule) : non_terminals{var}, rules{rule} {}

        [[nodiscard]] std::vector<SortedVar> get_non_terminals() const;

        [[nodiscard]] std::vector<GroupedRuleList> get_rules() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitGrammarDef(*this);
        }
    };

    class SynthFunCmd : public Command {
    private:
        EitherIdentifier id;
        std::vector<SortedVar> arguments;
        EitherSort sort;
        GrammarDef grammar;

    public:
        SynthFunCmd(EitherIdentifier &iden, std::vector<SortedVar> &args,
                    EitherSort &srt, GrammarDef &grmmr) : id{iden}, arguments{args},
                                                          sort{srt}, grammar{grmmr} {}

        [[nodiscard]] EitherIdentifier get_identifier() const;

        [[nodiscard]] std::vector<SortedVar> &get_arguments();

        [[nodiscard]] EitherSort get_sort() const;

        [[nodiscard]] GrammarDef get_grammar() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitSynthFunCmd(*this);
        }

    };

    class DeclareDatatype : public Command {

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitDeclareDatatype(*this);
        }
    };

    class DeclareDatatypes : public Command {

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitDeclareDatatypes(*this);
        }
    };

    class DeclareSort : public Command {
    private:
        EitherIdentifier id;
        Numeral numeral;

    public:
        DeclareSort(EitherIdentifier &iden, Numeral &num) : id{iden}, numeral{num} {}

        EitherIdentifier get_identifier();

        Numeral get_numeral();

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitDeclareSort(*this);
        }
    };

    class DefineFunCmd : public Command {
    private:
        EitherIdentifier id;
        std::vector<SortedVar> arguments;
        EitherSort sort;
        TermPtr term;

    public:
        DefineFunCmd(EitherIdentifier &iden,
                     std::vector<SortedVar> &args,
                     EitherSort &srt,
                     TermPtr &tm) :
                id{iden}, arguments{args}, sort{srt}, term{tm} {}

        [[nodiscard]] EitherIdentifier get_identifier() const;

        [[nodiscard]] std::vector<SortedVar> &get_arguments();

        [[nodiscard]] EitherSort get_sort() const;

        [[nodiscard]] TermPtr get_term() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitDefineFun(*this);
        }

    };

    class DefineSort : public Command {
    private:
        EitherIdentifier id;
        EitherSort sort;

    public:
        DefineSort(EitherIdentifier &iden, EitherSort &srt) : id{iden}, sort{srt} {}

        EitherIdentifier get_identifier();

        EitherSort get_sort();

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitDefineSort(*this);
        }
    };

    class SetInfo : public Command {
    private:
        std::string keyword;
        LiteralPtr literal;

    public:
        SetInfo(std::string &kw, LiteralPtr &lit) : keyword{kw}, literal{lit} { }

        std::string get_keyword();

        LiteralPtr get_literal();

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitSetInfo(*this);
        }
    };

    class SetLogic : public Command {
    private:
        std::string logic;

    public:
        explicit SetLogic(std::string &str) : logic{str} {}

        [[nodiscard]] std::string get_logic() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitSetLogic(*this);
        }
    };

    class SetOption : public Command {
    private:
        std::string keyword;
        LiteralPtr literal;

    public:
        SetOption(std::string &kw, LiteralPtr &lit) : keyword{kw}, literal{lit} {}

        [[nodiscard]] std::string get_keyword() const;

        [[nodiscard]] LiteralPtr get_literal() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitSetOption(*this);
        }
    };

    class SortDecl : public AstNode {
    public:
        std::any accept(AstVisitor &visitor) override {
            return visitor.visitSortDecl(*this);
        }
    };

    class DtDecl : public AstNode {
    public:
        std::any accept(AstVisitor &visitor) override {
            return visitor.visitDtDecl(*this);
        }
    };

    class DtConsDecl : public AstNode {
    public:
        std::any accept(AstVisitor &visitor) override {
            return visitor.visitDtConsDecl(*this);
        }
    };


    class ConstantGTerm : public Term {
    private:
        EitherSort sort;

    public:

        explicit ConstantGTerm(EitherSort &srt) : sort{srt} { }

        [[nodiscard]] EitherSort get_sort() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitConstantGTerm(*this);
        }
    };

    class VariableGTerm : public Term {
    private:
        EitherSort sort;

    public:

        explicit VariableGTerm(EitherSort &srt) : sort{srt} { }

        [[nodiscard]] EitherSort get_sort() const;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitVariableGTerm(*this);
        }
    };


    using SyGuSSolution = std::optional<std::vector<DefineFunCmd>>;


    class AstBaseVisitor : public AstVisitor {
    public:

        std::any visitIdentifierTerm(IdentifierTerm &term) override {
            return std::visit([&](auto id) mutable { return id.accept(*this); }, term.get_identifier());
        }


        std::any visitNumeral(Numeral &numeral) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitDecimal(Decimal &decimal) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitBoolConst(BoolConst &boolConst) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitHexConst(HexConst &hex) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitBinConst(BinConst &bin) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitStringConst(StringConst &s) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitApplicationTerm(ApplicationTerm &application) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitExistsTerm(ExistsTerm &exists) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitForallTerm(ForallTerm &forall) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitLetTerm(LetTerm &let) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitProblem(Problem &problem) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitSimpleIdentifier(SimpleIdentifier &identifier) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitIndexedIdentifier(IndexedIdentifier &indexedIdentifier) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitSimpleSort(SimpleSort &sort) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitParametricSort(ParametricSort &sort) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitAssumeCmd(AssumeCmd &assumeCmd) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitCheckSynthCmd(CheckSynthCmd &context) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitConstraintCmd(ConstraintCmd &context) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitDeclareVarCmd(DeclareVarCmd &context) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitSetFeatureCmd(SetFeatureCmd &context) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitSynthFunCmd(SynthFunCmd &synthFun) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitDeclareDatatype(DeclareDatatype &declDT) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitDeclareDatatypes(DeclareDatatypes &context) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitDeclareSort(DeclareSort &context) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitDefineFun(DefineFunCmd &context) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitDefineSort(DefineSort &context) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitSetInfo(SetInfo &context) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitSetLogic(SetLogic &context) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitSetOption(SetOption &context) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitSortDecl(SortDecl &context) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitDtDecl(DtDecl &context) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitDtConsDecl(DtConsDecl &context) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitGrammarDef(GrammarDef &context) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitGroupedRuleList(GroupedRuleList &context) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitConstantGTerm(ConstantGTerm &context) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

        std::any visitVariableGTerm(VariableGTerm &context) override {
            throw NotImplemented("Not implemented in AstBaseVisitor.");
        }

    };

}

#endif //PHYSER_AST_H

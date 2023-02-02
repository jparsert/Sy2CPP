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

    class Term;
    class Command;
    class Literal;

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

    class BfTermVisitor : public TermVisitor {

        std::any visitNumeral(Numeral &numeral) override = 0;

        std::any visitDecimal(Decimal &decimal) override = 0;

        std::any visitBoolConst(BoolConst &boolConst) override = 0;

        std::any visitHexConst(HexConst &hex) override = 0;

        std::any visitBinConst(BinConst &bin) override = 0;

        std::any visitStringConst(StringConst &s) override = 0;

        std::any visitIdentifierTerm(IdentifierTerm &term) override = 0;

        std::any visitApplicationTerm(ApplicationTerm &application) override = 0;

        std::any visitExistsTerm(ExistsTerm &exists) final {
            throw NotImplemented("ExistsTerm in BfTermVisistor not allowed.");
        }

        std::any visitForallTerm(ForallTerm &forall) final {
            throw NotImplemented("Forall in BfTermVisistor not allowed.");
        }

        std::any visitLetTerm(LetTerm &let) final {
            throw NotImplemented("LetTerm in BfTermVisistor not allowed.");
        }

    };

    enum class Feature {
        GRAMMARS,
        FWD_DECLS,
        RECURSION,
        ORACLES,
        WEIGHTS
    };

    using TermPtr = std::shared_ptr<Term>;
    using ComandPtr = std::shared_ptr<Command>;
    using LiteralPtr = std::shared_ptr<Literal>;

    class Command : public AstNode {

    };

    class Term : public AstNode {
    public:
        [[nodiscard]] virtual TermPtr copy() const = 0;
    };


    class Literal : public Term {

    };


    // Literal classes
    class Numeral : public Literal {

    private:
        long val;

    public:
        explicit Numeral(long v) : val{v} {}

        [[nodiscard]] long get_value() const;

        bool operator==(const Numeral &num) const;

        explicit operator std::string() const;

        [[nodiscard]] TermPtr copy() const override;

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
        explicit BoolConst(const bool x) : val{x} {}

        [[nodiscard]] bool get_value() const;

        [[nodiscard]] TermPtr copy() const override;

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

        [[nodiscard]] TermPtr copy() const override;

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

        explicit IndexedIdentifier(SimpleIdentifier symb, const std::vector<Index> &index_)
                : symbol(std::move(symb)), indices(index_)
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

    using EitherIdentifier = std::variant<SimpleIdentifier, IndexedIdentifier>;

}

// We create hashing functions in the std namespace so that containers like unordered set
namespace  std {

    template<>
    struct hash<Sy2CPP::IndexedIdentifier> {
        std::size_t operator()(const Sy2CPP::IndexedIdentifier &id) {
            return id.get_hash();
        }
    };

    /*
    template<>
    struct hash<Sy2CPP::EitherIdentifier> {
        std::size_t operator()(const Sy2CPP::EitherIdentifier& id) {
            return std::visit([](const auto& iden) mutable { return iden.get_hash();}, id);
        }
    };
    */
}


namespace Sy2CPP {



    inline EitherIdentifier get_simple_id_from_str(const std::string &s) {
        return EitherIdentifier{SimpleIdentifier{s}};
    }

    class IdentifierTerm : public Term {
    private:
        EitherIdentifier identifier;

    public:
        explicit IdentifierTerm(EitherIdentifier id) : identifier{std::move(id)} { }

        [[nodiscard]] EitherIdentifier get_identifier() const;

        [[nodiscard]] TermPtr copy() const override;

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
        ParametricSort(EitherIdentifier id, std::vector<EitherSort> &params) :
                identifier{std::move(id)}, parameters{params} {}

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

    /*
    template<>
    struct hash<Sy2CPP::EitherSort> {
        std::size_t operator()(const Sy2CPP::EitherSort& id) {
            return std::visit([](const auto& iden) mutable { return iden.get_hash();}, id);
        }
    };
    */
}

namespace Sy2CPP{

    inline EitherSort get_simple_sort_from_str(const std::string &s) {
        return {SimpleSort(get_simple_id_from_str(s))};

    }

    class ApplicationTerm : public Term {
    private:
        EitherIdentifier id;
        std::vector<TermPtr> arguments;

    public:
        ApplicationTerm(const std::variant<SimpleIdentifier, IndexedIdentifier> &iden,
                        const std::vector<TermPtr> &args) :
                id{iden},
                arguments{args} {}

        [[nodiscard]] EitherIdentifier get_identifier() const;

        std::vector<TermPtr> &get_arguments();

        [[nodiscard]] TermPtr copy() const  override;

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

        ExistsTerm(const std::vector<SortedVar> &v, TermPtr t) : vars{v}, subterm(std::move(t)) {}

        [[nodiscard]] std::vector<SortedVar> get_vars() const;

        [[nodiscard]] TermPtr get_term() const;

        [[nodiscard]] TermPtr copy() const override;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitExistsTerm(*this);
        }
    };

    class ForallTerm : public Term {
    private:
        std::vector<SortedVar> vars;
        TermPtr subterm;

    public:

        ForallTerm(const std::vector<SortedVar> &v,
                   TermPtr t) : vars{v}, subterm(std::move(t)) {}

        [[nodiscard]] std::vector<SortedVar> get_vars() const;

        [[nodiscard]] TermPtr get_term() const;

        [[nodiscard]] TermPtr copy() const override;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitForallTerm(*this);
        }
    };

    /**
     * In the standard it is specified that VarBinding is a pair of ID and Term. But since the type information is
     * used a lot and we will infer the type while building the AST and then carry the type information around.
     */
    using VarBinding = std::tuple<EitherIdentifier, EitherSort, TermPtr>;

    class LetTerm : public Term {
    private:
        std::vector<VarBinding> bindings;
        TermPtr subterm;

    public:

        LetTerm(const std::vector<VarBinding> &bdgs, TermPtr t) : bindings{bdgs}, subterm(std::move(t)) {}

        [[nodiscard]] std::vector<VarBinding> get_var_bindings() const;

        [[nodiscard]] TermPtr get_term() const;

        [[nodiscard]] TermPtr copy() const override;

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

        explicit ConstraintCmd(TermPtr ptr) : term{std::move(ptr)} { }

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
        DeclareVarCmd(EitherIdentifier  iden,EitherSort srt) : id{std::move(iden)}, sort{std::move(srt)} { }

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
        GroupedRuleList(EitherIdentifier iden, EitherSort srt, const std::vector<TermPtr> &trm) :
                id{std::move(iden)}, sort{std::move(srt)}, terms{trm} {}

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
        GrammarDef(const std::vector<SortedVar> &var, const std::vector<GroupedRuleList> &rule) : non_terminals{var}, rules{rule} {}

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
        SynthFunCmd(EitherIdentifier iden, const std::vector<SortedVar> &args,
                    EitherSort srt, GrammarDef grmmr) : id{std::move(iden)}, arguments{args},
                                                          sort{std::move(srt)}, grammar{std::move(grmmr)} {}

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
        DeclareSort(EitherIdentifier iden, Numeral num) : id{std::move(iden)}, numeral{std::move(num)} {}

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
        DefineFunCmd(EitherIdentifier iden,
                     const std::vector<SortedVar> &args,
                     EitherSort srt,
                     TermPtr tm) :
                id{std::move(iden)}, arguments{args}, sort{std::move(srt)}, term{std::move(tm)} {}

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
        DefineSort(EitherIdentifier iden, EitherSort srt) : id{std::move(iden)}, sort{std::move(srt)} {}

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
        SetInfo(std::string kw, LiteralPtr lit) : keyword{std::move(kw)}, literal{std::move(lit)} { }

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
        explicit SetLogic(std::string  str) : logic{std::move(str)} {}

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
        SetOption(std::string kw, LiteralPtr lit) : keyword{std::move(kw)}, literal{std::move(lit)} {}

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

        explicit ConstantGTerm(EitherSort srt) : sort{std::move(srt)} { }

        [[nodiscard]] EitherSort get_sort() const;

        [[nodiscard]] TermPtr copy() const override;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitConstantGTerm(*this);
        }
    };

    class VariableGTerm : public Term {
    private:
        EitherSort sort;

    public:

        explicit VariableGTerm(EitherSort srt) : sort{std::move(srt)} { }

        [[nodiscard]] EitherSort get_sort() const;

        [[nodiscard]] TermPtr copy() const override;

        std::any accept(AstVisitor &visitor) override {
            return visitor.visitVariableGTerm(*this);
        }
    };


    using SyGuSSolution = std::optional<std::vector<DefineFunCmd>>;


    class AstBaseVisitor : public AstVisitor {
    public:

        // Fake visitor functions for STL shorthands like variant/pair

        /**
         * We call \link std::visit on EitherIdentifier and return that return-value.
         *
         * */
        virtual std::any visitEitherIdentifier(EitherIdentifier&& term) {
            return std::visit([&](auto& id) mutable { return id.accept(*this); }, term);
        }

        /**
         * We call \link std::visit on EitherIdentifier and return that return-value.
         *
         * */
        virtual std::any visitEitherIdentifier(EitherIdentifier& term) {
            return std::visit([&](auto& id) mutable { return id.accept(*this); }, term);
        }

        /**
         * We call \link std::visit on EitherIdentifier and return that return-value.
         *
         * */
        virtual std::any visitEitherSort(EitherSort& sort) {
            return std::visit([&](auto& srt) mutable { return srt.accept(*this); }, sort);
        }

        /**
         * We call \link std::visit on EitherIdentifier and return that return-value.
         *
         * */
        virtual std::any visitEitherSort(EitherSort&& sort) {
            return std::visit([&](auto& srt) mutable { return srt.accept(*this); }, sort);
        }

        /**
         * Fake visitor for SortedVar which is a shorthand for pair<EitherIdentifier, EitherSort>.
         * By default we call \link visitEitherIdentifier and \link visitEitherSort on each element
         * and return a pair of the results.
         *
         * */
        virtual std::any visitSortedVar(SortedVar& s_var) {
            return std::pair<std::any, std::any>
                    (this->visitEitherIdentifier(s_var.first), this->visitEitherSort(s_var.second));
        }

        // Normal visitor functions for AST nodes
        std::any visitIdentifierTerm(IdentifierTerm &term) override {
            return visitEitherIdentifier(term.get_identifier());
        }

        std::any visitNumeral(Numeral &numeral) override {
            return {};
        }

        std::any visitDecimal(Decimal &decimal) override {
            return {};
        }

        std::any visitBoolConst(BoolConst &boolConst) override {
            return {};
        }

        std::any visitHexConst(HexConst &hex) override {
            return {};
        }

        std::any visitBinConst(BinConst &bin) override {
            return {};
        }

        std::any visitStringConst(StringConst &s) override {
            return {};
        }

        std::any visitApplicationTerm(ApplicationTerm &application) override {
            return {};
        }

        std::any visitExistsTerm(ExistsTerm &exists) override {
            return {};
        }

        std::any visitForallTerm(ForallTerm &forall) override {
            return {};
        }

        std::any visitLetTerm(LetTerm &let) override {
            return {};
        }

        std::any visitProblem(Problem &problem) override {
            return {};
        }

        std::any visitSimpleIdentifier(SimpleIdentifier &identifier) override {
            return {};
        }

        std::any visitIndexedIdentifier(IndexedIdentifier &indexedIdentifier) override {
            return {};
        }

        std::any visitSimpleSort(SimpleSort &sort) override {
            return {};
        }

        std::any visitParametricSort(ParametricSort &sort) override {
            return {};
        }

        std::any visitAssumeCmd(AssumeCmd &assumeCmd) override {
            return {};
        }

        std::any visitCheckSynthCmd(CheckSynthCmd &checkSynth) override {
            return {};
        }

        std::any visitConstraintCmd(ConstraintCmd &constraintCmd) override {
            return {};
        }

        std::any visitDeclareVarCmd(DeclareVarCmd &declareVarCmd) override {
            return {};
        }

        std::any visitSetFeatureCmd(SetFeatureCmd &setFeatureCmd) override {
            return {};
        }

        std::any visitDeclareDatatype(DeclareDatatype &declareDatatype) override {
            return {};
        }

        std::any visitDeclareDatatypes(DeclareDatatypes &declareDatatypes) override {
            return {};
        }

        std::any visitDeclareSort(DeclareSort &declareSort) override {
            return {};
        }

        std::any visitDefineFun(DefineFunCmd &defineFunCmd) override {
            return {};
        }

        std::any visitDefineSort(DefineSort &defineSort) override {
            return {};
        }

        std::any visitSetInfo(SetInfo &setInfo) override {
            return {};
        }

        std::any visitSetLogic(SetLogic &setLogic) override {
            return {};
        }

        std::any visitSetOption(SetOption &setOption) override {
            return {};
        }

        std::any visitSortDecl(SortDecl &sortDecl) override {
            return {};
        }

        std::any visitDtDecl(DtDecl &dtDecl) override {
            return {};
        }

        std::any visitDtConsDecl(DtConsDecl &dtConsDecl) override {
            return {};
        }

        std::any visitSynthFunCmd(SynthFunCmd &synthFun) override {
            return {};
        }

        std::any visitGrammarDef(GrammarDef &grammarDef) override {
            return {};
        }

        std::any visitGroupedRuleList(GroupedRuleList &groupedRuleList) override {
            return {};
        }

        std::any visitConstantGTerm(ConstantGTerm &constantGTerm) override {
            return {};
        }

        std::any visitVariableGTerm(VariableGTerm &variableGTerm) override {
            return {};
        }

    };

}

#endif //PHYSER_AST_H

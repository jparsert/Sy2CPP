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

#include "../exceptions/not_implemented.h"
#include "../exceptions/unsupported_feature.h"


namespace ast {

    class AstVisitor;

    class AstNode {
    public:
        virtual std::any accept(AstVisitor& visitor) = 0;

    };

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

    class  AstVisitor {
    public:

        virtual std::any visitProblem(Problem& problem) = 0;

        //virtual std::any visitLiteral(std::shared_ptr<Literal> lit) = 0;

        virtual std::any visitNumeral(Numeral& numeral) = 0;

        virtual std::any visitDecimal(Decimal& decimal) = 0;

        virtual std::any visitBoolConst(BoolConst& boolConst) = 0;

        virtual std::any visitHexConst(HexConst& hex) = 0;

        virtual std::any visitBinConst(BinConst& bin) = 0;

        virtual std::any visitStringConst(StringConst& s) = 0;

        virtual std::any visitSimpleIdentifier(SimpleIdentifier& identifier) = 0;

        virtual std::any visitIndexedIdentifier(IndexedIdentifier& indexedIdentifier) = 0;

        virtual std::any visitIdentifierTerm(IdentifierTerm& term) = 0;

        virtual std::any visitSimpleSort(SimpleSort& sort) = 0;

        virtual std::any visitParametricSort(ParametricSort& sort) = 0;

        virtual std::any visitApplicationTerm(ApplicationTerm& application) = 0;

        virtual std::any visitExistsTerm(ExistsTerm& exists) = 0;

        virtual std::any visitForallTerm(ForallTerm& forall) = 0;

        virtual std::any visitLetTerm(LetTerm& let) = 0;

        virtual std::any visitAssumeCmd(AssumeCmd& assumeCmd) = 0;

        virtual std::any visitCheckSynthCmd(CheckSynthCmd& context) = 0;

        virtual std::any visitConstraintCmd(ConstraintCmd& context) = 0;

        virtual std::any visitDeclareVarCmd(DeclareVarCmd& context) = 0;

        virtual std::any visitSetFeatureCmd(SetFeatureCmd& context) = 0;

        virtual std::any visitSynthFunCmd(SynthFunCmd& synthFun) = 0;

        //virtual std::any visitSmtCmd(std::shared_ptr<SmtCmd> smtCmd) = 0;

        virtual std::any visitDeclareDatatype(DeclareDatatype& declDT) = 0;

        virtual std::any visitDeclareDatatypes(DeclareDatatypes& context) = 0;

        virtual std::any visitDeclareSort(DeclareSort& context) = 0;

        virtual std::any visitDefineFun(DefineFun& context) = 0;

        virtual std::any visitDefineSort(DefineSort& context) = 0;

        virtual std::any visitSetInfo(SetInfo& context) = 0;

        virtual std::any visitSetLogic(SetLogic& context) = 0;

        virtual std::any visitSetOption(SetOption& context) = 0;

        virtual std::any visitSortDecl(SortDecl& context) = 0;

        virtual std::any visitDtDecl(DtDecl& context) = 0;

        virtual std::any visitDtConsDecl(DtConsDecl& context) = 0;

        virtual std::any visitGrammarDef(GrammarDef& context) = 0;

        virtual std::any visitGroupedRuleList(GroupedRuleList& context) = 0;

        virtual std::any visitConstantGTerm(ConstantGTerm& context) = 0;

        virtual std::any visitVariableGTerm(VariableGTerm& context) = 0;

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


    class Literal : public Term {

    };

    // Identifier
    class Identifier : public AstNode {
    public:
        [[nodiscard]] virtual std::size_t get_hash() const = 0;
    };

    class SimpleIdentifier : public Identifier {
        std::string symbol;
    public:

        explicit SimpleIdentifier(std::string symb): symbol{std::move(symb)} {}

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitSimpleIdentifier(*this);
        }

        [[nodiscard]] std::string get_symbol() const {
            return this->symbol;
        }

        bool operator==(const SimpleIdentifier& other) const {
            return this->symbol == other.get_symbol();
        }

        [[nodiscard]] std::size_t get_hash() const override {
            return std::hash<std::string>()(this->symbol);
        }
    };

    class IndexedIdentifier : public Identifier {
    public:

        explicit IndexedIdentifier() {
            throw not_implemented("Indexed identifiers are not supported yet.");
        }

        explicit IndexedIdentifier(const std::string& symbol) {
            throw not_implemented("Indexed identifiers are not supported yet.");
        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitIndexedIdentifier(*this);
        }

        bool operator==(const IndexedIdentifier& other) const {
            throw unsupported_feature("We do not support indexed identifiers yet.");
        }

        [[nodiscard]] std::size_t get_hash() const override {
            throw unsupported_feature("We do not support indexed identifiers yet.");
        }

    };

    using EitherIdentifier = std::variant<ast::SimpleIdentifier, ast::IndexedIdentifier>;

    inline EitherIdentifier get_simple_id_from_str(std::string& s) {
        return EitherIdentifier{SimpleIdentifier{s}} ;
    }

    inline EitherIdentifier get_simple_id_from_str(std::string&& s) {
        return EitherIdentifier{SimpleIdentifier{s}} ;
    }

    class IdentifierTerm : public Term {

        EitherIdentifier identifier;

    public:

        IdentifierTerm(EitherIdentifier& id) : identifier{id} {

        }

        EitherIdentifier get_identifier() {
            return identifier;
        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitIdentifierTerm(*this);
        }

    };

    class Problem : public AstNode {
    private:
        std::vector<std::shared_ptr<Command>> commands;

    public:

        void add_command(std::shared_ptr<Command>& cmd) {
            this->commands.push_back(cmd);
        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitProblem(*this);
        }

        std::vector<std::shared_ptr<Command>>& get_commands() {
            return this->commands;
        }

    };

    class Numeral : public  Literal {

    private:
        long val;

    public:
        explicit Numeral(long v) : val{v} {}

        [[nodiscard]] long get_value() const {
            return this->val;
        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitNumeral(*this);
        }
    };

    class Decimal : public  Literal {
    public:

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitDecimal(*this);
        }
    };

    class BoolConst : public  Literal {
    private:
        bool val;

    public:

        explicit BoolConst(bool x): val{x}{}

        [[nodiscard]] bool get_value() const {
            return this->val;
        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitBoolConst(*this);
        }
    };

    class HexConst : public  Literal {
        std::any accept(AstVisitor& visitor) override {
            return visitor.visitHexConst(*this);
        }
    };

    class BinConst : public  Literal {
        std::any accept(AstVisitor& visitor) override {
            return visitor.visitBinConst(*this);
        }
    };

    class StringConst : public  Literal {
    private:
        std::string str;

    public:

        explicit StringConst(std::string s): str{std::move(s)} {}

        [[nodiscard]] std::string get_string() const {
            return str;
        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitStringConst(*this);
        }
    };

    class Sort : public AstNode {

    };

    class SimpleSort : public  Sort {
    private:
        EitherIdentifier identifier;

    public:
        explicit SimpleSort(EitherIdentifier& id): identifier(id) {}
        explicit SimpleSort(EitherIdentifier&& id): identifier(id) {}

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitSimpleSort(*this);
        }

        [[nodiscard]] EitherIdentifier get_identifier() const {
            return identifier;
        }

    };

    class ParametricSort : public  Sort {
    public:
        std::any accept(AstVisitor& visitor) override {
            return visitor.visitParametricSort(*this);
        }
    };

    using EitherSort = std::variant<std::shared_ptr<ast::SimpleSort>, std::shared_ptr<ast::ParametricSort>>;
    using SortPtr = std::shared_ptr<EitherSort>;
    inline std::shared_ptr<EitherSort> get_simple_sort_from_str(std::string& s) {
        return std::make_shared<EitherSort>(std::make_shared<ast::SimpleSort>(get_simple_id_from_str("Bool")));
    }

    inline std::shared_ptr<EitherSort> get_simple_sort_from_str(std::string&& s) {
        return std::make_shared<EitherSort>(std::make_shared<ast::SimpleSort>(get_simple_id_from_str("Bool")));
    }

    class ApplicationTerm : public  Term {
    private:
        EitherIdentifier id;
        std::vector<TermPtr> arguments;

    public:

        ApplicationTerm(std::variant<SimpleIdentifier, IndexedIdentifier>& iden,
                        std::vector<std::shared_ptr<Term>>& args) :
        id{iden},
        arguments{args}
        { }

        [[nodiscard]] EitherIdentifier get_identifier() const {
            return this->id;
        }

        std::vector<TermPtr>& get_arguments() {
            return this->arguments;
        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitApplicationTerm(*this);
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

        [[nodiscard]] std::vector<std::shared_ptr<SortedVar>> get_vars() const {
            return this->vars;
        }

        [[nodiscard]] TermPtr get_term() const {
            return this->subterm;
        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitExistsTerm(*this);
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

        [[nodiscard]] std::vector<std::shared_ptr<SortedVar>> get_vars() const {
            return this->vars;
        }

        [[nodiscard]] TermPtr get_term() const {
            return this->subterm;
        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitForallTerm(*this);
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

        [[nodiscard]] std::vector<std::shared_ptr<VarBinding>> get_var_bindings() const {
            return this->bindings;
        }

        [[nodiscard]] TermPtr get_term() const {
            return this->subterm;
        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitLetTerm(*this);
        }
    };

    class AssumeCmd : public  Command {
    private:
        TermPtr term;

    public:
        explicit AssumeCmd(std::shared_ptr<Term> t) : term{std::move(t)} {}

        [[nodiscard]] TermPtr get_term() const {
            return term;
        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitAssumeCmd(*this);
        }
    };

    class CheckSynthCmd : public  Command {
        std::any accept(AstVisitor& visitor) override {
            return visitor.visitCheckSynthCmd(*this);
        }
    };

    class ConstraintCmd : public  Command {
    private:
        TermPtr term;

    public:

        explicit ConstraintCmd(TermPtr& ptr): term{ptr} {

        }

        [[nodiscard]] TermPtr get_term() const {
            return term;
        }
        std::any accept(AstVisitor& visitor) override {
            return visitor.visitConstraintCmd(*this);
        }
    };

    class DeclareVarCmd : public  Command {
    private:
        EitherIdentifier id;
        SortPtr sort;

    public:

        DeclareVarCmd(EitherIdentifier& iden, std::shared_ptr<EitherSort>& srt): id{iden}, sort{srt} {

        }

        [[nodiscard]] EitherIdentifier get_identifier() const {
            return this->id;
        }

        [[nodiscard]] SortPtr get_sort() const {
            return this->sort;
        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitDeclareVarCmd(*this);
        }


    };

    class SetFeatureCmd : public  Command {

    private:

        Feature feature;
        bool value;

    public:

        SetFeatureCmd(Feature f, bool v): feature{f}, value{v} {}

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitSetFeatureCmd(*this);
        }
    };

    class SynthFunCmd : public  Command {
    private:

        EitherIdentifier id;

        std::vector<std::shared_ptr<SortedVar>> arguments;

        SortPtr sort;

        std::shared_ptr<GrammarDef> grammar;

    public:

        SynthFunCmd(EitherIdentifier& iden, std::vector<std::shared_ptr<SortedVar>>& args,
                    std::shared_ptr<EitherSort>& srt, std::shared_ptr<GrammarDef>& grmmr): id{iden}, arguments{args},
                    sort{srt}, grammar{grmmr}{
        }

        [[nodiscard]] EitherIdentifier get_identifier() const {
            return this->id;
        }

        [[nodiscard]] std::vector<std::shared_ptr<SortedVar>> get_arguments() const {
            return this->arguments;
        }

        [[nodiscard]] SortPtr get_sort() const {
            return this->sort;
        }

        [[nodiscard]] std::shared_ptr<GrammarDef> get_grammar() const {
            return this->grammar;
        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitSynthFunCmd(*this);
        }

    };

    class DeclareDatatype : public  Command {
        std::any accept(AstVisitor& visitor) override {
            return visitor.visitDeclareDatatype(*this);
        }
    };

    class DeclareDatatypes : public  Command {
        std::any accept(AstVisitor& visitor) override {
            return visitor.visitDeclareDatatypes(*this);
        }
    };

    class DeclareSort : public  Command {

    private:
        EitherIdentifier id;

        std::shared_ptr<Numeral> numeral;

    public:

        DeclareSort(EitherIdentifier iden, std::shared_ptr<Numeral>& num) : id{std::move(iden)}, numeral{num}{}

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitDeclareSort(*this);
        }
    };

    class DefineFun : public  Command {

    private:
        EitherIdentifier id;

        std::vector<std::shared_ptr<ast::SortedVar>> arguments;

        std::shared_ptr<EitherSort> sort;

        TermPtr term;

    public:
        DefineFun(EitherIdentifier& iden,
                  std::vector<std::shared_ptr<ast::SortedVar>>& args,
                  std::shared_ptr<EitherSort>& srt,
                  TermPtr& tm):
                  id{iden}, arguments{args}, sort{srt}, term{tm} {}

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitDefineFun(*this);
        }
    };

    class DefineSort : public  Command {
    private:
        EitherIdentifier id;

        std::shared_ptr<EitherSort> sort;

    public:

        DefineSort(EitherIdentifier iden, std::shared_ptr<EitherSort>& srt): id{std::move(iden)}, sort{srt} {}

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitDefineSort(*this);
        }
    };

    class SetInfo : public  Command {

    private:

        std::string keyword;
        std::shared_ptr<Literal> literal;

    public:

        SetInfo(std::string& kw, std::shared_ptr<Literal>& lit): keyword{kw}, literal{lit} {

        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitSetInfo(*this);
        }
    };

    class SetLogic : public  Command {

    private:
        std::string logic;

    public:
        explicit SetLogic(std::string& str) : logic{str} {}

        [[nodiscard]] std::string get_logic() const {
            return logic;
        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitSetLogic(*this);
        }
    };

    class SetOption : public  Command {
    private:

        std::string keyword;
        std::shared_ptr<Literal> literal;

    public:

        SetOption(std::string& kw, std::shared_ptr<Literal>& lit): keyword{kw}, literal{lit} {

        }
        std::any accept(AstVisitor& visitor) override {
            return visitor.visitSetOption(*this);
        }
    };

    class SortDecl : public  AstNode {
        std::any accept(AstVisitor& visitor) override {
            return visitor.visitSortDecl(*this);
        }
    };

    class DtDecl : public  AstNode {
        std::any accept(AstVisitor& visitor) override {
            return visitor.visitDtDecl(*this);
        }
    };

    class DtConsDecl : public  AstNode {
        std::any accept(AstVisitor& visitor) override {
            return visitor.visitDtConsDecl(*this);
        }
    };

    class GroupedRuleList : public  AstNode {
    private:
        EitherIdentifier id;

        SortPtr sort;

        std::vector<TermPtr> terms;

    public:

        GroupedRuleList(EitherIdentifier iden, std::shared_ptr<EitherSort>& srt, std::vector<TermPtr>& trm):
        id{std::move(iden)}, sort{srt}, terms{trm} {}

        [[nodiscard]] EitherIdentifier get_identifier() const {
            return id;
        }

        [[nodiscard]] SortPtr get_sort() const {
            return sort;
        }

        [[nodiscard]] std::vector<TermPtr> get_terms() const {
            return terms;
        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitGroupedRuleList(*this);
        }
    };

    class GrammarDef : public  AstNode {
    private:
        std::vector<std::shared_ptr<ast::SortedVar>> vars;
        std::vector<std::shared_ptr<GroupedRuleList>> rules;

    public:
        GrammarDef(std::vector<std::shared_ptr<ast::SortedVar>>& var,
                   std::vector<std::shared_ptr<GroupedRuleList>>& rule) : vars{var}, rules{rule}
                   {}


        [[nodiscard]] std::vector<std::shared_ptr<ast::SortedVar>> get_vars() const {
            return this->vars;
        }

        [[nodiscard]] std::vector<std::shared_ptr<GroupedRuleList>> get_rules() const {
            return this->rules;
        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitGrammarDef(*this);
        }
    };


    class ConstantGTerm : public  Term {
    private:
        SortPtr sort;
    public:

        explicit ConstantGTerm(SortPtr& srt): sort{srt} {

        }

        [[nodiscard]] SortPtr get_sort() const {
            return this->sort;
        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitConstantGTerm(*this);
        }
    };

    class VariableGTerm : public  Term {
    private:
        SortPtr sort;
    public:

        explicit VariableGTerm(SortPtr& srt): sort{srt} {

        }

        [[nodiscard]] SortPtr get_sort() const {
            return this->sort;
        }

        std::any accept(AstVisitor& visitor) override {
            return visitor.visitVariableGTerm(*this);
        }
    };


    class AstBaseVisitor : public AstVisitor {
    public:

        std::any visitIdentifierTerm(IdentifierTerm& term) override {
            return std::visit([&](auto id) mutable {return id.accept(*this);}, term.get_identifier());
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

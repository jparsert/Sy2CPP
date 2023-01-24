//
// Created by julian on 17.12.22.
//

#include "ast.h"

namespace Sy2CPP {

    std::string to_string(const EitherIdentifier &ident) {
        return std::visit([](auto &id) mutable { return (std::string) id; }, ident);
    }

    std::string to_string(const EitherSort &ident) {
        return std::visit([](auto &id) mutable { return (std::string) id; }, ident);
    }

    LiteralPtr SetInfo::get_literal() {
        return literal;
    }

    std::string SetInfo::get_keyword()  {
        return keyword;
    }

    EitherSort DefineSort::get_sort() {
        return this->sort;
    }

    EitherIdentifier DefineSort::get_identifier() {
        return this->id;
    }

    std::size_t SimpleSort::get_hash() const {
        return std::visit([](auto id) { return id.get_hash(); }, identifier);
    }

    bool SimpleSort::operator==(const SimpleSort &other) const  {
        return this->get_identifier() == other.get_identifier();
    }

    bool SimpleSort::operator!=(const SimpleSort &other) const {
        return !(this->get_identifier() == other.get_identifier());
    }

    EitherIdentifier SimpleSort::get_identifier() const {
        return identifier;
    }

    SimpleSort::operator std::string() const {
        return to_string(identifier);
    }

    long Numeral::get_value() const  {
        return this->val;
    }

    bool Numeral::operator==(const Numeral &num) const  {
        return val == num.get_value();
    }

    Numeral::operator std::string() const{
        return std::to_string(val);
    }

    bool BoolConst::get_value() const  {
        return this->val;
    }

    std::any SimpleIdentifier::accept(AstVisitor &visitor) {
        return visitor.visitSimpleIdentifier(*this);
    }

    std::string SimpleIdentifier::get_symbol() const {
        return this->symbol;
    }

    bool SimpleIdentifier::operator==(const SimpleIdentifier &other) const  {
        return this->symbol == other.get_symbol();
    }

    bool SimpleIdentifier::operator!=(const SimpleIdentifier &other) const{
        return !(this->symbol == other.get_symbol());
    }

    std::size_t SimpleIdentifier::get_hash() const  {
        return std::hash<std::string>()(this->symbol);
    }

    SimpleIdentifier::operator std::string() const  {
        return symbol;
    }

    bool IndexedIdentifier::operator==(const IndexedIdentifier &other) const  {
        return symbol == other.symbol and (indices == other.indices);
    }

    bool IndexedIdentifier::operator!=(const IndexedIdentifier &other) const  {
        return not(*this == other);
    }

    std::size_t IndexedIdentifier::get_hash() const {
        size_t res_hash = symbol.get_hash();
        size_t lst_hash = hash_vector<Index>(indices);
        return res_hash^lst_hash; // TODO use a better (non-commutative) combine hash function
    }

    IndexedIdentifier::operator std::string() const {
        std::string res = "(_ " +  (std::string)symbol + " ";
        for (const auto& e : indices) {
            res += std::visit([&](const auto& index) mutable { return (std::string) index ; }, e);
        }
        res += ")";
        return res;
    }

    EitherIdentifier IdentifierTerm::get_identifier()
    {
        return identifier;
    }

    EitherIdentifier ApplicationTerm::get_identifier() const {
        return this->id;
    }

    std::vector<TermPtr> &ApplicationTerm::get_arguments() {
        return this->arguments;
    }

    std::vector<SortedVar> ExistsTerm::get_vars() const {
        return this->vars;
    }

    TermPtr ExistsTerm::get_term() const {
        return this->subterm;
    }

    std::vector<SortedVar> ForallTerm::get_vars() const {
        return this->vars;
    }

    TermPtr ForallTerm::get_term() const {
            return this->subterm;
    }

    std::vector<VarBinding> LetTerm::get_var_bindings() const {
        return this->bindings;
    }

    TermPtr LetTerm::get_term() const {
        return this->subterm;
    }

    TermPtr AssumeCmd::get_term() const {
        return term;
    }


    TermPtr ConstraintCmd::get_term() const {
        return term;
    }

    EitherIdentifier DeclareVarCmd::get_identifier() const{
        return this->id;
    }

    EitherSort DeclareVarCmd::get_sort() const  {
        return sort;
    }

    Feature SetFeatureCmd::get_feature() {
        return feature;
    }

    bool SetFeatureCmd::get_value() const {
        return value;
    }

    EitherIdentifier DefineFunCmd::get_identifier() const {
        return this->id;
    }

    std::vector<SortedVar> &DefineFunCmd::get_arguments() {
        return this->arguments;
    }

    EitherSort DefineFunCmd::get_sort() const{
        return this->sort;
    }

    TermPtr DefineFunCmd::get_term() const {
        return this->term;
    }

    EitherIdentifier DeclareSort::get_identifier(){
        return this->id;
    }

    Numeral DeclareSort::get_numeral() {
        return this->numeral;
    }

    EitherIdentifier SynthFunCmd::get_identifier() const{
        return this->id;
    }

    std::vector<SortedVar> &SynthFunCmd::get_arguments()  {
        return this->arguments;
    }

    EitherSort SynthFunCmd::get_sort() const {
        return this->sort;
    }

    GrammarDef SynthFunCmd::get_grammar() const  {
        return this->grammar;
    }

    std::vector<SortedVar> GrammarDef::get_non_terminals() const {
        return this->non_terminals;
    }

    std::vector<GroupedRuleList> GrammarDef::get_rules() const {
        return this->rules;
    }

    EitherIdentifier GroupedRuleList::get_identifier() const {
        return id;
    }

    EitherSort GroupedRuleList::get_sort() const  {
        return sort;
    }

    std::vector<TermPtr> GroupedRuleList::get_terms() const {
        return terms;
    }


}
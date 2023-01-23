//
// Created by julian on 15.12.22.
//

#ifndef PHYSER_SYMBOLTABLE_H
#define PHYSER_SYMBOLTABLE_H

#include <variant>
#include <vector>
#include <iostream>
#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>

#include "SyGuSv21BaseVisitor.h"
#include "exceptions.h"

#include "ast.h"
#include "resolvers.h"

namespace Sy2CPP {

    class symbol_table {

    private:

        // Mapping identifiers to theory functions
        std::unordered_map<EitherIdentifier, FunctionDescriptor> user_defined_funs;

        // Mapping identifiers to Synthesis functions
        std::unordered_map<EitherIdentifier, FunctionDescriptor> synth_fun_funs;

        // We will need to add Data type functions Constructor/Selector and Tester

        // Theory Resolvers
        std::vector<std::shared_ptr<AbstractResolver>> resolvers;

        // A set containing all present sorts
        std::vector<SymbolDescriptor> symbol_stack;

        //set of all sorts
        std::unordered_set<EitherSort> sorts;

    public:

        // adding bool sorts and default boolean functions
        symbol_table() {
            this->add_resolver(std::make_shared<CoreResolver>());
        }

        void add_resolver(const std::shared_ptr<AbstractResolver> &ptr);

        bool
        add_synth_fun(const EitherIdentifier &id, const std::vector<SortedVar> &arguments,
                      const EitherSort &range_sort);

        bool add_user_defined_fun(DefineFunCmd &defineFunCmd);

        std::optional<FunctionDescriptor> lookup_or_resolve_function(const EitherIdentifier &identifier,
                                                                     const std::vector<EitherSort> &arg_sorts) const;

        std::optional<EitherSort> lookup_sort(const EitherSort &sort) const;

        void push_symbol_stack(const SymbolDescriptor &descr);

        SymbolDescriptor pop_symbol_stack();

        std::vector<SymbolDescriptor> pop_symbol_stack(std::size_t n);

        /**
         * We search the stack for the symbol descriptor that id refers to. By traversing the stack "correctly" we take
         * care of shadowing etc.
         * */
        std::optional<SymbolDescriptor> resolve_symbol_descriptor(const EitherIdentifier &identifier) const;

    };

    class SymbolTableAstBuilder : public SyGuSv21BaseVisitor {
    private:
        std::shared_ptr<symbol_table> table;
        std::shared_ptr<Problem> problem;

        // maybe make private so we have a static builder class
        SymbolTableAstBuilder() {
            table = std::make_shared<symbol_table>();
            problem = std::make_shared<Problem>();
        }

    public:


        std::any visitSimpleIdentifier(SyGuSv21Parser::SimpleIdentifierContext *ctx) override;

        std::any visitIndexedIdentifier(SyGuSv21Parser::IndexedIdentifierContext *ctx) override;

        std::any visitNumeral(SyGuSv21Parser::NumeralContext *ctx) override;

        std::any visitDecimal(SyGuSv21Parser::DecimalContext *ctx) override;

        std::any visitBoolConstTrue(SyGuSv21Parser::BoolConstTrueContext *ctx) override;

        std::any visitBoolConstFalse(SyGuSv21Parser::BoolConstFalseContext *ctx) override;

        std::any visitHexConst(SyGuSv21Parser::HexConstContext *ctx) override {
            throw not_implemented("Decimal constants are not supported yet.");
        }

        std::any visitBinConst(SyGuSv21Parser::BinConstContext *ctx) override {
            throw not_implemented("Decimal constants are not supported yet.");
        }

        std::any visitStringConst(SyGuSv21Parser::StringConstContext *ctx) override;

        std::any visitIndex(SyGuSv21Parser::IndexContext *ctx) override {
            throw not_implemented("Indexes are not supported yet.");
        }

        std::any visitSimpleSort(SyGuSv21Parser::SimpleSortContext *ctx) override;

        std::any visitParametricSort(SyGuSv21Parser::ParametricSortContext *ctx) override;

        std::any visitIdentifierTerm(SyGuSv21Parser::IdentifierTermContext *ctx) override;

        std::any visitLiteralTerm(SyGuSv21Parser::LiteralTermContext *ctx) override;

        std::any visitApplicationTerm(SyGuSv21Parser::ApplicationTermContext *ctx) override;

        std::any visitExistsTerm(SyGuSv21Parser::ExistsTermContext *ctx) override;

        std::any visitForallTerm(SyGuSv21Parser::ForallTermContext *ctx) override;

        std::any visitLetTerm(SyGuSv21Parser::LetTermContext *ctx) override;

        std::any visitBfIdentifierTerm(SyGuSv21Parser::BfIdentifierTermContext *ctx) override;

        std::any visitBfLiteralTerm(SyGuSv21Parser::BfLiteralTermContext *ctx) override;

        std::any visitBfApplicationTerm(SyGuSv21Parser::BfApplicationTermContext *ctx) override;

        std::any visitSortedVar(SyGuSv21Parser::SortedVarContext *ctx) override;

        std::any visitVarBinding(SyGuSv21Parser::VarBindingContext *ctx) override;

        std::any visitFeature(SyGuSv21Parser::FeatureContext *ctx) override;

        std::any visitSetFeatureCmd(SyGuSv21Parser::SetFeatureCmdContext *ctx) override;

        std::any visitCheckSynthCmd(SyGuSv21Parser::CheckSynthCmdContext *ctx) override;

        std::any visitConstraintCmd(SyGuSv21Parser::ConstraintCmdContext *ctx) override;

        std::any visitDeclareVarCmd(SyGuSv21Parser::DeclareVarCmdContext *ctx) override;

        std::any visitSynthFunCmd(SyGuSv21Parser::SynthFunCmdContext *ctx) override;

        std::any visitDefineFun(SyGuSv21Parser::DefineFunContext *ctx) override;

        std::any visitDeclareDatatype(SyGuSv21Parser::DeclareDatatypeContext *ctx) override {
            throw not_implemented("DeclareDatatypes are not implemented yet.");
        }

        std::any visitDeclareDatatypes(SyGuSv21Parser::DeclareDatatypesContext *ctx) override {
            throw not_implemented("DeclareDatatypes are not implemented yet.");
        }

        // TODO add to symbol Table
        std::any visitDeclareSort(SyGuSv21Parser::DeclareSortContext *ctx) override;

        // TODO add to symbol Table
        std::any visitDefineSort(SyGuSv21Parser::DefineSortContext *ctx) override;

        std::any visitSetInfo(SyGuSv21Parser::SetInfoContext *ctx) override;

        std::any visitSetLogic(SyGuSv21Parser::SetLogicContext *ctx) override;

        std::any visitSetOption(SyGuSv21Parser::SetOptionContext *ctx) override;

        std::any visitSortDecl(SyGuSv21Parser::SortDeclContext *ctx) override {
            throw not_implemented("DeclareDatatypes are not implemented yet.");
        }

        std::any visitDtDecl(SyGuSv21Parser::DtDeclContext *ctx) override {
            throw not_implemented("DeclareDatatypes are not implemented yet.");
        }

        std::any visitDtConsDecl(SyGuSv21Parser::DtConsDeclContext *ctx) override {
            throw not_implemented("DeclareDatatypes are not implemented yet.");
        }

        std::any visitGrammarDef(SyGuSv21Parser::GrammarDefContext *ctx) override;

        std::any visitGroupedRuleList(SyGuSv21Parser::GroupedRuleListContext *ctx) override;

        std::any visitConstantGTerm(SyGuSv21Parser::ConstantGTermContext *ctx) override;

        std::any visitVariableGTerm(SyGuSv21Parser::VariableGTermContext *ctx) override;

        std::any visitProblem(SyGuSv21Parser::ProblemContext *ctx) override;

        std::any visitAssumeCmd(SyGuSv21Parser::AssumeCmdContext *ctx) override;

        static
        std::pair<std::shared_ptr<symbol_table>, std::shared_ptr<Problem>>
        build_symbol_table_and_ast(SyGuSv21Parser::ProblemContext *problem) {
            SymbolTableAstBuilder builder{};
            problem->accept(&builder);

            return {builder.table, builder.problem};
        }

    };
} // namespace Sy2CPP

#endif //PHYSER_SYMBOLTABLE_H

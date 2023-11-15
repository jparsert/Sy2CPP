// Generated from /home/julian/coding/Sy2CPP/build/antlr4_runtime/src/antlr4_runtime/tool-testsuite/test/org/antlr/v4/test/tool/Psl.g4 by ANTLR 4.12.0
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link PslParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface PslVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link PslParser#translation_unit}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTranslation_unit(PslParser.Translation_unitContext ctx);
	/**
	 * Visit a parse tree produced by {@link PslParser#pattern}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPattern(PslParser.PatternContext ctx);
	/**
	 * Visit a parse tree produced by {@link PslParser#numeric_range}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNumeric_range(PslParser.Numeric_rangeContext ctx);
	/**
	 * Visit a parse tree produced by {@link PslParser#numeric_endpoint}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNumeric_endpoint(PslParser.Numeric_endpointContext ctx);
	/**
	 * Visit a parse tree produced by {@link PslParser#floating_constant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFloating_constant(PslParser.Floating_constantContext ctx);
	/**
	 * Visit a parse tree produced by {@link PslParser#comma_number}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitComma_number(PslParser.Comma_numberContext ctx);
	/**
	 * Visit a parse tree produced by {@link PslParser#term_expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTerm_expression(PslParser.Term_expressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link PslParser#term}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTerm(PslParser.TermContext ctx);
	/**
	 * Visit a parse tree produced by {@link PslParser#integer_constant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInteger_constant(PslParser.Integer_constantContext ctx);
}
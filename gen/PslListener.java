// Generated from /home/julian/coding/Sy2CPP/build/antlr4_runtime/src/antlr4_runtime/tool-testsuite/test/org/antlr/v4/test/tool/Psl.g4 by ANTLR 4.12.0
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link PslParser}.
 */
public interface PslListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link PslParser#translation_unit}.
	 * @param ctx the parse tree
	 */
	void enterTranslation_unit(PslParser.Translation_unitContext ctx);
	/**
	 * Exit a parse tree produced by {@link PslParser#translation_unit}.
	 * @param ctx the parse tree
	 */
	void exitTranslation_unit(PslParser.Translation_unitContext ctx);
	/**
	 * Enter a parse tree produced by {@link PslParser#pattern}.
	 * @param ctx the parse tree
	 */
	void enterPattern(PslParser.PatternContext ctx);
	/**
	 * Exit a parse tree produced by {@link PslParser#pattern}.
	 * @param ctx the parse tree
	 */
	void exitPattern(PslParser.PatternContext ctx);
	/**
	 * Enter a parse tree produced by {@link PslParser#numeric_range}.
	 * @param ctx the parse tree
	 */
	void enterNumeric_range(PslParser.Numeric_rangeContext ctx);
	/**
	 * Exit a parse tree produced by {@link PslParser#numeric_range}.
	 * @param ctx the parse tree
	 */
	void exitNumeric_range(PslParser.Numeric_rangeContext ctx);
	/**
	 * Enter a parse tree produced by {@link PslParser#numeric_endpoint}.
	 * @param ctx the parse tree
	 */
	void enterNumeric_endpoint(PslParser.Numeric_endpointContext ctx);
	/**
	 * Exit a parse tree produced by {@link PslParser#numeric_endpoint}.
	 * @param ctx the parse tree
	 */
	void exitNumeric_endpoint(PslParser.Numeric_endpointContext ctx);
	/**
	 * Enter a parse tree produced by {@link PslParser#floating_constant}.
	 * @param ctx the parse tree
	 */
	void enterFloating_constant(PslParser.Floating_constantContext ctx);
	/**
	 * Exit a parse tree produced by {@link PslParser#floating_constant}.
	 * @param ctx the parse tree
	 */
	void exitFloating_constant(PslParser.Floating_constantContext ctx);
	/**
	 * Enter a parse tree produced by {@link PslParser#comma_number}.
	 * @param ctx the parse tree
	 */
	void enterComma_number(PslParser.Comma_numberContext ctx);
	/**
	 * Exit a parse tree produced by {@link PslParser#comma_number}.
	 * @param ctx the parse tree
	 */
	void exitComma_number(PslParser.Comma_numberContext ctx);
	/**
	 * Enter a parse tree produced by {@link PslParser#term_expression}.
	 * @param ctx the parse tree
	 */
	void enterTerm_expression(PslParser.Term_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link PslParser#term_expression}.
	 * @param ctx the parse tree
	 */
	void exitTerm_expression(PslParser.Term_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link PslParser#term}.
	 * @param ctx the parse tree
	 */
	void enterTerm(PslParser.TermContext ctx);
	/**
	 * Exit a parse tree produced by {@link PslParser#term}.
	 * @param ctx the parse tree
	 */
	void exitTerm(PslParser.TermContext ctx);
	/**
	 * Enter a parse tree produced by {@link PslParser#integer_constant}.
	 * @param ctx the parse tree
	 */
	void enterInteger_constant(PslParser.Integer_constantContext ctx);
	/**
	 * Exit a parse tree produced by {@link PslParser#integer_constant}.
	 * @param ctx the parse tree
	 */
	void exitInteger_constant(PslParser.Integer_constantContext ctx);
}
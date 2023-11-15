// Generated from /home/julian/coding/Sy2CPP/cmake-build-debug/antlr4_runtime/src/antlr4_runtime/runtime/Cpp/demo/TParser.g4 by ANTLR 4.12.0
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link TParser}.
 */
public interface TParserListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link TParser#main}.
	 * @param ctx the parse tree
	 */
	void enterMain(TParser.MainContext ctx);
	/**
	 * Exit a parse tree produced by {@link TParser#main}.
	 * @param ctx the parse tree
	 */
	void exitMain(TParser.MainContext ctx);
	/**
	 * Enter a parse tree produced by {@link TParser#divide}.
	 * @param ctx the parse tree
	 */
	void enterDivide(TParser.DivideContext ctx);
	/**
	 * Exit a parse tree produced by {@link TParser#divide}.
	 * @param ctx the parse tree
	 */
	void exitDivide(TParser.DivideContext ctx);
	/**
	 * Enter a parse tree produced by {@link TParser#and_}.
	 * @param ctx the parse tree
	 */
	void enterAnd_(TParser.And_Context ctx);
	/**
	 * Exit a parse tree produced by {@link TParser#and_}.
	 * @param ctx the parse tree
	 */
	void exitAnd_(TParser.And_Context ctx);
	/**
	 * Enter a parse tree produced by {@link TParser#conquer}.
	 * @param ctx the parse tree
	 */
	void enterConquer(TParser.ConquerContext ctx);
	/**
	 * Exit a parse tree produced by {@link TParser#conquer}.
	 * @param ctx the parse tree
	 */
	void exitConquer(TParser.ConquerContext ctx);
	/**
	 * Enter a parse tree produced by {@link TParser#unused}.
	 * @param ctx the parse tree
	 */
	void enterUnused(TParser.UnusedContext ctx);
	/**
	 * Exit a parse tree produced by {@link TParser#unused}.
	 * @param ctx the parse tree
	 */
	void exitUnused(TParser.UnusedContext ctx);
	/**
	 * Enter a parse tree produced by {@link TParser#unused2}.
	 * @param ctx the parse tree
	 */
	void enterUnused2(TParser.Unused2Context ctx);
	/**
	 * Exit a parse tree produced by {@link TParser#unused2}.
	 * @param ctx the parse tree
	 */
	void exitUnused2(TParser.Unused2Context ctx);
	/**
	 * Enter a parse tree produced by {@link TParser#stat}.
	 * @param ctx the parse tree
	 */
	void enterStat(TParser.StatContext ctx);
	/**
	 * Exit a parse tree produced by {@link TParser#stat}.
	 * @param ctx the parse tree
	 */
	void exitStat(TParser.StatContext ctx);
	/**
	 * Enter a parse tree produced by {@link TParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(TParser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link TParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(TParser.ExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Return}
	 * labeled alternative in {@link TParser#flowControl}.
	 * @param ctx the parse tree
	 */
	void enterReturn(TParser.ReturnContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Return}
	 * labeled alternative in {@link TParser#flowControl}.
	 * @param ctx the parse tree
	 */
	void exitReturn(TParser.ReturnContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Continue}
	 * labeled alternative in {@link TParser#flowControl}.
	 * @param ctx the parse tree
	 */
	void enterContinue(TParser.ContinueContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Continue}
	 * labeled alternative in {@link TParser#flowControl}.
	 * @param ctx the parse tree
	 */
	void exitContinue(TParser.ContinueContext ctx);
	/**
	 * Enter a parse tree produced by {@link TParser#id}.
	 * @param ctx the parse tree
	 */
	void enterId(TParser.IdContext ctx);
	/**
	 * Exit a parse tree produced by {@link TParser#id}.
	 * @param ctx the parse tree
	 */
	void exitId(TParser.IdContext ctx);
	/**
	 * Enter a parse tree produced by {@link TParser#array}.
	 * @param ctx the parse tree
	 */
	void enterArray(TParser.ArrayContext ctx);
	/**
	 * Exit a parse tree produced by {@link TParser#array}.
	 * @param ctx the parse tree
	 */
	void exitArray(TParser.ArrayContext ctx);
	/**
	 * Enter a parse tree produced by {@link TParser#idarray}.
	 * @param ctx the parse tree
	 */
	void enterIdarray(TParser.IdarrayContext ctx);
	/**
	 * Exit a parse tree produced by {@link TParser#idarray}.
	 * @param ctx the parse tree
	 */
	void exitIdarray(TParser.IdarrayContext ctx);
	/**
	 * Enter a parse tree produced by {@link TParser#any}.
	 * @param ctx the parse tree
	 */
	void enterAny(TParser.AnyContext ctx);
	/**
	 * Exit a parse tree produced by {@link TParser#any}.
	 * @param ctx the parse tree
	 */
	void exitAny(TParser.AnyContext ctx);
}
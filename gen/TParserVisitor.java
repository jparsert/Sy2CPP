// Generated from /home/julian/coding/Sy2CPP/cmake-build-debug/antlr4_runtime/src/antlr4_runtime/runtime/Cpp/demo/TParser.g4 by ANTLR 4.12.0
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link TParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface TParserVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link TParser#main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMain(TParser.MainContext ctx);
	/**
	 * Visit a parse tree produced by {@link TParser#divide}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDivide(TParser.DivideContext ctx);
	/**
	 * Visit a parse tree produced by {@link TParser#and_}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAnd_(TParser.And_Context ctx);
	/**
	 * Visit a parse tree produced by {@link TParser#conquer}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConquer(TParser.ConquerContext ctx);
	/**
	 * Visit a parse tree produced by {@link TParser#unused}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUnused(TParser.UnusedContext ctx);
	/**
	 * Visit a parse tree produced by {@link TParser#unused2}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUnused2(TParser.Unused2Context ctx);
	/**
	 * Visit a parse tree produced by {@link TParser#stat}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStat(TParser.StatContext ctx);
	/**
	 * Visit a parse tree produced by {@link TParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpr(TParser.ExprContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Return}
	 * labeled alternative in {@link TParser#flowControl}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitReturn(TParser.ReturnContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Continue}
	 * labeled alternative in {@link TParser#flowControl}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitContinue(TParser.ContinueContext ctx);
	/**
	 * Visit a parse tree produced by {@link TParser#id}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitId(TParser.IdContext ctx);
	/**
	 * Visit a parse tree produced by {@link TParser#array}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArray(TParser.ArrayContext ctx);
	/**
	 * Visit a parse tree produced by {@link TParser#idarray}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdarray(TParser.IdarrayContext ctx);
	/**
	 * Visit a parse tree produced by {@link TParser#any}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAny(TParser.AnyContext ctx);
}
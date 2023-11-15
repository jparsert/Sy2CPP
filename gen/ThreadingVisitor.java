// Generated from /home/julian/coding/Sy2CPP/build/antlr4_runtime/src/antlr4_runtime/runtime/Swift/Tests/Antlr4Tests/Threading.g4 by ANTLR 4.12.0
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link ThreadingParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface ThreadingVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link ThreadingParser#s}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitS(ThreadingParser.SContext ctx);
	/**
	 * Visit a parse tree produced by the {@code add}
	 * labeled alternative in {@link ThreadingParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAdd(ThreadingParser.AddContext ctx);
	/**
	 * Visit a parse tree produced by the {@code number}
	 * labeled alternative in {@link ThreadingParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNumber(ThreadingParser.NumberContext ctx);
	/**
	 * Visit a parse tree produced by the {@code multiply}
	 * labeled alternative in {@link ThreadingParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMultiply(ThreadingParser.MultiplyContext ctx);
}
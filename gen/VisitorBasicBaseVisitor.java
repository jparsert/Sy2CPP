// Generated from /home/julian/coding/Sy2CPP/build/antlr4_runtime/src/antlr4_runtime/runtime-testsuite/test/org/antlr/v4/test/runtime/java/api/VisitorBasic.g4 by ANTLR 4.12.0
import org.antlr.v4.runtime.tree.AbstractParseTreeVisitor;

/**
 * This class provides an empty implementation of {@link VisitorBasicVisitor},
 * which can be extended to create a visitor which only needs to handle a subset
 * of the available methods.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
@SuppressWarnings("CheckReturnValue")
public class VisitorBasicBaseVisitor<T> extends AbstractParseTreeVisitor<T> implements VisitorBasicVisitor<T> {
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation returns the result of calling
	 * {@link #visitChildren} on {@code ctx}.</p>
	 */
	@Override public T visitS(VisitorBasicParser.SContext ctx) { return visitChildren(ctx); }
}
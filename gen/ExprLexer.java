// Generated from /home/julian/coding/Sy2CPP/build/antlr4_runtime/src/antlr4_runtime/runtime/Python3/tests/expr/Expr.g4 by ANTLR 4.12.0
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class ExprLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.12.0", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, MUL=9, 
		DIV=10, ADD=11, SUB=12, RETURN=13, ID=14, INT=15, NEWLINE=16, WS=17;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "MUL", 
			"DIV", "ADD", "SUB", "RETURN", "ID", "INT", "NEWLINE", "WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'def'", "'('", "','", "')'", "'{'", "'}'", "';'", "'='", "'*'", 
			"'/'", "'+'", "'-'", "'return'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, "MUL", "DIV", "ADD", 
			"SUB", "RETURN", "ID", "INT", "NEWLINE", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public ExprLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Expr.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\u0004\u0000\u0011\\\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b"+
		"\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002"+
		"\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0001\u0000\u0001\u0000\u0001"+
		"\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0001"+
		"\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0001"+
		"\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0001\b\u0001\b\u0001\t\u0001"+
		"\t\u0001\n\u0001\n\u0001\u000b\u0001\u000b\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\r\u0004\rF\b\r\u000b\r\f\rG\u0001\u000e"+
		"\u0004\u000eK\b\u000e\u000b\u000e\f\u000eL\u0001\u000f\u0003\u000fP\b"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u0010\u0004"+
		"\u0010W\b\u0010\u000b\u0010\f\u0010X\u0001\u0010\u0001\u0010\u0000\u0000"+
		"\u0011\u0001\u0001\u0003\u0002\u0005\u0003\u0007\u0004\t\u0005\u000b\u0006"+
		"\r\u0007\u000f\b\u0011\t\u0013\n\u0015\u000b\u0017\f\u0019\r\u001b\u000e"+
		"\u001d\u000f\u001f\u0010!\u0011\u0001\u0000\u0003\u0002\u0000AZaz\u0001"+
		"\u000009\u0002\u0000\t\t  _\u0000\u0001\u0001\u0000\u0000\u0000\u0000"+
		"\u0003\u0001\u0000\u0000\u0000\u0000\u0005\u0001\u0000\u0000\u0000\u0000"+
		"\u0007\u0001\u0000\u0000\u0000\u0000\t\u0001\u0000\u0000\u0000\u0000\u000b"+
		"\u0001\u0000\u0000\u0000\u0000\r\u0001\u0000\u0000\u0000\u0000\u000f\u0001"+
		"\u0000\u0000\u0000\u0000\u0011\u0001\u0000\u0000\u0000\u0000\u0013\u0001"+
		"\u0000\u0000\u0000\u0000\u0015\u0001\u0000\u0000\u0000\u0000\u0017\u0001"+
		"\u0000\u0000\u0000\u0000\u0019\u0001\u0000\u0000\u0000\u0000\u001b\u0001"+
		"\u0000\u0000\u0000\u0000\u001d\u0001\u0000\u0000\u0000\u0000\u001f\u0001"+
		"\u0000\u0000\u0000\u0000!\u0001\u0000\u0000\u0000\u0001#\u0001\u0000\u0000"+
		"\u0000\u0003\'\u0001\u0000\u0000\u0000\u0005)\u0001\u0000\u0000\u0000"+
		"\u0007+\u0001\u0000\u0000\u0000\t-\u0001\u0000\u0000\u0000\u000b/\u0001"+
		"\u0000\u0000\u0000\r1\u0001\u0000\u0000\u0000\u000f3\u0001\u0000\u0000"+
		"\u0000\u00115\u0001\u0000\u0000\u0000\u00137\u0001\u0000\u0000\u0000\u0015"+
		"9\u0001\u0000\u0000\u0000\u0017;\u0001\u0000\u0000\u0000\u0019=\u0001"+
		"\u0000\u0000\u0000\u001bE\u0001\u0000\u0000\u0000\u001dJ\u0001\u0000\u0000"+
		"\u0000\u001fO\u0001\u0000\u0000\u0000!V\u0001\u0000\u0000\u0000#$\u0005"+
		"d\u0000\u0000$%\u0005e\u0000\u0000%&\u0005f\u0000\u0000&\u0002\u0001\u0000"+
		"\u0000\u0000\'(\u0005(\u0000\u0000(\u0004\u0001\u0000\u0000\u0000)*\u0005"+
		",\u0000\u0000*\u0006\u0001\u0000\u0000\u0000+,\u0005)\u0000\u0000,\b\u0001"+
		"\u0000\u0000\u0000-.\u0005{\u0000\u0000.\n\u0001\u0000\u0000\u0000/0\u0005"+
		"}\u0000\u00000\f\u0001\u0000\u0000\u000012\u0005;\u0000\u00002\u000e\u0001"+
		"\u0000\u0000\u000034\u0005=\u0000\u00004\u0010\u0001\u0000\u0000\u0000"+
		"56\u0005*\u0000\u00006\u0012\u0001\u0000\u0000\u000078\u0005/\u0000\u0000"+
		"8\u0014\u0001\u0000\u0000\u00009:\u0005+\u0000\u0000:\u0016\u0001\u0000"+
		"\u0000\u0000;<\u0005-\u0000\u0000<\u0018\u0001\u0000\u0000\u0000=>\u0005"+
		"r\u0000\u0000>?\u0005e\u0000\u0000?@\u0005t\u0000\u0000@A\u0005u\u0000"+
		"\u0000AB\u0005r\u0000\u0000BC\u0005n\u0000\u0000C\u001a\u0001\u0000\u0000"+
		"\u0000DF\u0007\u0000\u0000\u0000ED\u0001\u0000\u0000\u0000FG\u0001\u0000"+
		"\u0000\u0000GE\u0001\u0000\u0000\u0000GH\u0001\u0000\u0000\u0000H\u001c"+
		"\u0001\u0000\u0000\u0000IK\u0007\u0001\u0000\u0000JI\u0001\u0000\u0000"+
		"\u0000KL\u0001\u0000\u0000\u0000LJ\u0001\u0000\u0000\u0000LM\u0001\u0000"+
		"\u0000\u0000M\u001e\u0001\u0000\u0000\u0000NP\u0005\r\u0000\u0000ON\u0001"+
		"\u0000\u0000\u0000OP\u0001\u0000\u0000\u0000PQ\u0001\u0000\u0000\u0000"+
		"QR\u0005\n\u0000\u0000RS\u0001\u0000\u0000\u0000ST\u0006\u000f\u0000\u0000"+
		"T \u0001\u0000\u0000\u0000UW\u0007\u0002\u0000\u0000VU\u0001\u0000\u0000"+
		"\u0000WX\u0001\u0000\u0000\u0000XV\u0001\u0000\u0000\u0000XY\u0001\u0000"+
		"\u0000\u0000YZ\u0001\u0000\u0000\u0000Z[\u0006\u0010\u0000\u0000[\"\u0001"+
		"\u0000\u0000\u0000\u0005\u0000GLOX\u0001\u0006\u0000\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}
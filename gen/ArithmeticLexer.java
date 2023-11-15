// Generated from /home/julian/coding/Sy2CPP/build/antlr4_runtime/src/antlr4_runtime/runtime/CSharp/tests/issue-3079/Arithmetic.g4 by ANTLR 4.12.0
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class ArithmeticLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.12.0", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		VARIABLE=1, SCIENTIFIC_NUMBER=2, LPAREN=3, RPAREN=4, PLUS=5, MINUS=6, 
		TIMES=7, DIV=8, GT=9, LT=10, EQ=11, POINT=12, POW=13, SEMI=14, WS=15;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"VARIABLE", "SCIENTIFIC_NUMBER", "LPAREN", "RPAREN", "PLUS", "MINUS", 
			"TIMES", "DIV", "GT", "LT", "EQ", "POINT", "POW", "SEMI", "WS", "VALID_ID_START", 
			"VALID_ID_CHAR", "NUMBER", "UNSIGNED_INTEGER", "E", "SIGN"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, "'('", "')'", "'+'", "'-'", "'*'", "'/'", "'>'", "'<'", 
			"'='", "'.'", "'^'", "';'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "VARIABLE", "SCIENTIFIC_NUMBER", "LPAREN", "RPAREN", "PLUS", "MINUS", 
			"TIMES", "DIV", "GT", "LT", "EQ", "POINT", "POW", "SEMI", "WS"
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


	public ArithmeticLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Arithmetic.g4"; }

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
		"\u0004\u0000\u000fw\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b"+
		"\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002"+
		"\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002"+
		"\u0012\u0007\u0012\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0001"+
		"\u0000\u0001\u0000\u0005\u0000.\b\u0000\n\u0000\f\u00001\t\u0000\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0003\u00016\b\u0001\u0001\u0001\u0001"+
		"\u0001\u0003\u0001:\b\u0001\u0001\u0002\u0001\u0002\u0001\u0003\u0001"+
		"\u0003\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0006\u0001"+
		"\u0006\u0001\u0007\u0001\u0007\u0001\b\u0001\b\u0001\t\u0001\t\u0001\n"+
		"\u0001\n\u0001\u000b\u0001\u000b\u0001\f\u0001\f\u0001\r\u0001\r\u0001"+
		"\u000e\u0004\u000eU\b\u000e\u000b\u000e\f\u000eV\u0001\u000e\u0001\u000e"+
		"\u0001\u000f\u0003\u000f\\\b\u000f\u0001\u0010\u0001\u0010\u0003\u0010"+
		"`\b\u0010\u0001\u0011\u0004\u0011c\b\u0011\u000b\u0011\f\u0011d\u0001"+
		"\u0011\u0001\u0011\u0004\u0011i\b\u0011\u000b\u0011\f\u0011j\u0003\u0011"+
		"m\b\u0011\u0001\u0012\u0004\u0012p\b\u0012\u000b\u0012\f\u0012q\u0001"+
		"\u0013\u0001\u0013\u0001\u0014\u0001\u0014\u0000\u0000\u0015\u0001\u0001"+
		"\u0003\u0002\u0005\u0003\u0007\u0004\t\u0005\u000b\u0006\r\u0007\u000f"+
		"\b\u0011\t\u0013\n\u0015\u000b\u0017\f\u0019\r\u001b\u000e\u001d\u000f"+
		"\u001f\u0000!\u0000#\u0000%\u0000\'\u0000)\u0000\u0001\u0000\u0004\u0003"+
		"\u0000\t\n\r\r  \u0003\u0000AZ__az\u0002\u0000EEee\u0002\u0000++--y\u0000"+
		"\u0001\u0001\u0000\u0000\u0000\u0000\u0003\u0001\u0000\u0000\u0000\u0000"+
		"\u0005\u0001\u0000\u0000\u0000\u0000\u0007\u0001\u0000\u0000\u0000\u0000"+
		"\t\u0001\u0000\u0000\u0000\u0000\u000b\u0001\u0000\u0000\u0000\u0000\r"+
		"\u0001\u0000\u0000\u0000\u0000\u000f\u0001\u0000\u0000\u0000\u0000\u0011"+
		"\u0001\u0000\u0000\u0000\u0000\u0013\u0001\u0000\u0000\u0000\u0000\u0015"+
		"\u0001\u0000\u0000\u0000\u0000\u0017\u0001\u0000\u0000\u0000\u0000\u0019"+
		"\u0001\u0000\u0000\u0000\u0000\u001b\u0001\u0000\u0000\u0000\u0000\u001d"+
		"\u0001\u0000\u0000\u0000\u0001+\u0001\u0000\u0000\u0000\u00032\u0001\u0000"+
		"\u0000\u0000\u0005;\u0001\u0000\u0000\u0000\u0007=\u0001\u0000\u0000\u0000"+
		"\t?\u0001\u0000\u0000\u0000\u000bA\u0001\u0000\u0000\u0000\rC\u0001\u0000"+
		"\u0000\u0000\u000fE\u0001\u0000\u0000\u0000\u0011G\u0001\u0000\u0000\u0000"+
		"\u0013I\u0001\u0000\u0000\u0000\u0015K\u0001\u0000\u0000\u0000\u0017M"+
		"\u0001\u0000\u0000\u0000\u0019O\u0001\u0000\u0000\u0000\u001bQ\u0001\u0000"+
		"\u0000\u0000\u001dT\u0001\u0000\u0000\u0000\u001f[\u0001\u0000\u0000\u0000"+
		"!_\u0001\u0000\u0000\u0000#b\u0001\u0000\u0000\u0000%o\u0001\u0000\u0000"+
		"\u0000\'s\u0001\u0000\u0000\u0000)u\u0001\u0000\u0000\u0000+/\u0003\u001f"+
		"\u000f\u0000,.\u0003!\u0010\u0000-,\u0001\u0000\u0000\u0000.1\u0001\u0000"+
		"\u0000\u0000/-\u0001\u0000\u0000\u0000/0\u0001\u0000\u0000\u00000\u0002"+
		"\u0001\u0000\u0000\u00001/\u0001\u0000\u0000\u000029\u0003#\u0011\u0000"+
		"35\u0003\'\u0013\u000046\u0003)\u0014\u000054\u0001\u0000\u0000\u0000"+
		"56\u0001\u0000\u0000\u000067\u0001\u0000\u0000\u000078\u0003%\u0012\u0000"+
		"8:\u0001\u0000\u0000\u000093\u0001\u0000\u0000\u00009:\u0001\u0000\u0000"+
		"\u0000:\u0004\u0001\u0000\u0000\u0000;<\u0005(\u0000\u0000<\u0006\u0001"+
		"\u0000\u0000\u0000=>\u0005)\u0000\u0000>\b\u0001\u0000\u0000\u0000?@\u0005"+
		"+\u0000\u0000@\n\u0001\u0000\u0000\u0000AB\u0005-\u0000\u0000B\f\u0001"+
		"\u0000\u0000\u0000CD\u0005*\u0000\u0000D\u000e\u0001\u0000\u0000\u0000"+
		"EF\u0005/\u0000\u0000F\u0010\u0001\u0000\u0000\u0000GH\u0005>\u0000\u0000"+
		"H\u0012\u0001\u0000\u0000\u0000IJ\u0005<\u0000\u0000J\u0014\u0001\u0000"+
		"\u0000\u0000KL\u0005=\u0000\u0000L\u0016\u0001\u0000\u0000\u0000MN\u0005"+
		".\u0000\u0000N\u0018\u0001\u0000\u0000\u0000OP\u0005^\u0000\u0000P\u001a"+
		"\u0001\u0000\u0000\u0000QR\u0005;\u0000\u0000R\u001c\u0001\u0000\u0000"+
		"\u0000SU\u0007\u0000\u0000\u0000TS\u0001\u0000\u0000\u0000UV\u0001\u0000"+
		"\u0000\u0000VT\u0001\u0000\u0000\u0000VW\u0001\u0000\u0000\u0000WX\u0001"+
		"\u0000\u0000\u0000XY\u0006\u000e\u0000\u0000Y\u001e\u0001\u0000\u0000"+
		"\u0000Z\\\u0007\u0001\u0000\u0000[Z\u0001\u0000\u0000\u0000\\ \u0001\u0000"+
		"\u0000\u0000]`\u0003\u001f\u000f\u0000^`\u000209\u0000_]\u0001\u0000\u0000"+
		"\u0000_^\u0001\u0000\u0000\u0000`\"\u0001\u0000\u0000\u0000ac\u000209"+
		"\u0000ba\u0001\u0000\u0000\u0000cd\u0001\u0000\u0000\u0000db\u0001\u0000"+
		"\u0000\u0000de\u0001\u0000\u0000\u0000el\u0001\u0000\u0000\u0000fh\u0005"+
		".\u0000\u0000gi\u000209\u0000hg\u0001\u0000\u0000\u0000ij\u0001\u0000"+
		"\u0000\u0000jh\u0001\u0000\u0000\u0000jk\u0001\u0000\u0000\u0000km\u0001"+
		"\u0000\u0000\u0000lf\u0001\u0000\u0000\u0000lm\u0001\u0000\u0000\u0000"+
		"m$\u0001\u0000\u0000\u0000np\u000209\u0000on\u0001\u0000\u0000\u0000p"+
		"q\u0001\u0000\u0000\u0000qo\u0001\u0000\u0000\u0000qr\u0001\u0000\u0000"+
		"\u0000r&\u0001\u0000\u0000\u0000st\u0007\u0002\u0000\u0000t(\u0001\u0000"+
		"\u0000\u0000uv\u0007\u0003\u0000\u0000v*\u0001\u0000\u0000\u0000\u000b"+
		"\u0000/59V[_djlq\u0001\u0000\u0001\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}
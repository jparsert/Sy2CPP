// Generated from /home/julian/coding/Sy2CPP/build/antlr4_runtime/src/antlr4_runtime/tool-testsuite/test/org/antlr/v4/test/tool/PositionAdjustingLexer.g4 by ANTLR 4.12.0
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class PositionAdjustingLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.12.0", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		ASSIGN=1, PLUS_ASSIGN=2, LCURLY=3, TOKENS=4, LABEL=5, IDENTIFIER=6, NEWLINE=7, 
		WS=8;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"ASSIGN", "PLUS_ASSIGN", "LCURLY", "TOKENS", "LABEL", "IDENTIFIER", "IGNORED", 
			"NEWLINE", "WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'='", "'+='", "'{'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "ASSIGN", "PLUS_ASSIGN", "LCURLY", "TOKENS", "LABEL", "IDENTIFIER", 
			"NEWLINE", "WS"
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


		@Override
		public Token nextToken() {
			if (!(_interp instanceof PositionAdjustingLexerATNSimulator)) {
				_interp = new PositionAdjustingLexerATNSimulator(this, _ATN, _decisionToDFA, _sharedContextCache);
			}

			return super.nextToken();
		}

		@Override
		public Token emit() {
			switch (_type) {
			case TOKENS:
				handleAcceptPositionForKeyword("tokens");
				break;

			case LABEL:
				handleAcceptPositionForIdentifier();
				break;

			default:
				break;
			}

			return super.emit();
		}

		private boolean handleAcceptPositionForIdentifier() {
			String tokenText = getText();
			int identifierLength = 0;
			while (identifierLength < tokenText.length() && isIdentifierChar(tokenText.charAt(identifierLength))) {
				identifierLength++;
			}

			if (getInputStream().index() > _tokenStartCharIndex + identifierLength) {
				int offset = identifierLength - 1;
				getInterpreter().resetAcceptPosition(getInputStream(), _tokenStartCharIndex + offset, _tokenStartLine, _tokenStartCharPositionInLine + offset);
				return true;
			}

			return false;
		}

		private boolean handleAcceptPositionForKeyword(String keyword) {
			if (getInputStream().index() > _tokenStartCharIndex + keyword.length()) {
				int offset = keyword.length() - 1;
				getInterpreter().resetAcceptPosition(getInputStream(), _tokenStartCharIndex + offset, _tokenStartLine, _tokenStartCharPositionInLine + offset);
				return true;
			}

			return false;
		}

		@Override
		public PositionAdjustingLexerATNSimulator getInterpreter() {
			return (PositionAdjustingLexerATNSimulator)super.getInterpreter();
		}

		private static boolean isIdentifierChar(char c) {
			return Character.isLetterOrDigit(c) || c == '_';
		}

		protected static class PositionAdjustingLexerATNSimulator extends LexerATNSimulator {

			public PositionAdjustingLexerATNSimulator(Lexer recog, ATN atn,
													  DFA[] decisionToDFA,
													  PredictionContextCache sharedContextCache)
			{
				super(recog, atn, decisionToDFA, sharedContextCache);
			}

			protected void resetAcceptPosition(CharStream input, int index, int line, int charPositionInLine) {
				input.seek(index);
				this.line = line;
				this.charPositionInLine = charPositionInLine;
				consume(input);
			}

		}


	public PositionAdjustingLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "PositionAdjustingLexer.g4"; }

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
		"\u0004\u0000\bF\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0001\u0000\u0001\u0000\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0001\u0003\u0001\u0003\u0001"+
		"\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001"+
		"\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0003\u0004(\b"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0005\u0005.\b"+
		"\u0005\n\u0005\f\u00051\t\u0005\u0001\u0006\u0005\u00064\b\u0006\n\u0006"+
		"\f\u00067\t\u0006\u0001\u0007\u0004\u0007:\b\u0007\u000b\u0007\f\u0007"+
		";\u0001\u0007\u0001\u0007\u0001\b\u0004\bA\b\b\u000b\b\f\bB\u0001\b\u0001"+
		"\b\u0000\u0000\t\u0001\u0001\u0003\u0002\u0005\u0003\u0007\u0004\t\u0005"+
		"\u000b\u0006\r\u0000\u000f\u0007\u0011\b\u0001\u0000\u0005\u0003\u0000"+
		"AZ__az\u0004\u000009AZ__az\u0003\u0000\t\n\r\r  \u0002\u0000\n\n\r\r\u0002"+
		"\u0000\t\t  I\u0000\u0001\u0001\u0000\u0000\u0000\u0000\u0003\u0001\u0000"+
		"\u0000\u0000\u0000\u0005\u0001\u0000\u0000\u0000\u0000\u0007\u0001\u0000"+
		"\u0000\u0000\u0000\t\u0001\u0000\u0000\u0000\u0000\u000b\u0001\u0000\u0000"+
		"\u0000\u0000\u000f\u0001\u0000\u0000\u0000\u0000\u0011\u0001\u0000\u0000"+
		"\u0000\u0001\u0013\u0001\u0000\u0000\u0000\u0003\u0015\u0001\u0000\u0000"+
		"\u0000\u0005\u0018\u0001\u0000\u0000\u0000\u0007\u001a\u0001\u0000\u0000"+
		"\u0000\t$\u0001\u0000\u0000\u0000\u000b+\u0001\u0000\u0000\u0000\r5\u0001"+
		"\u0000\u0000\u0000\u000f9\u0001\u0000\u0000\u0000\u0011@\u0001\u0000\u0000"+
		"\u0000\u0013\u0014\u0005=\u0000\u0000\u0014\u0002\u0001\u0000\u0000\u0000"+
		"\u0015\u0016\u0005+\u0000\u0000\u0016\u0017\u0005=\u0000\u0000\u0017\u0004"+
		"\u0001\u0000\u0000\u0000\u0018\u0019\u0005{\u0000\u0000\u0019\u0006\u0001"+
		"\u0000\u0000\u0000\u001a\u001b\u0005t\u0000\u0000\u001b\u001c\u0005o\u0000"+
		"\u0000\u001c\u001d\u0005k\u0000\u0000\u001d\u001e\u0005e\u0000\u0000\u001e"+
		"\u001f\u0005n\u0000\u0000\u001f \u0005s\u0000\u0000 !\u0001\u0000\u0000"+
		"\u0000!\"\u0003\r\u0006\u0000\"#\u0005{\u0000\u0000#\b\u0001\u0000\u0000"+
		"\u0000$%\u0003\u000b\u0005\u0000%\'\u0003\r\u0006\u0000&(\u0005+\u0000"+
		"\u0000\'&\u0001\u0000\u0000\u0000\'(\u0001\u0000\u0000\u0000()\u0001\u0000"+
		"\u0000\u0000)*\u0005=\u0000\u0000*\n\u0001\u0000\u0000\u0000+/\u0007\u0000"+
		"\u0000\u0000,.\u0007\u0001\u0000\u0000-,\u0001\u0000\u0000\u0000.1\u0001"+
		"\u0000\u0000\u0000/-\u0001\u0000\u0000\u0000/0\u0001\u0000\u0000\u0000"+
		"0\f\u0001\u0000\u0000\u00001/\u0001\u0000\u0000\u000024\u0007\u0002\u0000"+
		"\u000032\u0001\u0000\u0000\u000047\u0001\u0000\u0000\u000053\u0001\u0000"+
		"\u0000\u000056\u0001\u0000\u0000\u00006\u000e\u0001\u0000\u0000\u0000"+
		"75\u0001\u0000\u0000\u00008:\u0007\u0003\u0000\u000098\u0001\u0000\u0000"+
		"\u0000:;\u0001\u0000\u0000\u0000;9\u0001\u0000\u0000\u0000;<\u0001\u0000"+
		"\u0000\u0000<=\u0001\u0000\u0000\u0000=>\u0006\u0007\u0000\u0000>\u0010"+
		"\u0001\u0000\u0000\u0000?A\u0007\u0004\u0000\u0000@?\u0001\u0000\u0000"+
		"\u0000AB\u0001\u0000\u0000\u0000B@\u0001\u0000\u0000\u0000BC\u0001\u0000"+
		"\u0000\u0000CD\u0001\u0000\u0000\u0000DE\u0006\b\u0000\u0000E\u0012\u0001"+
		"\u0000\u0000\u0000\u0006\u0000\'/5;B\u0001\u0006\u0000\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}
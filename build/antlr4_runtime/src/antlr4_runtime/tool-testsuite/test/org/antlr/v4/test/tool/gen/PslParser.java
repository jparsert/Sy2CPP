// Generated from /home/julian/coding/Sy2CPP/build/antlr4_runtime/src/antlr4_runtime/tool-testsuite/test/org/antlr/v4/test/tool/Psl.g4 by ANTLR 4.12.0
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class PslParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.12.0", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		WHITESPACE_IN_LINE=1, NEWLINE=2, WHITESPACE_ALL=3, DIGIT_SEQUENCE=4, INTEGER_CONSTANT=5, 
		BINARY_CONSTANT=6, DECIMAL_CONSTANT=7, HEXADECIMAL_CONSTANT=8, OCTAL_CONSTANT=9, 
		ALL=10, EURO_NUMBER=11, NUMBER=12, RETURN=13, IDENTIFIER=14, COMMA=15, 
		MINUS=16, PAREN_LEFT=17, PAREN_RIGHT=18, PERIOD=19, PLUS=20, TILDE=21, 
		ANY_CHAR_BUT_NEWLINE=22;
	public static final int
		RULE_translation_unit = 0, RULE_pattern = 1, RULE_numeric_range = 2, RULE_numeric_endpoint = 3, 
		RULE_floating_constant = 4, RULE_comma_number = 5, RULE_term_expression = 6, 
		RULE_term = 7, RULE_integer_constant = 8;
	private static String[] makeRuleNames() {
		return new String[] {
			"translation_unit", "pattern", "numeric_range", "numeric_endpoint", "floating_constant", 
			"comma_number", "term_expression", "term", "integer_constant"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, "','", "'-'", "'('", "')'", "'.'", "'+'", "'~'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "WHITESPACE_IN_LINE", "NEWLINE", "WHITESPACE_ALL", "DIGIT_SEQUENCE", 
			"INTEGER_CONSTANT", "BINARY_CONSTANT", "DECIMAL_CONSTANT", "HEXADECIMAL_CONSTANT", 
			"OCTAL_CONSTANT", "ALL", "EURO_NUMBER", "NUMBER", "RETURN", "IDENTIFIER", 
			"COMMA", "MINUS", "PAREN_LEFT", "PAREN_RIGHT", "PERIOD", "PLUS", "TILDE", 
			"ANY_CHAR_BUT_NEWLINE"
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
	public String getGrammarFileName() { return "Psl.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }


		public void printPosition(String name, Token tok)
		{
			System.out.printf("%s: pos %d, len %d%n",
					name, tok.getCharPositionInLine(), tok.getText().length());
		}


		/**
		 * Checks whether a set of digit groups and commas construct
		 * a valid command-number.
		 *
		 * @param digits
		 *		The groups of digits, each group in a separate item.
		 * @param commas
		 *		The commas found separating the digit groups.
		 *
		 * There should be one more digit group than commas.
		 * There should be no internal white space.
		 *
		 * @returns true (valid), false (invalid)
		 */

		public boolean isValidCommaNumber(List<Token> digits, List<Token> commas)
		{
			Token[]	aDigits = new Token[0];
			Token[]	aCommas = new Token[0];
			int		j;

			aDigits = digits.toArray(aDigits);
			aCommas = commas.toArray(aCommas);
			if (aDigits.length != aCommas.length + 1)
			{
				return false;
			}
			for (j = 0; j < aCommas.length; ++j)
			{
				int	p1, p2, p3;
				p1 = aDigits[j].getCharPositionInLine()
						+ aDigits[j].getText().length();
				p2 = aCommas[j].getCharPositionInLine();
				p3 = aDigits[j + 1].getCharPositionInLine();
				if (p1 != p2 || (p2 + 1) != p3)
				{
					return false;
				}
			}
			return true;
		}


		/**
		 * Checks whether a the pieces of a floating-point number
		 * construct a valid number.
		 *
		 * @param whole
		 *		The whole part of the number.  Can be null.
		 * @param period
		 *		The decimal point.
		 * @param fraction
		 *		The fraction part of the number.  Can be null.
		 *
		 * At least one of the whole or fraction must be present.
		 * The decimal point is required.
		 *
		 * @returns true (valid), false (invalid)
		 */

		public boolean isValidFloatingConstant(
			Token whole,
			Token period,
			Token fraction
		)
		{
			boolean		foundDigits = false;
			int			column;

			if (whole != null)
			{
				foundDigits = true;
				column = whole.getCharPositionInLine()
						+ whole.getText().length();
				if (column != period.getCharPositionInLine())
				{
					return false;
				}
			}
			if (fraction != null)
			{
				foundDigits = true;
				column = period.getCharPositionInLine() + 1;
				if (column != fraction.getCharPositionInLine())
				{
					return false;
				}
			}
			return foundDigits;
		}

	public PslParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Translation_unitContext extends ParserRuleContext {
		public Numeric_rangeContext numeric_range() {
			return getRuleContext(Numeric_rangeContext.class,0);
		}
		public TerminalNode EOF() { return getToken(PslParser.EOF, 0); }
		public Translation_unitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_translation_unit; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PslListener ) ((PslListener)listener).enterTranslation_unit(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PslListener ) ((PslListener)listener).exitTranslation_unit(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof PslVisitor ) return ((PslVisitor<? extends T>)visitor).visitTranslation_unit(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Translation_unitContext translation_unit() throws RecognitionException {
		Translation_unitContext _localctx = new Translation_unitContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_translation_unit);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(18);
			numeric_range();
			setState(19);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class PatternContext extends ParserRuleContext {
		public Numeric_rangeContext numeric_range() {
			return getRuleContext(Numeric_rangeContext.class,0);
		}
		public PatternContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_pattern; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PslListener ) ((PslListener)listener).enterPattern(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PslListener ) ((PslListener)listener).exitPattern(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof PslVisitor ) return ((PslVisitor<? extends T>)visitor).visitPattern(this);
			else return visitor.visitChildren(this);
		}
	}

	public final PatternContext pattern() throws RecognitionException {
		PatternContext _localctx = new PatternContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_pattern);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(21);
			numeric_range();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Numeric_rangeContext extends ParserRuleContext {
		public TerminalNode EURO_NUMBER() { return getToken(PslParser.EURO_NUMBER, 0); }
		public TerminalNode PAREN_LEFT() { return getToken(PslParser.PAREN_LEFT, 0); }
		public List<Numeric_endpointContext> numeric_endpoint() {
			return getRuleContexts(Numeric_endpointContext.class);
		}
		public Numeric_endpointContext numeric_endpoint(int i) {
			return getRuleContext(Numeric_endpointContext.class,i);
		}
		public TerminalNode TILDE() { return getToken(PslParser.TILDE, 0); }
		public TerminalNode PAREN_RIGHT() { return getToken(PslParser.PAREN_RIGHT, 0); }
		public TerminalNode NUMBER() { return getToken(PslParser.NUMBER, 0); }
		public Numeric_rangeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numeric_range; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PslListener ) ((PslListener)listener).enterNumeric_range(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PslListener ) ((PslListener)listener).exitNumeric_range(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof PslVisitor ) return ((PslVisitor<? extends T>)visitor).visitNumeric_range(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Numeric_rangeContext numeric_range() throws RecognitionException {
		Numeric_rangeContext _localctx = new Numeric_rangeContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_numeric_range);
		try {
			setState(37);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case EURO_NUMBER:
				enterOuterAlt(_localctx, 1);
				{
				setState(23);
				match(EURO_NUMBER);
				setState(24);
				match(PAREN_LEFT);
				setState(25);
				numeric_endpoint();
				setState(26);
				match(TILDE);
				setState(27);
				numeric_endpoint();
				setState(28);
				match(PAREN_RIGHT);
				}
				break;
			case NUMBER:
				enterOuterAlt(_localctx, 2);
				{
				setState(30);
				match(NUMBER);
				setState(31);
				match(PAREN_LEFT);
				setState(32);
				numeric_endpoint();
				setState(33);
				match(TILDE);
				setState(34);
				numeric_endpoint();
				setState(35);
				match(PAREN_RIGHT);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Numeric_endpointContext extends ParserRuleContext {
		public Integer_constantContext integer_constant() {
			return getRuleContext(Integer_constantContext.class,0);
		}
		public TerminalNode PLUS() { return getToken(PslParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(PslParser.MINUS, 0); }
		public Floating_constantContext floating_constant() {
			return getRuleContext(Floating_constantContext.class,0);
		}
		public Comma_numberContext comma_number() {
			return getRuleContext(Comma_numberContext.class,0);
		}
		public Numeric_endpointContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numeric_endpoint; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PslListener ) ((PslListener)listener).enterNumeric_endpoint(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PslListener ) ((PslListener)listener).exitNumeric_endpoint(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof PslVisitor ) return ((PslVisitor<? extends T>)visitor).visitNumeric_endpoint(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Numeric_endpointContext numeric_endpoint() throws RecognitionException {
		Numeric_endpointContext _localctx = new Numeric_endpointContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_numeric_endpoint);
		int _la;
		try {
			setState(51);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(40);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==MINUS || _la==PLUS) {
					{
					setState(39);
					_la = _input.LA(1);
					if ( !(_la==MINUS || _la==PLUS) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
				}

				setState(42);
				integer_constant();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(44);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==MINUS || _la==PLUS) {
					{
					setState(43);
					_la = _input.LA(1);
					if ( !(_la==MINUS || _la==PLUS) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
				}

				setState(46);
				floating_constant();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(48);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==MINUS || _la==PLUS) {
					{
					setState(47);
					_la = _input.LA(1);
					if ( !(_la==MINUS || _la==PLUS) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
				}

				setState(50);
				comma_number();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Floating_constantContext extends ParserRuleContext {
		public Comma_numberContext comma_number;
		public Token PERIOD;
		public Token fraction;
		public Comma_numberContext comma_number() {
			return getRuleContext(Comma_numberContext.class,0);
		}
		public TerminalNode PERIOD() { return getToken(PslParser.PERIOD, 0); }
		public TerminalNode DIGIT_SEQUENCE() { return getToken(PslParser.DIGIT_SEQUENCE, 0); }
		public Floating_constantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_floating_constant; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PslListener ) ((PslListener)listener).enterFloating_constant(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PslListener ) ((PslListener)listener).exitFloating_constant(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof PslVisitor ) return ((PslVisitor<? extends T>)visitor).visitFloating_constant(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Floating_constantContext floating_constant() throws RecognitionException {
		Floating_constantContext _localctx = new Floating_constantContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_floating_constant);
		try {
			setState(63);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case DIGIT_SEQUENCE:
				enterOuterAlt(_localctx, 1);
				{
				setState(53);
				((Floating_constantContext)_localctx).comma_number = comma_number();
				setState(54);
				((Floating_constantContext)_localctx).PERIOD = match(PERIOD);
				setState(56);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
				case 1:
					{
					setState(55);
					((Floating_constantContext)_localctx).fraction = match(DIGIT_SEQUENCE);
					}
					break;
				}
				setState(58);
				if (!(
							isValidFloatingConstant((((Floating_constantContext)_localctx).comma_number!=null?(((Floating_constantContext)_localctx).comma_number.stop):null), ((Floating_constantContext)_localctx).PERIOD, ((Floating_constantContext)_localctx).fraction)
						)) throw new FailedPredicateException(this, "\n\t\t\tisValidFloatingConstant($comma_number.stop, $PERIOD, $fraction)\n\t\t", 
							"COMMA:A floating-point constant cannot have internal white space"
						);
				}
				break;
			case PERIOD:
				enterOuterAlt(_localctx, 2);
				{
				setState(60);
				((Floating_constantContext)_localctx).PERIOD = match(PERIOD);
				setState(61);
				((Floating_constantContext)_localctx).fraction = match(DIGIT_SEQUENCE);
				setState(62);
				if (!(
							isValidFloatingConstant(null, ((Floating_constantContext)_localctx).PERIOD, ((Floating_constantContext)_localctx).fraction)
						)) throw new FailedPredicateException(this, "\n\t\t\tisValidFloatingConstant(null, $PERIOD, $fraction)\n\t\t", 
							"DEC:A floating-point constant cannot have internal white space"
						);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Comma_numberContext extends ParserRuleContext {
		public Token DIGIT_SEQUENCE;
		public List<Token> digits = new ArrayList<Token>();
		public Token COMMA;
		public List<Token> commas = new ArrayList<Token>();
		public List<TerminalNode> DIGIT_SEQUENCE() { return getTokens(PslParser.DIGIT_SEQUENCE); }
		public TerminalNode DIGIT_SEQUENCE(int i) {
			return getToken(PslParser.DIGIT_SEQUENCE, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(PslParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(PslParser.COMMA, i);
		}
		public Comma_numberContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_comma_number; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PslListener ) ((PslListener)listener).enterComma_number(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PslListener ) ((PslListener)listener).exitComma_number(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof PslVisitor ) return ((PslVisitor<? extends T>)visitor).visitComma_number(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Comma_numberContext comma_number() throws RecognitionException {
		Comma_numberContext _localctx = new Comma_numberContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_comma_number);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(65);
			((Comma_numberContext)_localctx).DIGIT_SEQUENCE = match(DIGIT_SEQUENCE);
			((Comma_numberContext)_localctx).digits.add(((Comma_numberContext)_localctx).DIGIT_SEQUENCE);
			setState(68); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(66);
					((Comma_numberContext)_localctx).COMMA = match(COMMA);
					((Comma_numberContext)_localctx).commas.add(((Comma_numberContext)_localctx).COMMA);
					setState(67);
					((Comma_numberContext)_localctx).DIGIT_SEQUENCE = match(DIGIT_SEQUENCE);
					((Comma_numberContext)_localctx).digits.add(((Comma_numberContext)_localctx).DIGIT_SEQUENCE);
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(70); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			setState(72);
			if (!(
						isValidCommaNumber(((Comma_numberContext)_localctx).digits, ((Comma_numberContext)_localctx).commas)
					)) throw new FailedPredicateException(this, "\n\t\t\tisValidCommaNumber($digits, $commas)\n\t\t", 
						"A comma-number cannot have internal white space"
					);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Term_expressionContext extends ParserRuleContext {
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public TerminalNode RETURN() { return getToken(PslParser.RETURN, 0); }
		public TerminalNode PAREN_LEFT() { return getToken(PslParser.PAREN_LEFT, 0); }
		public TerminalNode PAREN_RIGHT() { return getToken(PslParser.PAREN_RIGHT, 0); }
		public Integer_constantContext integer_constant() {
			return getRuleContext(Integer_constantContext.class,0);
		}
		public TerminalNode ALL() { return getToken(PslParser.ALL, 0); }
		public Term_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_term_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PslListener ) ((PslListener)listener).enterTerm_expression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PslListener ) ((PslListener)listener).exitTerm_expression(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof PslVisitor ) return ((PslVisitor<? extends T>)visitor).visitTerm_expression(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Term_expressionContext term_expression() throws RecognitionException {
		Term_expressionContext _localctx = new Term_expressionContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_term_expression);
		try {
			setState(85);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case EURO_NUMBER:
			case NUMBER:
			case PAREN_LEFT:
				enterOuterAlt(_localctx, 1);
				{
				setState(74);
				term();
				}
				break;
			case RETURN:
				enterOuterAlt(_localctx, 2);
				{
				setState(75);
				match(RETURN);
				setState(82);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
				case 1:
					{
					setState(76);
					match(PAREN_LEFT);
					setState(79);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case DIGIT_SEQUENCE:
					case INTEGER_CONSTANT:
					case BINARY_CONSTANT:
					case DECIMAL_CONSTANT:
					case HEXADECIMAL_CONSTANT:
					case OCTAL_CONSTANT:
						{
						setState(77);
						integer_constant();
						}
						break;
					case ALL:
						{
						setState(78);
						match(ALL);
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(81);
					match(PAREN_RIGHT);
					}
					break;
				}
				setState(84);
				term();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TermContext extends ParserRuleContext {
		public PatternContext pattern() {
			return getRuleContext(PatternContext.class,0);
		}
		public TerminalNode PAREN_LEFT() { return getToken(PslParser.PAREN_LEFT, 0); }
		public Term_expressionContext term_expression() {
			return getRuleContext(Term_expressionContext.class,0);
		}
		public TerminalNode PAREN_RIGHT() { return getToken(PslParser.PAREN_RIGHT, 0); }
		public TermContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_term; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PslListener ) ((PslListener)listener).enterTerm(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PslListener ) ((PslListener)listener).exitTerm(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof PslVisitor ) return ((PslVisitor<? extends T>)visitor).visitTerm(this);
			else return visitor.visitChildren(this);
		}
	}

	public final TermContext term() throws RecognitionException {
		TermContext _localctx = new TermContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_term);
		try {
			setState(92);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case EURO_NUMBER:
			case NUMBER:
				enterOuterAlt(_localctx, 1);
				{
				setState(87);
				pattern();
				}
				break;
			case PAREN_LEFT:
				enterOuterAlt(_localctx, 2);
				{
				setState(88);
				match(PAREN_LEFT);
				setState(89);
				term_expression();
				setState(90);
				match(PAREN_RIGHT);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Integer_constantContext extends ParserRuleContext {
		public TerminalNode DIGIT_SEQUENCE() { return getToken(PslParser.DIGIT_SEQUENCE, 0); }
		public TerminalNode INTEGER_CONSTANT() { return getToken(PslParser.INTEGER_CONSTANT, 0); }
		public TerminalNode BINARY_CONSTANT() { return getToken(PslParser.BINARY_CONSTANT, 0); }
		public TerminalNode DECIMAL_CONSTANT() { return getToken(PslParser.DECIMAL_CONSTANT, 0); }
		public TerminalNode HEXADECIMAL_CONSTANT() { return getToken(PslParser.HEXADECIMAL_CONSTANT, 0); }
		public TerminalNode OCTAL_CONSTANT() { return getToken(PslParser.OCTAL_CONSTANT, 0); }
		public Integer_constantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_integer_constant; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PslListener ) ((PslListener)listener).enterInteger_constant(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PslListener ) ((PslListener)listener).exitInteger_constant(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof PslVisitor ) return ((PslVisitor<? extends T>)visitor).visitInteger_constant(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Integer_constantContext integer_constant() throws RecognitionException {
		Integer_constantContext _localctx = new Integer_constantContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_integer_constant);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(94);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 1008L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 4:
			return floating_constant_sempred((Floating_constantContext)_localctx, predIndex);
		case 5:
			return comma_number_sempred((Comma_numberContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean floating_constant_sempred(Floating_constantContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return 
					isValidFloatingConstant((((Floating_constantContext)_localctx).comma_number!=null?(((Floating_constantContext)_localctx).comma_number.stop):null), ((Floating_constantContext)_localctx).PERIOD, ((Floating_constantContext)_localctx).fraction)
				;
		case 1:
			return 
					isValidFloatingConstant(null, ((Floating_constantContext)_localctx).PERIOD, ((Floating_constantContext)_localctx).fraction)
				;
		}
		return true;
	}
	private boolean comma_number_sempred(Comma_numberContext _localctx, int predIndex) {
		switch (predIndex) {
		case 2:
			return 
					isValidCommaNumber(((Comma_numberContext)_localctx).digits, ((Comma_numberContext)_localctx).commas)
				;
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001\u0016a\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0003\u0002&\b\u0002\u0001\u0003\u0003\u0003"+
		")\b\u0003\u0001\u0003\u0001\u0003\u0003\u0003-\b\u0003\u0001\u0003\u0001"+
		"\u0003\u0003\u00031\b\u0003\u0001\u0003\u0003\u00034\b\u0003\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0003\u00049\b\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0003\u0004@\b\u0004\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0004\u0005E\b\u0005\u000b\u0005\f\u0005F\u0001"+
		"\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0003\u0006P\b\u0006\u0001\u0006\u0003\u0006S\b\u0006\u0001\u0006"+
		"\u0003\u0006V\b\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0003\u0007]\b\u0007\u0001\b\u0001\b\u0001\b\u0000\u0000"+
		"\t\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010\u0000\u0002\u0002\u0000\u0010"+
		"\u0010\u0014\u0014\u0001\u0000\u0004\td\u0000\u0012\u0001\u0000\u0000"+
		"\u0000\u0002\u0015\u0001\u0000\u0000\u0000\u0004%\u0001\u0000\u0000\u0000"+
		"\u00063\u0001\u0000\u0000\u0000\b?\u0001\u0000\u0000\u0000\nA\u0001\u0000"+
		"\u0000\u0000\fU\u0001\u0000\u0000\u0000\u000e\\\u0001\u0000\u0000\u0000"+
		"\u0010^\u0001\u0000\u0000\u0000\u0012\u0013\u0003\u0004\u0002\u0000\u0013"+
		"\u0014\u0005\u0000\u0000\u0001\u0014\u0001\u0001\u0000\u0000\u0000\u0015"+
		"\u0016\u0003\u0004\u0002\u0000\u0016\u0003\u0001\u0000\u0000\u0000\u0017"+
		"\u0018\u0005\u000b\u0000\u0000\u0018\u0019\u0005\u0011\u0000\u0000\u0019"+
		"\u001a\u0003\u0006\u0003\u0000\u001a\u001b\u0005\u0015\u0000\u0000\u001b"+
		"\u001c\u0003\u0006\u0003\u0000\u001c\u001d\u0005\u0012\u0000\u0000\u001d"+
		"&\u0001\u0000\u0000\u0000\u001e\u001f\u0005\f\u0000\u0000\u001f \u0005"+
		"\u0011\u0000\u0000 !\u0003\u0006\u0003\u0000!\"\u0005\u0015\u0000\u0000"+
		"\"#\u0003\u0006\u0003\u0000#$\u0005\u0012\u0000\u0000$&\u0001\u0000\u0000"+
		"\u0000%\u0017\u0001\u0000\u0000\u0000%\u001e\u0001\u0000\u0000\u0000&"+
		"\u0005\u0001\u0000\u0000\u0000\')\u0007\u0000\u0000\u0000(\'\u0001\u0000"+
		"\u0000\u0000()\u0001\u0000\u0000\u0000)*\u0001\u0000\u0000\u0000*4\u0003"+
		"\u0010\b\u0000+-\u0007\u0000\u0000\u0000,+\u0001\u0000\u0000\u0000,-\u0001"+
		"\u0000\u0000\u0000-.\u0001\u0000\u0000\u0000.4\u0003\b\u0004\u0000/1\u0007"+
		"\u0000\u0000\u00000/\u0001\u0000\u0000\u000001\u0001\u0000\u0000\u0000"+
		"12\u0001\u0000\u0000\u000024\u0003\n\u0005\u00003(\u0001\u0000\u0000\u0000"+
		"3,\u0001\u0000\u0000\u000030\u0001\u0000\u0000\u00004\u0007\u0001\u0000"+
		"\u0000\u000056\u0003\n\u0005\u000068\u0005\u0013\u0000\u000079\u0005\u0004"+
		"\u0000\u000087\u0001\u0000\u0000\u000089\u0001\u0000\u0000\u00009:\u0001"+
		"\u0000\u0000\u0000:;\u0004\u0004\u0000\u0001;@\u0001\u0000\u0000\u0000"+
		"<=\u0005\u0013\u0000\u0000=>\u0005\u0004\u0000\u0000>@\u0004\u0004\u0001"+
		"\u0001?5\u0001\u0000\u0000\u0000?<\u0001\u0000\u0000\u0000@\t\u0001\u0000"+
		"\u0000\u0000AD\u0005\u0004\u0000\u0000BC\u0005\u000f\u0000\u0000CE\u0005"+
		"\u0004\u0000\u0000DB\u0001\u0000\u0000\u0000EF\u0001\u0000\u0000\u0000"+
		"FD\u0001\u0000\u0000\u0000FG\u0001\u0000\u0000\u0000GH\u0001\u0000\u0000"+
		"\u0000HI\u0004\u0005\u0002\u0001I\u000b\u0001\u0000\u0000\u0000JV\u0003"+
		"\u000e\u0007\u0000KR\u0005\r\u0000\u0000LO\u0005\u0011\u0000\u0000MP\u0003"+
		"\u0010\b\u0000NP\u0005\n\u0000\u0000OM\u0001\u0000\u0000\u0000ON\u0001"+
		"\u0000\u0000\u0000PQ\u0001\u0000\u0000\u0000QS\u0005\u0012\u0000\u0000"+
		"RL\u0001\u0000\u0000\u0000RS\u0001\u0000\u0000\u0000ST\u0001\u0000\u0000"+
		"\u0000TV\u0003\u000e\u0007\u0000UJ\u0001\u0000\u0000\u0000UK\u0001\u0000"+
		"\u0000\u0000V\r\u0001\u0000\u0000\u0000W]\u0003\u0002\u0001\u0000XY\u0005"+
		"\u0011\u0000\u0000YZ\u0003\f\u0006\u0000Z[\u0005\u0012\u0000\u0000[]\u0001"+
		"\u0000\u0000\u0000\\W\u0001\u0000\u0000\u0000\\X\u0001\u0000\u0000\u0000"+
		"]\u000f\u0001\u0000\u0000\u0000^_\u0007\u0001\u0000\u0000_\u0011\u0001"+
		"\u0000\u0000\u0000\f%(,038?FORU\\";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}
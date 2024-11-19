
// Generated from grammar/prolog.g4 by ANTLR 4.13.2


#include "prologListener.h"

#include "prologParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct PrologParserStaticData final {
  PrologParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PrologParserStaticData(const PrologParserStaticData&) = delete;
  PrologParserStaticData(PrologParserStaticData&&) = delete;
  PrologParserStaticData& operator=(const PrologParserStaticData&) = delete;
  PrologParserStaticData& operator=(PrologParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag prologParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<PrologParserStaticData> prologParserStaticData = nullptr;

void prologParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (prologParserStaticData != nullptr) {
    return;
  }
#else
  assert(prologParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<PrologParserStaticData>(
    std::vector<std::string>{
      "p_text", "directive", "clause", "termlist", "term", "operator_", 
      "atom", "integer"
    },
    std::vector<std::string>{
      "", "':-'", "'.'", "','", "'('", "')'", "'-'", "'['", "'|'", "']'", 
      "'{'", "'}'", "'-->'", "'\\u003F-'", "'dynamic'", "'multifile'", "'discontiguous'", 
      "'public'", "';'", "'->'", "'\\+'", "'='", "'\\='", "'=='", "'\\=='", 
      "'@<'", "'@=<'", "'@>'", "'@>='", "'=..'", "'is'", "'=:='", "'=\\='", 
      "'<'", "'=<'", "'>'", "'>='", "':'", "'+'", "'/\\'", "'\\/'", "'*'", 
      "'/'", "'//'", "'rem'", "'mod'", "'<<'", "'>>'", "'**'", "'^'", "'\\'", 
      "'!'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "LETTER_DIGIT", "VARIABLE", "DECIMAL", "BINARY", "OCTAL", "HEX", 
      "CHARACTER_CODE_CONSTANT", "FLOAT", "GRAPHIC_TOKEN", "QUOTED", "DOUBLE_QUOTED_LIST", 
      "BACK_QUOTED_STRING", "WS", "COMMENT", "MULTILINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,66,104,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,1,0,1,0,5,0,19,8,0,10,0,12,0,22,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,
  	1,2,1,2,1,3,1,3,1,3,5,3,36,8,3,10,3,12,3,39,9,3,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,3,4,48,8,4,1,4,1,4,3,4,52,8,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,3,4,67,8,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,76,8,4,1,
  	4,1,4,1,4,1,4,5,4,82,8,4,10,4,12,4,85,9,4,1,5,1,5,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,3,6,100,8,6,1,7,1,7,1,7,0,1,8,8,0,2,4,6,8,10,
  	12,14,0,2,4,0,1,1,3,3,6,6,12,50,1,0,54,58,118,0,20,1,0,0,0,2,25,1,0,0,
  	0,4,29,1,0,0,0,6,32,1,0,0,0,8,75,1,0,0,0,10,86,1,0,0,0,12,99,1,0,0,0,
  	14,101,1,0,0,0,16,19,3,2,1,0,17,19,3,4,2,0,18,16,1,0,0,0,18,17,1,0,0,
  	0,19,22,1,0,0,0,20,18,1,0,0,0,20,21,1,0,0,0,21,23,1,0,0,0,22,20,1,0,0,
  	0,23,24,5,0,0,1,24,1,1,0,0,0,25,26,5,1,0,0,26,27,3,8,4,0,27,28,5,2,0,
  	0,28,3,1,0,0,0,29,30,3,8,4,0,30,31,5,2,0,0,31,5,1,0,0,0,32,37,3,8,4,0,
  	33,34,5,3,0,0,34,36,3,8,4,0,35,33,1,0,0,0,36,39,1,0,0,0,37,35,1,0,0,0,
  	37,38,1,0,0,0,38,7,1,0,0,0,39,37,1,0,0,0,40,41,6,4,-1,0,41,76,5,53,0,
  	0,42,43,5,4,0,0,43,44,3,8,4,0,44,45,5,5,0,0,45,76,1,0,0,0,46,48,5,6,0,
  	0,47,46,1,0,0,0,47,48,1,0,0,0,48,49,1,0,0,0,49,76,3,14,7,0,50,52,5,6,
  	0,0,51,50,1,0,0,0,51,52,1,0,0,0,52,53,1,0,0,0,53,76,5,59,0,0,54,55,3,
  	12,6,0,55,56,5,4,0,0,56,57,3,6,3,0,57,58,5,5,0,0,58,76,1,0,0,0,59,60,
  	3,10,5,0,60,61,3,8,4,4,61,76,1,0,0,0,62,63,5,7,0,0,63,66,3,6,3,0,64,65,
  	5,8,0,0,65,67,3,8,4,0,66,64,1,0,0,0,66,67,1,0,0,0,67,68,1,0,0,0,68,69,
  	5,9,0,0,69,76,1,0,0,0,70,71,5,10,0,0,71,72,3,6,3,0,72,73,5,11,0,0,73,
  	76,1,0,0,0,74,76,3,12,6,0,75,40,1,0,0,0,75,42,1,0,0,0,75,47,1,0,0,0,75,
  	51,1,0,0,0,75,54,1,0,0,0,75,59,1,0,0,0,75,62,1,0,0,0,75,70,1,0,0,0,75,
  	74,1,0,0,0,76,83,1,0,0,0,77,78,10,5,0,0,78,79,3,10,5,0,79,80,3,8,4,5,
  	80,82,1,0,0,0,81,77,1,0,0,0,82,85,1,0,0,0,83,81,1,0,0,0,83,84,1,0,0,0,
  	84,9,1,0,0,0,85,83,1,0,0,0,86,87,7,0,0,0,87,11,1,0,0,0,88,89,5,7,0,0,
  	89,100,5,9,0,0,90,91,5,10,0,0,91,100,5,11,0,0,92,100,5,52,0,0,93,100,
  	5,60,0,0,94,100,5,61,0,0,95,100,5,62,0,0,96,100,5,63,0,0,97,100,5,18,
  	0,0,98,100,5,51,0,0,99,88,1,0,0,0,99,90,1,0,0,0,99,92,1,0,0,0,99,93,1,
  	0,0,0,99,94,1,0,0,0,99,95,1,0,0,0,99,96,1,0,0,0,99,97,1,0,0,0,99,98,1,
  	0,0,0,100,13,1,0,0,0,101,102,7,1,0,0,102,15,1,0,0,0,9,18,20,37,47,51,
  	66,75,83,99
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  prologParserStaticData = std::move(staticData);
}

}

prologParser::prologParser(TokenStream *input) : prologParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

prologParser::prologParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  prologParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *prologParserStaticData->atn, prologParserStaticData->decisionToDFA, prologParserStaticData->sharedContextCache, options);
}

prologParser::~prologParser() {
  delete _interpreter;
}

const atn::ATN& prologParser::getATN() const {
  return *prologParserStaticData->atn;
}

std::string prologParser::getGrammarFileName() const {
  return "prolog.g4";
}

const std::vector<std::string>& prologParser::getRuleNames() const {
  return prologParserStaticData->ruleNames;
}

const dfa::Vocabulary& prologParser::getVocabulary() const {
  return prologParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView prologParser::getSerializedATN() const {
  return prologParserStaticData->serializedATN;
}


//----------------- P_textContext ------------------------------------------------------------------

prologParser::P_textContext::P_textContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* prologParser::P_textContext::EOF() {
  return getToken(prologParser::EOF, 0);
}

std::vector<prologParser::DirectiveContext *> prologParser::P_textContext::directive() {
  return getRuleContexts<prologParser::DirectiveContext>();
}

prologParser::DirectiveContext* prologParser::P_textContext::directive(size_t i) {
  return getRuleContext<prologParser::DirectiveContext>(i);
}

std::vector<prologParser::ClauseContext *> prologParser::P_textContext::clause() {
  return getRuleContexts<prologParser::ClauseContext>();
}

prologParser::ClauseContext* prologParser::P_textContext::clause(size_t i) {
  return getRuleContext<prologParser::ClauseContext>(i);
}


size_t prologParser::P_textContext::getRuleIndex() const {
  return prologParser::RuleP_text;
}

void prologParser::P_textContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterP_text(this);
}

void prologParser::P_textContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitP_text(this);
}

prologParser::P_textContext* prologParser::p_text() {
  P_textContext *_localctx = _tracker.createInstance<P_textContext>(_ctx, getState());
  enterRule(_localctx, 0, prologParser::RuleP_text);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(20);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -2854) != 0)) {
      setState(18);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(16);
        directive();
        break;
      }

      case 2: {
        setState(17);
        clause();
        break;
      }

      default:
        break;
      }
      setState(22);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(23);
    match(prologParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectiveContext ------------------------------------------------------------------

prologParser::DirectiveContext::DirectiveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

prologParser::TermContext* prologParser::DirectiveContext::term() {
  return getRuleContext<prologParser::TermContext>(0);
}


size_t prologParser::DirectiveContext::getRuleIndex() const {
  return prologParser::RuleDirective;
}

void prologParser::DirectiveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDirective(this);
}

void prologParser::DirectiveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDirective(this);
}

prologParser::DirectiveContext* prologParser::directive() {
  DirectiveContext *_localctx = _tracker.createInstance<DirectiveContext>(_ctx, getState());
  enterRule(_localctx, 2, prologParser::RuleDirective);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(25);
    match(prologParser::T__0);
    setState(26);
    term(0);
    setState(27);
    match(prologParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClauseContext ------------------------------------------------------------------

prologParser::ClauseContext::ClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

prologParser::TermContext* prologParser::ClauseContext::term() {
  return getRuleContext<prologParser::TermContext>(0);
}


size_t prologParser::ClauseContext::getRuleIndex() const {
  return prologParser::RuleClause;
}

void prologParser::ClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClause(this);
}

void prologParser::ClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClause(this);
}

prologParser::ClauseContext* prologParser::clause() {
  ClauseContext *_localctx = _tracker.createInstance<ClauseContext>(_ctx, getState());
  enterRule(_localctx, 4, prologParser::RuleClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29);
    term(0);
    setState(30);
    match(prologParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermlistContext ------------------------------------------------------------------

prologParser::TermlistContext::TermlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<prologParser::TermContext *> prologParser::TermlistContext::term() {
  return getRuleContexts<prologParser::TermContext>();
}

prologParser::TermContext* prologParser::TermlistContext::term(size_t i) {
  return getRuleContext<prologParser::TermContext>(i);
}


size_t prologParser::TermlistContext::getRuleIndex() const {
  return prologParser::RuleTermlist;
}

void prologParser::TermlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTermlist(this);
}

void prologParser::TermlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTermlist(this);
}

prologParser::TermlistContext* prologParser::termlist() {
  TermlistContext *_localctx = _tracker.createInstance<TermlistContext>(_ctx, getState());
  enterRule(_localctx, 6, prologParser::RuleTermlist);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(32);
    term(0);
    setState(37);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == prologParser::T__2) {
      setState(33);
      match(prologParser::T__2);
      setState(34);
      term(0);
      setState(39);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

prologParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t prologParser::TermContext::getRuleIndex() const {
  return prologParser::RuleTerm;
}

void prologParser::TermContext::copyFrom(TermContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Atom_termContext ------------------------------------------------------------------

prologParser::AtomContext* prologParser::Atom_termContext::atom() {
  return getRuleContext<prologParser::AtomContext>(0);
}

prologParser::Atom_termContext::Atom_termContext(TermContext *ctx) { copyFrom(ctx); }

void prologParser::Atom_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_term(this);
}
void prologParser::Atom_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_term(this);
}
//----------------- Binary_operatorContext ------------------------------------------------------------------

std::vector<prologParser::TermContext *> prologParser::Binary_operatorContext::term() {
  return getRuleContexts<prologParser::TermContext>();
}

prologParser::TermContext* prologParser::Binary_operatorContext::term(size_t i) {
  return getRuleContext<prologParser::TermContext>(i);
}

prologParser::Operator_Context* prologParser::Binary_operatorContext::operator_() {
  return getRuleContext<prologParser::Operator_Context>(0);
}

prologParser::Binary_operatorContext::Binary_operatorContext(TermContext *ctx) { copyFrom(ctx); }

void prologParser::Binary_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinary_operator(this);
}
void prologParser::Binary_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinary_operator(this);
}
//----------------- Unary_operatorContext ------------------------------------------------------------------

prologParser::Operator_Context* prologParser::Unary_operatorContext::operator_() {
  return getRuleContext<prologParser::Operator_Context>(0);
}

prologParser::TermContext* prologParser::Unary_operatorContext::term() {
  return getRuleContext<prologParser::TermContext>(0);
}

prologParser::Unary_operatorContext::Unary_operatorContext(TermContext *ctx) { copyFrom(ctx); }

void prologParser::Unary_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_operator(this);
}
void prologParser::Unary_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_operator(this);
}
//----------------- Braced_termContext ------------------------------------------------------------------

prologParser::TermContext* prologParser::Braced_termContext::term() {
  return getRuleContext<prologParser::TermContext>(0);
}

prologParser::Braced_termContext::Braced_termContext(TermContext *ctx) { copyFrom(ctx); }

void prologParser::Braced_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBraced_term(this);
}
void prologParser::Braced_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBraced_term(this);
}
//----------------- List_termContext ------------------------------------------------------------------

prologParser::TermlistContext* prologParser::List_termContext::termlist() {
  return getRuleContext<prologParser::TermlistContext>(0);
}

prologParser::TermContext* prologParser::List_termContext::term() {
  return getRuleContext<prologParser::TermContext>(0);
}

prologParser::List_termContext::List_termContext(TermContext *ctx) { copyFrom(ctx); }

void prologParser::List_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterList_term(this);
}
void prologParser::List_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitList_term(this);
}
//----------------- VariableContext ------------------------------------------------------------------

tree::TerminalNode* prologParser::VariableContext::VARIABLE() {
  return getToken(prologParser::VARIABLE, 0);
}

prologParser::VariableContext::VariableContext(TermContext *ctx) { copyFrom(ctx); }

void prologParser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}
void prologParser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}
//----------------- FloatContext ------------------------------------------------------------------

tree::TerminalNode* prologParser::FloatContext::FLOAT() {
  return getToken(prologParser::FLOAT, 0);
}

prologParser::FloatContext::FloatContext(TermContext *ctx) { copyFrom(ctx); }

void prologParser::FloatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloat(this);
}
void prologParser::FloatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloat(this);
}
//----------------- Compound_termContext ------------------------------------------------------------------

prologParser::AtomContext* prologParser::Compound_termContext::atom() {
  return getRuleContext<prologParser::AtomContext>(0);
}

prologParser::TermlistContext* prologParser::Compound_termContext::termlist() {
  return getRuleContext<prologParser::TermlistContext>(0);
}

prologParser::Compound_termContext::Compound_termContext(TermContext *ctx) { copyFrom(ctx); }

void prologParser::Compound_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_term(this);
}
void prologParser::Compound_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_term(this);
}
//----------------- Integer_termContext ------------------------------------------------------------------

prologParser::IntegerContext* prologParser::Integer_termContext::integer() {
  return getRuleContext<prologParser::IntegerContext>(0);
}

prologParser::Integer_termContext::Integer_termContext(TermContext *ctx) { copyFrom(ctx); }

void prologParser::Integer_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInteger_term(this);
}
void prologParser::Integer_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInteger_term(this);
}
//----------------- Curly_bracketed_termContext ------------------------------------------------------------------

prologParser::TermlistContext* prologParser::Curly_bracketed_termContext::termlist() {
  return getRuleContext<prologParser::TermlistContext>(0);
}

prologParser::Curly_bracketed_termContext::Curly_bracketed_termContext(TermContext *ctx) { copyFrom(ctx); }

void prologParser::Curly_bracketed_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCurly_bracketed_term(this);
}
void prologParser::Curly_bracketed_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCurly_bracketed_term(this);
}

prologParser::TermContext* prologParser::term() {
   return term(0);
}

prologParser::TermContext* prologParser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  prologParser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  prologParser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, prologParser::RuleTerm, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(75);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<VariableContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(41);
      match(prologParser::VARIABLE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Braced_termContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(42);
      match(prologParser::T__3);
      setState(43);
      term(0);
      setState(44);
      match(prologParser::T__4);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Integer_termContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(47);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == prologParser::T__5) {
        setState(46);
        match(prologParser::T__5);
      }
      setState(49);
      integer();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<FloatContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(51);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == prologParser::T__5) {
        setState(50);
        match(prologParser::T__5);
      }
      setState(53);
      match(prologParser::FLOAT);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<Compound_termContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(54);
      atom();
      setState(55);
      match(prologParser::T__3);
      setState(56);
      termlist();
      setState(57);
      match(prologParser::T__4);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<Unary_operatorContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(59);
      operator_();
      setState(60);
      term(4);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<List_termContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(62);
      match(prologParser::T__6);
      setState(63);
      termlist();
      setState(66);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == prologParser::T__7) {
        setState(64);
        match(prologParser::T__7);
        setState(65);
        term(0);
      }
      setState(68);
      match(prologParser::T__8);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<Curly_bracketed_termContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(70);
      match(prologParser::T__9);
      setState(71);
      termlist();
      setState(72);
      match(prologParser::T__10);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<Atom_termContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(74);
      atom();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(83);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Binary_operatorContext>(_tracker.createInstance<TermContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleTerm);
        setState(77);

        if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
        setState(78);
        operator_();
        setState(79);
        term(5); 
      }
      setState(85);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Operator_Context ------------------------------------------------------------------

prologParser::Operator_Context::Operator_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t prologParser::Operator_Context::getRuleIndex() const {
  return prologParser::RuleOperator_;
}

void prologParser::Operator_Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperator_(this);
}

void prologParser::Operator_Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperator_(this);
}

prologParser::Operator_Context* prologParser::operator_() {
  Operator_Context *_localctx = _tracker.createInstance<Operator_Context>(_ctx, getState());
  enterRule(_localctx, 10, prologParser::RuleOperator_);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2251799813681226) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

prologParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t prologParser::AtomContext::getRuleIndex() const {
  return prologParser::RuleAtom;
}

void prologParser::AtomContext::copyFrom(AtomContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Backq_stringContext ------------------------------------------------------------------

tree::TerminalNode* prologParser::Backq_stringContext::BACK_QUOTED_STRING() {
  return getToken(prologParser::BACK_QUOTED_STRING, 0);
}

prologParser::Backq_stringContext::Backq_stringContext(AtomContext *ctx) { copyFrom(ctx); }

void prologParser::Backq_stringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBackq_string(this);
}
void prologParser::Backq_stringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBackq_string(this);
}
//----------------- CutContext ------------------------------------------------------------------

prologParser::CutContext::CutContext(AtomContext *ctx) { copyFrom(ctx); }

void prologParser::CutContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCut(this);
}
void prologParser::CutContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCut(this);
}
//----------------- Empty_bracesContext ------------------------------------------------------------------

prologParser::Empty_bracesContext::Empty_bracesContext(AtomContext *ctx) { copyFrom(ctx); }

void prologParser::Empty_bracesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmpty_braces(this);
}
void prologParser::Empty_bracesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmpty_braces(this);
}
//----------------- Dq_stringContext ------------------------------------------------------------------

tree::TerminalNode* prologParser::Dq_stringContext::DOUBLE_QUOTED_LIST() {
  return getToken(prologParser::DOUBLE_QUOTED_LIST, 0);
}

prologParser::Dq_stringContext::Dq_stringContext(AtomContext *ctx) { copyFrom(ctx); }

void prologParser::Dq_stringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDq_string(this);
}
void prologParser::Dq_stringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDq_string(this);
}
//----------------- NameContext ------------------------------------------------------------------

tree::TerminalNode* prologParser::NameContext::LETTER_DIGIT() {
  return getToken(prologParser::LETTER_DIGIT, 0);
}

prologParser::NameContext::NameContext(AtomContext *ctx) { copyFrom(ctx); }

void prologParser::NameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName(this);
}
void prologParser::NameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName(this);
}
//----------------- Quoted_stringContext ------------------------------------------------------------------

tree::TerminalNode* prologParser::Quoted_stringContext::QUOTED() {
  return getToken(prologParser::QUOTED, 0);
}

prologParser::Quoted_stringContext::Quoted_stringContext(AtomContext *ctx) { copyFrom(ctx); }

void prologParser::Quoted_stringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuoted_string(this);
}
void prologParser::Quoted_stringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuoted_string(this);
}
//----------------- Empty_listContext ------------------------------------------------------------------

prologParser::Empty_listContext::Empty_listContext(AtomContext *ctx) { copyFrom(ctx); }

void prologParser::Empty_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmpty_list(this);
}
void prologParser::Empty_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmpty_list(this);
}
//----------------- GraphicContext ------------------------------------------------------------------

tree::TerminalNode* prologParser::GraphicContext::GRAPHIC_TOKEN() {
  return getToken(prologParser::GRAPHIC_TOKEN, 0);
}

prologParser::GraphicContext::GraphicContext(AtomContext *ctx) { copyFrom(ctx); }

void prologParser::GraphicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGraphic(this);
}
void prologParser::GraphicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGraphic(this);
}
//----------------- SemicolonContext ------------------------------------------------------------------

prologParser::SemicolonContext::SemicolonContext(AtomContext *ctx) { copyFrom(ctx); }

void prologParser::SemicolonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSemicolon(this);
}
void prologParser::SemicolonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSemicolon(this);
}
prologParser::AtomContext* prologParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 12, prologParser::RuleAtom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(99);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case prologParser::T__6: {
        _localctx = _tracker.createInstance<prologParser::Empty_listContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(88);
        match(prologParser::T__6);
        setState(89);
        match(prologParser::T__8);
        break;
      }

      case prologParser::T__9: {
        _localctx = _tracker.createInstance<prologParser::Empty_bracesContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(90);
        match(prologParser::T__9);
        setState(91);
        match(prologParser::T__10);
        break;
      }

      case prologParser::LETTER_DIGIT: {
        _localctx = _tracker.createInstance<prologParser::NameContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(92);
        match(prologParser::LETTER_DIGIT);
        break;
      }

      case prologParser::GRAPHIC_TOKEN: {
        _localctx = _tracker.createInstance<prologParser::GraphicContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(93);
        match(prologParser::GRAPHIC_TOKEN);
        break;
      }

      case prologParser::QUOTED: {
        _localctx = _tracker.createInstance<prologParser::Quoted_stringContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(94);
        match(prologParser::QUOTED);
        break;
      }

      case prologParser::DOUBLE_QUOTED_LIST: {
        _localctx = _tracker.createInstance<prologParser::Dq_stringContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(95);
        match(prologParser::DOUBLE_QUOTED_LIST);
        break;
      }

      case prologParser::BACK_QUOTED_STRING: {
        _localctx = _tracker.createInstance<prologParser::Backq_stringContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(96);
        match(prologParser::BACK_QUOTED_STRING);
        break;
      }

      case prologParser::T__17: {
        _localctx = _tracker.createInstance<prologParser::SemicolonContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(97);
        match(prologParser::T__17);
        break;
      }

      case prologParser::T__50: {
        _localctx = _tracker.createInstance<prologParser::CutContext>(_localctx);
        enterOuterAlt(_localctx, 9);
        setState(98);
        match(prologParser::T__50);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegerContext ------------------------------------------------------------------

prologParser::IntegerContext::IntegerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* prologParser::IntegerContext::DECIMAL() {
  return getToken(prologParser::DECIMAL, 0);
}

tree::TerminalNode* prologParser::IntegerContext::CHARACTER_CODE_CONSTANT() {
  return getToken(prologParser::CHARACTER_CODE_CONSTANT, 0);
}

tree::TerminalNode* prologParser::IntegerContext::BINARY() {
  return getToken(prologParser::BINARY, 0);
}

tree::TerminalNode* prologParser::IntegerContext::OCTAL() {
  return getToken(prologParser::OCTAL, 0);
}

tree::TerminalNode* prologParser::IntegerContext::HEX() {
  return getToken(prologParser::HEX, 0);
}


size_t prologParser::IntegerContext::getRuleIndex() const {
  return prologParser::RuleInteger;
}

void prologParser::IntegerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInteger(this);
}

void prologParser::IntegerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<prologListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInteger(this);
}

prologParser::IntegerContext* prologParser::integer() {
  IntegerContext *_localctx = _tracker.createInstance<IntegerContext>(_ctx, getState());
  enterRule(_localctx, 14, prologParser::RuleInteger);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 558446353793941504) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool prologParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 4: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool prologParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

void prologParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  prologParserInitialize();
#else
  ::antlr4::internal::call_once(prologParserOnceFlag, prologParserInitialize);
#endif
}

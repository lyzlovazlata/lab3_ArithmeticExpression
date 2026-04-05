
// Generated from Pascal.g4 by ANTLR 4.13.2


#include "PascalVisitor.h"

#include "PascalParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct PascalParserStaticData final {
  PascalParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PascalParserStaticData(const PascalParserStaticData&) = delete;
  PascalParserStaticData(PascalParserStaticData&&) = delete;
  PascalParserStaticData& operator=(const PascalParserStaticData&) = delete;
  PascalParserStaticData& operator=(PascalParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag pascalParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<PascalParserStaticData> pascalParserStaticData = nullptr;

void pascalParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (pascalParserStaticData != nullptr) {
    return;
  }
#else
  assert(pascalParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<PascalParserStaticData>(
    std::vector<std::string>{
      "program", "statement", "assignment", "whileLoop", "condition", "expression", 
      "term", "factor"
    },
    std::vector<std::string>{
      "", "'('", "')'", "'+'", "'-'", "'*'", "'/'", "';'", "'='", "'while'", 
      "'do'", "'end'", "'<'", "'>'", "'<='", "'>='"
    },
    std::vector<std::string>{
      "", "", "", "PLUS", "MINUS", "MULTIPLY", "DEVIDE", "SEMICOLON", "EQUALS", 
      "WHILE", "DO", "END", "LESS", "GREATER", "LESS_EQ", "GREATER_EQ", 
      "NOT_EQ", "VARIABLE", "DOUBLE", "INTEGER", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,20,83,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
  	7,7,1,0,5,0,18,8,0,10,0,12,0,21,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,3,1,34,8,1,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,5,3,46,8,
  	3,10,3,12,3,49,9,3,1,3,1,3,1,4,1,4,1,4,3,4,56,8,4,1,5,1,5,1,5,5,5,61,
  	8,5,10,5,12,5,64,9,5,1,6,1,6,1,6,5,6,69,8,6,10,6,12,6,72,9,6,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,3,7,81,8,7,1,7,0,0,8,0,2,4,6,8,10,12,14,0,3,2,0,8,
  	8,12,16,1,0,3,4,1,0,5,6,84,0,19,1,0,0,0,2,33,1,0,0,0,4,35,1,0,0,0,6,39,
  	1,0,0,0,8,52,1,0,0,0,10,57,1,0,0,0,12,65,1,0,0,0,14,80,1,0,0,0,16,18,
  	3,2,1,0,17,16,1,0,0,0,18,21,1,0,0,0,19,17,1,0,0,0,19,20,1,0,0,0,20,22,
  	1,0,0,0,21,19,1,0,0,0,22,23,5,0,0,1,23,1,1,0,0,0,24,25,3,4,2,0,25,26,
  	5,7,0,0,26,34,1,0,0,0,27,28,3,6,3,0,28,29,5,7,0,0,29,34,1,0,0,0,30,31,
  	3,10,5,0,31,32,5,7,0,0,32,34,1,0,0,0,33,24,1,0,0,0,33,27,1,0,0,0,33,30,
  	1,0,0,0,34,3,1,0,0,0,35,36,5,17,0,0,36,37,5,8,0,0,37,38,3,10,5,0,38,5,
  	1,0,0,0,39,40,5,9,0,0,40,41,5,1,0,0,41,42,3,8,4,0,42,43,5,2,0,0,43,47,
  	5,10,0,0,44,46,3,2,1,0,45,44,1,0,0,0,46,49,1,0,0,0,47,45,1,0,0,0,47,48,
  	1,0,0,0,48,50,1,0,0,0,49,47,1,0,0,0,50,51,5,11,0,0,51,7,1,0,0,0,52,55,
  	3,10,5,0,53,54,7,0,0,0,54,56,3,10,5,0,55,53,1,0,0,0,55,56,1,0,0,0,56,
  	9,1,0,0,0,57,62,3,12,6,0,58,59,7,1,0,0,59,61,3,12,6,0,60,58,1,0,0,0,61,
  	64,1,0,0,0,62,60,1,0,0,0,62,63,1,0,0,0,63,11,1,0,0,0,64,62,1,0,0,0,65,
  	70,3,14,7,0,66,67,7,2,0,0,67,69,3,14,7,0,68,66,1,0,0,0,69,72,1,0,0,0,
  	70,68,1,0,0,0,70,71,1,0,0,0,71,13,1,0,0,0,72,70,1,0,0,0,73,81,5,19,0,
  	0,74,81,5,18,0,0,75,81,5,17,0,0,76,77,5,1,0,0,77,78,3,10,5,0,78,79,5,
  	2,0,0,79,81,1,0,0,0,80,73,1,0,0,0,80,74,1,0,0,0,80,75,1,0,0,0,80,76,1,
  	0,0,0,81,15,1,0,0,0,7,19,33,47,55,62,70,80
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  pascalParserStaticData = std::move(staticData);
}

}

PascalParser::PascalParser(TokenStream *input) : PascalParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

PascalParser::PascalParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  PascalParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *pascalParserStaticData->atn, pascalParserStaticData->decisionToDFA, pascalParserStaticData->sharedContextCache, options);
}

PascalParser::~PascalParser() {
  delete _interpreter;
}

const atn::ATN& PascalParser::getATN() const {
  return *pascalParserStaticData->atn;
}

std::string PascalParser::getGrammarFileName() const {
  return "Pascal.g4";
}

const std::vector<std::string>& PascalParser::getRuleNames() const {
  return pascalParserStaticData->ruleNames;
}

const dfa::Vocabulary& PascalParser::getVocabulary() const {
  return pascalParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PascalParser::getSerializedATN() const {
  return pascalParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

PascalParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ProgramContext::EOF() {
  return getToken(PascalParser::EOF, 0);
}

std::vector<PascalParser::StatementContext *> PascalParser::ProgramContext::statement() {
  return getRuleContexts<PascalParser::StatementContext>();
}

PascalParser::StatementContext* PascalParser::ProgramContext::statement(size_t i) {
  return getRuleContext<PascalParser::StatementContext>(i);
}


size_t PascalParser::ProgramContext::getRuleIndex() const {
  return PascalParser::RuleProgram;
}


std::any PascalParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProgramContext* PascalParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, PascalParser::RuleProgram);
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
    setState(19);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 918018) != 0)) {
      setState(16);
      statement();
      setState(21);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(22);
    match(PascalParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

PascalParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::AssignmentContext* PascalParser::StatementContext::assignment() {
  return getRuleContext<PascalParser::AssignmentContext>(0);
}

tree::TerminalNode* PascalParser::StatementContext::SEMICOLON() {
  return getToken(PascalParser::SEMICOLON, 0);
}

PascalParser::WhileLoopContext* PascalParser::StatementContext::whileLoop() {
  return getRuleContext<PascalParser::WhileLoopContext>(0);
}

PascalParser::ExpressionContext* PascalParser::StatementContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}


size_t PascalParser::StatementContext::getRuleIndex() const {
  return PascalParser::RuleStatement;
}


std::any PascalParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::StatementContext* PascalParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, PascalParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(33);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(24);
      assignment();
      setState(25);
      match(PascalParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(27);
      whileLoop();
      setState(28);
      match(PascalParser::SEMICOLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(30);
      expression();
      setState(31);
      match(PascalParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

PascalParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::AssignmentContext::VARIABLE() {
  return getToken(PascalParser::VARIABLE, 0);
}

tree::TerminalNode* PascalParser::AssignmentContext::EQUALS() {
  return getToken(PascalParser::EQUALS, 0);
}

PascalParser::ExpressionContext* PascalParser::AssignmentContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}


size_t PascalParser::AssignmentContext::getRuleIndex() const {
  return PascalParser::RuleAssignment;
}


std::any PascalParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::AssignmentContext* PascalParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 4, PascalParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35);
    match(PascalParser::VARIABLE);
    setState(36);
    match(PascalParser::EQUALS);
    setState(37);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileLoopContext ------------------------------------------------------------------

PascalParser::WhileLoopContext::WhileLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::WhileLoopContext::WHILE() {
  return getToken(PascalParser::WHILE, 0);
}

PascalParser::ConditionContext* PascalParser::WhileLoopContext::condition() {
  return getRuleContext<PascalParser::ConditionContext>(0);
}

tree::TerminalNode* PascalParser::WhileLoopContext::DO() {
  return getToken(PascalParser::DO, 0);
}

tree::TerminalNode* PascalParser::WhileLoopContext::END() {
  return getToken(PascalParser::END, 0);
}

std::vector<PascalParser::StatementContext *> PascalParser::WhileLoopContext::statement() {
  return getRuleContexts<PascalParser::StatementContext>();
}

PascalParser::StatementContext* PascalParser::WhileLoopContext::statement(size_t i) {
  return getRuleContext<PascalParser::StatementContext>(i);
}


size_t PascalParser::WhileLoopContext::getRuleIndex() const {
  return PascalParser::RuleWhileLoop;
}


std::any PascalParser::WhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitWhileLoop(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::WhileLoopContext* PascalParser::whileLoop() {
  WhileLoopContext *_localctx = _tracker.createInstance<WhileLoopContext>(_ctx, getState());
  enterRule(_localctx, 6, PascalParser::RuleWhileLoop);
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
    setState(39);
    match(PascalParser::WHILE);
    setState(40);
    match(PascalParser::T__0);
    setState(41);
    condition();
    setState(42);
    match(PascalParser::T__1);
    setState(43);
    match(PascalParser::DO);
    setState(47);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 918018) != 0)) {
      setState(44);
      statement();
      setState(49);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(50);
    match(PascalParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

PascalParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::ExpressionContext *> PascalParser::ConditionContext::expression() {
  return getRuleContexts<PascalParser::ExpressionContext>();
}

PascalParser::ExpressionContext* PascalParser::ConditionContext::expression(size_t i) {
  return getRuleContext<PascalParser::ExpressionContext>(i);
}

tree::TerminalNode* PascalParser::ConditionContext::LESS() {
  return getToken(PascalParser::LESS, 0);
}

tree::TerminalNode* PascalParser::ConditionContext::GREATER() {
  return getToken(PascalParser::GREATER, 0);
}

tree::TerminalNode* PascalParser::ConditionContext::EQUALS() {
  return getToken(PascalParser::EQUALS, 0);
}

tree::TerminalNode* PascalParser::ConditionContext::LESS_EQ() {
  return getToken(PascalParser::LESS_EQ, 0);
}

tree::TerminalNode* PascalParser::ConditionContext::GREATER_EQ() {
  return getToken(PascalParser::GREATER_EQ, 0);
}

tree::TerminalNode* PascalParser::ConditionContext::NOT_EQ() {
  return getToken(PascalParser::NOT_EQ, 0);
}


size_t PascalParser::ConditionContext::getRuleIndex() const {
  return PascalParser::RuleCondition;
}


std::any PascalParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ConditionContext* PascalParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 8, PascalParser::RuleCondition);
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
    setState(52);
    expression();
    setState(55);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 127232) != 0)) {
      setState(53);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 127232) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(54);
      expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

PascalParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::TermContext *> PascalParser::ExpressionContext::term() {
  return getRuleContexts<PascalParser::TermContext>();
}

PascalParser::TermContext* PascalParser::ExpressionContext::term(size_t i) {
  return getRuleContext<PascalParser::TermContext>(i);
}

std::vector<tree::TerminalNode *> PascalParser::ExpressionContext::PLUS() {
  return getTokens(PascalParser::PLUS);
}

tree::TerminalNode* PascalParser::ExpressionContext::PLUS(size_t i) {
  return getToken(PascalParser::PLUS, i);
}

std::vector<tree::TerminalNode *> PascalParser::ExpressionContext::MINUS() {
  return getTokens(PascalParser::MINUS);
}

tree::TerminalNode* PascalParser::ExpressionContext::MINUS(size_t i) {
  return getToken(PascalParser::MINUS, i);
}


size_t PascalParser::ExpressionContext::getRuleIndex() const {
  return PascalParser::RuleExpression;
}


std::any PascalParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ExpressionContext* PascalParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 10, PascalParser::RuleExpression);
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
    setState(57);
    term();
    setState(62);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::PLUS

    || _la == PascalParser::MINUS) {
      setState(58);
      _la = _input->LA(1);
      if (!(_la == PascalParser::PLUS

      || _la == PascalParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(59);
      term();
      setState(64);
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

PascalParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::FactorContext *> PascalParser::TermContext::factor() {
  return getRuleContexts<PascalParser::FactorContext>();
}

PascalParser::FactorContext* PascalParser::TermContext::factor(size_t i) {
  return getRuleContext<PascalParser::FactorContext>(i);
}

std::vector<tree::TerminalNode *> PascalParser::TermContext::MULTIPLY() {
  return getTokens(PascalParser::MULTIPLY);
}

tree::TerminalNode* PascalParser::TermContext::MULTIPLY(size_t i) {
  return getToken(PascalParser::MULTIPLY, i);
}

std::vector<tree::TerminalNode *> PascalParser::TermContext::DEVIDE() {
  return getTokens(PascalParser::DEVIDE);
}

tree::TerminalNode* PascalParser::TermContext::DEVIDE(size_t i) {
  return getToken(PascalParser::DEVIDE, i);
}


size_t PascalParser::TermContext::getRuleIndex() const {
  return PascalParser::RuleTerm;
}


std::any PascalParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::TermContext* PascalParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 12, PascalParser::RuleTerm);
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
    setState(65);
    factor();
    setState(70);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::MULTIPLY

    || _la == PascalParser::DEVIDE) {
      setState(66);
      _la = _input->LA(1);
      if (!(_la == PascalParser::MULTIPLY

      || _la == PascalParser::DEVIDE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(67);
      factor();
      setState(72);
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

//----------------- FactorContext ------------------------------------------------------------------

PascalParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::FactorContext::INTEGER() {
  return getToken(PascalParser::INTEGER, 0);
}

tree::TerminalNode* PascalParser::FactorContext::DOUBLE() {
  return getToken(PascalParser::DOUBLE, 0);
}

tree::TerminalNode* PascalParser::FactorContext::VARIABLE() {
  return getToken(PascalParser::VARIABLE, 0);
}

PascalParser::ExpressionContext* PascalParser::FactorContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}


size_t PascalParser::FactorContext::getRuleIndex() const {
  return PascalParser::RuleFactor;
}


std::any PascalParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FactorContext* PascalParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 14, PascalParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(80);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(73);
        match(PascalParser::INTEGER);
        break;
      }

      case PascalParser::DOUBLE: {
        enterOuterAlt(_localctx, 2);
        setState(74);
        match(PascalParser::DOUBLE);
        break;
      }

      case PascalParser::VARIABLE: {
        enterOuterAlt(_localctx, 3);
        setState(75);
        match(PascalParser::VARIABLE);
        break;
      }

      case PascalParser::T__0: {
        enterOuterAlt(_localctx, 4);
        setState(76);
        match(PascalParser::T__0);
        setState(77);
        expression();
        setState(78);
        match(PascalParser::T__1);
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

void PascalParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  pascalParserInitialize();
#else
  ::antlr4::internal::call_once(pascalParserOnceFlag, pascalParserInitialize);
#endif
}

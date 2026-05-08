
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
      "program", "statement", "assignment", "whileLoop", "ifcond", "block", 
      "condition", "expression", "term", "factor"
    },
    std::vector<std::string>{
      "", "'('", "')'", "'+'", "'-'", "'*'", "'/'", "';'", "'='", "'if'", 
      "'else'", "'while'", "'do'", "'end'", "'<'", "'>'", "'<='", "'>='"
    },
    std::vector<std::string>{
      "", "", "", "PLUS", "MINUS", "MULTIPLY", "DEVIDE", "SEMICOLON", "EQUALS", 
      "IF", "ELSE", "WHILE", "DO", "END", "LESS", "GREATER", "LESS_EQ", 
      "GREATER_EQ", "NOT_EQ", "VARIABLE", "DOUBLE", "INTEGER", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,22,108,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,1,0,5,0,22,8,0,10,0,12,0,25,9,0,1,0,1,0,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,41,8,1,1,2,1,2,1,2,1,2,1,
  	3,1,3,1,3,1,3,1,3,1,3,5,3,53,8,3,10,3,12,3,56,9,3,1,3,1,3,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,3,4,68,8,4,1,4,1,4,1,5,5,5,73,8,5,10,5,12,5,76,9,
  	5,1,6,1,6,1,6,3,6,81,8,6,1,7,1,7,1,7,5,7,86,8,7,10,7,12,7,89,9,7,1,8,
  	1,8,1,8,5,8,94,8,8,10,8,12,8,97,9,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,106,
  	8,9,1,9,0,0,10,0,2,4,6,8,10,12,14,16,18,0,3,2,0,8,8,14,18,1,0,3,4,1,0,
  	5,6,110,0,23,1,0,0,0,2,40,1,0,0,0,4,42,1,0,0,0,6,46,1,0,0,0,8,59,1,0,
  	0,0,10,74,1,0,0,0,12,77,1,0,0,0,14,82,1,0,0,0,16,90,1,0,0,0,18,105,1,
  	0,0,0,20,22,3,2,1,0,21,20,1,0,0,0,22,25,1,0,0,0,23,21,1,0,0,0,23,24,1,
  	0,0,0,24,26,1,0,0,0,25,23,1,0,0,0,26,27,5,0,0,1,27,1,1,0,0,0,28,29,3,
  	4,2,0,29,30,5,7,0,0,30,41,1,0,0,0,31,32,3,6,3,0,32,33,5,7,0,0,33,41,1,
  	0,0,0,34,35,3,8,4,0,35,36,5,7,0,0,36,41,1,0,0,0,37,38,3,14,7,0,38,39,
  	5,7,0,0,39,41,1,0,0,0,40,28,1,0,0,0,40,31,1,0,0,0,40,34,1,0,0,0,40,37,
  	1,0,0,0,41,3,1,0,0,0,42,43,5,19,0,0,43,44,5,8,0,0,44,45,3,14,7,0,45,5,
  	1,0,0,0,46,47,5,11,0,0,47,48,5,1,0,0,48,49,3,12,6,0,49,50,5,2,0,0,50,
  	54,5,12,0,0,51,53,3,2,1,0,52,51,1,0,0,0,53,56,1,0,0,0,54,52,1,0,0,0,54,
  	55,1,0,0,0,55,57,1,0,0,0,56,54,1,0,0,0,57,58,5,13,0,0,58,7,1,0,0,0,59,
  	60,5,9,0,0,60,61,5,1,0,0,61,62,3,12,6,0,62,63,5,2,0,0,63,64,5,12,0,0,
  	64,67,3,10,5,0,65,66,5,10,0,0,66,68,3,10,5,0,67,65,1,0,0,0,67,68,1,0,
  	0,0,68,69,1,0,0,0,69,70,5,13,0,0,70,9,1,0,0,0,71,73,3,2,1,0,72,71,1,0,
  	0,0,73,76,1,0,0,0,74,72,1,0,0,0,74,75,1,0,0,0,75,11,1,0,0,0,76,74,1,0,
  	0,0,77,80,3,14,7,0,78,79,7,0,0,0,79,81,3,14,7,0,80,78,1,0,0,0,80,81,1,
  	0,0,0,81,13,1,0,0,0,82,87,3,16,8,0,83,84,7,1,0,0,84,86,3,16,8,0,85,83,
  	1,0,0,0,86,89,1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,0,88,15,1,0,0,0,89,87,
  	1,0,0,0,90,95,3,18,9,0,91,92,7,2,0,0,92,94,3,18,9,0,93,91,1,0,0,0,94,
  	97,1,0,0,0,95,93,1,0,0,0,95,96,1,0,0,0,96,17,1,0,0,0,97,95,1,0,0,0,98,
  	106,5,21,0,0,99,106,5,20,0,0,100,106,5,19,0,0,101,102,5,1,0,0,102,103,
  	3,14,7,0,103,104,5,2,0,0,104,106,1,0,0,0,105,98,1,0,0,0,105,99,1,0,0,
  	0,105,100,1,0,0,0,105,101,1,0,0,0,106,19,1,0,0,0,9,23,40,54,67,74,80,
  	87,95,105
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
    setState(23);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3672578) != 0)) {
      setState(20);
      statement();
      setState(25);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(26);
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

PascalParser::IfcondContext* PascalParser::StatementContext::ifcond() {
  return getRuleContext<PascalParser::IfcondContext>(0);
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
    setState(40);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(28);
      assignment();
      setState(29);
      match(PascalParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(31);
      whileLoop();
      setState(32);
      match(PascalParser::SEMICOLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(34);
      ifcond();
      setState(35);
      match(PascalParser::SEMICOLON);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(37);
      expression();
      setState(38);
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
    setState(42);
    match(PascalParser::VARIABLE);
    setState(43);
    match(PascalParser::EQUALS);
    setState(44);
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
    setState(46);
    match(PascalParser::WHILE);
    setState(47);
    match(PascalParser::T__0);
    setState(48);
    condition();
    setState(49);
    match(PascalParser::T__1);
    setState(50);
    match(PascalParser::DO);
    setState(54);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3672578) != 0)) {
      setState(51);
      statement();
      setState(56);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(57);
    match(PascalParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfcondContext ------------------------------------------------------------------

PascalParser::IfcondContext::IfcondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::IfcondContext::IF() {
  return getToken(PascalParser::IF, 0);
}

PascalParser::ConditionContext* PascalParser::IfcondContext::condition() {
  return getRuleContext<PascalParser::ConditionContext>(0);
}

tree::TerminalNode* PascalParser::IfcondContext::DO() {
  return getToken(PascalParser::DO, 0);
}

tree::TerminalNode* PascalParser::IfcondContext::END() {
  return getToken(PascalParser::END, 0);
}

std::vector<PascalParser::BlockContext *> PascalParser::IfcondContext::block() {
  return getRuleContexts<PascalParser::BlockContext>();
}

PascalParser::BlockContext* PascalParser::IfcondContext::block(size_t i) {
  return getRuleContext<PascalParser::BlockContext>(i);
}

tree::TerminalNode* PascalParser::IfcondContext::ELSE() {
  return getToken(PascalParser::ELSE, 0);
}


size_t PascalParser::IfcondContext::getRuleIndex() const {
  return PascalParser::RuleIfcond;
}


std::any PascalParser::IfcondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitIfcond(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::IfcondContext* PascalParser::ifcond() {
  IfcondContext *_localctx = _tracker.createInstance<IfcondContext>(_ctx, getState());
  enterRule(_localctx, 8, PascalParser::RuleIfcond);
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
    setState(59);
    match(PascalParser::IF);
    setState(60);
    match(PascalParser::T__0);
    setState(61);
    condition();
    setState(62);
    match(PascalParser::T__1);
    setState(63);
    match(PascalParser::DO);
    setState(64);
    antlrcpp::downCast<IfcondContext *>(_localctx)->thenBranch = block();
    setState(67);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::ELSE) {
      setState(65);
      match(PascalParser::ELSE);
      setState(66);
      antlrcpp::downCast<IfcondContext *>(_localctx)->elseBranch = block();
    }
    setState(69);
    match(PascalParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

PascalParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::StatementContext *> PascalParser::BlockContext::statement() {
  return getRuleContexts<PascalParser::StatementContext>();
}

PascalParser::StatementContext* PascalParser::BlockContext::statement(size_t i) {
  return getRuleContext<PascalParser::StatementContext>(i);
}


size_t PascalParser::BlockContext::getRuleIndex() const {
  return PascalParser::RuleBlock;
}


std::any PascalParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::BlockContext* PascalParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 10, PascalParser::RuleBlock);
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
    setState(74);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3672578) != 0)) {
      setState(71);
      statement();
      setState(76);
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
  enterRule(_localctx, 12, PascalParser::RuleCondition);
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
    setState(77);
    expression();
    setState(80);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 508160) != 0)) {
      setState(78);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 508160) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(79);
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
  enterRule(_localctx, 14, PascalParser::RuleExpression);
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
    setState(82);
    term();
    setState(87);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::PLUS

    || _la == PascalParser::MINUS) {
      setState(83);
      _la = _input->LA(1);
      if (!(_la == PascalParser::PLUS

      || _la == PascalParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(84);
      term();
      setState(89);
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
  enterRule(_localctx, 16, PascalParser::RuleTerm);
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
    setState(90);
    factor();
    setState(95);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::MULTIPLY

    || _la == PascalParser::DEVIDE) {
      setState(91);
      _la = _input->LA(1);
      if (!(_la == PascalParser::MULTIPLY

      || _la == PascalParser::DEVIDE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(92);
      factor();
      setState(97);
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
  enterRule(_localctx, 18, PascalParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(105);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(98);
        match(PascalParser::INTEGER);
        break;
      }

      case PascalParser::DOUBLE: {
        enterOuterAlt(_localctx, 2);
        setState(99);
        match(PascalParser::DOUBLE);
        break;
      }

      case PascalParser::VARIABLE: {
        enterOuterAlt(_localctx, 3);
        setState(100);
        match(PascalParser::VARIABLE);
        break;
      }

      case PascalParser::T__0: {
        enterOuterAlt(_localctx, 4);
        setState(101);
        match(PascalParser::T__0);
        setState(102);
        expression();
        setState(103);
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

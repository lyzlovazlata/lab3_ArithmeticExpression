
// Generated from Pascal.g4 by ANTLR 4.13.2


#include "PascalLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct PascalLexerStaticData final {
  PascalLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PascalLexerStaticData(const PascalLexerStaticData&) = delete;
  PascalLexerStaticData(PascalLexerStaticData&&) = delete;
  PascalLexerStaticData& operator=(const PascalLexerStaticData&) = delete;
  PascalLexerStaticData& operator=(PascalLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag pascallexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<PascalLexerStaticData> pascallexerLexerStaticData = nullptr;

void pascallexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (pascallexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(pascallexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<PascalLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "PLUS", "MINUS", "MULTIPLY", "DEVIDE", "SEMICOLON", 
      "EQUALS", "WHILE", "DO", "END", "LESS", "GREATER", "LESS_EQ", "GREATER_EQ", 
      "NOT_EQ", "VARIABLE", "DOUBLE", "INTEGER", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,20,116,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,1,0,1,0,1,1,1,
  	1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,8,1,8,1,8,
  	1,8,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,13,
  	1,14,1,14,1,14,1,15,1,15,1,15,1,15,3,15,85,8,15,1,16,1,16,5,16,89,8,16,
  	10,16,12,16,92,9,16,1,17,4,17,95,8,17,11,17,12,17,96,1,17,1,17,4,17,101,
  	8,17,11,17,12,17,102,1,18,4,18,106,8,18,11,18,12,18,107,1,19,4,19,111,
  	8,19,11,19,12,19,112,1,19,1,19,0,0,20,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,
  	8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,
  	20,1,0,4,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,1,0,48,57,
  	3,0,9,10,13,13,32,32,121,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,
  	0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,
  	19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,
  	0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,
  	0,1,41,1,0,0,0,3,43,1,0,0,0,5,45,1,0,0,0,7,47,1,0,0,0,9,49,1,0,0,0,11,
  	51,1,0,0,0,13,53,1,0,0,0,15,55,1,0,0,0,17,57,1,0,0,0,19,63,1,0,0,0,21,
  	66,1,0,0,0,23,70,1,0,0,0,25,72,1,0,0,0,27,74,1,0,0,0,29,77,1,0,0,0,31,
  	84,1,0,0,0,33,86,1,0,0,0,35,94,1,0,0,0,37,105,1,0,0,0,39,110,1,0,0,0,
  	41,42,5,40,0,0,42,2,1,0,0,0,43,44,5,41,0,0,44,4,1,0,0,0,45,46,5,43,0,
  	0,46,6,1,0,0,0,47,48,5,45,0,0,48,8,1,0,0,0,49,50,5,42,0,0,50,10,1,0,0,
  	0,51,52,5,47,0,0,52,12,1,0,0,0,53,54,5,59,0,0,54,14,1,0,0,0,55,56,5,61,
  	0,0,56,16,1,0,0,0,57,58,5,119,0,0,58,59,5,104,0,0,59,60,5,105,0,0,60,
  	61,5,108,0,0,61,62,5,101,0,0,62,18,1,0,0,0,63,64,5,100,0,0,64,65,5,111,
  	0,0,65,20,1,0,0,0,66,67,5,101,0,0,67,68,5,110,0,0,68,69,5,100,0,0,69,
  	22,1,0,0,0,70,71,5,60,0,0,71,24,1,0,0,0,72,73,5,62,0,0,73,26,1,0,0,0,
  	74,75,5,60,0,0,75,76,5,61,0,0,76,28,1,0,0,0,77,78,5,62,0,0,78,79,5,61,
  	0,0,79,30,1,0,0,0,80,81,5,33,0,0,81,85,5,61,0,0,82,83,5,60,0,0,83,85,
  	5,62,0,0,84,80,1,0,0,0,84,82,1,0,0,0,85,32,1,0,0,0,86,90,7,0,0,0,87,89,
  	7,1,0,0,88,87,1,0,0,0,89,92,1,0,0,0,90,88,1,0,0,0,90,91,1,0,0,0,91,34,
  	1,0,0,0,92,90,1,0,0,0,93,95,7,2,0,0,94,93,1,0,0,0,95,96,1,0,0,0,96,94,
  	1,0,0,0,96,97,1,0,0,0,97,98,1,0,0,0,98,100,5,46,0,0,99,101,7,2,0,0,100,
  	99,1,0,0,0,101,102,1,0,0,0,102,100,1,0,0,0,102,103,1,0,0,0,103,36,1,0,
  	0,0,104,106,7,2,0,0,105,104,1,0,0,0,106,107,1,0,0,0,107,105,1,0,0,0,107,
  	108,1,0,0,0,108,38,1,0,0,0,109,111,7,3,0,0,110,109,1,0,0,0,111,112,1,
  	0,0,0,112,110,1,0,0,0,112,113,1,0,0,0,113,114,1,0,0,0,114,115,6,19,0,
  	0,115,40,1,0,0,0,7,0,84,90,96,102,107,112,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  pascallexerLexerStaticData = std::move(staticData);
}

}

PascalLexer::PascalLexer(CharStream *input) : Lexer(input) {
  PascalLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *pascallexerLexerStaticData->atn, pascallexerLexerStaticData->decisionToDFA, pascallexerLexerStaticData->sharedContextCache);
}

PascalLexer::~PascalLexer() {
  delete _interpreter;
}

std::string PascalLexer::getGrammarFileName() const {
  return "Pascal.g4";
}

const std::vector<std::string>& PascalLexer::getRuleNames() const {
  return pascallexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& PascalLexer::getChannelNames() const {
  return pascallexerLexerStaticData->channelNames;
}

const std::vector<std::string>& PascalLexer::getModeNames() const {
  return pascallexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& PascalLexer::getVocabulary() const {
  return pascallexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PascalLexer::getSerializedATN() const {
  return pascallexerLexerStaticData->serializedATN;
}

const atn::ATN& PascalLexer::getATN() const {
  return *pascallexerLexerStaticData->atn;
}




void PascalLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  pascallexerLexerInitialize();
#else
  ::antlr4::internal::call_once(pascallexerLexerOnceFlag, pascallexerLexerInitialize);
#endif
}

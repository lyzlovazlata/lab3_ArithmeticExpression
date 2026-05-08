
// Generated from Pascal.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  PascalLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, PLUS = 3, MINUS = 4, MULTIPLY = 5, DEVIDE = 6, SEMICOLON = 7, 
    EQUALS = 8, IF = 9, ELSE = 10, WHILE = 11, DO = 12, END = 13, LESS = 14, 
    GREATER = 15, LESS_EQ = 16, GREATER_EQ = 17, NOT_EQ = 18, VARIABLE = 19, 
    DOUBLE = 20, INTEGER = 21, WS = 22
  };

  explicit PascalLexer(antlr4::CharStream *input);

  ~PascalLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};


#pragma once
#include <string>
#include "IMap.h"
#include "antlr4-runtime.h"
#include "PascalLexer.h"
#include "PascalParser.h"
#include"ProgVisitor.h"
#include<iostream>
using namespace std;


class ThrowingErrorListener : public antlr4::BaseErrorListener {
public:
	void syntaxError(antlr4::Recognizer* recognizer,
		antlr4::Token* offendingSymbol,
		size_t line,
		size_t charPositionInLine,
		const std::string& msg,
		std::exception_ptr e) override;
};

class PascalProgramm {
	
	IMap<string, double>* variableStorage;
	string prog;

	void parseInput(string prog);

public:
	PascalProgramm(IMap<string, double>* memory, string _prog);
};
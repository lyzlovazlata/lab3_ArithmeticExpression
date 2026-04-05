#pragma once
#include <string>
#include "IMap.h"
#include "antlr4-runtime.h"
#include "PascalLexer.h"
#include "PascalParser.h"
#include"ProgVisiotr.h"
#include<iostream>
using namespace std;


class ThrowingErrorListener : public antlr4::BaseErrorListener {
public:
	void syntaxError(antlr4::Recognizer* recognizer,
		antlr4::Token* offendingSymbol,
		size_t line,
		size_t charPositionInLine,
		const std::string& msg,
		std::exception_ptr e) override
	{
		throw std::runtime_error(
			"Syntax error at line " + std::to_string(line) +
			":" + std::to_string(charPositionInLine) +
			" -> " + msg
		);
	}
};

class PascalProgramm {
	IMap<string, double>* variableStorage;
	string prog;

	void parseInput(string prog)
	{
		antlr4::ANTLRInputStream input(prog);
		PascalLexer lexer(&input);
		antlr4::CommonTokenStream tokens(&lexer);
		PascalParser parser(&tokens);

		//Убираем дефолтные ошибки
		parser.removeErrorListeners();
		lexer.removeErrorListeners();

		//Добавляем свои
		auto errorListener = new ThrowingErrorListener();
		parser.addErrorListener(errorListener);
		lexer.addErrorListener(errorListener);

		try {
			auto tree = parser.program();

			ProgVisitor visitor(variableStorage);
			visitor.visit(tree);
		}
		catch (const std::runtime_error& e) {
			// можешь пробросить дальше или обработать
			cout << e.what();
		}
	}

public:
	PascalProgramm(IMap<string, double>* memory, string _prog) : prog(_prog), variableStorage(memory) {
		parseInput(prog);
	}

};
#pragma once
#include "Pascal.h"
using namespace std;


	void ThrowingErrorListener:: syntaxError(antlr4::Recognizer* recognizer,
		antlr4::Token* offendingSymbol,
		size_t line,
		size_t charPositionInLine,
		const std::string& msg,
		std::exception_ptr e)
	{
		throw std::runtime_error(
			"Synt err there " + std::to_string(line) +
			":" + std::to_string(charPositionInLine) +
			" - " + msg
		);
	}


	void PascalProgramm:: parseInput(string prog)
	{
		antlr4::ANTLRInputStream input(prog);
		PascalLexer lexer(&input);
		antlr4::CommonTokenStream tokens(&lexer);
		PascalParser parser(&tokens);

		parser.removeErrorListeners();
		lexer.removeErrorListeners();

		auto errorListener = new ThrowingErrorListener();
		parser.addErrorListener(errorListener);
		lexer.addErrorListener(errorListener);

		try {
			auto tree = parser.program();

			ProgVisitor visitor(variableStorage);
			visitor.visit(tree);
		}
		catch (const std::runtime_error& e) {
			cout << e.what();
		}
	}

	PascalProgramm:: PascalProgramm(IMap<string, double>* memory, string _prog) : prog(_prog), variableStorage(memory) {
		parseInput(prog);
	}

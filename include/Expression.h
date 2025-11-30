#pragma once
#include <string>
#include "LexAutomat.h"
#include"SyntAutomat.h"
#include"TQueue.h"
#include"Word.h"
using namespace std;

class Expression {

	string in;
	TQueue<Word> infix;
	TQueue<Word> postfix;
	int res;

public:
	Expression(string _in);
	Expression(const Expression& expr);
	Expression& operator=(const Expression& expr);
	void run();

	TQueue<Word> getInfix();
	TQueue<Word> getPostfix();
	int getRes();
};
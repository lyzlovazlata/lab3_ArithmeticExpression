#pragma once
#include <string>
#include "LexAutomat.h"
#include"SyntAutomat.h"
#include"TQueue.h"
#include"Word.h"
#include"TreeExpression.h"
#include<iostream>
using namespace std;


class Expression {

	string in;
	TQueue<Word> infix;
	Expr* treeRoot;
	int res;
public:
	Expression(string _in);
	Expression(const Expression& expr);
	Expression& operator=(const Expression& expr);
	void run();

	TQueue<Word> getInfix();
	int getRes();
	friend ostream& operator<<(ostream& ostr, Expression& exp);
};

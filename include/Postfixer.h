#pragma once
#include"TQueue.h"
#include"TStack.h"
#include"Word.h"
#include<map>
#include"TreeExpression.h"
#include"SyntAutomat.h"
#include "Expression.h"
using namespace std;

class Postfixer {
public:
	TQueue<Word> in;
	
	map<char, int> priority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 0} };

	TStack<Word> st;
	Word stackItem;
	Word inItem;

	TStack<Expr*> tree;
	Expr* root;

	Postfixer();

	Postfixer(const TQueue<Word> _in);


	//postfix functions
	void operatorWork(Word inItem);

	void pos(Word word);

	void run();

	Expr* getRoot();


};
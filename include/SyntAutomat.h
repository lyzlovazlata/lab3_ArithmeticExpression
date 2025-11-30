#pragma once
#include"TQueue.h"
#include"TStack.h"
#include"Word.h"
#include<map>
using namespace std;

/*
* Синтаксический автомат. В нем очень много: проверка скобок, проверка синтаксиса (унарность, колво операндов) а так же создание постфикса
* Вроде как это и получилось что-то типа восходящего разбора или как его там?
*/

class SyntAutomat {

	using SFunction = void (SyntAutomat::*)(Word);
	// На вход идет очередь - из лексического автомата, на выход - очередь результативная
	TQueue<Word> in;
	TQueue<int> errs;
	int err_ind;

	int state;
	SFunction** call;
	int** next;

	TStack<int> parOpen;
	TStack<int> parClose;

	// Штуки для постфикса - приоритеты, стек и т.д.
	map<char, int> priority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 0} };
	TQueue<Word> postfix;
	TStack<Word> st;
	bool canPostfix;
	Word stackItem;
	Word inItem;

	//postfix functions

	void operatorWork(Word inItem);


	//  # TRANSITION FUNCTION #

	int nextState(Word c);
	//  ######################

//	 # SYNTAXIS FUNCTIONS #

	void f0Push(Word word);

	void f1OpErr(Word word);
	
	void f2OpenParErr(Word word); 
	
	void f3CloseParErr(Word word);
	
	void f4ValErr(Word word);
	void f5OpUnar(Word word);

	void f6FakeFunc(Word word);

	//  #####################
public:

	SyntAutomat();
	~SyntAutomat();

	SyntAutomat(const TQueue<Word> _in);
	SyntAutomat(const SyntAutomat& _sa);

	SyntAutomat& operator=(const SyntAutomat _sa);


	void run();

	TQueue<Word> getInfix();

	TQueue<Word> getPostfix();

	TQueue<int> getErrors();
};
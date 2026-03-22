#pragma once
#include "Word.h"
#include "TQueue.h"

/*
 ласс лексического автомата. ≈го цель - проверить алфавит, то есть нет ли сторонних символов и что важно - преобразовать строчку в правильную очередь
¬ него подаем строчку (то есть этот автомат будет первой проверкой), получаем очередь, индексы ошибок
*/
class LexAutomat {

	using LFunction = void (LexAutomat::*)(char c); // ќдин из вариантов задани€ указател€ на функицю (мне не хотелось делать это страктом....)

	// пол€ дл€ логики и результата
	string infix;
	TQueue<Word> res;
	TQueue<int> errs;

	// ѕол€ дл€ работы автомата
	int state;
	LFunction** call;
	int** next;

	// Ќу, такое, полувспомагательное поле (дл€ набирани€ числа)
	Word value;

//  # TRANSITION FUNCTION #

	int nextState(char c);

//  ######################

//	 # LEXICAL FUNCTIONS #

	void f0IncValue(char c);

	void f1PushValueAndOp(char c);

	void f2PushOp(char c);

//  #####################
public:

	LexAutomat();

	LexAutomat(const string& inf);

	~LexAutomat();

	TQueue<Word> getLexRes();

	void run();

	TQueue<int> getErrors();

	LexAutomat(const LexAutomat& l);

	LexAutomat& operator=(const LexAutomat& l);
};

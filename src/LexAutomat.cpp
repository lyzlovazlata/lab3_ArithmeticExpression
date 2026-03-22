#include"LexAutomat.h"
#include <stdexcept>

//  # TRANSITION FUNCTION #

int LexAutomat::nextState(char c)
{
	if ((c == '(') || (c == ')') || (c == '-') || (c == '+') || (c == '/') || (c == '*'))
	{
		return 1;
	}
	else if ((c == '0') || (c == '1') || (c == '2') || (c == '3') || (c == '4') || (c == '5') || (c == '6') || (c == '7') || (c == '8') || (c == '9'))
	{
		return 0;
	}
	else
	{
		throw invalid_argument("LEX: You can't put anything else but numbers, parentheses or base operations!");
	}
}

//  ######################

//	 # LEXICAL FUNCTIONS #

// ‘ункци€ котора€ будет набирать чиселку дл€ правильного добавлени€ в очередь
void LexAutomat::f0IncValue(char c) {
	int tmp = c - '0'; // эта штука нужна чтобы правильно считалс€ код числа (циферки нумеруютс€ с нул€ типа)
	value.getValue() = value.getValue() * 10 + tmp;
	value.getLen()++;
}

// ѕри встрече с оператором мы пушим набранное значение и пушим оператор
void LexAutomat::f1PushValueAndOp(char c) {
	if (value.getLen() != 0)
	{
		res.push(value);
		value.getValue() = 0;
		value.getLen() = 0;
	}
	Word tmp = Word(c);
	res.push(tmp);
}

// закидон оператора ( по сути нужна только если р€дом два оператора)
void LexAutomat::f2PushOp(char c) {
	Word tmp = Word(c);
	res.push(tmp);
}

//  #####################
LexAutomat::LexAutomat() {
	state = 0;
	next = new int* [2];
	call = new LFunction * [2];
	for (size_t i = 0; i < 2; i++)
	{
		next[i] = new int[2];
		call[i] = new LFunction[2];
	}

	next[0][0] = 0;
	next[0][1] = 1;
	next[1][0] = 0;
	next[1][1] = 1;

	call[0][0] = &LexAutomat::f0IncValue;
	call[0][1] = &LexAutomat::f1PushValueAndOp;
	call[1][0] = &LexAutomat::f0IncValue;
	call[1][1] = &LexAutomat::f2PushOp;
};

LexAutomat::LexAutomat(const string& inf)
{
	infix = inf;
	errs = TQueue<int>(infix.size());
	state = 0;
	res = TQueue<Word>(infix.size()); // Ёто больше чем нужно но вроде не так уж и критично, в конце концов € хз как динамически очередь расшир€ть


	next = new int* [2];
	call = new LFunction * [2];
	for (size_t i = 0; i < 2; i++)
	{
		next[i] = new int[2];
		call[i] = new LFunction[2];
	}

	next[0][0] = 0;
	next[0][1] = 1;
	next[1][0] = 0;
	next[1][1] = 1;

	call[0][0] = &LexAutomat::f0IncValue;
	call[0][1] = &LexAutomat::f1PushValueAndOp;
	call[1][0] = &LexAutomat::f0IncValue;
	call[1][1] = &LexAutomat::f2PushOp;
}

LexAutomat::~LexAutomat() {
	for (size_t i = 0; i < 2; i++)
	{
		delete[] next[i];
		delete[] call[i];
	}
	delete[] next;
	delete[] call;
}

TQueue<Word> LexAutomat::getLexRes()
{
	return res;
}

// –ан, самый сок.  ¬ нем мы как раз ходим по состо€ни€м, но есть но
void LexAutomat::run()
{
	int i = 0;
	while (i < infix.size() - 1)
	{
		try
		{
			(this->*call[state][nextState(infix[i])])(infix[i]);

			state = next[state][nextState(infix[i])];

		}
		catch (...)
		{
			errs.push(i);
		}
		i++;
	}

	Word tmp;
// »з-за особенностеей моих функций автомата приходитс€ отдельно рассматривать последний символ, а то вдруг это число и надо допушить
	try
	{
		tmp = Word(infix[i]);
	}
	catch (...)
	{
		errs.push(i);
		throw - 1;
	}

	if (tmp.isNum() == true)
	{
		try
		{
			this->f0IncValue(infix[i]);
			res.push(value);
		}
		catch (...)
		{
			errs.push(i);
		}
	}
	else
	{
		try
		{
			this->f1PushValueAndOp(infix[i]);
		}
		catch (...)
		{
			errs.push(i);
		}
	}


	if (!errs.isEmpty())
		throw - 1;
}

TQueue<int> LexAutomat::getErrors()
{
	return errs;
}

LexAutomat::LexAutomat(const LexAutomat& l) {
	errs = l.errs;
	state = l.state;
	infix = l.infix;
	res = l.res;
	next = new int* [2];
	call = new LFunction * [2];
	value = l.value;
	for (size_t i = 0; i < 2; i++)
	{
		next[i] = new int[2];
		call[i] = new LFunction[2];
		for (size_t j = 0; j < 2; j++)
		{
			next[i][j] = l.next[i][j];
			call[i][j] = l.call[i][j];
		}
	}
}

LexAutomat& LexAutomat::operator=(const LexAutomat& l) {
	if (this == &l) return *this;
	for (size_t i = 0; i < 2; i++)
	{
		delete[] next[i];
		delete[] call[i];
	}
	delete[] next;
	delete[] call;

	errs = l.errs;
	state = l.state;
	infix = l.infix;
	res = l.res;
	next = new int* [2];
	call = new LFunction * [2];
	value = l.value;
	for (size_t i = 0; i < 2; i++)
	{
		next[i] = new int[2];
		call[i] = new LFunction[2];
	}

	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			next[i][j] = l.next[i][j];
			call[i][j] = l.call[i][j];
		}
	}
	return *this;
}

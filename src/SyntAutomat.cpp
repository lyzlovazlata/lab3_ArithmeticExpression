#include"SyntAutomat.h"

// Функция которая работает с постфиксными операторами (вытаскивет то шо надо как надо)
void SyntAutomat::operatorWork(Word inItem)
{
	if (canPostfix)
	{
		while (!st.isEmpty())
		{
			stackItem = st.pop();
			if (!inItem.isBin())
			{
				// Очень некрасивая штука но это создание нуля
				// Да, такое сложное, потому что от нуля просто нормально ниче не работало, приходится вручную вот так все создавать
				Word zeroHelper;
				zeroHelper.getLen() = 1;
				zeroHelper.isNum() = true;
				zeroHelper.isBin() = false;
				zeroHelper.getValue() = 0;
				postfix.push(zeroHelper);
			}
			if (priority[char(inItem.getValue())] <= priority[char(stackItem.getValue())])
				postfix.push(stackItem);
			else
			{
				st.push(stackItem);
				break;
			}
		}
		// это если унар в начале
		if (!inItem.isBin() && st.isEmpty())
		{
			Word zeroHelper;
			zeroHelper.getLen() = 1;
			zeroHelper.isNum() = true;
			zeroHelper.isBin() = false;
			zeroHelper.getValue() = 0;
			postfix.push(zeroHelper);
		}

		st.push(inItem);
	}
}


//  # TRANSITION FUNCTION #

// Четыре состояния на числа, скобки и остальное
int SyntAutomat::nextState(Word c)
{
	if (c.isNum())
	{
		return 1;
	}
	else if ((char)c.getValue() == '(')
	{
		return 0;
	}
	else if ((char)c.getValue() == ')')
	{
		return 2;
	}
	else
	{
		return 3;
	}
}
//  ######################

//	 # SYNTAXIS FUNCTIONS #

// Это одна большая и самая встречающаяся функция - просто пуш того, что попалось. Она в моменты когда нет никаких проблем
void SyntAutomat::f0Push(Word word)
{
	inItem = word;
	if (word.isNum())
	{
		err_ind += word.getLen();
		if (canPostfix)
		{
			postfix.push(inItem);
		}
	}
	else if (char(word.getValue()) == '(')
	{
		parOpen.push(err_ind);
		err_ind++;
		if (canPostfix)
		{
			st.push(inItem);

		}
	}
	else if (char(word.getValue()) == ')')
	{
		try {
			parOpen.pop();
		}
		catch (...)
		{
			parClose.push(err_ind);
		}
		err_ind++;
		if (canPostfix && parClose.isEmpty())
		{
			stackItem = st.pop();
			while (char(stackItem.getValue()) != '(')
			{
				postfix.push(stackItem);
				stackItem = st.pop();
			}
		}
	}
	else //то есть оператор
	{
		err_ind++;
		operatorWork(inItem);
	}
}

// Встретили плохой оператор (сразу пушим ошибку, а значит отрубаем постфикс)
void SyntAutomat::f1OpErr(Word word)
{
	errs.push(err_ind);
	err_ind++;
	if (canPostfix)
		canPostfix = false;
}
void SyntAutomat::f2OpenParErr(Word word)// плохая открытая скобка
{
	parOpen.push(err_ind);
	errs.push(err_ind);
	err_ind++;
	if (canPostfix)
		canPostfix = false;
	return;
}
void SyntAutomat::f3CloseParErr(Word word)// плохая закрытая скобка
{
	try
	{
		parOpen.pop();
	}
	catch (...)
	{
		parClose.push(err_ind);
	}
	errs.push(err_ind);
	err_ind++;
	if (canPostfix)
		canPostfix = false;
}
void SyntAutomat::f4ValErr(Word word)// число там где не надо
{
	errs.push(err_ind);
	err_ind += word.getLen();
	if (canPostfix)
		canPostfix = false;
}
void SyntAutomat::f5OpUnar(Word word)// проверка может ли быть унарным оператор
{
	if (char(word.getValue()) == '+' || char(word.getValue()) == '-')
	{
		word.isBin() = false;
		err_ind++;

		operatorWork(word);

	}
	else
		f1OpErr(word);
}

void SyntAutomat::f6FakeFunc(Word word) // Заглушка для случая например когда у нас из числа в число (такого быть не может, но надо сделать функцию)
{
	return;
}

//  #####################

SyntAutomat::SyntAutomat()
{
	err_ind = 0;
	canPostfix = true;
	state = 0;
	call = new SFunction * [4];
	next = new int* [4];
	for (size_t i = 0; i < 4; i++)
	{
		call[i] = new SFunction[4];
		next[i] = new int[4];
	}

	next[0][0] = 0;
	next[0][1] = 1;
	next[0][2] = 2;
	next[0][3] = 3;

	next[1][0] = 0;
	next[1][1] = 1;
	next[1][2] = 2;
	next[1][3] = 3;

	next[2][0] = 0;
	next[2][1] = 1;
	next[2][2] = 2;
	next[2][3] = 3;

	next[3][0] = 0;
	next[3][1] = 1;
	next[3][2] = 2;
	next[3][3] = 3;

	call[0][0] = &SyntAutomat::f0Push;
	call[0][1] = &SyntAutomat::f0Push;
	call[0][2] = &SyntAutomat::f3CloseParErr;
	call[0][3] = &SyntAutomat::f5OpUnar;

	call[1][0] = &SyntAutomat::f2OpenParErr;
	call[1][1] = &SyntAutomat::f6FakeFunc;
	call[1][2] = &SyntAutomat::f0Push;
	call[1][3] = &SyntAutomat::f0Push;

	call[2][0] = &SyntAutomat::f2OpenParErr;
	call[2][1] = &SyntAutomat::f4ValErr;
	call[2][2] = &SyntAutomat::f0Push;
	call[2][3] = &SyntAutomat::f0Push;

	call[3][0] = &SyntAutomat::f0Push;
	call[3][1] = &SyntAutomat::f0Push;
	call[3][2] = &SyntAutomat::f3CloseParErr;
	call[3][3] = &SyntAutomat::f1OpErr;
};
SyntAutomat::~SyntAutomat()
{
	for (size_t i = 0; i < 4; i++)
	{
		delete[] call[i];
		delete[] next[i];
	}
	delete[] call;
	delete[] next;
}

SyntAutomat::SyntAutomat(const TQueue<Word> _in) {
	in = _in;
	errs = TQueue<int>(in.getSZ());
	state = 0;
	parOpen = TStack<int>(in.getSZ());
	parClose = TStack<int>(in.getSZ());
	err_ind = 0;
	map<char, int> priority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 0} };
	postfix = TQueue<Word>(in.getSZ());
	st = TStack<Word>(in.getSZ());
	canPostfix = true;
	Word stackItem;

	call = new SFunction * [4];
	next = new int* [4];
	for (size_t i = 0; i < 4; i++)
	{
		call[i] = new SFunction[4];
		next[i] = new int[4];
	}

	next[0][0] = 0;
	next[0][1] = 1;
	next[0][2] = 2;
	next[0][3] = 3;

	next[1][0] = 0;
	next[1][1] = 1;
	next[1][2] = 2;
	next[1][3] = 3;

	next[2][0] = 0;
	next[2][1] = 1;
	next[2][2] = 2;
	next[2][3] = 3;

	next[3][0] = 0;
	next[3][1] = 1;
	next[3][2] = 2;
	next[3][3] = 3;

	call[0][0] = &SyntAutomat::f0Push;
	call[0][1] = &SyntAutomat::f0Push;
	call[0][2] = &SyntAutomat::f3CloseParErr;
	call[0][3] = &SyntAutomat::f5OpUnar;

	call[1][0] = &SyntAutomat::f2OpenParErr;
	call[1][1] = &SyntAutomat::f6FakeFunc;
	call[1][2] = &SyntAutomat::f0Push;
	call[1][3] = &SyntAutomat::f0Push;

	call[2][0] = &SyntAutomat::f2OpenParErr;
	call[2][1] = &SyntAutomat::f4ValErr;
	call[2][2] = &SyntAutomat::f0Push;
	call[2][3] = &SyntAutomat::f0Push;

	call[3][0] = &SyntAutomat::f0Push;
	call[3][1] = &SyntAutomat::f0Push;
	call[3][2] = &SyntAutomat::f3CloseParErr;
	call[3][3] = &SyntAutomat::f1OpErr;
};
SyntAutomat::SyntAutomat(const SyntAutomat& _sa)
{
	in = _sa.in;
	errs = _sa.errs;
	state = _sa.state;
	call = new SFunction * [4];
	next = new int* [4];
	for (size_t i = 0; i < 4; i++)
	{
		call[i] = new SFunction[4];
		next[i] = new int[4];
		for (size_t j = 0; j < 4; j++)
		{
			call[i][j] = _sa.call[i][j];
			next[i][j] = _sa.next[i][j];
		}
	}
	parOpen = _sa.parOpen;
	parClose = _sa.parClose;

	err_ind = _sa.err_ind;
	priority = _sa.priority;
	postfix = _sa.postfix;

	st = _sa.st;
	canPostfix = _sa.canPostfix;
	stackItem = _sa.stackItem;
	inItem = _sa.inItem;
}

SyntAutomat& SyntAutomat::operator=(const SyntAutomat _sa)
{
	if (this == &_sa)return*this;
	in = _sa.in;
	errs = _sa.errs;
	state = _sa.state;
	for (size_t i = 0; i < 4; i++)
	{
		delete[] call[i];
		delete[] next[i];
	}
	delete[] call;
	delete[] next;

	call = new SFunction * [4];
	next = new int* [4];
	for (size_t i = 0; i < 4; i++)
	{
		call[i] = new SFunction[4];
		next[i] = new int[4];
		for (size_t j = 0; j < 4; j++)
		{
			call[i][j] = _sa.call[i][j];
			next[i][j] = _sa.next[i][j];
		}
	}
	parOpen = _sa.parOpen;
	parClose = _sa.parClose;

	err_ind = _sa.err_ind;
	priority = _sa.priority;
	postfix = _sa.postfix;

	st = _sa.st;
	canPostfix = _sa.canPostfix;
	stackItem = _sa.stackItem;
	inItem = _sa.inItem;

	return *this;
}


void SyntAutomat::run()
{
	while (!in.isEmpty())
	{
		Word w = in.pop();
		(this->*call[state][nextState(w)])(w);
		state = next[state][nextState(w)];
	}
	// отдельно надо проверить скобки
	while (!parOpen.isEmpty())
	{
		errs.push(parOpen.pop());
		if (canPostfix)
			canPostfix = false;
	}

	while (!parClose.isEmpty())
	{
		errs.push(parClose.pop());
		if (canPostfix)
			canPostfix = false;
	}

	//У нас есть последнее состояние и логично если там скобка открыта или операторы - то что-то не так
	if (state == 3 || state == 0)
	{
		errs.push(--err_ind);
		if (canPostfix)
			canPostfix = false;
	}

	if (!errs.isEmpty())
	{

		throw - 2;
		if (canPostfix)
			canPostfix = false;
	}

	//postfix 
	while (!st.isEmpty())
	{
		stackItem = st.pop();
		postfix.push(stackItem);
	}
}

TQueue<Word> SyntAutomat::getInfix()
{
	return in;
}

TQueue<Word> SyntAutomat::getPostfix()
{
	return postfix;
}

TQueue<int> SyntAutomat::getErrors()
{
	return errs;
}
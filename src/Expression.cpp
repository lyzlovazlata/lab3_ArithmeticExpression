#include"Expression.h"


Expression::Expression(string _in) : in(_in), res(0) {}
Expression::Expression(const Expression& expr)
{
	in = expr.in;
	infix = expr.infix;
	postfix = expr.postfix;
	res = expr.res;
}
Expression& Expression::operator=(const Expression& expr)
{
	if (this == &expr) return *this;
	in = expr.in;
	infix = expr.infix;
	postfix = expr.postfix;
	res = expr.res;
	return*this;
}
void Expression::run()
{
	LexAutomat la(in);
	try
	{
		la.run();
	}
	catch (...)
	{
		cout << "Lex Errors" << endl;
		cout << la.getErrors() << endl;
		throw "Lex Er";
	}

	SyntAutomat sa(la.getLexRes());
	try
	{
		sa.run();
	}
	catch (...)
	{
		cout << "Synt Errors" << endl;
		cout << sa.getErrors() << endl;
		throw "Lex Er";
	}

	// прошли лекс и синт автомат -начинаем считать
	infix = sa.getInfix();
	postfix = sa.getPostfix();

	TQueue<Word>_postfix(postfix);
	TStack<int> stack(_postfix.getSZ());

	// ну дальше стандартный постфиксный счет
	while (!_postfix.isEmpty())
	{
		Word inItem = _postfix.pop();
		if (inItem.isNum())
			stack.push(inItem.getValue());
		else
		{
			char c = char(inItem.getValue());
			int a = stack.pop();
			int b = stack.pop();
			switch (c)
			{			
			case'-':
				stack.push(b - a);
				break;
			case'+':
				stack.push(b + a);
				break;

			case'*':
				stack.push(b * a);
				break;
			case'/':
				if (a != 0)
					stack.push(b / a);
				else throw "Don't divide by zero!";
				break;
			}
		}
	}

	res = stack.pop(); // в конце концов останется результат
}

TQueue<Word> Expression::getInfix()
{
	return infix;
}
TQueue<Word> Expression::getPostfix()
{
	return postfix;
}
int Expression::getRes()
{
	return res;
}
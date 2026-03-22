#include"Expression.h"
#include "Postfixer.h"

Expression::Expression(string _in) : in(_in), res(0), treeRoot(nullptr) {}
Expression::Expression(const Expression& expr)
{
	in = expr.in;
	infix = expr.infix;
	res = expr.res;
	treeRoot = nullptr;
}
Expression& Expression::operator=(const Expression& expr)
{
	if (this == &expr) return *this;
	in = expr.in;
	infix = expr.infix;
	res = expr.res;
	return*this;
}

void Expression::run()
{
	if (in.empty())
		throw invalid_argument("Empty expression");
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
		throw "Synt Er";
	}

	Postfixer post(sa.getOut()); 
	try
	{
		post.run();
	}
	catch (...)
	{
		cout << "Post errors" << endl;
		cout << sa.getErrors() << endl;
		throw "Post Er";
	}
	treeRoot = post.getRoot();
	CalcVisitor calculator;
	res = treeRoot->accept(&calculator);

}

TQueue<Word> Expression::getInfix()
{
	return infix;
}
int Expression::getRes()
{
	return res;
}

ostream& operator<<(ostream& ostr, Expression& exp)
{
	if (!exp.treeRoot) return ostr;
	PrintVisitor print;
	exp.treeRoot->accept(&print);
	return ostr;
}
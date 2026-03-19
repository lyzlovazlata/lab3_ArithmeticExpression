#include"Expression.h"


Expression::Expression(string _in) : in(_in), res(0) {}
Expression::Expression(const Expression& expr)
{
	in = expr.in;
	infix = expr.infix;
	res = expr.res;
}
Expression& Expression::operator=(const Expression& expr)
{
	if (this == &expr) return *this;
	in = expr.in;
	infix = expr.infix;
	res = expr.res;
	return*this;
}
//Expr* Expression::buildTree(TQueue<Word> postfix)
//{
//	TStack<Expr*> st(postfix.getSZ());
//
//	while (!postfix.isEmpty())
//	{
//		Word w = postfix.pop();
//
//		if (w.isNum())
//		{
//			st.push(new Number(w.getValue()));
//		}
//		else
//		{
//			Expr* right = st.pop();
//			Expr* left = st.pop();
//
//			st.push(new BiOperation(char(w.getValue()), left, right));
//		}
//	}
//
//	return st.pop();
//}
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

	//=--------------------------------------------------------------------------------
	treeRoot = sa.getRoot();
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
	PrintVisitor print;
	exp.treeRoot->accept(&print);
	return ostr;
}
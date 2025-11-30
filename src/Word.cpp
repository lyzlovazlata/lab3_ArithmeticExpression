#include"Word.h"
#include <stdexcept>
#include<iostream>


Word::Word(char c) : len(1), value(c)
{
	if ((c == '(') || (c == ')') || (c == '-') || (c == '+') || (c == '/') || (c == '*'))
	{
		isnum = false;
		isbin = true;
		value = int(c); // если символ это не число то будем хранить его код в аске, это удобно
	}
	// ДА, это нехорошое условие, но у меня "нормальное" не работает :( Может я чето не так пишу....
	else if ((c == '0') || (c == '1') || (c == '2') || (c == '3') || (c == '4') || (c == '5') || (c == '6') || (c == '7') || (c == '8') || (c == '9'))
	{
		isnum = true;
		isbin = false;
	}
	else
	{
		throw invalid_argument("WORD: You can't put anything else but numbers, parentheses or base operations!");
	}
}
Word::Word(const Word& w)
{
	isnum = w.isnum;
	value = w.value;
	len = w.len;
	isbin = w.isbin;

}
Word& Word::operator=(const Word& w)
{
	if (this == &w)return *this;

	isnum = w.isnum;
	value = w.value;
	len = w.len;
	isbin = w.isbin;
	return *this;
}

Word::Word() {
	isnum = true;
	isbin = false;

	len = 0;

	value = 0;
}

int& Word::getValue()
{
	return value;
}

size_t& Word::getLen()
{
	return len;
}

bool& Word::isNum() {
	return isnum;
}

bool& Word::isBin() {
	return isbin;
}

ostream& operator<<(ostream& ostr, Word q)
{
	if (q.isnum)
		ostr << q.value;
	else
		ostr << char(q.value);
	return ostr;
}
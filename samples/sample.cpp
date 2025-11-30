#include "Expression.h"
#include <string>
#include<iostream>
#include<locale.h>

using namespace std;

int main()
{

	string s = "-3*4+(6-2)";
	Expression e(s);
	try {
		e.run();
	}
	catch (...) {

	}
	cout << e.getPostfix() << endl;
	cout << e.getRes() << endl;
}				  



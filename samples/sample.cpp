#include "Expression.h"
#include <string>
#include<iostream>
#include<locale.h>

using namespace std;

int main()
{

	string s = "5-8-0";
	Expression e(s);
	e.run();

	cout << e.getRes() << endl;
	cout << e;
}				  

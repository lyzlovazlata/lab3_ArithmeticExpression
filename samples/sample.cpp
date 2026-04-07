#include <string>
#include<iostream>
#include<locale.h>
#include"Pascal.h"
#include"AVLMap.h"

using namespace std;

int main()
{
	AVLMap<std::string, double>* avlMap = new AVLMap<string, double>();
	string s = "a = 12 + (3 * 4); b = 3 * 6; while (a < b) do 4 * 5; end;";
	PascalProgramm pp(avlMap, s);
}				  

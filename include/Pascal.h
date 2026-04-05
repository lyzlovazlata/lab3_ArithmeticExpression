#pragma once
#include <string>
#include "IMap.h"
using namespace std;


class PascalProgramm {
	IMap<string, double>* variableStorage;
	string prog;
	void parseInput(string prog)
	{

	}

public:
	PascalProgramm(IMap<string, double>* memory, string _prog) : prog(_prog), variableStorage(memory) {}

};
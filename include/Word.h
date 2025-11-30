#pragma once
#include <string>
using namespace std;


/*
Класс для хранения слова
Он сделан для того, чтобы правильно создавать очередь и корректно получать итоговое выражение (Например, получать из записи 12 не 1 и 2, а именно двенадцать)
Так же чтобы ставить флаг на унарный оператор
А еще с помощью поля длины мы сможем легче узнавать индекс ошибки (нам ведь нужно выдавать ошибку именно посимвольно а не по номеру в очереди)
*/

class Word {
	
	bool isnum;
	bool isbin;

	size_t len;

	int value;

public:

	Word(char c);
	Word(const Word& w);
	Word& operator=(const Word& w);
	Word();
	int& getValue();
	size_t& getLen();
	bool& isNum();
	bool& isBin();
	friend ostream& operator<<(ostream& ostr, Word q);
};
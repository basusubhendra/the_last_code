#ifndef _NUMBER_
#define _NUMBER_
#include "common.hpp"
class Number {
	private:
		char* value;
	public:
                Number(char*);
		~Number();
};

Number::Number(char* s) {
	this->value = s;
}

Number::~Number() {
	free(value);
}
#endif

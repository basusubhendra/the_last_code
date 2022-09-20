#ifndef _ADAPTER_
#define _ADAPTER_
#include "common.hpp"
class Adapter {
	private:
		char* num;
		unsigned long l;
		std::string b_str;
	public:
		Adapter(char* num);
		void convert();
		std::string getBinary();
		~Adapter();
};

Adapter::Adapter(char* s) {
	this->num = strdup(s);
	this->l = strlen(s);
}

void Adapter::convert() {
	this->b_str = _bin_(this->num, 0);
}

std::string Adapter::getBinary() {
	return this->b_str;
}

Adapter::~Adapter() {
	free(this->num);
}
#endif

#ifndef _ADAPTER_
#define _ADAPTER_
#include "common.hpp"
class Adapter {
	private:
		char* num;
		unsigned long l;
		unsigned long mid;
		std::string b_str;
		std::string reverse_of_b_str;
	public:
		Adapter(char* num);
		void convert();
		unsigned long getMidPoint();
		std::string getBinary();
		std::string getReverseBinary();
		~Adapter();
};

Adapter::Adapter(char* s) {
	this->num = strdup(s);
	this->l = strlen(s);
	this->mid = ceil(this->l / 2.0);
}

unsigned long Adapter::getMidPoint() {
	return this->mid;
}

void Adapter::convert() {
	this->b_str = _bin_(this->num, 0);
	this->reverse_of_b_str = _bin_(this->num, 1);
}

std::string Adapter::getBinary() {
	return this->b_str;
}

std::string Adapter::getReverseBinary() {
	return this->reverse_of_b_str;
}

Adapter::~Adapter() {
	free(this->num);
}
#endif

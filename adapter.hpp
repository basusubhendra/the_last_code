#ifndef _ADAPTER_
#define _ADAPTER_
#include "common.hpp"
int base4_1[10] = { 1, 1, 1, 1, 3, 0, 1, 1, 3, 2 };
int base4_2[10] = { 2, 2, 2, 2, 3, 0, 2, 2, 3, 1 };
class Adapter {
	private:
		char* num;
		long l;
                vector<short int>* states1;
                vector<short int>* states2;
	public:
		Adapter(char* num);
		void convert();
		vector<short int>* getStates1();
		vector<short int>* getStates2();
		~Adapter();
};

Adapter::Adapter(char* s) {
	this->num = strdup(s);
	this->l = strlen(s);
	this->states1 = new vector<short int>[1];
	this->states2 = new vector<short int>[1];
}

void Adapter::convert() {
	for (int i = 0; i < this->l; ++i) {
		this->states1->push_back(base4_1[num[i] - '0']);
		this->states2->push_back(base4_2[num[i] - '0']);
	}
	std::reverse(this->states2->begin(), this->states2->end());
}

vector<short int>* Adapter::getStates1() {
	return states1;
}

vector<short int>* Adapter::getStates2() {
	return states2;
}

Adapter::~Adapter() {
	free(this->num);
	delete this->states1;
	delete this->states2;
}
#endif

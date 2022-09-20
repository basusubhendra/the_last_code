#ifndef _ADAPTER_
#define _ADAPTER_
#include "common.hpp"
int base4[10] = { 1, 1, 1, 1, 3, 0, 1, 1, 3, 2 };
class Adapter {
	private:
		char* num;
		long l;
                vector<short int>* states;
	public:
		Adapter(char* num);
		void convert();
		vector<short int>* getStates();
		~Adapter();
};

Adapter::Adapter(char* s) {
	this->num = strdup(s);
	this->l = strlen(s);
	this->states = new vector<short int>[1];
}

void Adapter::convert() {
	for (int i = 0; i < this->l; ++i) {
		this->states->push_back(base4[num[i] - '0']);
	}
}

vector<short int>* Adapter::getStates() {
	return states;
}

Adapter::~Adapter() {
	free(num);
}
#endif

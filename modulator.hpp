#ifndef _MODULATOR_
#define _MODULATOR_
#include "common.hpp"
#include "pi.hpp"
#include "e.hpp"

class Modulator {
	private:
		char* num;
		unsigned long long int l;
		vector<short int>* native_states;
		const char* modulation_strategy;
		std::string last_snippet;
		short int parity;
		unsigned long long int index;
	public:
		Modulator(char*, vector<short int>*, const char*, short int);
		void run_micro_step();
		std::string get_last_snippet();
};

Modulator::Modulator(char* s, vector<short int>* states, const char* p, short int pty) {
	this->num = strdup(s);
	this->l = strlen(s);
	this->native_states = states;
	this->modulation_strategy = p;
	this->parity = pty;
	this->index = 0;
}

void Modulator::run_micro_step() {
	unsigned long long int intervening_counter = 0;
	short int state = 0;
	unsigned long long int interval = 0;
	int ctr = 0;
	while (1) {
		short int pp1 = modulation_strategy[this->index] - '0';
		short int pp2 = modulation_strategy[this->index + 1] - '0';
		short int relation = _getStateRelation_(_deriveStateRelation_(pp1, pp2));
		if (relation == native_states->at(ctr % this->l)) {
			if ((this->parity == 1 && state == 1 && intervening_counter > 0) || (this->parity == 0 && state == 1 && intervening_counter == 0)) {
				this->last_snippet = _bin_(interval);
				intervening_counter = 0;
				state = 0;
				if (parity == 1) {
					++interval;
				} else {
					return;
				}
			} else if ((this->parity == 1 && state == 1 && intervening_counter == 0) || (this->parity == 0 && state == 1 && intervening_counter > 0)) {
				intervening_counter = 0;
				state = 0;
				if (parity == 0) {
					++interval;
				} else {
					return;
				}
			}
			++ctr;
			if (ctr == this->l) {
				state = 1;
				ctr = 0;
			}
		} else if (relation != 3 && state == 1) {
			intervening_counter++;
		}
		index += 2;
	}
}

std::string Modulator::get_last_snippet() {
	return this->last_snippet;
}
#endif

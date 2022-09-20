#ifndef _MODULATOR_
#define _MODULATOR_
#include "common.hpp"
#include "pi.hpp"
#include "e.hpp"

class Modulator {
	private:
		char* num;
		unsigned long long int l;
		std::string binary_string1;
		const char* modulation_strategy1;
		const char* modulation_strategy2;
		std::string snippet;
		short int parity;
		unsigned long long int offset;
	public:
		Modulator(char*, std::string, const char*, const char*, short int);
		void run_micro_step();
		std::string getSnippet();
};

Modulator::Modulator(char* s, std::string _bin_, const char* pp, const char* ee, short int _parity_) {
	this->num = strdup(s);
	this->l = strlen(s);
	this->binary_string1 = _bin_;
	this->modulation_strategy1 = pp;
	this->modulation_strategy2 = ee;
	this->parity = _parity_;
}

void Modulator::run_micro_step() {
	unsigned long long int ctr = this->offset;
	unsigned long long int idx = 0;
	vector<unsigned long long int> markers;
	vector<int> pi_pivots;
	vector<int> e_pivots;
	while ((idx % this->l != 0) && (ctr > 0)) {
		short int pp1 = modulation_strategy1[ctr] - '0';
		short int ee1 = modulation_strategy2[ctr] - '0';
		short int pp2 = modulation_strategy1[ctr + 1] - '0';
		short int ee2 = modulation_strategy2[ctr + 1] - '0';
		short int relation1 = _getStateRelation_(_deriveStateRelation_(pp1, pp2));
		short int relation2 = _getStateRelation_(_deriveStateRelation_(ee1, ee2));
		if (((relation1 == 2 && relation1 == 1 && this->binary_string1[idx % this->binary_string1.size()] == '0') 
					|| (relation1 == 1 && relation2 == 2 && this->binary_string1[idx % this->binary_string1.size()] == '1')) && 
				((this->parity == 0 && (pp1*10 + pp2) < (ee1*10 + ee2))
				 || (this->parity == 1 && (pp1*10 + pp2) > (ee1*10 + ee2)))) {
			markers.push_back(ctr);
			pi_pivots.push_back(pp1*10 + pp2);
			e_pivots.push_back(ee1*10+ ee2);
			++idx;
		}
		ctr += 2;
	}
	unsigned long long int last_ctr =  markers[markers.size() - 1];
	unsigned long long int sz = last_ctr;
	unsigned long long int first_ctr = 0;
	unsigned long long int idx1 = 0, idx2 = sz;
	bool flag1 = false, flag2 = false;
	std::string _factor_ = "";
	while (last_ctr >= 0 && first_ctr < sz) {
		flag1 = flag2 = false;
		if (last_ctr == markers[idx2]) {
			flag1 = true;
			--idx2;
		}
		if (first_ctr == markers[idx1]) {
			flag2 = true;
			++idx1;
		}
		if (flag1 == true && flag2 == true) {
			if (pi_pivots[idx1 - 1] < e_pivots[idx1 - 1]) {
				_factor_ += "0";
			} else if (pi_pivots[idx1 - 1] > e_pivots[idx1 - 1]) {
				_factor_ += "1";
			} else {
				//NOP
			}
		}
		last_ctr -= 2;
		first_ctr += 2;

	}
	this->snippet = _factor_;
	return;
}

std::string Modulator::getSnippet() {
	return this->snippet;
}
#endif

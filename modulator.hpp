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
		std::string binary_string2;
		const char* modulation_strategy1;
		const char* modulation_strategy2;
		std::string factor1;
		std::string factor2;
	public:
		Modulator(char*, std::string, std::string, const char*, const char*);
		void run();
		std::string getFactor1();
		std::string getFactor2();
};

Modulator::Modulator(char* s, std::string _bin_, std::string _r_bin_, const char* pp, const char* ee) {
	this->num = strdup(s);
	this->l = strlen(s);
	this->binary_string1 = _bin_;
	this->binary_string2 = _r_bin_;
	this->modulation_strategy1 = pp;
	this->modulation_strategy2 = ee;
}

void Modulator::run() {
	unsigned long ctr = 0;
	unsigned long number_index = 0;
	unsigned long reverse_number_index = 0;
	std::string _factor1_ = "";
	std::string _factor2_ = "";
	unsigned long accumulator_1_ = 0;
	unsigned long accumulator_0_ = 0;
	while (number_index < this->binary_string1.size()) {
		short int pp1 = modulation_strategy1[ctr] - '0';
		short int pp2 = modulation_strategy1[ctr + 1] - '0';
		short int ee1 = modulation_strategy2[ctr] - '0';
		short int ee2 = modulation_strategy2[ctr + 1] - '0';
		short int relation1 = _getStateRelation_(_deriveStateRelation_(pp1, pp2));
		short int relation2 = _getStateRelation_(_deriveStateRelation_(ee1, ee2));
		if (relation1 == 1 && relation2 == 2) {
			if (this->binary_string1[number_index % this->binary_string1.size()] == '1') {
				++accumulator_1_;
				++accumulator_0_;
			}
			++number_index;
		} else if (relation2 == 1 && relation1 == 2) {
			if (this->binary_string2[reverse_number_index % this->binary_string2.size()] == '0') {
				_factor2_ += _bin_(accumulator_0_);
				accumulator_0_ = 0;
			} else {
				_factor1_ += _bin_(accumulator_1_);
				accumulator_1_ = 0;
			}
			reverse_number_index++;
		}
		ctr += 2;
	}
	this->factor1 = _factor1_;
	this->factor2 = _factor2_;
	return;
}

std::string Modulator::getFactor1() {
	return this->factor1;
}

std::string Modulator::getFactor2() {
	return this->factor2;
}
#endif

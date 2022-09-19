#ifndef _ENGINE_
#define _ENGINE_
#include "number.hpp"
#include "pi_e_engine.hpp"
class Engine {
	private:
	      Number* num;
	      pi_e_engine* pie;
	      short int polarity;
              std::string last_snippet;           
	public:
	      Engine(Number*, pi_e_engine*);
	      bool getPolarity();
	      std::string getLastSnippet();
	      bool getFinishedStatus();
	      void run1Step();
}; 

Engine::Engine(Number* obj, pi_e_engine* _pie_) {
	this->num = obj;
	this->pie = _pie_;
	this->polarity = -1;
	this->last_snippet = "";
}

bool Engine::getPolarity() {
	switch (polarity) {
		case 0:
			return false;
		case 1:
			return true;
		case -1:
			cout << "Unusual command detected" << endl;
			exit(1);
			break;
	}
	return false;
}

std::string Engine::getLastSnippet() {
	return this->last_snippet;
}

bool Engine::getFinishedStatus() {
	return this->num->getFinishedStatus();
}

void Engine::run1Step() {
     short int relation = this->num->getStateRelation();
     ///TBD: Actual engine code comes here
     std::string snippet = "";
     int accumulator = 0;
     while (1) {
	     //Compose snippet until l2r match (higher factor) or r2l match (lower factor). 
	     short int left_match = -1, right_match = -1;
	     this->pie->run_micro_step(relation, left_match, right_match);
	     if ((left_match == -1 && right_match > -1) || (left_match > -1 && right_match == -1)) {
		     accumulator++;
	     } else if (left_match == -1 && right_match == -1) {
	     } else {
		     ++accumulator;
		     snippet += boost::lexical_cast<std::string>(accumulator);
		     accumulator = 1;
	     }
	     short int l2r_digit = this->num->getL2RDigit();
	     short int r2l_digit = this->num->getR2LDigit();
	     if (left_match == l2r_digit && left_match == r2l_digit) {
		     this->last_snippet = snippet;
		     this->polarity = 2;
		     break;
	     } else if (right_match == l2r_digit && right_match == r2l_digit) {
		     this->last_snippet = snippet;
		     this->polarity = 2;
		     break;
	     } else if (left_match == l2r_digit) {
		     this->last_snippet = snippet;
		     this->polarity = 0;
		     break;
	     } else if (right_match == r2l_digit) {
		     this->last_snippet = snippet;
		     this->polarity = 1;
		     break;
	     }
     }
     return;
}
#endif

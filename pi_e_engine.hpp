#ifndef _PI_E_
#define _PI_E_
#include "pi.hpp"
#include "e.hpp"
class pi_e_engine {
	private:
		char* pi;
		char* e;
		unsigned long long int last_offset;
		short int last_disambiguated;
	public:
		pi_e_engine() {
                     this->pi = pi;
		     this->e = e;
		     this->last_offset = 0;
		}
		void run_micro_step(short int& left, short int& right);
};

void pi_e_engine::run_micro_step(short int& left, short int& right) {
}
#endif

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
                     this->pi = const_cast<char*>(_pi_);
		     this->e = const_cast<char*>(_e_);
		     this->last_offset = 0;
		}
		void run_micro_step(short int, short int& left, short int& right);
		void getMatch(unsigned long long int, short int&, short int&);
};

void pi_e_engine::getMatch(unsigned long long int offset, short int& left, short int& right) {
	char* e_copy = (char*) calloc(offset + 1, sizeof(char));
	strncpy(e_copy, e, offset);
	e_copy[offset] = '\0';
	bool left_match = false, right_match = false;
	short int left_matching_digit = -1, right_matching_digit = -1;
#ifdef _DEBUG
	cout << e_copy << endl;
#endif
	for (int i = 0; i < offset; i += 2) {
#ifdef _DEBUG
		cout << i << "\t\t" << offset << "\t\t" << offset - 1 - i << endl;
		system("a=1;read a");
#endif
		if (e_copy[i] == pi[offset - 1 - i]) {
			right_match = true;
			right_matching_digit = e_copy[i] - '0';
			cout << "Matcch Found 2.1\n";
		}
		if (e_copy[i + 1] == pi[offset - 2 - i]) {
			left_match = true;
			left_matching_digit = e_copy[i + 1] - '0';
			cout << "Matcch Found 2.2\n";
		}
		if (left_match || right_match) break; //break on first match
	}
	left = left_matching_digit;
	right = right_matching_digit;
	free(e_copy);
	return;		
}

void pi_e_engine::run_micro_step(short int relation, short int& left, short int& right) {
	while (1) {
		short int left_digit = this->pi[this->last_offset] - '0';
		short int right_digit = this->pi[this->last_offset + 1] - '0';
		cout << left_digit << "\t\t" << right_digit << endl;
		short int derived_relation = _getStateRelation_(_deriveStateRelation_(left_digit, right_digit));
		cout << derived_relation << "\t\t" << relation << endl;
		if (derived_relation == relation) {
			cout << "Match Found\n";
			this->getMatch(this->last_offset+1+1, left, right);
			cout << left << "\t\t" << right << endl;
			system("a=1;read a");
		        this->last_offset += 2;
			break;
		}
		this->last_offset += 2;
	}
	return;
}
#endif

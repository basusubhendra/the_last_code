#ifndef _COMMON_
#define _COMMON_
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <algorithm>
#include <gmp.h>
using namespace std;
using namespace boost;
enum state_relation { _equal_, _lt_, _gt_, _nan_1_, _nan_2_ };
enum state_relation _deriveStateRelation_(short int x, short int y) {
	if (x == 0) {
		return _nan_1_;
	} else if (y == 0) {
		return _nan_2_;
	} else if (x == y) {
		return _equal_;
	} else if (x < y) {
		return _lt_;
	} else if (x > y) {
		return _gt_;
	}
}

short int _getStateRelation_(enum state_relation relation) {
	switch (relation) {
		case _equal_: 
			return 0;
		case _lt_:
			return 1;	
		case _gt_:
			return 2;
		case _nan_1_:
			return 3;
		case _nan_2_:
			return 4;
		default:
			break;
	}
	return -1;
}

std::string _bin_(unsigned long acc) {
	if (acc == 0) {
		std::string ss = "0";
		return ss;
	}
	std::string ss = "";
	while (acc > 0) {
		int r = acc % 2;
		ss += boost::lexical_cast<std::string>(r);
		acc /= 2;
	}
//	std::reverse(ss.begin(), ss.end());
	return ss;
}

std::string _bin_(char* num, short int param) {
	mpz_t nz;
	mpz_init(nz);
	mpz_set_str(nz, num, 10);
	mpz_t rz;
	mpz_init(rz);
	std::string ss = "";
	while (mpz_cmp_si(nz, 0) > 0) {
		mpz_mod_ui(rz, nz, 2);
		int r = mpz_get_ui(rz);
		ss += boost::lexical_cast<std::string>(r);
		mpz_div_ui(nz, nz, 2);
	}
	if (!param) {
		std::reverse(ss.begin(), ss.end());
	}
	mpz_clear(nz);
	mpz_clear(rz);
	return ss;
}

std::string _int_(std::string __b) {
	mpz_t prod;
	mpz_init(prod);
	mpz_set_ui(prod, 1);
	mpz_t sum;
	mpz_init(sum);
	mpz_set_si(sum, 0);
	mpz_t term;
	mpz_init(term);
	for (int i = __b.size() - 1; i >= 0; --i) {
		short int bk = __b[i] - '0';
                mpz_mul_ui(term, prod, bk);
		mpz_add(sum, sum, term);
		mpz_mul_ui(prod, prod, 2);
	}
	std::string _res_ = strdup(mpz_get_str(0, 10, sum));
	mpz_clear(prod);
	mpz_clear(sum);
	mpz_clear(term);
	return _res_;
}
#endif

#ifndef _COMMON_
#define _COMMON_
#include <stdio.h>
#include <string.h>
#include <math.h>
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
	std::reverse(ss.begin(), ss.end());
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
#endif


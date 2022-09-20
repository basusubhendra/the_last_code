#ifndef _COMMON_
#define _COMMON_
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <vector>
using namespace std;
using namespace boost;
enum state_relation { _equal_, _lt_, _gt_, _nan_ };
enum state_relation _deriveStateRelation_(short int x, short int y) {
	if (x == 0 || y == 0) {
	       return _nan_;
	} else if (x == y) {
	       return _equal_;
	} else if (x < y) {
	       return _lt_;
	} else if (x > y) {
	       return _gt_;
	}
	return _nan_;
}

short int _getStateRelation_(enum state_relation relation) {
	switch (relation) {
		case _equal_: 
		       return 0;
	        case _lt_:
	               return 1;	
		case _gt_:
		       return 2;
		case _nan_:
		       return 3;
		default:
		       break;
	}
        return -1;
}
#endif


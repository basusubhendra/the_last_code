#ifndef _NUMBER_
#define _NUMBER_
#include "common.hpp"
enum state_relation { _equal_, _lt_, _gt_, _nan_ };
class Number {
	private:
		char* value;
		long l;
		short int l2rstate;
		short int r2lstate;
		enum state_relation relation;
		bool isFinished_b;
                void updateStateRelation();
		void updateFinishedStatus();
	public:
                Number(char*);
		short int getL2RState();
		short int getR2LState();
		short int getL2RDigit();
		short int getR2LDigit();
		void incrementL2RState();
		void incrementR2LState();
		short int getStateRelation();
		bool getFinishedStatus();
};

Number::Number(char* s) {
	this->value = s;
	this->l = strlen(this->value);
	this->isFinished_b = false;
	this->relation = _nan_;
	this->l2rstate = this->r2lstate = 0;
}

short int Number::getL2RState() {
	return this->l2rstate;
}

short int Number::getR2LState() {
	return this->r2lstate;
}

void Number::incrementL2RState() {
	this->l2rstate = this->l2rstate + 1;
	this->updateStateRelation();
	this->updateFinishedStatus();
}

void Number::incrementR2LState() {
	this->r2lstate = this->r2lstate + 1;
	this->updateStateRelation();
	this->updateFinishedStatus();
}

void Number::updateStateRelation() {
	if (this->r2lstate == 0 || this->l2rstate == 0) {
		this->relation = _nan_;
	} else if (this->r2lstate == this->l2rstate) {
		this->relation = _equal_;
	} else if (this->l2rstate < this->r2lstate) {
	       this->relation = _lt_;
	} else if (this->l2rstate > this->r2lstate) {
	       this->relation = _gt_;
	}
	return;
}

void Number::updateFinishedStatus() {
	if (this->l2rstate + this->r2lstate + 1 + 1 > this->l) {
		this->isFinished_b = true;
	}
}

short int Number::getStateRelation() {
	switch (this->relation) {
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

bool Number::getFinishedStatus() {
	return this->isFinished_b;
}

short int Number::getL2RDigit() {
	return this->value[this->getL2RState()] - '0';
}

short int Number::getR2LDigit() {
	return this->value[this->getR2LState()] - '0';
}

#endif

#ifndef _NUMBER_
#define _NUMBER_
#include "common.hpp"
enum state_relation { equal, lt, gt, nan };
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
		void incrementL2RState();
		void incrementR2LState();
		short int getStateRelation();
		bool getFinishedStatus();
};

Number::Number(char* s) {
	this->value = s;
	this->l = strlen(this->value);
	this->isFinished_b = false;
	this->relation = nan;
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
		this->relation = nan;
	} else if (this->r2lstate == this->l2rstate) {
		this->relation = equal;
	} else if (this->l2rstate < this->r2lstate) {
	       this->relation = lt;
	} else if (this->l2rstate > this->r2lstate) {
	       this->relation = gt;
	}
	return;
}

void Number::updateFinishedStatus() {
	if (this->l2rstate == this->r2lstate) {
		this->isFinished_b = true;
	}
}

short int Number::getStateRelation() {
	switch (this->relation) {
		case equal: 
		       return 0;
	        case lt:
	               return 1;	
		case gt:
		       return 2;
		case nan:
		       return 3;
		default:
		       break;
	}
        return -1;
}

bool Number::getFinishedStatus() {
	return this->isFinished_b;
}
#endif

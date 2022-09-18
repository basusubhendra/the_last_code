#ifndef _ENGINE_
#define _ENGINE_
#include "number.hpp"
class Engine {
	private:
	      Number* num;
	public:
	      Engine(Number*);
};

Engine::Engine(Number* obj) {
	this->num = obj;
}

#endif

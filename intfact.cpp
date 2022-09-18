#include "common.hpp"
#include "number.hpp"
#include "engine.hpp"

int main(int argc, char* argv[]) {
	char* num = strdup(argv[1]);
	Number* num_obj = new Number(num);
	Engine* engine = new Engine(num_obj);
	return 0;
}

#include "common.hpp"
#include "number.hpp"
#include "engine.hpp"

int main(int argc, char* argv[]) {
	char* num = strdup(argv[1]);
	Number* num_obj = new Number(num);
	pi_e_engine* pie = new pi_e_engine();
	Engine* engine = new Engine(num_obj, pie);
	std::string lower_factor = "";
	std::string higher_factor = "";
	while (!engine->getFinishedStatus()) {
		engine->run1Step();
		short int polarity = engine->getPolarity();
		std::string snippet = engine->getLastSnippet();
		cout << "Snippet = " << snippet << endl;
		system("a=1;read a");
		switch (polarity) {
			case 0:
				lower_factor += snippet;
				num_obj->incrementR2LState();
		                break;
			case 1:
				higher_factor += snippet;
				num_obj->incrementL2RState();
				break;
			case 2:
				lower_factor += snippet;
				higher_factor += snippet;
				num_obj->incrementL2RState();
				num_obj->incrementR2LState();
				break;
		}
	}
	cout << num << "\t=\t" << lower_factor << "\tX\t" << higher_factor << endl;
	return 0;
}

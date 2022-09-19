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
		bool polarity = engine->getPolarity();
		std::string snippet = engine->getLastSnippet();
		switch (polarity) {
			case 0:
				lower_factor += snippet;
		                break;
			case 1:
				higher_factor += snippet;
				break;
		}
	}
	cout << num << "\t=\t" << lower_factor << "\tX\t" << higher_factor << endl;
	return 0;
}

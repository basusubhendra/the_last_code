#include "common.hpp"
#include "adapter.hpp"
#include "modulator.hpp"

int main(int argc, char* argv[]) {
	char* num = strdup(argv[1]);
	Adapter* adp = new Adapter(num);
	adp->convert();
	vector<short int>* states = adp->getStates();
	Modulator* mod_pi = new Modulator(num, states, pi);
	std::string factor1 = "";
	std::string factor2 = "";
	while (1) {
		mod_pi->run_micro_step();
		std::string snippet = mod_pi->get_last_snippet();
		cout << "Snippet PI : " << snippet << endl;
		system("a=1;read a");
                //check if accumulated product of snippets is the number itself
		//then exit
	} 
	cout << num << "\t=\t" << factor1 << "\tX\t" << factor2 << endl;
	free(num);
	return 0;
}

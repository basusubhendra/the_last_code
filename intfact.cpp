#include "common.hpp"
#include "adapter.hpp"
#include "modulator.hpp"

int main(int argc, char* argv[]) {
	char* num = strdup(argv[1]);
	Adapter* adp = new Adapter(num);
	adp->convert();
	vector<short int>* states1 = adp->getStates1();
	vector<short int>* states2 = adp->getStates2();
	Modulator* mod_pi = new Modulator(num, states1, pi, 0);
	Modulator* mod_e = new Modulator(num, states2, e, 1);
	std::string factor1 = "";
	std::string factor2 = "";
	while (1) {
		mod_pi->run_micro_step();
		mod_e->run_micro_step();
		std::string snippet_pi = mod_pi->get_last_snippet();
		std::string snippet_e  = mod_e->get_last_snippet();
		cout << snippet_pi << endl;
		cout << snippet_e << endl;
		system("a=1;read a");
                //check if accumulated product of snippets is the number itself
		//then exit
	} 
	cout << num << "\t=\t" << factor1 << "\tX\t" << factor2 << endl;
	free(num);
	return 0;
}

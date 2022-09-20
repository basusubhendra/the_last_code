#include "common.hpp"
#include "adapter.hpp"
#include "modulator.hpp"

int main(int argc, char* argv[]) {
	char* num = strdup(argv[1]);
	Adapter* adp = new Adapter(num);
	adp->convert();
	Modulator* mod = new Modulator(num, adp->getBinary(), adp->getReverseBinary(), pi, e);
	mod->run();
	std::string factor1 = mod->getFactor1();
	std::string factor2 = mod->getFactor2();
	cout << num << "\t=\t" << factor1 << "\tX\t" << factor2 << endl;
	free(num);
	return 0;
}

#include "common.hpp"
#include "adapter.hpp"
#include "modulator.hpp"

int main(int argc, char* argv[]) {
	char* num = strdup(argv[1]);
	Adapter* adp = new Adapter(num);
	adp->convert();
	Modulator* mod = new Modulator(num, adp->getMidPoint(), adp->getBinary(), adp->getReverseBinary(), pi, e);
	mod->run();
	std::string factor1 = mod->getFactor1();
	std::string factor2 = mod->getFactor2();
	free(num);
	return 0;
}

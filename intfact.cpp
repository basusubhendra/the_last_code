#include "common.hpp"
#include "adapter.hpp"
#include "modulator.hpp"

int main(int argc, char* argv[]) {
	char* num = strdup(argv[1]);
	Adapter* adp = new Adapter(num);
	adp->convert();
	Modulator* mod1 = new Modulator(num, adp->getBinary(), pi, e, 0);
	Modulator* mod2 = new Modulator(num, adp->getBinary(), pi, e, 1);
	std::string _factor1_ = "";
	std::string _factor2_ = "";
	while (1) {
		mod1->run_micro_step();
		mod2->run_micro_step();
		std::string snippet1 = mod1->getSnippet();
		std::string snippet2 = mod2->getSnippet();
		_factor1_ += snippet1;
		_factor2_ += snippet2;
		//if product of _factor1_ and _factor2_ is num
		//then exit
	}
	std::string factor1_in_decimal = _int_(_factor1_);
	std::string factor2_in_decimal = _int_(_factor2_);
	cout << num << "\t=\t" << factor1_in_decimal << "\tX\t" << factor2_in_decimal << endl;
	free(num);
	return 0;
}

#include "common.hpp"
#include "number.hpp"
#include "adapter.hpp"

int main(int argc, char* argv[]) {
	char* num = strdup(argv[1]);
	Number* num_obj = new Number(num);
	Adapter* adp = new Adapter(num);
	adp->convert();
	vector<short int>* states = adp->getStates();
	for (int i = 0; i < states->size(); ++i) {
		cout << states->at(i) << endl;
	}
	std::string lower_factor = "";
	std::string higher_factor = "";
	cout << num << "\t=\t" << lower_factor << "\tX\t" << higher_factor << endl;
	return 0;
}

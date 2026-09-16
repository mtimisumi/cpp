#include "RPN.hpp"
#include <cctype>
#include <string>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "Error: No expression given\n";
		return 1;
	}
	
	try {
		RPN rpn;
		rpn.calculate(argv[1]);
		std::cout << rpn.getResult() << "\n";
	}
	catch(const std::exception& e) {
		std::cerr << "Error" << e.what() << "\n";
		return 1;
	}
}
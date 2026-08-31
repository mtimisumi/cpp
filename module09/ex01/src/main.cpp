#include "RPN.hpp"
#include <cctype>
#include <string>

std::vector<char> tokenize(const std::string& s)
{
	std::vector<char> v;

	for (char c : s)
	{
		if (c == ' ')
			continue ;

		if (std::isdigit(c) || isoperator(c))
			v.push_back(c);
		else
			throw(std::runtime_error(std::string("Invalid token ") + c));
	}

	return v;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "Error: No expression given\n";
		return 1;
	}
	
	try {
		std::vector<char> v = tokenize(argv[1]);

		RPN rpn;
		rpn.calculate(v);
		std::cout << rpn.getResult() << "\n";
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
		return 1;
	}
}
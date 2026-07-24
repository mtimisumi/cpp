#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		std::string s = argv[1];
		ScalarConverter::convert(s);
		return 0;
	}

	std::cout << "== empty ==\n";
	std::string empty = "";
	ScalarConverter::convert(empty);
	std::cout << "\n";

	std::cout << "==== a ====\n";
	std::string a = "a";
	ScalarConverter::convert(a);
	std::cout << "\n";

	std::cout << "= number ==\n";
	std::string number = "1234";
	ScalarConverter::convert(number);
	std::cout << "\n";

	std::cout << "== intmax =\n";
	std::string intmax = "2147483647";
	ScalarConverter::convert(intmax);
	std::cout << "\n";

	std::cout << "== intmin =\n";
	std::string intmin = "-2147483648";
	ScalarConverter::convert(intmin);
	std::cout << "\n";

	std::cout << "==== f ====\n";
	std::string f = "3764.54574f";
	ScalarConverter::convert(f);
	std::cout << "\n";

	std::cout << "==== d ====\n";
	std::string d = "245.643";
	ScalarConverter::convert(d);
	std::cout << "\n";

	std::cout << "=== nan ===\n";
	std::string nan = "nan";
	ScalarConverter::convert(nan);
	std::cout << "\n";

	std::cout << "=== inf ===\n";
	std::string inf = "inf";
	ScalarConverter::convert(inf);
	std::cout << "\n";

	std::cout << "= invalid =\n";
	std::string invalid = "3489f2398d@iq2";
	ScalarConverter::convert(invalid);
	std::cout << "\n";
}
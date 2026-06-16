#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& s)
{
	if (!all_displayable(s)) {
		std::cout << "All characters in string must be displayable\n";
		return ;
	}

	ScalarConverter::Type type = detectType(s);
	if (type == PSEUDO)
		std::cout << "hello";
}

bool ScalarConverter::all_displayable(const std::string& s)
{
	for (char c: s)
	{
		if (!isprint(c))
			return false;
	}

	return true;
}

ScalarConverter::Type ScalarConverter::detectType(const std::string& s)
{
	if (isPseudo(s))
		return PSEUDO;
	return INVALID;
}

bool ScalarConverter::isPseudo(const std::string& s)
{
	if (s == "-inf" || s == "+inf" || s == "nan" ||
			s == "-inff" || s == "+inff" || s == "nanff")
				return true;

	return false;
}

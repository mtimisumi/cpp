#include "ScalarConverter.hpp"

Type::INVALID;

void ScalarConverter::convert(const std::string& s)
{
	if (!all_displayable(s)) {
		std::cout << "All characters in string must be displayable\n";
		return ;
	}

	detectType();
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

void ScalarConverter::detectType(const std::string& s)
{
	if (isPseudo(s))
		Type = PSEUDO;
}
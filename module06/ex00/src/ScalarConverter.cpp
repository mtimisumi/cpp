#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& input)
{

}

bool ScalarConverter::isPseudo(const std::string& input) const
{
	if (input == "nan" || input == "+inf" || input == "-inf"
		|| input == "nanf" || input == "+inff" || input == "-inff") {
			return true;
		}
	return false;
}

bool ScalarConverter::isChar(const std::string& input)
{
	// must be char not string
	if (input.length() != 1)
		return false;
	// must fit into ascii
		// THIS IS WRONG
	if (input[0] < 0 || input[0] > 176)
		return false;
	if (input[0] > 0 && input[0] < 33)
		return false;
	return true;
}
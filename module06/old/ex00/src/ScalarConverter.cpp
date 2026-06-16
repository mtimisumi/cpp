#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& s)
{
	enum Type{CHAR, INT, FLOAT, DOUBLE, PSEUDO};

	Type type = detectType(s);

	static void (ScalarConverter::*f[])(const std::string& s) = {&ScalarConverter::convertChar,
			&ScalarConverter::convertInt, &ScalarConverter::convertFloat, &ScalarConverter::convertDouble};
	
	for (int i = 0; i < MAX; i++)
	{
		if (type == Type) {
			(this->*f[i](s));
			return ;
		}
	}
	
}

Type ScalarConverter::detectType(const std::string& s);
{
	if (isChar(s))
		return CHAR;
	if (isInt(s))
		return INT;
	if (isFloat(s))
		return FLOAT;
	if (isDouble)
		return DOUBLE;
}

bool ScalarConverter::isChar(const std::string& s)
{
	if (s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]))
		return true;
}

bool ScalarConverter::isInt(const std::string& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (i == 0 && (s[i] == '+' || s[i] == '-'))
			continue;
		if (!std::isdigit(s[i]))
			return false;
	}

}

// bool ScalarConverter::isPseudo(const std::string& input) const
// {
// 	if (input == "nan" || input == "+inf" || input == "-inf"
// 		|| input == "nanf" || input == "+inff" || input == "-inff") {
// 			return true;
// 		}
// 	return false;
// }

// bool ScalarConverter::isChar(const std::string& input)
// {
// 	// must be char not string
// 	if (input.length() != 1)
// 		return false;
// 	// must fit into ascii
// 		// THIS IS WRONG
// 	if (input[0] < 0 || input[0] > 176)
// 		return false;
// 	if (input[0] > 0 && input[0] < 33)
// 		return false;
// 	return true;
// }
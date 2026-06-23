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
	if (s.empty())
		return false;

	for (char c: s) {
		if (!isprint(c))
			return false;
	}

	return true;
}

ScalarConverter::Type ScalarConverter::detectType(const std::string& s)
{
	if (isPseudo(s))
		return PSEUDO;
	if (isChar(s))
		return CHAR;
	if (isInt(s))
		return INT;
	if (isDouble(s))
		return DOUBLE;
	if (isFloat(s))
		return FLOAT;

	return INVALID;
}

bool ScalarConverter::isPseudo(const std::string& s)
{
	if (s == "-inf" || s == "+inf" || s == "nan" ||
			s == "-inff" || s == "+inff" || s == "nanf")
				return true;

	return false;
}

bool ScalarConverter::isChar(const std::string& s)
{
	if (s.length() == 1 && !isdigit(s[0]))
		return true;

	return false;
}

bool ScalarConverter::isInt(const std::string& s)
{
	std::string temp = s;

	if (s[0] == '+' || s[0] == '-')
		temp = temp.substr(1);

	if (temp.empty())
		return false;

	for (char c: temp)
	{
		if (!isdigit(c))
			return false;
	}

	if (temp.length() > 10)
		return false;

	if (s[0] == '-' && temp.length() == 10 && temp > "2147483648")
		return false;

	if (s[0] != '-' && temp.length() == 10 && temp > "2147483647")
		return false;

	return true;
}

bool ScalarConverter::isDouble(const std::string& s)
{
	std::string temp = s;

	if (s[0] == '-')
		temp = temp.substr(1);

	int pos = temp.find_first_of('.');
	if (pos == std::string::npos)
		return false;

	std::string number = temp.substr(0, pos);
	std::string decimal = temp.substr(pos + 1);
	if (number.empty() || decimal.empty())
		return false;

	for (char c: number) {
		if (!isdigit(c))
			return false;
	}

	for (char c: decimal) {
		if (!isdigit(c))
			return false;
	}

	return true;
}

bool ScalarConverter::isFloat(const std::string& s)
{
	char f = s.back();
	if (f != 'f')
		return false;

	std::string temp = s.substr(0, s.length() - 1);
	if (temp.empty() || !isDouble(temp))
		return false;

	return true;
}

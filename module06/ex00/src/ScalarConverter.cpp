#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& s)
{
	if (!all_displayable(s)) {
		std::cout << "All characters in string must be displayable\n";
		return ;
	}

	ScalarConverter::Type type = detectType(s);
	// if (type == PSEUDO)
	// 	std::cout << "Pseudo\n";
	// else if (type == CHAR)
	// 	std::cout << "Char\n";
	// else if (type == INT)
	// 	std::cout << "Int\n";
	// else if (type == DOUBLE)
	// 	std::cout << "Double\n";
	// else if (type == FLOAT)
	// 	std::cout << "Float\n";
	// else if (type == INVALID)
	// 	std::cout << "Invalid\n";
	switch (type)
	{
		case PSEUDO: convertPseudo(s); break ;
		case CHAR: convertChar(s); break ;
		case INT: convertInt(s); break ;
		case DOUBLE: convertDouble(s); break ;
		case FLOAT: convertFloat(s); break ;
		case INVALID: std::cout << "Input is invalid\n"; break ;
	}
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

	std::string::size_type pos = temp.find_first_of('.');
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

void ScalarConverter::convertPseudo(const std::string& s)
{
	std::cout << "impossible\n";
	std::cout << "impossible\n";
	if (s == "nan" || s == "+inf" || s == "-inf")
	{
		std::cout << s << std::endl;
		std::cout << s << "f\n";
	}
	else
	{
		std::cout << s.substr(0, s.size() - 1) << std::endl;
		std::cout << s << std::endl;
	}
}

void ScalarConverter::convertChar(const std::string& s)
{
	char c = s[0];

	std::cout << c << std::endl;
	std::cout << static_cast<int>(c) << std::endl;
	std::cout << static_cast<double>(c) << std::endl;
	std::cout << static_cast<float>(c) << std::endl;
}

void ScalarConverter::convertInt(const std::string& s)
{
	int i = stoi(s);

	if (i >= 32 && i < 127)
		std::cout << static_cast<char>(i) << std::endl;
	else
		std::cout << "impossible\n";

	std::cout << i << std::endl;
	std::cout << static_cast<double>(i) << ".0\n";
	std::cout << static_cast<float>(i) << ".0f\n";
}

void ScalarConverter::convertDouble(const std::string& s)
{
	double d = stod(s);

	if (d >= 32 && d < 127)
		std::cout << static_cast<char>(d) << std::endl;
	else
		std::cout << "impossible\n";

	std::cout << static_cast<int>(d) << std::endl;

	if (static_cast<int>(d) == d)
	{
		std::cout << d << ".0\n";
		std::cout << static_cast<float>(d) << ".0f\n";
	}
	else
	{
		std::cout << d << std::endl;
		std::cout << static_cast<float>(d) << "f\n";
	}
}

void ScalarConverter::convertFloat(const std::string& s)
{
	float f = stof(s);

	if (f >= 32 && f < 127)
		std::cout << static_cast<char>(f) << std::endl;
	else
		std::cout << "impossible\n";

	std::cout << static_cast<int>(f) << std::endl;

	if (static_cast<int>(f) == f)
	{
		std::cout << static_cast<double>(f) << ".0\n";
		std::cout << f << ".0f\n";
	}
	std::cout << static_cast<double>(f) << std::endl;
	std::cout << f << "f\n";
}
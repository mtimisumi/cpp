#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& s)
{
	if (!all_displayable(s)) {
		std::cout << "All characters in string must be displayable\n";
		return ;
	}

	ScalarConverter::Type type = detectType(s);
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
	size_t pos;
	int value;

	try
	{
		value = std::stoi(s, &pos);
	}
	catch (const std::exception& e)
	{
		return false;
	}

	if (s[pos] != '\0')
		return false;

	return true;
}

bool ScalarConverter::isDouble(const std::string& s)
{
	size_t pos;
	int value;

	try
	{
		value = std::stod(s, &pos);
	}
	catch (const std::exception& e)
	{
		return false;
	}

	if (s[pos] != '\0')
		return false;

	return true;
}

bool ScalarConverter::isFloat(const std::string& s)
{
	size_t pos;
	int value;

	try
	{
		value = std::stof(s, &pos);
	}
	catch (const std::exception& e)
	{
		return false;
	}

	if (s[pos] != '\0')
		return false;

	return true;
}

void ScalarConverter::convertPseudo(const std::string& s)
{
	std::cout << "char: impossible\n";
	std::cout << "char: impossible\n";
	if (s == "nan" || s == "+inf" || s == "-inf")
	{
		std::cout << "double: " << s << std::endl;
		std::cout << "float: " << s << "f\n";
	}
	else
	{
		std::cout << "double: " << s.substr(0, s.size() - 1) << std::endl;
		std::cout << "float: " << s << std::endl;
	}
}

void ScalarConverter::convertChar(const std::string& s)
{
	char c = s[0];

	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl;
}

void ScalarConverter::convertInt(const std::string& s)
{
	int i = stoi(s);

	if (i >= 32 && i <= 126)
		std::cout << "char: '" << static_cast<char>(i) << "'\n";
	else if (i >= 0 && i <= 127)
		std::cout << "char: non displayable\n";
	else
		std::cout << "char: impossible\n";

	std::cout << "int: " << i << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0\n";
	std::cout << "float: " << static_cast<float>(i) << ".0f\n";
}

void ScalarConverter::convertDouble(const std::string& s)
{
	double d = stod(s);

	if (d >= 32 && d <= 126)
		std::cout << "char: ' " << static_cast<char>(d) << "'\n";
	else if (d >= 0 && d <= 127)
		std::cout << "char: nondisplayable\n";
	else
		std::cout << "char: impossible\n";

	if (d <= (double)INT_MAX && d >= (double)INT_MIN)
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible\n";

	if (d == std::floor(d))
	{
		std::cout << "double: " << d << ".0\n";
		std::cout << "float: " << static_cast<float>(d) << ".0f\n";
	}
	else
	{
		std::cout << "double: " << d << std::endl;
		std::cout << "float: " << static_cast<float>(d) << "f\n";
	}
}

void ScalarConverter::convertFloat(const std::string& s)
{
	float f = stod(s);

	if (f >= 32 && f <= 126)
		std::cout << "char: ' " << static_cast<char>(f) << "'\n";
	else if (f >= 0 && f <= 127)
		std::cout << "char: nondisplayable\n";
	else
		std::cout << "char: impossible\n";

	if (f <= (float)INT_MAX && f >= (float)INT_MIN)
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible\n";

	if (f == std::floor(f))
	{
		std::cout << "double: " << static_cast<double>(f) << ".0\n";
		std::cout << "float: " << f << ".0f\n";
	}
	else
	{
		std::cout << "double: " << static_cast<double>(f) << std::endl;
		std::cout << "float: " << f << "f\n";
	}
}

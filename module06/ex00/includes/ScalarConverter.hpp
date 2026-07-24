#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <climits>

class ScalarConverter
{
	public:
		static void convert(const std::string& s);

	private:
		enum Type{PSEUDO, CHAR, INT, DOUBLE, FLOAT, INVALID};
	
		static bool all_displayable(const std::string& s);
		static Type detectType(const std::string& s);

		static bool isPseudo(const std::string& s);
		static bool isChar(const std::string& s);
		static bool isInt(const std::string& s);
		static bool isDouble(const std::string& s);
		static bool isFloat(const std::string& s);

		static void convertPseudo(const std::string& s);
		static void convertChar(const std::string& s);
		static void convertInt(const std::string& s);
		static void convertDouble(const std::string& s);
		static void convertFloat(const std::string& s);
		static void convertInvalid();

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
};
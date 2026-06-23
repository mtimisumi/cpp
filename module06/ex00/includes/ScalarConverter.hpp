#pragma once

#include <string>
#include <iostream>

class ScalarConverter
{
	private:
		enum Type{PSEUDO, CHAR, INT, DOUBLE, FLOAT, INVALID};
	
	public:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		ScalarConverter& operator=(const ScalarConverter& other) = delete;
		~ScalarConverter() = delete;

		static void convert(const std::string& s);

	private:
		static bool all_displayable(const std::string& s);
		static Type detectType(const std::string& s);
		static bool isPseudo(const std::string& s);
		static bool isChar(const std::string& s);
		static bool isInt(const std::string& s);
		static bool isDouble(const std::string& s);
		static bool isFloat(const std::string& s);
};
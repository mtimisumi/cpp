#pragma once

#include <string>
#include <iostream>

class ScalarConverter
{
	public:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		ScalarConverter& operator=(const ScalarConverter& other) = delete;
		~ScalarConverter() = delete;

		static void convert(const std::string& s);

	private:
		static bool all_displayable(const std::string& s);
		static void detectType(const std::string& s);
		static bool isPseudo(const std::string& s);

	private:
		enum class Type{PSEUDO, CHAR, INT, DOUBLE, FLOAT, INVALID};
};
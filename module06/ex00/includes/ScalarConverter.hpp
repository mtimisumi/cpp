#pragma once

#include <iostream>
#include <string>
#include <cctype>

#define MAX 5

class ScalarConverter
{
	// private:
	// 	enum Type{CHAR, INT, FLOAT, DOUBLE, PSEUDO};

	private:
		static Type detectType(const std::string& s);
		static bool isChar(const std::string& s);
		static bool isInt(const std::string& s);

	public:
		static void convert(const std::string& s);






	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();







	// private:
	// 	enum Type {CHAR, INT, FLOAT, DOUBLE, PSEUDO, NONCHAR, NONINT};
	// 	bool isChar() const;
	// 	bool isInt() const;
	// 	bool isFloat() const;
	// 	bool isDouble() const;
	// 	bool isPseudo() const;

		// char castChar();
		// int castInt();

};
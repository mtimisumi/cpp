#include <iostream>
#include <string>

class ScalarConverter
{
	public:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		ScalarConverter& operator=(const ScalarConverter& other) = delete;
		~ScalarConverter() = delete;

		static void convert(const std::string& input);

	private:
		enum Type {CHAR, INT, FLOAT, DOUBLE, PSEUDO, NONCHAR, NONINT};
		bool isChar() const;
		bool isInt() const;
		bool isFloat() const;
		bool isDouble() const;
		bool isPseudo() const;

		char castChar();
		int castInt();

};
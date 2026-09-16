#pragma once

#include <iostream>
#include <exception>
#include <stack>

class RPN
{
	private:
		long _result;

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		long getResult() const;
		void calculate(const std::string& s);

	private:
		void solvePart(std::stack<long>& s, char sign);
};

bool isoperator(char c);

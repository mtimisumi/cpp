#pragma once

#include <iostream>
#include <exception>
#include <stack>
#include <vector>

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
		void calculate(const std::vector<char>& v);

	private:
		void solvePart(std::stack<long>& s, char sign);
};

bool isoperator(char c);

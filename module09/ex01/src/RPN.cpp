#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN& other)
{
	_result = other._result;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_result = other._result;

	return *this;
}

RPN::~RPN()
{}

long RPN::getResult() const
{
	return _result;
}

void RPN::calculate(const std::string& s)
{
	std::stack<long> stack;

	for (char c : s)
	{
		if (c == ' ')
			continue ;

		if (std::isdigit(c))
			stack.push(c - '0');

		else if (isoperator(c))
			solvePart(stack, c);

		else
			throw std::runtime_error("");
	}

	if (stack.size() > 1)
		throw std::runtime_error("");

	_result = stack.top();
}

void RPN::solvePart(std::stack<long>& s, char sign)
{
	if (s.size() < 2)
		throw std::runtime_error("");

	long b = s.top();
	s.pop();
	long a = s.top();
	s.pop();

	switch(sign)
	{
		case '+': s.push(a + b); return ;
		case '-': s.push(a - b); return ;
		case '*': s.push(a * b); return ;
		case '/': s.push(a / b); return ;
	}
}


bool isoperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}


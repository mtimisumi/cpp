#pragma once
#include <stack>
#include <algorithm>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();
};

#include "MutantStack.tpp"
#include "MutantStack.hpp"

template<typename T>
MutantStack::MutantStack()
{}

template<typename T>
MutantStack::MutantStack(const MutantStack& other) : std::stack<T>(other)
{}

template<typename T>
MutantStack& MutantStack::operator=(const MutantStack& other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template<typename T>
MutantStack::~MutantStack()
{}

template<typename T>
iterator MutantStack::begin()
{}

template<typename T>
iterator MutantStack::end()
{}

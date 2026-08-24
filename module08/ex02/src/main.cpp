#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> m_stack;

	m_stack.push(1);
	m_stack.push(2);
	m_stack.push(3);
	m_stack.push(4);
	m_stack.push(5);

	std::cout << *m_stack.begin() << "\n";
	std::cout << *m_stack.end() << "\n";


}
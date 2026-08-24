#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <deque>

int main()
{
	MutantStack<int> m_stack;
	std::list<int> l;


	m_stack.push(1); l.push_back(1);
	m_stack.push(2); l.push_back(2);
	m_stack.push(3); l.push_back(3);
	m_stack.push(4); l.push_back(4);
	m_stack.push(5); l.push_back(5);

	std::deque<int>::iterator m_it = m_stack.begin();
	std::list<int>::iterator l_it = l.begin();

	std::cout << "first element:\n";
	std::cout << *m_it << "\n";
	std::cout << *l_it << "\n\n";

	m_it++; l_it++;
	m_it++; l_it++;

	std::cout << "element after iteration:\n";
	std::cout << *m_it << "\n";
	std::cout << *l_it << "\n\n";

	std::cout << "size:\n";
	std::cout << m_stack.size() << "\n";
	std::cout << l.size() << "\n\n";

	m_stack.pop(); l.pop_back();

	std::cout << "size after pop:\n";
	std::cout << m_stack.size() << "\n";
	std::cout << l.size() << "\n\n";

	for (m_it = m_stack.begin(); m_it != m_stack.end(); m_it++)
		std::cout << *m_it;
	
	std::cout << "\n";

	for (l_it = l.begin(); l_it != l.end(); l_it++)
		std::cout << *l_it;

	std::cout << "\n";
}
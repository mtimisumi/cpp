#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

Base::~Base()
{}

Base* Base::generate()
{
	switch(std::rand() % 3)
	{
		case 0: return (new A);
		case 1: return (new B);
		case 2: return (new C);
	}
}

void Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n"
}

void Base::identify(Base& p)
{

}
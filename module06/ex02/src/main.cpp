#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base* a = new A;
	a->identify(a);
	delete a;

	Base* b = new B;
	b->identify(b);
	delete b;

	Base* c = new C;
	c->identify(c);
	delete c;

	std::cout << "\n\n";

	// randomization with pointers and references
	Base* p = nullptr;
	for (int i = 0; i < 6; i++)
	{
		p = p->generate();
		p->identify(p);
		p->identify(*p);
		delete p;
	}
}
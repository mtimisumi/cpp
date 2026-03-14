#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	std::cout << "Point default constructor called\n";
}

Point::Point(const float& x, const float& y) : _x(x), _y(y)
{
	std::cout << "Point constructer called\n";
}

Point::~Point()
{
	std::cout << "Point destructor called\n";
}
\
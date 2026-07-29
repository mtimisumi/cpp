#include "Array.hpp"

template<typename T>
Array<T>::Array() : _elements(nullptr), _size(0)
{}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	_elements = new T[n]();
}

template<typename T>
Array<T>::Array(const Array& other) : _size(other._size)
{
	if (_size == 0)
	{
		_elements = nullptr;
		return ;
	}

	_elements = new T[_size];

	for (unsigned int i = 0; i < _size; i++)
		_elements[i] = other._elements[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] _elements;
		_size = other._size;
		_elements = new T[_size];

		for (unsigned int i = 0; i < _size; i++)
			_elements[i] = other._elements[i];
	}

	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete[] _elements;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw IndexOutOfBounds();
	
	return _elements[index];
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template<typename T>
const char* Array<T>::IndexOutOfBounds::what() const noexcept
{
	return "Index is out of bounds";
}
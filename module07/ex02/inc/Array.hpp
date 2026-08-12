#pragma once

#include <iostream>

template<typename T>
class Array
{
	private:
		T* _elements;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		T& operator[](unsigned int index);
		unsigned int size() const;

	private:
		class IndexOutOfBounds : public std::exception
		{
			const char* what() const noexcept override;
		};
};

#include "Array.tpp"
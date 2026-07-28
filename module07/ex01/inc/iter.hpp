#pragma once

#include <iostream>

template<typename T> void print(const T& value)
{
	std::cout << value << "\n";
}

void increment(int& value)
{
	value++;
}

void change(std::string& s)
{
	s = "hi";
}

template<typename T, typename F>
void iter(T* ptr, const int length, F func)
{
	for (int i = 0; i < length; i++)
	{
		func(ptr[i]);
	}
}
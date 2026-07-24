#include "Serializer.hpp"

int main()
{
	Data data;
	data.i = 42;
	data.s = "fortytwo";
	uintptr_t ptr;
	Data* data_copy;

	std::cout << "data adress: " << &data << std::endl;
	ptr = Serializer::serialize(&data);
	std::cout << "data uintptr: " << ptr << std::endl;

	data_copy = Serializer::deserialize(ptr);
	std::cout << "data copy adress: " << data_copy << std::endl;
	std::cout << "data_copy->i = " << data_copy->i << std::endl;
	std::cout << "data_copy->s = " << data_copy->s << std::endl;
}
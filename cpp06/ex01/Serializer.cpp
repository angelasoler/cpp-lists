
#include "Serializer.hpp"

Serializer::Serializer(void)
{
	if (DEBUG)
		std::cout << "Serializer constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	if (DEBUG)
		std::cout << "Serializer copy constructor called" << std::endl;
	*this = copy;
}

Serializer &Serializer::operator=(const Serializer &copy)
{
	if (DEBUG)
		std::cout << "Serializer copy assignment operator called" << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

Serializer::~Serializer(void)
{
	if (DEBUG)
		std::cout << "Serializer destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

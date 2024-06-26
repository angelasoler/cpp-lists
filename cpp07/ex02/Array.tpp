
#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : data(new T), length(0)
{
	if (DEBUG)
		std::cout << "Array constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]), length(n)
{
	if (DEBUG)
		std::cout << "Array constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &copy)
	: data(new T[copy.length]), length(copy.size())
{
	for (size_t i = 0; i < length; ++i)
		data[i] = copy.data[i];
	if (DEBUG)
		std::cout << "Array copy constructor called" << std::endl;
	*this = copy;
}

template <typename T>
T &Array<T>::operator[](size_t index)
{
	if (index >= length) {
		throw (std::out_of_range("Index out of bound"));
	}
	return data[index];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
	if (DEBUG)
		std::cout << "Array copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		// delete[] data;
		length = copy.length;
		data = new T[length];
		for (size_t i = 0; i < size(); ++i) {
			data[i] = copy.data[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array(void)
{
	delete data;
	if (DEBUG)
		std::cout << "Array destructor called" << std::endl;
}

template <typename T>
size_t	Array<T>::size(void) const
{
	return (length);
}

template <typename T>
void	Array<T>::setData(T data, size_t index)
{
	(*this)[index] = data;
}

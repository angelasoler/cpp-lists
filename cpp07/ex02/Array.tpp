
#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : data(new T), length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]), length(n) {}

template <typename T>
Array<T>::Array(const Array &copy)
{
	length = copy.length;
	data = new T[length];
	for (size_t i = 0; i < length; ++i)
		data[i] = copy.data[i];
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
	if (this != &copy)
	{
		delete data;
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
	delete[] data;
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

template <typename T>
void initMembers(Array<T> &A)
{
	for (size_t i = 0; i < A.size(); i++)
		A.setData(0, i);
}

template <typename T>
void printMembers(Array<T> &A)
{
	std::cout << "\t\t====== Print all members =====" << std::endl;
		try
		{
			for (size_t i = 0; i < A.size(); i++)
				std::cout << A[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
}


#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdint.h>

template <typename T>
class Array
{
	private:
		T		*data;
		size_t	length;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &copy);
		Array &operator=(const Array &copy);
		T &operator[](size_t i);
		~Array(void);
		size_t	size(void) const;
		void	printMembers(Array<T> &A);
		void	initMembers(T A);
};

#include "Array.tpp"

#endif /* ARRAY_HPP */

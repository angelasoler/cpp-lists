#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void printMember(T &member)
{
	std::cout << member << std::endl;
}

template <typename T, typename Func>
void iter(T *address, size_t length, Func fc)
{
	for (size_t i = 0; i < length; ++i) {
		fc(address[i]);
	}
}

#endif //ITER_HPP
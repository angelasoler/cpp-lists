
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void	easyfind(T cont, int toFind)
{
	std::vector<int>::iterator	it;

	it = std::find(cont.begin(), cont.end(), toFind);
	if (it != cont.end()) {
		std::cout << "Element " << toFind << 
				" found at position : ";
		std::cout << it - cont.begin() << 
					" (counting from zero) \n";
	}
	else
	{
		throw std::runtime_error("Item not found");
	}
}

#endif /* EASYFIND_HPP */

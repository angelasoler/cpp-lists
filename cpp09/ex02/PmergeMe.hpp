
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

class PmergeMe
{
	private:
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe(void);
};

template<typename Container>
void insertionSort(Container &cont) {
	if (cont.size() < 2)
		return ;
	typename Container::value_type tmp = cont[1];

	if (cont[0] > tmp) {
		cont[1] = cont[0];
		cont[0] = tmp;
	}
}

template<typename Container>
Container merge(const Container &left, const Container &right) {
	Container result;
	typename Container::size_type i = 0, j = 0;
	while (i < left.size() && j < right.size()) {
		if (left[i] < right[j]) {
			result.push_back(left[i]);
			++i;
		} else {
			result.push_back(right[j]);
			++j;
		}
	}
	while (i < left.size()) {
		result.push_back(left[i]);
		++i;
	}
	while (j < right.size()) {
		result.push_back(right[j]);
		++j;
	}
	return result;
}

template<typename Container>
Container fordJohnsonSort(const Container &elements) {
	if (elements.size() <= 1) {
		return elements;
	}

	typename Container::size_type subsetSize = 2;
	std::vector<Container> subsets;
	for (typename Container::size_type i = 0; i < elements.size(); i += subsetSize) {
		Container subset(elements.begin() + i, elements.begin() + std::min(i + subsetSize, elements.size()));
		insertionSort(subset);
		subsets.push_back(subset);
	}

	while (subsets.size() > 1) {
		std::vector<Container> newSubsets;
		for (typename std::vector<Container>::size_type i = 0; i < subsets.size(); i += subsetSize) {
			if (i + 1 < subsets.size())
				newSubsets.push_back(merge(subsets[i], subsets[i + 1]));
			else
				newSubsets.push_back(subsets[i]);
		}
		subsets = newSubsets;
	}
	return subsets[0];
}

#endif /* PMERGEME_HPP */

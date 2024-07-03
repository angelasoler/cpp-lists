
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

		// template <typename Container>
		// Container	fordJohnsonSort(const Container &arr);
};


// std::vector<int> fordJohnsonSort(const std::vector<int> &arr);

#endif /* PMERGEME_HPP */

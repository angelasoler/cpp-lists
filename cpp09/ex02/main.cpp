#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	std::vector<int>	vec;
	std::deque<int>		deque;
	std::vector<int>	sortedVec;
	std::deque<int>		sortedDeque;
	int					i = 1;

	while (i < argc) {
		vec.push_back(std::atoi(argv[i]));
		deque.push_back(std::atoi(argv[i]));
		i++;
	}

	std::clock_t start = std::clock();
	sortedVec = fordJohnsonSort(vec);
	std::clock_t end = std::clock();
	double	vecDuration = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	start = std::clock();
	sortedDeque = fordJohnsonSort(deque);
	end = std::clock();
	double	dequeDuration = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	std::vector<int>::iterator it;
	std::cout << "before: ";
	for (it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "After: ";
	for (it = sortedVec.begin(); it != sortedVec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << sortedVec.size() << " elements sorted from container "
			<< "vector: " << std::fixed << std::setprecision(6) << vecDuration << " sec\n" << std::endl;
	std::cout << sortedDeque.size() << " elements sorted from container "
			<< "deque: " << std::fixed << std::setprecision(6) << dequeDuration << " sec\n" << std::endl;
}

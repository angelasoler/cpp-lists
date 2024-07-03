#include "PmergeMe.hpp"

// Função para ordenar um contêiner utilizando o algoritmo de inserção
template<typename Container>
void insertionSort(Container& cont) {
	for (typename Container::size_type i = 1; i < cont.size(); ++i) {
		typename Container::value_type key = cont[i];
		typename Container::size_type j = i;
		while (j > 0 && cont[j - 1] > key) {
			cont[j] = cont[j - 1];
			--j;
		}
		cont[j] = key;
	}
}

// Função para intercalar dois contêineres ordenados
template<typename Container>
Container merge(const Container& left, const Container& right) {
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

// Função principal do Ford-Johnson
template<typename Container>
Container fordJohnsonSort(const Container& arr) {
	if (arr.size() <= 1) {
		return arr;
	}

	// Passo 1: Dividir o contêiner em pequenos subconjuntos
	typename Container::size_type subsetSize = 2; // Escolha de tamanho do subconjunto (pode ser ajustado)
	std::deque<Container> subsets;
	for (typename Container::size_type i = 0; i < arr.size(); i += subsetSize) {
		Container subset(arr.begin() + i, arr.begin() + std::min(i + subsetSize, arr.size()));
		insertionSort(subset);
		subsets.push_back(subset);
	}

	// Passo 2: Intercalar os subconjuntos ordenados
	while (subsets.size() > 1) {
		std::deque<Container> newSubsets;
		for (typename std::deque<Container>::size_type i = 0; i < subsets.size(); i += 2) {
			if (i + 1 < subsets.size()) {
				newSubsets.push_back(merge(subsets[i], subsets[i + 1]));
			} else {
				newSubsets.push_back(subsets[i]);
			}
		}
		subsets = newSubsets;
	}

	return subsets[0];
}

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
	std::vector<int>::iterator it;
	std::cout << "before: ";
	for (it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::clock_t start = std::clock();
	sortedVec = fordJohnsonSort(vec);
	std::clock_t end = std::clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "vector: " << std::fixed << std::setprecision(6) << duration << " sec" << std::endl;


	start = std::clock();
	sortedDeque = fordJohnsonSort(deque);
	end = std::clock();
	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "deque: " << std::fixed << std::setprecision(6) << duration << " sec" << std::endl;


	std::cout << "After: ";
	for (it = sortedVec.begin(); it != sortedVec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

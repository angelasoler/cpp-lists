
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
	}
	return *this;
}

PmergeMe::~PmergeMe(void) {}

// // Função para ordenar um contêiner utilizando o algoritmo de inserção
// template<typename Container>
// void insertionSort(Container& cont) {
// 	for (typename Container::size_type i = 1; i < cont.size(); ++i) {
// 		typename Container::value_type key = cont[i];
// 		typename Container::size_type j = i;
// 		while (j > 0 && cont[j - 1] > key) {
// 			cont[j] = cont[j - 1];
// 			--j;
// 		}
// 		cont[j] = key;
// 	}
// }

// // Função para intercalar dois contêineres ordenados
// template<typename Container>
// Container merge(const Container& left, const Container& right) {
// 	Container result;
// 	typename Container::size_type i = 0, j = 0;
// 	while (i < left.size() && j < right.size()) {
// 		if (left[i] < right[j]) {
// 			result.push_back(left[i]);
// 			++i;
// 		} else {
// 			result.push_back(right[j]);
// 			++j;
// 		}
// 	}
// 	while (i < left.size()) {
// 		result.push_back(left[i]);
// 		++i;
// 	}
// 	while (j < right.size()) {
// 		result.push_back(right[j]);
// 		++j;
// 	}
// 	return result;
// }

// // Função principal do Ford-Johnson
// template <typename Container>
// Container PmergeMe::fordJohnsonSort(const Container& arr) {
// 	if (arr.size() <= 1) {
// 		return arr;
// 	}

// 	// Passo 1: Dividir o contêiner em pequenos subconjuntos
// 	typename Container::size_type subsetSize = 2; // Escolha de tamanho do subconjunto (pode ser ajustado)
// 	std::vector<Container> subsets;
// 	for (typename Container::size_type i = 0; i < arr.size(); i += subsetSize) {
// 		Container subset(arr.begin() + i, arr.begin() + std::min(i + subsetSize, arr.size()));
// 		insertionSort(subset);
// 		subsets.push_back(subset);
// 	}

// 	// Passo 2: Intercalar os subconjuntos ordenados
// 	while (subsets.size() > 1) {
// 		std::vector<Container> newSubsets;
// 		for (typename std::vector<Container>::size_type i = 0; i < subsets.size(); i += 2) {
// 			if (i + 1 < subsets.size()) {
// 				newSubsets.push_back(merge(subsets[i], subsets[i + 1]));
// 			} else {
// 				newSubsets.push_back(subsets[i]);
// 			}
// 		}
// 		subsets = newSubsets;
// 	}

// 	return subsets[0];
// }

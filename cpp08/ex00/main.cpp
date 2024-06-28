#include "easyfind.hpp"
#include <vector>

int	main()
{
	int arr[] = {34, 6, 3, 6654, 854, 2, 46};
	std::vector<int> intCont(arr, arr + (sizeof(arr) / sizeof(arr[0])));

	try
	{
		easyfind(intCont, 6);
		easyfind(intCont, 46);
		easyfind(intCont, 34);
		easyfind(intCont, 855);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

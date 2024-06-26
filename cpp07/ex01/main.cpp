#include "iter.hpp"

int	main()
{
	int		array[] = {1, 2, 3, 4, 5};
	char	arraychar[] = {97, 98, 99, 100, 101};

	iter(array, 5 , static_cast<void(*)(int&)>(printMember));
	iter(arraychar, 5 , static_cast<void(*)(char&)>(printMember));
}

#include "tasks.hpp"

#include <iostream>
#include <algorithm>
#include <iterator>

#include "container.hpp"

void razukrantov::taskFactorial()
{
	razukrantov::Container container;
	std::copy(container.begin(), container.end(), std::ostream_iterator< size_t >(std::cout, " "));
	std::cout << "\n";
	std::reverse_copy(container.begin(), container.end(), std::ostream_iterator< size_t >(std::cout, " "));
	std::cout << "\n";
}

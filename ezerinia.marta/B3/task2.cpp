#include <algorithm>
#include <iostream>
#include "Container.hpp"

void task2()
{
  Container container;
  std::copy(container.begin(), container.end(), std::ostream_iterator< int >(std::cout, " "));
  std::cout << "\n";
  std::reverse_copy(container.begin(), container.end(), std::ostream_iterator< int >(std::cout, " "));
  std::cout << "\n";
}

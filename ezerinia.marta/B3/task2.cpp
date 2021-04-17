#include "task2.hpp"
#include <algorithm>
#include <iostream>
#include "Container.hpp"

namespace lab = ezerinia;

void lab::task2()
{
  Container container;
  std::copy(container.begin(), container.end(), std::ostream_iterator< int >(std::cout, " "));
  std::cout << "\n";
  std::reverse_copy(container.begin(), container.end(), std::ostream_iterator< int >(std::cout, " "));
  std::cout << "\n";
}

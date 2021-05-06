#include "task2.hpp"
#include <algorithm>
#include <iostream>
#include "Container.hpp"

namespace lab = ezerinia;

void lab::task2()
{
  std::ostream_iterator< unsigned int > out(std::cout, " ");
  Container container;
  std::copy(container.begin(), container.end(), out);
  std::cout << "\n";
  std::reverse_copy(container.begin(), container.end(), out);
  std::cout << "\n";
}

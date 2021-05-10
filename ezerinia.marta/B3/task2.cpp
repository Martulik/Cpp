#include "task2.hpp"
#include <algorithm>
#include <iostream>
#include "Container.hpp"

namespace lab = ezerinia;

void lab::task2(std::ostream &out)
{
  std::ostream_iterator< Container::value_type > output(out, " ");
  Container container;
  std::copy(container.begin(), container.end(), output);
  std::cout << "\n";
  std::reverse_copy(container.begin(), container.end(), output);
  std::cout << "\n";
}

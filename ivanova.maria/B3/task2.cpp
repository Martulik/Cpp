#include <algorithm>
#include <iostream>
#include "container.hpp"
#include "task2.hpp"

namespace iva = ivanova;

int iva::task2()
{
  Container container;
  std::copy(container.begin(), container.end(), std::ostream_iterator< size_t >(std::cout, " "));
  std::cout << '\n';
  std::reverse_copy(container.begin(), container.end(), std::ostream_iterator< size_t >(std::cout, " "));
  std::cout << '\n';
  return 0;
}

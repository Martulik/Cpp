#include "task2.hpp"
#include <algorithm>
#include <iostream>
#include "container.hpp"

void diurdeva::task2()
{
  std::ostream_iterator< int > out_iter(std::cout, " ");
  Container container;
  std::copy(container.begin(), container.end(), out_iter);
  std::cout << '\n';

  std::reverse_copy(container.begin(), container.end(), out_iter);
  std::cout << '\n';
}

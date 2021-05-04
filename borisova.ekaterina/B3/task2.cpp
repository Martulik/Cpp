#include "tasks.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>
#include "container.hpp"

namespace lab = borisova;

void lab::doTask2()
{
  Container cont;
  std::ostream_iterator< size_t > out(std::cout, " ");
  std::copy(cont.begin(), cont.end(), out);
  std::cout << "\n";
  std::reverse_copy(cont.begin(), cont.end(), out);
  std::cout << "\n";
}

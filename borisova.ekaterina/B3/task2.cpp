#include "tasks.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>
#include "container.hpp"

namespace lab = borisova;

void lab::doTask2(std::ostream& output)
{
  Container cont;
  output << *cont.end() << "\n";
  std::ostream_iterator< size_t > out(output, " ");
  std::copy(cont.begin(), cont.end(), out);
  output << "\n";
  std::reverse_copy(cont.begin(), cont.end(), out);
  output << "\n";
}

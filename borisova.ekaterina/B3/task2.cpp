#include "tasks.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>
#include "container.hpp"

namespace lab = borisova;

void lab::doTask2(std::ostream& output)
{
  Container cont;
  std::ostream_iterator< Container::unInt > out(output, " ");
  std::copy(cont.begin(), cont.end(), out);
  output << "\n";
  std::reverse_copy(cont.begin(), cont.end(), out);
  output << "\n";
}

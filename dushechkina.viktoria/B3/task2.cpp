#include "tasks.hpp"
#include <iostream>
#include <algorithm>
#include "factorial.hpp"

void dushechkina::task2(std::istream&, std::ostream& out)
{
  dushechkina::Container container;
  std::ostream_iterator< unsigned int > output(out, " ");

  std::copy(container.begin(), container.end(), output);
  out << "\n";

  std::reverse_copy(container.begin(), container.end(), output);
  out << "\n";
}

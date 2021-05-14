#include "tasks.hpp"
#include <iostream>
#include <algorithm>
#include "factorial.hpp"

void dushechkina::doSecondTask(std::istream&, std::ostream& out)
{
  dushechkina::Container container;
  std::ostream_iterator<unsigned int> output(out, " ");

  std::copy(container.begin(), container.end(), output);
  std::cout << "\n";

  std::reverse_copy(container.begin(), container.end(), output);
  std::cout << "\n";
}

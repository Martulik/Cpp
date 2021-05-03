#include "task-factorial.hpp"
#include <algorithm>
#include <iostream>
#include "factorial-container.hpp"

void shilyaev::taskFactorial()
{
  FactorialContainer container;
  std::ostream_iterator< unsigned int > ostreamIterator(std::cout, " ");
  std::copy(container.begin(), container.end(), ostreamIterator);
  std::cout << '\n';
  std::reverse_copy(container.begin(), container.end(), ostreamIterator);
  std::cout << '\n';
}

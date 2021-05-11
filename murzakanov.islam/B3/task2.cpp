#include "tasks.hpp"

#include <iostream>
#include <algorithm>
#include <iterator>

#include "factorial-container.hpp"

void murzakanov::task2(std::ostream& out)
{
  murzakanov::FactorialContainer factorial;
  std::copy(factorial.begin(), factorial.end(), std::ostream_iterator< size_t >(out, " "));
  out << "\n";
  std::reverse_copy(factorial.begin(), factorial.end(), std::ostream_iterator< size_t >(out, " "));
  out << "\n";
}

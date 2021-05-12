#include "tasks.hpp"

#include <iostream>
#include <algorithm>
#include <iterator>

#include "factorial-container.hpp"

void murzakanov::task2(std::ostream& out)
{
  using value_type = murzakanov::FactorialContainer::value_type;
  murzakanov::FactorialContainer factorial;
  std::copy(factorial.begin(), factorial.end(), std::ostream_iterator< value_type >(out, " "));
  out << "\n";
  std::reverse_copy(factorial.begin(), factorial.end(), std::ostream_iterator< value_type >(out, " "));
  out << "\n";
}

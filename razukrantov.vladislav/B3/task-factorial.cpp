#include "tasks.hpp"

#include <ostream>
#include <algorithm>
#include <iterator>

#include "container.hpp"

void razukrantov::taskFactorial(std::ostream& out)
{
  razukrantov::Container container;
  std::copy(container.begin(), container.end(), std::ostream_iterator< size_t >(out, " "));
  out << "\n";
  std::reverse_copy(container.begin(), container.end(), std::ostream_iterator< size_t >(out, " "));
  out << "\n";
}

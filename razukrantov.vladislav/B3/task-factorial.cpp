#include "tasks.hpp"

#include <ostream>
#include <algorithm>

#include "container.hpp"

void razukrantov::taskFactorial(std::ostream& out)
{
  using valueType = razukrantov::Container::valueType;
  razukrantov::Container container;
  std::copy(container.begin(), container.end(), std::ostream_iterator< valueType >(out, " "));
  out << "\n";
  std::reverse_copy(container.begin(), container.end(), std::ostream_iterator< valueType >(out, " "));
  out << "\n";
}

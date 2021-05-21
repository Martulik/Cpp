#include "tasks.hpp"
#include <algorithm>
#include <ostream>
#include "container.hpp"

void ferapontov::task2(std::ostream& out)
{
  Container it;
  std::copy(it.begin(), it.end(), std::ostream_iterator< Container::valueType >(out, " "));
  out << '\n';
  std::reverse_copy(it.begin(), it.end(), std::ostream_iterator< Container::valueType >(out, " "));
  out << '\n';
}

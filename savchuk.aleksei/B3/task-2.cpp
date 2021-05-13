#include "tasks.hpp"

#include <iterator>
#include <ostream>

#include "container.hpp"

namespace lab = savchuk;

void lab::task2(std::ostream& os)
{
  Container cnt;
  std::copy(cnt.begin(), cnt.end(), std::ostream_iterator< Container::valueType >(os, " "));
  os << '\n';
  std::reverse_copy(cnt.begin(), cnt.end(), std::ostream_iterator< Container::valueType >(os, " "));
  os << '\n';
}

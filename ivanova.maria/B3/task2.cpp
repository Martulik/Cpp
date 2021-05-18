#include "task2.hpp"

#include <iostream>
#include <algorithm>

#include "container.hpp"
namespace iva = ivanova;

int iva::task2(std::ostream &out)
{
  Container container;
  using iterator = std::ostream_iterator< Container::value_type >;
  std::copy(container.begin(), container.end(), iterator (out, " "));
  out << '\n';
  std::reverse_copy(container.begin(), container.end(), iterator (out, " "));
  out << '\n';
  return 0;
}

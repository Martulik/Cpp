#include "data-struct.hpp"
#include <iostream>

std::ostream& lebedeva::operator<<(std::ostream& out, const DataStruct& data)
{
  out << data.key1 << ',' << data.key2 << ',' << data.str << '\n';
  return out;
}

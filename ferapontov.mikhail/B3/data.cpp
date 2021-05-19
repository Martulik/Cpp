#include "data.hpp"
#include <ostream>

std::ostream& ferapontov::operator<<(std::ostream& out, const ferapontov::data_t& src)
{
  out << src.number << " " << src.name;
  return out;
}

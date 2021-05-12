#include "data.hpp"

std::ostream& operator<<(std::ostream& out, const ferapontov::data_t& src)
{
  out << src.name << " " << src.number;
  return out;
}

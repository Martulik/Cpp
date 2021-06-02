#include "line.hpp"
#include <iostream>

std::istream& lebedeva::operator>>(std::istream& is, Line& line)
{
  return std::getline(is, line.lineTemp);
}

std::ostream& lebedeva::operator<<(std::ostream& os, const Line& line)
{
  return os << line.lineTemp;
}

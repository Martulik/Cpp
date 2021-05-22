#include "shape.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

std::istream& murzakanov::operator >>(std::istream& in, murzakanov::Shape& shp)
{
  std::string line;
  while (!getline(in, line))
  {
    return in;
  }
  std::istringstream lin(line);
  size_t n = 0;
  lin >> n;
  std::istream_iterator< murzakanov::Point > firstIterator(lin);
  std::istream_iterator< murzakanov::Point > lastIterator;
  murzakanov::Shape tempShape(firstIterator, lastIterator);
  if (tempShape.size() != n)
  {
    in.setstate(std::ios_base::failbit);
  }
  shp = tempShape;
  return in;
}

std::ostream& murzakanov::operator<<(std::ostream& out, const murzakanov::Shape& shp)
{
  out << shp.size() << " ";
  for (size_t i = 0; i < shp.size(); i++)
  {
    out << shp[i];
  }
  return out;
}

#include "shape.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>

#include "tools.hpp"

std::istream& murzakanov::operator>>(std::istream& in, murzakanov::Shape& shp)
{
  std::string line;
  do
  {
    getline(in, line);
  } while (std::all_of(line.begin(), line.end(), ::isspace) && !in.eof());

  std::istringstream lin(line);
  size_t n = 0;
  lin >> n;
  if (!lin)
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
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

bool murzakanov::isTriangle(const Shape& shp)
{
  return shp.size() == 3;
}

bool murzakanov::isRectangle(const Shape& shp)
{
  if (shp.size() != 4)
  {
    return false;
  }
  std::vector< int > sides = calculateSides(shp);
  std::sort(sides.begin(), sides.end());
  if (sides[0] == sides[1] && sides[2] == sides[3] && sides[4] == sides[5] && sides[0] != sides[2])
  {
    return true;
  }
  return false;
}

bool murzakanov::isSquare(const Shape& shp)
{
  if (shp.size() != 4)
  {
    return false;
  }
  std::vector< int > sides = calculateSides(shp);
  std::sort(sides.begin(), sides.end());
  if (sides[0] == sides[1] && sides[2] == sides[3] && sides[4] == sides[5] && sides[0] == sides[2])
  {
    return true;
  }
  return false;
}

bool murzakanov::isPentagon(const Shape& shp)
{
  return shp.size() == 5;
}

bool murzakanov::operator<(const murzakanov::Shape& shp1, const murzakanov::Shape& shp2)
{
  if (shp1.size() > 4 && shp2.size() > 4)
  {
    return false;
  }
  if (shp1.size() == 4 && shp1.size() == shp2.size())
  {
    return isSquare(shp1);
  }
  return shp1.size() < shp2.size();
}

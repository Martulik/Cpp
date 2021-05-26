#include "shape.hpp"

#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include <array>

#include "tools.hpp"

std::istream& murzakanov::operator>>(std::istream& in, murzakanov::Shape& shp)
{
  size_t n = 0;
  in >> n;
  if (!in || in.get() != ' ')
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  murzakanov::Shape tempShape;
  tempShape.reserve(n);
  std::copy_n(std::istream_iterator< Point >(in), n, std::back_inserter(tempShape));
  if ((in.fail() && !in.eof()) || tempShape.size() != n)
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  shp = tempShape;
  return in;
}

std::ostream& murzakanov::operator<<(std::ostream& out, const murzakanov::Shape& shp)
{
  out << shp.size() << ' ';
  std::copy(shp.begin(), shp.end(), std::ostream_iterator< murzakanov::Point >(out, " "));
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
  std::array< int, 6 > sides = calculateSides(shp);
  std::sort(sides.begin(), sides.end());
  return (sides[0] == sides[1] && sides[2] == sides[3] && sides[4] == sides[5] && sides[0] != sides[2]);
}

bool murzakanov::isSquare(const Shape& shp)
{
  if (shp.size() != 4)
  {
    return false;
  }
  std::array< int, 6 > sides = calculateSides(shp);
  std::sort(sides.begin(), sides.end());
  return (sides[0] == sides[1] && sides[2] == sides[3] && sides[4] == sides[5] && sides[0] == sides[2]);
}

bool murzakanov::isPentagon(const Shape& shp)
{
  return shp.size() == 5;
}

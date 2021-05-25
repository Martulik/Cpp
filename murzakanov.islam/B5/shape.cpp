#include "shape.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <array>

#include "tools.hpp"

std::istream& murzakanov::operator>>(std::istream& in, murzakanov::Shape& shp)
{
  size_t n = 0;
  in >> n;
  if (!in || in.peek() != ' ')
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  if (!in)
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  murzakanov::Shape tempShape;
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
  std::array< int, 6 > sides = calculateSides(shp);
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
  std::array< int, 6 > sides = calculateSides(shp);
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

int murzakanov::readNumber(std::string& buff, char delim, std::istream& in)
{
  std::string num;
  std::string::iterator it = buff.begin();
  while (*it != delim)
  {
    if (it == buff.end())
    {
      in.setstate(std::ios::failbit);
      return 0;
    }
    num += *it;
    buff.erase(it);
  }
  buff.erase(0, 1);
  if (!std::all_of(num.begin(), num.end(), ::isdigit))
  {
    in.setstate(std::ios::failbit);
    return 0;
  }
  int number = std::stoi(num);
  return number;
}
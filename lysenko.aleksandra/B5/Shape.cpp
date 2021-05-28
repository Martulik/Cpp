#include "Shape.h"

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

std::ostream& lysenko::operator<<(std::ostream& out, const lysenko::point_t& point)
{
  out << '(' << point.x << ';' << point.y << ')';
  return out;
}

std::istream& lysenko::operator>>(std::istream& in, lysenko::point_t& point)
{
  in >> std::ws;
  char delimiter;
  int number;
  in >> delimiter;
  if ((in.fail()) || (delimiter != '('))
  {
    throw std::invalid_argument("Incorrect format point");
  }
  in >> number;
  if (in.fail())
  {
    throw std::invalid_argument("Incorrect format point");
  }
  point.x = number;
  in >> delimiter;
  if ((in.fail()) || (delimiter != ';'))
  {
    throw std::invalid_argument("Incorrect format point");
  }
  in >> number;
  if (in.fail())
  {
    throw std::invalid_argument("Incorrect format point");
  }
  point.y = number;
  in >> delimiter;
  if ((in.fail()) || (delimiter != ')'))
  {
    throw std::invalid_argument("Incorrect format point");
  }
  return in;
}

namespace lysenko
{
  std::istream& operator>>(std::istream& in, lysenko::Shape& Shape)
  {
    size_t numberOfVerticles;
    in >> numberOfVerticles;

    if (in.fail())
    {
      throw std::invalid_argument("Incorrect format of number of verticles");
    }

    if (numberOfVerticles == 0)
    {
      throw std::invalid_argument("Incorrect number of verticles");
    }

    std::vector< lysenko::point_t > verticles;
    std::copy_n(std::istream_iterator< point_t >(in), numberOfVerticles, std::back_inserter(verticles));

    if (!(in.eof()))
    {
      throw std::invalid_argument("Too many points for figure");
    }

    std::swap(Shape.verticles_, verticles);
  }
}

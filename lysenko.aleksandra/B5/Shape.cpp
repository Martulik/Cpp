#include "Shape.h"

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

namespace lysenko
{
  void checkCorrectDelimiter(std::istream& in, const char& expected)
  {
    char delimiter;
    in >> delimiter;
    if ((in.fail()) || (delimiter != expected))
    {
      throw std::invalid_argument("Incorrect format point");
    }
  }
}

std::istream& lysenko::operator>>(std::istream& in, lysenko::Shape& Shape)
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

  std::vector< lysenko::Point > verticles;
  std::copy_n(std::istream_iterator< Point >(in), numberOfVerticles, std::back_inserter(verticles));

  std::swap(Shape, verticles);
  return in;
}

std::ostream& lysenko::operator<<(std::ostream& out, const lysenko::Point& point)
{
  out << '(' << point.x << ';' << point.y << ')';
  return out;
}

std::istream& lysenko::operator>>(std::istream& in, lysenko::Point& point)
{
  in >> std::ws;
  int number;

  checkCorrectDelimiter(in, '(');

  in >> number;
  if (in.fail())
  {
    throw std::invalid_argument("Incorrect format point");
  }
  point.x = number;

  checkCorrectDelimiter(in, ';');

  in >> number;
  if (in.fail())
  {
    throw std::invalid_argument("Incorrect format point");
  }
  point.y = number;

  checkCorrectDelimiter(in, ')');

  return in;
}

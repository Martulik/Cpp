#include "Shape.h"

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>

namespace lysenko
{
  std::istream& checkCorrectDelimiter(std::istream& in, const char& expected)
  {
    char delimiter;
    in >> delimiter;
    if ((in.fail()) || (delimiter != expected))
    {
      throw std::invalid_argument("Incorrect format point");
    }
    return in;
  }
}

std::istream& lysenko::operator>>(std::istream& in, lysenko::Shape& Shape)
{
  std::string numberOfVerticles;

  in >> std::ws;
  getline(in,numberOfVerticles,' ');

  if (numberOfVerticles.empty())
  {
    return in;
  }

  int realNumber = std::stoi(numberOfVerticles);
  if (realNumber == 0)
  {
    throw std::invalid_argument("Incorrect number of verticles");
  }

  std::vector< lysenko::Point > verticles;
  std::copy_n(std::istream_iterator< Point >(in), realNumber, std::back_inserter(verticles));

  std::swap(Shape, verticles);
  return in;
}

std::ostream& lysenko::operator<<(std::ostream& out, const lysenko::Point& point)
{
  out << '(' << point.x << "; " << point.y << ')';
  return out;
}
std::ostream& lysenko::operator<<(std::ostream& out, const Shape& Shape)
{
  out << Shape.size() << " ";
  std::copy(Shape.begin(), Shape.end(), std::ostream_iterator< lysenko::Point >(out, " "));
  return out;
}

std::istream& lysenko::operator>>(std::istream& in, lysenko::Point& point)
{
  int number;

  checkCorrectDelimiter(in, '(');

  in >> number;
  if (in.fail())
  {
    throw std::invalid_argument("Incorrect format point");
  }
  point.x = number;

  in >> std::ws;
  checkCorrectDelimiter(in, ';');

  in >> std::ws;
  in >> number;
  if (in.fail())
  {
    throw std::invalid_argument("Incorrect format point");
  }
  point.y = number;

  in >> std::ws;
  checkCorrectDelimiter(in, ')');

  return in;
}

bool lysenko::operator<(const Point& point1, const Point& point2)
{
  if (point1.y <= point2.y)
  {
    return (point1.x < point2.y);
  }
  return 0;
}

bool lysenko::operator==(const Point& point1, const Point& point2)
{
  return (!((point1 < point2) || (point2 < point1)));
}

#include "point.hpp"

#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include <cmath>

const char OPEN = '(';
const char SEMICOLON = ';';
const char CLOSE = ')';

std::istream& dushechkina::operator>>(std::istream& in, Point& point)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    throw std::invalid_argument("Empty input\n");
    return in;
  }
  in >> std::ws;
  if (in.eof())
  {
    return in;
  }
  char sign;
  in >> sign;
  if (sign != OPEN)
  {
    throw std::invalid_argument("Invalid first literal\n");
  }
  if (!(in >> point.x))
  {
    throw std::invalid_argument("Invalid coordinate X\n");
  }
  in >> sign;
  if (sign != SEMICOLON)
  {
    throw std::invalid_argument("Invalid separate\n");
  }
  if (!(in >> point.y))
  {
    throw std::invalid_argument("Invalid coordinate Y\n");
  }
  in >> sign;
  if (sign != CLOSE)
  {
    throw std::invalid_argument("Invalid last literal\n");
  }
  return in;
}

std::ostream& dushechkina::operator<<(std::ostream& out, const Point& point)
{
  out << OPEN << point.x << SEMICOLON << point.y << CLOSE;
  return out;
}
int dushechkina::getDistance(const Point& begin, const Point& end)
{
  int x = end.x - begin.x;
  int y = end.y - begin.y;
  return (x * x + y * y);
}

bool dushechkina::isTriangle(const Shape& shape)
{
  return shape.size() == 3;
}

bool dushechkina::isRectangle(const Shape& shape)
{
  return shape.size() == 4;
}

bool dushechkina::isPentagon(const Shape& shape)
{
  return shape.size() == 5;
}

bool dushechkina::isSquare(const Shape& shape)
{
  int side1 = getDistance(shape[0], shape[1]);
  int side2 = getDistance(shape[1], shape[2]);
  int side3 = getDistance(shape[2], shape[3]);
  int side4 = getDistance(shape[3], shape[0]);
  return (side1 == side2) && (side1 == side3) && (side1 == side4);
}

int dushechkina::summarizeVertices(int vertices, const Shape& shape)
{
  return vertices + shape.size();
}

dushechkina::Point dushechkina::getFront(const Shape& shape)
{
  return shape.front();
}

std::istream& dushechkina::operator>>(std::istream& in, Shape& shape)
{
  size_t peaks;
  if (!(in >> peaks))
  {
    return in;
  }
  if (peaks <= 2)
  {
    throw std::invalid_argument("Invalid figure\n");
  }
  Shape temp;
  temp.reserve(peaks);
  std::copy_n(std::istream_iterator< Point >(in), peaks, std::back_inserter(temp));
  if ((in.fail() && !in.eof()) || temp.size() != peaks)
  {
    throw std::invalid_argument("Invalid number of peaks");
  }
  shape = temp;
  return in;
}

std::ostream& dushechkina::operator<<(std::ostream& out, const Shape& shape)
{
  out << shape.size() << ' ';
  std::copy(shape.begin(), shape.end(), std::ostream_iterator< Point >(out, " "));
  return out;
}

bool dushechkina::operator<(const Shape& first, const Shape& second)
{
  if (first.size() > 4 && second.size() > 4)
  {
    return false;
  }
  if ((first.size() == second.size()) && (first.size() == 4))
  {
    return isSquare(first) && !isSquare(second);
  }
  return first.size() < second.size();
}


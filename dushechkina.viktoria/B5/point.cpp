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
  std::istream::sentry inp(in);
  if (!inp)
  {
    throw std::invalid_argument("Empty input");
    return in;
  }
  in >> std::ws;
  if (in.eof())
  {
    return in;
  }
  char character;
  in >> character;
  if (character != OPEN)
  {
    throw std::invalid_argument("Invalid first character. It must be open bracket");
  }
  if (!(in >> point.x))
  {
    throw std::invalid_argument("Invalid point");
  }
  in >> character;
  if (character != SEMICOLON)
  {
    throw std::invalid_argument("Invalid separate character. It must be semicolon");
  }
  if (!(in >> point.y))
  {
    throw std::invalid_argument("Invalid point");
  }
  in >> character;
  if (character != CLOSE)
  {
    throw std::invalid_argument("Invalid last character. It must be close bracket");
  }
  return in;
}

std::ostream& dushechkina::operator<<(std::ostream& out, const Point& point)
{
  return out << OPEN << point.x << SEMICOLON << point.y << CLOSE;
}

int dushechkina::compareSide(const Shape& shape)
{
  return getDistanceSquare(shape[0], shape[1]) == getDistanceSquare(shape[1], shape[2]);
}

int dushechkina::getDistanceSquare(const Point& first, const Point& second)
{
  return std::pow(first.x - second.x, 2) + std::pow(first.y - second.y, 2);
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
  return isRectangle(shape) && compareSide(shape);
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
  size_t vertices;
  if (!(in >> vertices))
  {
    return in;
  }

  if (vertices <= 2)
  {
    throw std::invalid_argument("Figure does not exist");
  }

  Shape shape1;
  shape1.reserve(vertices);
  std::copy_n(std::istream_iterator< Point >(in), vertices, std::back_inserter(shape1));
  if (shape1.size() != vertices || (in.fail() && !in.eof()))
  {
    throw std::invalid_argument("Wrong number of shape vertices");
  }
  shape = shape1;

  return in;
}

std::ostream& dushechkina::operator<<(std::ostream& out, const Shape& shape)
{
  out << shape.size() << ' ';
  std::copy(shape.begin(), shape.end(), std::ostream_iterator< Point >(out, " "));
  return out;
}

bool dushechkina::operator<(const Shape& begin, const Shape& end)
{
  if ((begin.size() == 4) && (begin.size() == end.size()))
  {
    return isSquare(begin) && !isSquare(end);
  }
  else if (begin.size() > 4 && end.size() > 4)
  {
    return false;
  }

  return begin.size() < end.size();
}

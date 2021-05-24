#include "shape.hpp"

#include <iostream>
#include <stdexcept>

#include "functions.hpp"

std::ostream& pochernin::operator<<(std::ostream& out, const Point& point)
{
  out << "(" << point.x << "; " << point.y << ")";
  return out;
}

std::istream& pochernin::operator>>(std::istream& in, Point& point)
{
  std::string buffer;
  std::getline(in, buffer, '(');
  if (buffer.back() == '\n')
  {
    throw(std::invalid_argument("Incorrect point reading"));
  }

  std::getline(in, buffer, ';');
  if (buffer.back() == '\n')
  {
    throw(std::invalid_argument("Incorrect point reading"));
  }
  int x = 0;
  if (isNumber(buffer))
  {
    x = std::stoi(buffer);
  }
  else
  {
    throw(std::invalid_argument("Incorrect point reading"));
  }

  in >> std::ws;
  std::getline(in, buffer, ')');
  if (buffer.back() == '\n')
  {
    throw(std::invalid_argument("Incorrect point reading"));
  }
  int y = 0;
    if (isNumber(buffer))
  {
    y = std::stoi(buffer);
  }
  else
  {
    throw(std::invalid_argument("Incorrect point reading"));
  }

  point.x = x;
  point.y = y;

  return in;
}

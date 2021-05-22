#include "point.hpp"

#include <iostream>

namespace lab = savchuk;

std::istream& lab::operator>>(std::istream& is, Point& point)
{
  std::istream::sentry sentry(is);
  if (sentry)
  {
    int x, y;
    readDelimiter(is, '(');
    is >> std::ws >> x;
    readDelimiter(is, ';');
    is >> std::ws >> y;
    readDelimiter(is, ')');
    if (is)
    {
      point = { x, y };
    }
  }
  return is;
}

std::ostream& lab::operator<<(std::ostream& os, const Point& point)
{
  std::ostream::sentry sentry(os);
  if (sentry)
  {
    os << '(' << point.x << "; " << point.y << ')';
  }
  return os;
}

void lab::readDelimiter(std::istream& is, char delim)
{
  is >> std::ws;
  if (is.peek() != delim)
  {
    is.setstate(std::ios::failbit);
    return;
  }
  is.get();
}

#include "point.hpp"

#include <iostream>
#include <cctype>

namespace lab = savchuk;

std::istream& lab::operator>>(std::istream& is, Point& point)
{
  std::istream::sentry sentry(is);
  if (sentry)
  {
    int x, y;
    readDelimiter(is, '(');
    is >> skipws >> x;
    readDelimiter(is, ';');
    is >> skipws >> y;
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
  if (is >> skipws)
  {
    if (is.peek() != delim)
    {
      is.setstate(std::ios::failbit);
      return;
    }
    is.get();
  }
}

std::istream& lab::skipws(std::istream& is)
{
  if (is)
  {
    char ch = is.peek();
    while (isspace(ch))
    {
      if (ch == '\n')
      {
        is.setstate(std::ios::failbit);
        break;
      }
      is.get();
      ch = is.peek();
    }
  }
  return is;
}

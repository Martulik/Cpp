#include "point.hpp"
#include <iostream>

std::istream& ferapontov::operator>>(std::istream& in, Point& point)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    in >> std::ws;
    checkNextSymbol(in, '(');
    int x = 0;
    if (in)
    {
      in >> std::ws >> x;
    }
    else
    {
      return in;
    }
    checkNextSymbol(in, ';');
    int y = 0;
    if (in)
    {
      in >> std::ws >> y;
    }
    else
    {
      return in;
    }
    checkNextSymbol(in, ')');
    if (in)
    {
      point= {x, y};
    }
  }
  return in;
}

std::ostream& ferapontov::operator<<(std::ostream& out, const Point& point)
{
  std::ostream::sentry sentry(out);
  if(sentry)
  {
    return out << '(' << point.x << ';' << point.y << ')';
  }
  return out;
}

std::istream& ferapontov::checkNextSymbol(std::istream& in, const char& delim)
{
  char a = in.get();
  if (a != delim || a == '\n')
  {
    in.setstate(std::ios::badbit);
  }
  return in;
}

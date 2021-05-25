#include "point.hpp"

#include <iostream>

std::ostream& murzakanov::operator<<(std::ostream& out, const murzakanov::Point& point)
{
  out << '(' << point.x << ';' << point.y << ')';
  return out;
}

std::istream& murzakanov::operator>>(std::istream& in, Point& point)
{
  int x = 0;
  int y = 0;
  in >> std::ws;
  if (in.get() != '(')
  {
    in.clear();
    in.setstate(std::ios_base::failbit);
    return in;
  }
  in >> std::ws >> x >> std::ws;
  if (!in || in.get() != ';')
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  in >> std::ws >> y >> std::ws;
  if (!in || in.get() != ')')
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  point = {x, y};
  return in;
}

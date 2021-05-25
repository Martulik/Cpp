#include "point.hpp"
#include <iostream>

std::ostream& murzakanov::operator<<(std::ostream& out, const murzakanov::Point& point)
{
  out << '(' << point.x << ';' << point.y << ')' << ' ';
  return out;
}

std::istream& murzakanov::operator>>(std::istream& in, Point& point)
{
  in >> std::ws;
  if (in.get() != '(')
  {
    in.clear();
    in.setstate(std::ios_base::failbit);
    return in;
  }
  in >> std::ws >> point.x >> std::ws;
  if (!in || in.get() != ';')
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  in >> std::ws >> point.y >> std::ws;
  if (!in || in.get() != ')')
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  return in;
}

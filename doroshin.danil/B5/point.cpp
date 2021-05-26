#include "point.hpp"
#include <iostream>
#include "istream-fail.hpp"

namespace dan = doroshin;

std::istream& dan::operator>>(std::istream& in, Point& p)
{
  in >> std::ws;
  if(!in || in.get() != '(') {
    return dan::fail(in);
  }
  in >> std::ws >> p.x >> std::ws;
  if(!in || in.get() != ';') {
    return dan::fail(in);
  }
  in >> std::ws >> p.y >> std::ws;
  if(!in || in.get() != ')') {
    return dan::fail(in);
  }
  return in;
}

std::ostream& dan::operator<<(std::ostream& out, const Point& p)
{
  out << '(' << p.x << ';' << p.y << ')';
  return out;
}


bool dan::operator==(const Point& lhs, const Point& rhs)
{
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

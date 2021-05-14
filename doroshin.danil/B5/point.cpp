#include "point.hpp"
#include <iostream>

namespace dan = doroshin;

std::istream& dan::operator>>(std::istream& in, Point& p)
{
  const auto fail = [&]() {
    in.setstate(in.rdstate() | std::ios::failbit);
  };

  in >> std::ws;
  if(!in || in.get() != '(') {
    fail();
    return in;
  }
  in >> p.x;
  if(!in || in.get() != ';') {
    fail();
    return in;
  }
  in >> p.y;
  if(!in || in.get() != ')') {
    fail();
    return in;
  }
  return in;
}

std::ostream& dan::operator<<(std::ostream& out, const Point& p)
{
  out << '(' << p.x << ';' << p.y << ')';
  return out;
}

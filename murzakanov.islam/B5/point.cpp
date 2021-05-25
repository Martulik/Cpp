#include "point.hpp"

#include <iostream>

#include "tools.hpp"

std::ostream& murzakanov::operator<<(std::ostream& out, const murzakanov::Point& point)
{
  out << '(' << point.x << ';' << point.y << ')';
  return out;
}

std::istream& murzakanov::operator>>(std::istream& in, Point& point)
{
  int x = 0;
  int y = 0;
  in >> murzakanov::myWs;
  if (in.get() != '(')
  {
    in.clear();
    in.setstate(std::ios_base::failbit);
    return in;
  }
  in >> murzakanov::myWs;
  if (in.peek() == '\n')
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  in >> x >> murzakanov::myWs;
  if (!in || in.get() != ';')
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  in >> murzakanov::myWs;
  if (in.peek() == '\n')
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  in >> y >> murzakanov::myWs;
  if (!in || in.get() != ')')
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  point = {x, y};
  return in;
}

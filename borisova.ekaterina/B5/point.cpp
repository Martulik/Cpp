#include "point.hpp"
#include <iostream>

namespace lab = borisova;

int lab::getSquareDistance(const Point& first, const Point& second)
{
  int sqrDx = (first.x - second.x) * (first.x - second.x);
  int sqrDy = (first.y - second.y) * (first.y - second.y);
  return (sqrDx + sqrDy);
}

std::istream& lab::operator>>(std::istream& in, Point& point)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    throw std::invalid_argument("Empty input\n");
    return in;
  }
  in >> std::ws;
  if (in.eof())
  {
    return in;
  }
  char sign;
  in >> sign;
  if (sign != '(')
  {
    throw std::invalid_argument("Invalid first literal\n");
  }
  if (!(in >> point.x))
  {
    throw std::invalid_argument("Invalid coordinate X\n");
  }
  in >> sign;
  if (sign != ';')
  {
    throw std::invalid_argument("Invalid separate\n");
  }
  if (!(in >> point.y))
  {
    throw std::invalid_argument("Invalid coordinate Y\n");
  }
  in >> sign;
  if (sign != ')')
  {
    throw std::invalid_argument("Invalid last literal\n");
  }
  return in;
}

std::ostream& lab::operator<<(std::ostream& out, const Point& point)
{
  out << '(' << point.x << "; " << point.y << ')';
  return out;
}

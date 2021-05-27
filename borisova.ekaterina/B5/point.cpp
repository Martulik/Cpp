#include "point.hpp"
#include <iostream>

namespace lab = borisova;

double lab::getSquareDistance(const Point& first, const Point& second)
{
  double sqrDx = (first.x - second.x) * (first.x - second.x);
  double sqrDy = (first.y - second.y) * (first.y - second.y);
  return (sqrDx + sqrDy);
}

bool lab::isPerpendicularity(const Point& one, const Point& two, const Point three)
{
  int dx = (one.x - two.x) * (three.x - two.x);
  int dy = (one.y - two.y) * (three.y - two.y);
  return (dx + dy) == 0;
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

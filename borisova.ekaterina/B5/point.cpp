#include "point.hpp"
#include <iostream>
#include <cmath>

namespace lab = borisova;

double lab::getDistance(const Point& first, const Point& second)
{
  int sqrDx = (first.x - second.x) * (first.x - second.x);
  int sqrDy = (first.y - second.y) * (first.y - second.y);
  return std::sqrt(sqrDx + sqrDy);
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
  if (in.get() != '(')
  {
    throw std::invalid_argument("Invalid first literal\n");
  }
  in >> std::ws >> point.x >> std::ws;
  if (in.fail())
  {
    throw std::invalid_argument("Invalid coordinate X\n");
  }
  if (in.get() != ';')
  {
    throw std::invalid_argument("Invalid separate\n");
  }
  in >> std::ws >> point.y >> std::ws;
  if (in.fail())
  {
    throw std::invalid_argument("Invalid coordinate Y\n");
  }
  if (in.get() != ')')
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

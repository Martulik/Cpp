#include "point.hpp"
#include <iostream>
#include <sstream>
#include<cmath>

namespace lab = borisova;

double lab::getDistance(const Point& first, const Point& second)
{
  return std::sqrt((first.x - second.x) * (first.x - second.x) +
    (first.y - second.y) * (first.y - second.y));
}

bool lab::isPerpendicularity(const Point& one, const Point& two, const Point three)
{
  return ((one.x - two.x) * (three.x - two.x)
    + (one.y - two.y) * (three.y - two.y)) == 0;
}

std::istream& lab::operator>>(std::istream& in, Point& point)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return in;
  }
  std::string line;
  std::getline(in, line, '(');
  if (in.eof())
  {
    return in;
  }
  if (!std::getline(in, line, ')'))
  {
    throw std::invalid_argument("Empty input\n");
  }
  std::istringstream input(line);
  input >> point.x;
  if (input.fail())
  {
    throw std::invalid_argument("Invalid coordinate X\n");
  }
  char sign;
  input >> sign;
  if (sign != ';')
  {
    throw std::invalid_argument("Invalid separate\n");
  }
  input >> point.y;
  if (input.fail())
  {
    throw std::invalid_argument("Invalid coordinate Y\n");
  }
  return in;
}

std::ostream& lab::operator<<(std::ostream& out, const Point& point)
{
  out << '(' << point.x << "; " << point.y << ')';
  return out;
}

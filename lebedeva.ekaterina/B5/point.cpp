#include "point.hpp"
#include <iostream>
#include <string>

std::istream& lebedeva::operator>>(std::istream& in, Point& point)
{
  int temp = 0;
  char delimiter = 0;

  in >> std::ws >> delimiter;
  if (delimiter == '(')
  {
    in >> std::ws >> temp;
    if (in.fail())
    {
      throw std::invalid_argument("Invalid abscissa coordinate");
    }
    point.x = temp;
    in >> std::ws >> delimiter;
    if (delimiter == ';')
    {
      in >> std::ws >> temp;
      if (in.fail())
      {
        throw std::invalid_argument("Invalid ordinate coordinate");
      }
      point.y = temp;
      in >> std::ws >> delimiter;
      if (delimiter != ')')
      {
        throw std::invalid_argument("Invalid point format");
      }
    }
    else
    {
      throw std::invalid_argument("Invalid point format");
    }
  }
  else
  {
    throw std::invalid_argument("Invalid point format");
  }
  return in;
}

std::ostream& lebedeva::operator<<(std::ostream& out, const Point& point)
{
  out << '(' << point.x << "; " << point.y << ')';
  return out;
}

lebedeva::Point lebedeva::operator+(const Point lhs, const Point rhs)
{
  return { lhs.x + rhs.x, lhs.y + rhs.y };
}

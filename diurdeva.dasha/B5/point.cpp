#include "point.hpp"
#include <sstream>

const char OPEN_BRACKET = '(';
const char CLOSE_BRACKET = ')';
const char SEMICOLON = ';';

std::istream& diurdeva::operator>>(std::istream& in, Point& point)
{
  in >> std::ws;
  if (!in || in.get() != '(')
  {
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

std::ostream& diurdeva::operator<<(std::ostream& out, const Point& point)
{
  return out << OPEN_BRACKET << point.x << SEMICOLON << " " << point.y << CLOSE_BRACKET;
}

int diurdeva::squareDistance(const Point& point1, const Point& point2)
{
  return (point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y);
}

#include "point.hpp"

std::ostream& murzakanov::operator<<(std::ostream& out, const murzakanov::Point& point)
{
  out << '(' << point.x << ';' << point.y << ')' << ' ';
  return out;
}

std::istream& murzakanov::operator>>(std::istream& in, Point& point)
{
  char bracketOpen = '(';
  char semicolon = ';';
  char bracketClose = ')';
  in >> bracketOpen >> point.x >> semicolon >> point.y >> bracketClose;
  if (!in || bracketOpen != '(' || bracketClose != ')' || semicolon != ';')
  {
    in.setstate(std::ios_base::failbit);
  }
  return in;
}

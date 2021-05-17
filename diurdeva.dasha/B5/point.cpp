#include "point.hpp"
#include <sstream>

const char OPEN_BRACKET = '(';
const char CLOSE_BRACKET = ')';
const char SEMICOLON = ';';

std::istream& diurdeva::operator>>(std::istream& in, Point& point)
{
  try {
    std::string str;
    std::getline(in, str, OPEN_BRACKET);
    std::getline(in, str, SEMICOLON);
    point.x = std::stoi(str);
    std::getline(in, str, CLOSE_BRACKET);
    point.y = std::stoi(str);
  }
  catch (const std::invalid_argument&) {
    in.setstate(std::ios::failbit);
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

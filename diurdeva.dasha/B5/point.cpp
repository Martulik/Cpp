#include "point.hpp"
#include <sstream>

const char OPEN_BRACKET = '(';
const char CLOSE_BRACKET = ')';
const char SEMICOLON = ';';

std::istream& diurdeva::operator>>(std::istream& in, Point& point)
{
  try {
    std::string str;
    std::getline(in, line, OPEN_BRACKET);
    if (line.find('\n') != std::string::npos) {
      throw std::invalid_argument("Read point fail");
    }
    std::getline(in, line, CLOSE_BRACKET);
    if (line.find(SEMICOLON) == std::string::npos) {
      throw std::invalid_argument("Not found semicolon");
    }
    std::string str_point_x = line.substr(0, line.find(SEMICOLON));
    point.x = std::stoi(str_point_x);
    std::string str_point_y = line.substr(line.find(SEMICOLON) + 1);
    point.y = std::stoi(str_point_y);
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

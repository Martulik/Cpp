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
    if (str.find('\n') != std::string::npos) {
      throw std::invalid_argument("Read point fail");
    }
    std::getline(in, str, CLOSE_BRACKET);
    if (str.find(SEMICOLON) == std::string::npos) {
      throw std::invalid_argument("Not found semicolon");
    }
    std::string x = str.substr(0, str.find(SEMICOLON));
    point.x = std::stoi(x);
    std::string y = str.substr(str.find(SEMICOLON) + 1);
    point.y = std::stoi(y);
  }
  catch (const std::invalid_argument &fail) {
    throw fail;
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

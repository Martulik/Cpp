#include "point.hpp"
#include <sstream>

constexpr char OPEN = '(';
constexpr char SEMICOLON = ';';
constexpr char CLOSE = ')';

std::istream& dushechkina::operator>>(std::istream& in, Point& point)
{
  std::string str;
  std::getline(in, str, OPEN);
  if (str.find('\n') != std::string::npos)
  {
    throw std::invalid_argument("Invalid data reading");
  }
  std::getline(in, str, SEMICOLON);
  if (str.find('\n') != std::string::npos)
  {
    throw std::invalid_argument("Invalid data reading");
  }
  int x = std::stoi(str);
  std::getline(in, str, CLOSE);
  if (str.find('\n') != std::string::npos)
  {
    throw std::invalid_argument("Invalid data reading");
  }
  int y = std::stoi(str);
  point = { x, y };
  return in;
}

std::ostream& dushechkina::operator<<(std::ostream& out, const Point& point)
{
  out << OPEN << point.x << SEMICOLON << point.y << CLOSE;
  return out;
}

bool dushechkina::isTriangle(const Shape& shape)
{
  return shape.size() == 3;
}

bool dushechkina::isRectangle(const Shape& shape)
{
  return shape.size() == 4;
}

bool dushechkina::isPentagon(const Shape& shape)
{
  return shape.size() == 5;
}

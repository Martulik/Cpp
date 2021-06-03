#include "point.hpp"

#include <sstream>
#include <cmath>

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
int dushechkina::getDistance(const Point& begin, const Point& end)
{
  return (pow((end.x - begin.x), 2) + pow(end.y - begin.y, 2));
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

bool dushechkina::isSquare(const Shape& shape)
{
  int side1 = getDistance(shape[0], shape[1]);
  int side2 = getDistance(shape[1], shape[2]);
  int side3 = getDistance(shape[2], shape[3]);
  int side4 = getDistance(shape[3], shape[0]);
  return (side1 == side2) && (side2 == side3) && (side3 == side4) && (side1 == side4);
}

#include "point.hpp"

#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include <cmath>

const char OPEN = '(';
const char SEMICOLON = ';';
const char CLOSE = ')';

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
  int AB = getDistance(shape[0], shape[1]);
  int BC = getDistance(shape[1], shape[2]);
  int CD = getDistance(shape[2], shape[3]);
  int AD = getDistance(shape[3], shape[0]);

  return (AB == BC) && (BC == CD) && (CD == AD) && (AB == AD);
}

int dushechkina::summarizeVertices(int vertices, const Shape& shape)
{
  return vertices + shape.size();
}

dushechkina::Point dushechkina::getFront(const Shape& shape)
{
  return shape.front();
}

std::istream& dushechkina::operator>>(std::istream& in, Shape& shape)
{
  size_t n = 0;
  if (!(in >> n))
  {
    return in;
  }

  if (n <= 2)
  {
    throw std::invalid_argument("Invalid figure input");
  }

  Shape tempShape;
  tempShape.reserve(n);
  std::copy_n(std::istream_iterator< Point >(in), n, std::back_inserter(tempShape));

  if (tempShape.size() != n || (in.fail() && !in.eof()))
  {
    throw std::invalid_argument("Invalid number of shape vertices");
  }

  shape = tempShape;
  return in;
}

std::ostream& dushechkina::operator<<(std::ostream& out, const Shape& shape)
{
  out << shape.size() << ' ';
  std::copy(shape.begin(), shape.end(), std::ostream_iterator< Point >(out, " "));
  return out;
}

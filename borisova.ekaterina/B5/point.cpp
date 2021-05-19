#include "point.hpp"
#include <iostream>
#include <sstream>

namespace lab = borisova;

double lab::getDistance(const Point& first, const Point& second)
{
  return std::sqrt((first.x - second.x) * (first.x - second.x) +
    (first.y - second.y) * (first.y - second.y));
}

std::istream& lab::operator>>(std::istream& in, Point& point)
{
  char sign;
  std::string line;
  std::getline(in >> std::ws, line, ')');
  if (line.empty() || in.eof())
  {
    return in;
  }
  std::istringstream input(line);
  input >> sign;
  if (sign != '(')
  {
    throw std::invalid_argument("Invalid literal\n");
  }
  input >> point.x;
  if (input.fail())
  {
    throw std::invalid_argument("Invalid coordinate X\n");
  }
  input >> sign;
  if (sign != ';')
  {
    throw std::invalid_argument("Invalid separate\n");
  }
  in >> point.y;
  if (input.fail())
  {
    throw std::invalid_argument("Invalid coordinate Y\n");
  }
  return in;
}

std::ostream& lab::operator<<(std::ostream& out, const Point& point)
{
  out << '(' << point.x << ';' << point.y << ')';
  return out;
}

#include "point.hpp"

#include <iostream>

std::ostream& razukrantov::operator<<(std::ostream& out, const Point& point)
{
  out << "(" << point.x << "; " << point.y << ")";
  return out;
}

void razukrantov::checkNoLine(const std::string& str)
{
  if (str.find('\n') != std::string::npos) 
  {
    throw(std::invalid_argument("Incorrect reading"));
  }
}

std::istream& razukrantov::operator>>(std::istream& in, Point& point)
{
  std::string str;
  std::getline(in, str, '(');
  checkNoLine(str);
  std::getline(in, str, ';');
  checkNoLine(str);
  int x = std::stoi(str);
  std::getline(in, str, ')');
  checkNoLine(str);
  int y = std::stoi(str);
  point = { x, y };
  return in;
}

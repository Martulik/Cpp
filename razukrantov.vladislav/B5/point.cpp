#include "point.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

std::ostream& razukrantov::operator<<(std::ostream& out, const Point& point)
{
  out << "(" << point.x << "; " << point.y << ")";
  return out;
}

std::istream& razukrantov::operator>>(std::istream& in, Point& point)
{
  std::string str;
  std::getline(in, str, '(');
  if (str.find('\n') != std::string::npos)
  {
    throw(std::invalid_argument("Incorrect reading"));
  }
  std::getline(in, str, ';');
  if (str.find(';') == std::string::npos)
  {
    throw(std::invalid_argument("Incorrect reading"));
  }
  std::string x = str.substr(0, str.find(';'));
  std::string y = str.substr(0, str.find(';') + 1);
  point.x = std::stoi(x);
  point.y = std::stoi(y);
  return in;
}

#include "point.hpp"
#include <iostream>
#include <algorithm>

namespace shilyaev {
  bool safeGetline(std::istream &istream, std::string &str, char delimiter)
  {
    std::getline(istream, str, delimiter);
    return std::find(str.cbegin(), str.cend(), '\n') == str.cend();
  }

  bool operator==(const Point &a, const Point &b)
  {
    return a.x == b.x && a.y == b.y;
  }

  Point operator+(const Point &a, const Point &b)
  {
    return Point{a.x + b.x, a.y + b.y};
  }

  Point operator-(const Point &a, const Point &b)
  {
    return Point{a.x - b.x, a.y - b.y};
  }

  std::ostream &operator<<(std::ostream &ostream, const Point &point)
  {
    ostream << '(' << point.x << "; " << point.y << ')';
    return ostream;
  }

  std::istream &operator>>(std::istream &istream, Point &point)
  {
    Point newPoint{};
    try {
      std::string str;
      bool foundDelimiter = safeGetline(istream, str, '(');
      foundDelimiter &= safeGetline(istream, str, ';');
      newPoint.x = std::stoi(str);
      foundDelimiter &= safeGetline(istream, str, ')');
      newPoint.y = std::stoi(str);
      if (!foundDelimiter) {
        istream.setstate(std::ios::failbit);
        return istream;
      }
    } catch (const std::invalid_argument &) {
      istream.setstate(std::ios::failbit);
      return istream;
    }
    point = newPoint;
    return istream;
  }
}

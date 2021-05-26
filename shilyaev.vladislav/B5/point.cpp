#include "point.hpp"
#include <iostream>

namespace shilyaev {
  bool safeGetline(std::istream &istream, std::string &str, char delimiter)
  {
    str.erase();
    char ch;
    while (istream.peek() != '\n' && istream.get(ch)) {
      if (ch == delimiter) {
        return true;
      }
      str += ch;
    }
    return false;
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

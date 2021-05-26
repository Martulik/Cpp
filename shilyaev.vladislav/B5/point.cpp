#include "point.hpp"
#include <iostream>
#include <algorithm>

namespace shilyaev {
  bool operator==(Point a, Point b)
  {
    return a.x == b.x && a.y == b.y;
  }

  Point operator+(Point a, Point b)
  {
    return Point{a.x + b.x, a.y + b.y};
  }

  Point operator-(Point a, Point b)
  {
    return Point{a.x - b.x, a.y - b.y};
  }

  std::ostream &operator<<(std::ostream &ostream, Point point)
  {
    ostream << '(' << point.x << "; " << point.y << ')';
    return ostream;
  }

  std::string safeGetline(std::istream &istream, char delimiter)
  {
    std::string str;
    std::getline(istream, str, delimiter);
    if (str.find('\n') != std::string::npos || istream.eof()) {
      istream.clear();
      istream.setstate(std::ios::failbit);
      return "";
    }
    return str;
  }

  std::istream &operator>>(std::istream &istream, Point &point)
  {
    try {
      safeGetline(istream, '(');
      int x = std::stoi(safeGetline(istream, ';'));
      int y = std::stoi(safeGetline(istream, ')'));
      if (!istream) {
        return istream;
      }
      point = {x, y};
    } catch (std::invalid_argument &) {
      istream.setstate(std::ios::failbit);
    }
    return istream;
  }
}

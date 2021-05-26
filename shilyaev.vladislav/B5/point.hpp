#ifndef POINT_HPP
#define POINT_HPP

#include <iosfwd>

namespace shilyaev {
  struct Point {
    int x;
    int y;
  };
  bool operator==(Point a, Point b);
  Point operator+(Point a, Point b);
  Point operator-(Point a, Point b);
  std::ostream &operator<<(std::ostream &ostream, Point point);
  std::istream &operator>>(std::istream &istream, Point &point);
}

#endif

#ifndef POINT_HPP
#define POINT_HPP

#include <iosfwd>

namespace shilyaev {
  struct Point {
    int x;
    int y;
  };
  bool operator==(const Point &a, const Point &b);
  Point operator+(const Point &a, const Point &b);
  std::ostream &operator<<(std::ostream &ostream, const Point &point);
  std::istream &operator>>(std::istream &istream, Point &point);
}

#endif

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include <iosfwd>

namespace shilyaev {
  struct Point {
    int x;
    int y;
  };
  using Shape = std::vector< Point >;
  std::ostream &operator<<(std::ostream &ostream, const Point &point);
  std::istream &operator>>(std::istream &istream, Point &point);
  int calculateDistanceSquared(const Point &a, const Point &b);
  bool isTriangle(const Shape &shape);
  bool isSquare(const Shape &shape);
  bool isRectangle(const Shape &shape);
  bool isPentagon(const Shape &shape);
}

#endif

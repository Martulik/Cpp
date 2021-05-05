#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include <iostream>

namespace ezerinia {
  struct Point {
    int x, y;
  };
  using Shape = std::vector< Point >;

  double getSideLength(const Point &p1, const Point &p2);

  bool isSidesEqual(const Shape &shape);
}

std::istream &operator>>(std::istream &in, ezerinia::Point &point);

std::istream &operator>>(std::istream &in, ezerinia::Shape &shape);

std::ostream &operator<<(std::ostream &out, const ezerinia::Point &point);

std::ostream &operator<<(std::ostream &out, const ezerinia::Shape &shape);

#endif

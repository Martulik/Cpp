#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

namespace diurdeva {
  struct Point
  {
    int x, y;
  };

  int squareDistance(const Point& point1, const Point& point2);
  std::istream& operator>>(std::istream& in, Point& point);
  std::ostream& operator<<(std::ostream& out, const Point& point);
}

#endif

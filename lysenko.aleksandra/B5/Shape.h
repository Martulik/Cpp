#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <vector>

namespace lysenko
{
  struct Point
  {
    int x;
    int y;
  };

  std::istream& operator>>(std::istream& in, Point& point);
  std::ostream& operator<<(std::ostream& out, const Point& point);
  bool operator<(const Point& point1, const Point& point2);
  bool operator==(const Point& point1, const Point& point2);

  using Shape = std::vector< Point >;
  std::istream& operator>>(std::istream& in, Shape& Shape);
  std::ostream& operator<<(std::ostream& out, const Shape& Shape);
}

#endif

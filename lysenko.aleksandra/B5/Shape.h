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

  using Shape = std::vector< Point >;
  std::istream& operator>>(std::istream& in, Shape& Shape);
}

#endif
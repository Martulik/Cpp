#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <vector>

namespace murzakanov
{
  struct Point
  {
    int x, y;
  };
  std::ostream& operator<<(std::ostream& out, const Point point);
  using Shape = std::vector< Point >;
  std::istream& operator>>(std::istream& in, Shape& shp);
  std::ostream& operator<<(std::ostream& out, const Shape& shp);
}

#endif

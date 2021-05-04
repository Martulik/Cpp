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
  using Shape = std::vector< Point >;
  std::istream& operator >>(std::istream& in, Shape& shp);
}

#endif

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include <iosfwd>

namespace pochernin
{
  struct Point
  {
    int x, y;
  };

  using Shape = std::vector< Point >;

  std::ostream& operator<<(std::ostream& out, const Point& point);
}

#endif

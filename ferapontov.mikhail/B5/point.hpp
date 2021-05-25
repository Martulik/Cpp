#ifndef POINT_HPP
#define POINT_HPP

#include <vector>
#include <iosfwd>

namespace ferapontov
{
  struct Point
  {
    int x;
    int y;
  };

  using Shape = std::vector< Point >;
  std::istream& operator>>(std::istream& in, Point point);
  std::ostream& operator<<(std::ostream& out, Point point);
}

#endif

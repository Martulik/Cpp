#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include <iosfwd>

namespace shkurov
{
  struct Point
  {
    int x, y;
  };

  using Shape = std::vector< Point >;

  std::istream& operator>>(std::istream& in, Point& point);
  std::istream& operator>>(std::istream& in, Shape& shape);
  std::ostream& operator<<(std::ostream& out, const Shape& shape);
  std::ostream& operator<<(std::ostream& out, const Point& point);

  bool operator<(const Shape& lhs, const Shape& rhs);
}

#endif

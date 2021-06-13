#ifndef POINT_HPP
#define POINT_HPP
#include <iosfwd>

namespace lebedeva
{
  struct Point
  {
    int x;
    int y;
  };

  std::istream& operator>>(std::istream& in, Point& point);
  std::ostream& operator<<(std::ostream& out, const Point& point);
  Point operator+(const Point lhs, const Point rhs);
}
#endif

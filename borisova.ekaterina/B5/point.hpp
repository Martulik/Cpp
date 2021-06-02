#ifndef POINT_HPP
#define POINT_HPP

#include <iosfwd>
#include <vector>

namespace borisova
{
  struct Point
  {
    int x, y;
  };

  int getSquareDistance(const Point& first, const Point& second);
  std::istream& operator>>(std::istream& in, Point& point);
  std::ostream& operator<<(std::ostream& out, const Point& point);
}
#endif

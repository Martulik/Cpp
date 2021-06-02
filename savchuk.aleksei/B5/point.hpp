#ifndef POINT_HPP
#define POINT_HPP

#include <iosfwd>
#include <string>

namespace savchuk
{
  struct Point
  {
    int x;
    int y;
  };

  std::istream& operator>>(std::istream& is, Point& point);
  std::ostream& operator<<(std::ostream& os, const Point& point);

  void move(Point& point, int dx, int dy);
}

#endif

#ifndef POINT_HPP
#define POINT_HPP

#include <iosfwd>
#include <string>

namespace razukrantov
{
  struct Point
  {
    int x, y;
  };

  std::ostream& operator<<(std::ostream& out, const Point& point);
  std::istream& operator>>(std::istream& in, Point& point);
  void checkNoLine(const std::string& str);
}

#endif

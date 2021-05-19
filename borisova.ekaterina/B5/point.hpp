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
  double getDistance(const Point& first, const Point& second);
  bool isPerpendicularity(const Point& one, const Point& two, const Point three);
  std::istream& operator>>(std::istream& in, Point& point);
  std::ostream& operator<<(std::ostream& out, const Point& point);
}
#endif

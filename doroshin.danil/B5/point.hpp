#ifndef POINT_HPP
#define POINT_HPP

#include <iosfwd>

namespace doroshin
{
  struct Point
  {
    int x, y;
  };

  std::istream& operator>>(std::istream&, Point&);
  std::ostream& operator<<(std::ostream&, const Point&);
}

#endif //POINT_HPP

#ifndef POINT_HPP
#define POINT_HPP

#include <iosfwd>

namespace ferapontov
{
  struct Point
  {
    int x;
    int y;
  };

  std::istream& operator>>(std::istream& in, Point& point);
  std::ostream& operator<<(std::ostream& out, const Point& point);

  std::istream& checkNextSymbol(std::istream& in, const char& delim);
}

#endif

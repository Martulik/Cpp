#ifndef POINT_HPP
#define POINT_HPP

#include <iosfwd>

namespace savchuk
{
  struct Point
  {
    int x;
    int y;
  };

  std::istream& operator>>(std::istream& is, Point& point);
  std::ostream& operator<<(std::ostream& os, const Point& point);

  void readDelimiter(std::istream& is, char delim);
  std::istream& skipws(std::istream& is);
}

#endif

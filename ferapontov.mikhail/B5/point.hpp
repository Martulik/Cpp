#ifndef POINT_HPP
#define POINT_HPP

#include <iosfwd>
#include <string>

namespace ferapontov
{
  struct Point
  {
    int x;
    int y;
  };

  std::istream& operator>>(std::istream& in, Point& point);
  std::ostream& operator<<(std::ostream& out, const Point& point);

  void checkDelim(std::string& line, const char& delim, std::istream& err);
  int readNumber(std::string& line, std::istream& err);
  void skipWs(std::string& line, std::istream& err);

  struct noWs
  {
    bool operator()(char a);
  };
}

#endif

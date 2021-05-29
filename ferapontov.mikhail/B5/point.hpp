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

  void checkDelim(std::string& line, const char& delim, int& err);
  int readNumber(std::string& line, int& err);
  void skipWs(std::string& line, int& err);

  struct noWs
  {
    bool operator()(char a);
  };
}

#endif

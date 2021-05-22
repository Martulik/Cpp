#include <iosfwd>

namespace murzakanov
{
  struct Point
  {
    int x, y;
  };
  std::ostream& operator<<(std::ostream& out, const Point& point);
  std::istream& operator>>(std::istream& in, Point& point);
}

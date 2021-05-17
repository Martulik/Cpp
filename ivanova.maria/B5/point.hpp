#ifndef B5_POINT_HPP
#define B5_POINT_HPP
#include <iosfwd>
#include <vector>
namespace ivanova
{
  struct Point
  {
    int x;
    int y;
  };

  using Shape = std::vector< Point >;

  std::istream &operator >>(std::istream &in, Point& point);
  std::ostream &operator <<(std::ostream &out, const Point &point);

  bool isRect(const Shape &shp);
  bool isTriangle(const Shape& shp);
  bool isSquare(const Shape &shp);
  bool isPentagon(const Shape &shp);
}
#endif

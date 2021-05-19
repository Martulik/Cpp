#ifndef B5_POINT_HPP
#define B5_POINT_HPP
#include <iosfwd>
#include <vector>
#include <string>
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

  inline bool isRect(const Shape &shp);
  inline bool isTriangle(const Shape& shp);
  inline bool isSquare(const Shape &shp);
  inline bool checkSidesForSquare(const Shape &shp);
}

#endif

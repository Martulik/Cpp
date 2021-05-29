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
  std::istream &operator >>(std::istream &in, Shape &shp);
  std::ostream &operator <<(std::ostream &out, const Shape &elem);

  bool compare(const Shape &elem1, const Shape &elem2);
  unsigned int countVertices(unsigned int sum, const Shape& shp);
  Point getFront(const Shape &shp);
  int getSide(const Point &a, const Point &b);

  bool isRect(const Shape &shp);
  bool isTriangle(const Shape &shp);
  bool isSquare(const Shape &shp);
  bool isPentagon(const Shape &shp);
  bool checkSidesForSquare(const Shape &shp);
}

#endif

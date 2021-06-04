#ifndef POINT_HPP
#define POINT_HPP

#include <vector>
#include <iosfwd>

namespace dushechkina
{
  struct Point
  {
    int x;
    int y;
  };

  std::istream& operator>>(std::istream& in, Point& point);
  std::ostream& operator<<(std::ostream& out, const Point& point);

  using Shape = std::vector< Point >;
  bool isTriangle(const Shape& shape);
  bool isRectangle(const Shape& shape);
  bool isPentagon(const Shape& shape);
  bool isSquare(const Shape& shape);
  int summarizeVertices(int vertices, const Shape& shape);
  int compareSide(const Shape& shape);
  int getDistanceSquare(const Point& first, const Point& second);
  Point getFront(const Shape& shp);
  std::istream& operator>>(std::istream& in, Shape& shape);
  std::ostream& operator<<(std::ostream& out, const Shape& shape);
  bool operator<(const Shape& first, const Shape& second);
}
#endif

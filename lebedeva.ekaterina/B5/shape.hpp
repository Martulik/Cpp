#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <vector>
#include "point.hpp"

namespace lebedeva
{
  using Shape = std::vector< Point >;

  struct ShapesSpecifics
  {
    size_t vertices = 0;
    size_t triangles = 0;
    size_t squares = 0;
    size_t rectangles = 0;
  };

  std::istream& operator>>(std::istream& in, Shape& shape);
  std::ostream& operator<<(std::ostream& out, const Shape& shape);

  bool isTriangle(const Shape& shape);
  bool isSquare(const Shape& shape);
  bool isRectangle(const Shape& shape);
  bool isPentagon(const Shape& shape);
  int getDistance(const Point& p1, const Point& p2);
}
#endif

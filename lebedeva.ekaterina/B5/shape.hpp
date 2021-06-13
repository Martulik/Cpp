#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <vector>
#include "point.hpp"

namespace lebedeva
{
  using Shape = std::vector< Point >;

  struct ShapesSpecifics
  {
    int vertices = 0;
    int triangles = 0;
    int squares = 0;
    int rectangles = 0;
  };

  std::istream& operator>>(std::istream& in, Shape& shape);
  std::ostream& operator<<(std::ostream& out, const Shape& shape);

  bool isTriangle(const Shape& shape);
  bool isSquare(const Shape& shape);
  bool isRectangle(const Shape& shape);
  bool isPentagon(const Shape& shape);
  int getDistance(const Point& p1, const Point& p2);
  bool compareDistances(const Shape& shape);

  bool compareDistancesFromOnePoint(const Point p1, const Point p2, const Point p3);
  bool isCrossedSquare(const Shape& shape);
  bool isCrossedRectangle(const Shape& shape);
  bool isSquareAdvanced(const Shape& shape);
  bool isRectangleAdvanced(const Shape& shape);
  std::vector< int > getAllDistances(const Shape& shape);
  bool checkSquareDistances(const Shape& shape);
  bool checkRectangleDistances(const Shape& shape);
  bool checkHypotenuse(const Shape& shape);
}
#endif

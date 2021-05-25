#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>

#include "shape.hpp"

namespace pochernin
{
  int getTaskNumber(const char* string);
  bool isNumber(const std::string& str);
  unsigned int sumVertices(unsigned int sum, const Shape& shape);
  bool isTriangle(const Shape& shape);
  void fillSquaredSideVector(std::vector< unsigned int >& squaredSides, const Shape& shape);
  unsigned int getSquaredSide(const Point& lhs, const Point& rhs);
  bool isRectangle(const Shape& shape);
  bool isSquare(const Shape& shape);
  bool isPentagon(const Shape& shape);
  Point getFirstPoint(const Shape& shape);
  void deleteExtraSpaces(std::string& str);
  void sortShapes(std::vector< Shape >& shapes);
}

#endif

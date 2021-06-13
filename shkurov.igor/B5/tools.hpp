#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iosfwd>
#include <tuple>
#include <random>

#include "shape.hpp"

namespace shkurov
{
  using tupleCount = std::tuple< unsigned int, unsigned int, unsigned int >;

  unsigned int countVertices(unsigned int sum, const Shape& cur);
  tupleCount accumFigures(tupleCount& prev, const Shape& cur);
  bool isTriangle(const Shape& shape);
  bool isRectangle(const Shape& shape);
  bool isSquare(const Shape& shape);
  bool isPentagon(const Shape& shape);
  bool allSidesEqual(const Shape& shape);
  unsigned int getSquaredDistance(const Point& a, const Point& b);
  Point getPoint(const Shape& shape);
  Shape rectGen(bool isSquare, std::mt19937& rnd);
  Shape rsGen(unsigned int r, unsigned int s, std::mt19937& rnd);
}

#endif

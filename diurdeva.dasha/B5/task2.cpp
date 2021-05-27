#include "task2.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include "shape.hpp"

namespace diurdeva {
  unsigned int accumulateVertices(unsigned int vertices, const Shape& shape)
  {
    return vertices + shape.size();
  }

  Point frontPoint(const Shape& shape)
  {
    return shape.front();
  }

  bool isLess(const Shape& shape1, const Shape& shape2)
  {
    return getType(shape2) > getType(shape1);
  }
}

void diurdeva::task2(std::istream& in, std::ostream& out)
{
  std::istream_iterator< Shape > firstIterator(in);
  std::istream_iterator< Shape > lastIterator;
  std::vector< Shape > shapes(firstIterator, lastIterator);

  if (!in && !in.eof()) {
    throw std::runtime_error("Stream reading failed");
  }
  const int verticesAmount = std::accumulate(shapes.begin(), shapes.end(), 0, accumulateVertices);
  const int trianglesAmount = std::count_if(shapes.begin(), shapes.end(), isTriangle);
  const int squaresAmount = std::count_if(shapes.begin(), shapes.end(), isSquare);
  const int rectanglesAmount = squaresAmount + std::count_if(shapes.begin(), shapes.end(), isRectangle);

  out << "Vertices: " << verticesAmount << "\n";
  out << "Triangles: " << trianglesAmount << "\n";
  out << "Squares: " << squaresAmount << "\n";
  out << "Rectangles: " << rectanglesAmount << "\n";

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), isPentagon),shapes.end());

  Shape points;
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points), frontPoint);

  out << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator< Point >(std::cout, " "));

  std::sort(shapes.begin(), shapes.end(), isLess);

  out << "\nShapes:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< Shape >(out, "\n"));
}

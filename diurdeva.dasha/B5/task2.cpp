#include "task2.hpp"

#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include "shape.hpp"

void diurdeva::task2(std::istream& in, std::ostream& out)
{
  std::istream_iterator< Shape > firstIterator(in);
  std::istream_iterator< Shape > lastIterator;
  std::vector<Shape> shapes(firstIterator, lastIterator);

  if (!in && !in.eof()) {
    throw std::runtime_error("Stream reading failed");
  }
  int verticesAmount = std::accumulate(shapes.begin(), shapes.end(), 0, [](unsigned int count, const Shape& shape) {
    return count + shape.size();
  });

  int trianglesAmount = std::count_if(shapes.begin(), shapes.end(), isTriangle);

  int squaresAmount = std::count_if(shapes.begin(), shapes.end(), isSquare);

  int rectanglesAmount = squaresAmount + std::count_if(shapes.begin(), shapes.end(), isRectangle);

  out << "Vertices: " << verticesAmount << "\nTriangles: " << trianglesAmount
    << "\nSquares: " << squaresAmount << "\nRectangles: " << rectanglesAmount;

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), isPentagon),shapes.end());

  Shape points;
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points),
    [](const Shape& shape) {return shape.front(); });

  out << "\nPoints: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator< Point >(std::cout, " "));

  std::sort(shapes.begin(), shapes.end(),
    [](const Shape& shape1, const Shape& shape2) {return getType(shape2) > getType(shape1); });

  out << "\nShapes:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator<Shape>(out, "\n"));
}

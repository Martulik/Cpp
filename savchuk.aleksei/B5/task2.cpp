#include "tasks.hpp"

#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <numeric>

#include "shape.hpp"
#include "tools.hpp"

namespace lab = savchuk;

void lab::doTask2(std::istream& is, std::ostream& os)
{
  std::istream_iterator< Shape > first(is);
  std::istream_iterator< Shape > last;
  std::vector< Shape > shapes(first, last);
  if (is.fail() && !is.eof())
  {
    throw std::runtime_error("Input error");
  }

  ShapeCounter counter = std::for_each(shapes.cbegin(), shapes.cend(), ShapeCounter());

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), isPentagon), shapes.end());

  struct GetPoint
  {
    Point operator()(const Shape& shape)
    {
      return shape.back();
    }
  };

  std::vector< Point > points;
  std::transform(shapes.cbegin(), shapes.cend(), std::back_inserter(points), GetPoint());

  auto it1 = std::partition(shapes.begin(), shapes.end(), isTriangle);
  auto it2 = std::partition(it1, shapes.end(), isSquare);
  std::partition(it2, shapes.end(), isRectangle);

  os << "Vertices: " << counter.vertices
     << "\nTriangles: " << counter.triangles
     << "\nSquares: " << counter.squares
     << "\nRectangles: " << counter.rectangles
     << "\nPoints: ";
  std::copy(points.cbegin(), points.cend(), std::ostream_iterator< Point >(os, " "));
  os << "\nShapes:\n";
  std::copy(shapes.cbegin(), shapes.cend(), std::ostream_iterator< Shape >(os, "\n"));
}

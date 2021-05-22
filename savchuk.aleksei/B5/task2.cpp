#include "tasks.hpp"

#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <numeric>

#include "shape.hpp"

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
  unsigned int vertices = std::accumulate(shapes.cbegin(), shapes.cend(), 0u,
                                          [](unsigned int sum, const Shape& s)
                                          {
                                            return sum + s.size();
                                          });
  unsigned int triangles = std::count_if(shapes.cbegin(), shapes.cend(), isTriangle);
  unsigned int rectangles = std::count_if(shapes.cbegin(), shapes.cend(), isRectangle);
  unsigned int squares = std::count_if(shapes.cbegin(), shapes.cend(), isSquare);
  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), isPentagon), shapes.end());
  std::vector< Point > points;
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points),
                [](Shape& s)
                {
                  return s.back();
                });
  std::sort(shapes.begin(), shapes.end(), compare);
  os << "Vertices: " << vertices;
  os << "\nTriangles: " << triangles;
  os << "\nSquares: " << squares;
  os << "\nRectangles: " << rectangles;
  os << "\nPoints: ";
  std::copy(points.cbegin(), points.cend(), std::ostream_iterator< Point >(os, " "));
  os << "\nShapes:\n";
  std::copy(shapes.cbegin(), shapes.cend(), std::ostream_iterator< Shape >(os, "\n"));
}

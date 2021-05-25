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

  std::vector< Point > points;
  std::transform(shapes.cbegin(), shapes.cend(), std::back_inserter(points),
                 [](const Shape& s)
                 {
                   return s.back();
                 });

  std::vector< Shape > sortedShapes;
  std::copy_if(shapes.cbegin(), shapes.cend(), std::back_inserter(sortedShapes), isTriangle);
  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), isTriangle), shapes.end());

  std::copy_if(shapes.cbegin(), shapes.cend(), std::back_inserter(sortedShapes), isSquare);
  std::copy_if(shapes.cbegin(), shapes.cend(), std::back_inserter(sortedShapes),
               [](const Shape& s)
               {
                 return isRectangle(s) && !isSquare(s);
               });
  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), isRectangle), shapes.end());

  sortedShapes.insert(sortedShapes.end(), shapes.cbegin(), shapes.cend());

  os << "Vertices: " << counter.vertices
     << "\nTriangles: " << counter.triangles
     << "\nSquares: " << counter.squares
     << "\nRectangles: " << counter.rectangles
     << "\nPoints: ";
  std::copy(points.cbegin(), points.cend(), std::ostream_iterator< Point >(os, " "));
  os << "\nShapes:\n";
  std::copy(sortedShapes.cbegin(), sortedShapes.cend(), std::ostream_iterator< Shape >(os, "\n"));
}

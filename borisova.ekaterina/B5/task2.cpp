#include "tasks.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>
#include "shape.hpp"

namespace lab = borisova;

void lab::doTask2(std::istream& in, std::ostream& out)
{
  using iterIn = std::istream_iterator< Shape >;
  std::vector< Shape > vec{ iterIn(in), iterIn() };

  int peaks = std::accumulate(vec.begin(), vec.end(), 0, [](int count, const Shape& shape)
    {
    return count + shape.size();
    });

  int triangles = std::count_if(vec.begin(), vec.end(), isTriangle);
  int squares = std::count_if(vec.begin(), vec.end(), isSquare);
  int rectangles = squares + std::count_if(vec.begin(), vec.end(), isRectangle);

  vec.erase(std::remove_if(vec.begin(), vec.end(), isPentagon), vec.end());

  std::vector< Point > points;
  std::transform(vec.begin(), vec.end(), std::back_inserter(points), [](const Shape& shape)
    {
      return shape.back();
    });

  std::sort(vec.begin(), vec.end());

  out << "Vertices: " << peaks << "\nTriangles: " << triangles;
  out << "\nSquares: " << squares << "\nRectangles: " << rectangles;
  out << "\nPoints: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator< Point >(out, " "));
  out << "\nShapes: ";
  std::copy(vec.begin(), vec.end(), std::ostream_iterator< Shape >(out, "\n"));
}

#include "task-shape.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include "shape.hpp"

namespace shilyaev {
  unsigned int accumulator(unsigned int acc, const Shape &shape)
  {
    return acc + shape.size();
  }

  const Point &getFront(const Shape &shape)
  {
    return shape.front();
  }

  std::vector< Point > createPointsVector(const std::vector< Shape > &shapes)
  {
    std::vector< Point > points;
    points.reserve(shapes.size());
    std::transform(shapes.cbegin(), shapes.cend(), std::back_inserter(points), getFront);
    return points;
  }

  void partitionShapes(std::vector< Shape > &shapes)
  {
    auto bound = std::partition(shapes.begin(), shapes.end(), isTriangle);
    bound = std::partition(bound, shapes.end(), isSquare);
    std::partition(bound, shapes.end(), isRectangle);
  }

  int runShapeTask(std::istream &istream, std::ostream &ostream, std::ostream &err)
  {
    std::istream_iterator< Shape > istreamIterator(istream);
    std::istream_iterator< Shape > istreamIteratorEnd;
    std::vector< Shape > shapes;
    std::copy(istreamIterator, istreamIteratorEnd, std::back_inserter(shapes));
    if (!istream && !istream.eof()) {
      err << "Input error";
      return 1;
    }
    const unsigned int verticesCount = std::accumulate(shapes.cbegin(), shapes.cend(), 0, accumulator);
    const unsigned int trianglesCount = std::count_if(shapes.cbegin(), shapes.cend(), isTriangle);
    const unsigned int squaresCount = std::count_if(shapes.cbegin(), shapes.cend(), isSquare);
    const unsigned int rectanglesCount = std::count_if(shapes.cbegin(), shapes.cend(), isRectangle);
    shapes.erase(std::remove_if(shapes.begin(), shapes.end(), isPentagon), shapes.end());
    const std::vector< Point > points = createPointsVector(shapes);
    partitionShapes(shapes);
    ostream << "Vertices: " << verticesCount
            << "\nTriangles: " << trianglesCount
            << "\nSquares: " << squaresCount
            << "\nRectangles: " << rectanglesCount
            << "\nPoints: ";
    std::ostream_iterator< Point > pointOstreamIterator(ostream, " ");
    std::copy(points.cbegin(), points.cend(), std::ostream_iterator< Point >(ostream, " "));
    ostream << "\nShapes: \n";
    std::copy(shapes.cbegin(), shapes.cend(), std::ostream_iterator< Shape >(ostream, "\n"));
    return 0;
  }
}

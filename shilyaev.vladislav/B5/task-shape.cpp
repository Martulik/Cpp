#include "task-shape.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include "shape.hpp"

namespace shilyaev {
  unsigned int countVertices(const std::vector< Shape > &shapes)
  {
    return std::accumulate(shapes.begin(), shapes.end(), 0, [](unsigned int sum, const Shape &shape) {
      return sum + shape.size();
    });
  }

  std::vector< Point > createPointsVector(const std::vector< Shape > &shapes)
  {
    std::vector< Point > points;
    points.reserve(shapes.size());
    std::transform(shapes.begin(), shapes.end(), std::back_inserter(points), [](const Shape &shape) {
      return shape.front();
    });
    return points;
  }

  int getPriority(const Shape &shape)
  {
    if (isTriangle(shape)) {
      return 0;
    } else if (isSquare(shape)) {
      return 1;
    } else if (isRectangle(shape)) {
      return 2;
    }
    return 3;
  }

  void sortShapes(std::vector< Shape > &shapes)
  {
    std::sort(shapes.begin(), shapes.end(), [](const Shape &a, const Shape &b) {
      return getPriority(a) < getPriority(b);
    });
  }

  int runShapeTask(std::istream &istream, std::ostream &ostream)
  {
    std::istream_iterator< Shape > istreamIterator(istream);
    std::istream_iterator< Shape > istreamIteratorEnd;
    std::vector< Shape > shapes;
    std::copy(istreamIterator, istreamIteratorEnd, std::back_inserter(shapes));
    if (!istream && !istream.eof()) {
      std::cerr << "Input error";
      return 1;
    }
    const unsigned int verticesCount = countVertices(shapes);
    const unsigned int trianglesCount = std::count_if(shapes.begin(), shapes.end(), isTriangle);
    const unsigned int squaresCount = std::count_if(shapes.begin(), shapes.end(), isSquare);
    const unsigned int rectanglesCount = std::count_if(shapes.begin(), shapes.end(), isRectangle);
    shapes.erase(std::remove_if(shapes.begin(), shapes.end(), isPentagon), shapes.end());
    const std::vector< Point > points = createPointsVector(shapes);
    sortShapes(shapes);
    ostream << "Vertices: " << verticesCount
            << "\nTriangles: " << trianglesCount
            << "\nSquares: " << squaresCount
            << "\nRectangles: " << rectanglesCount
            << "\nPoints: ";
    std::ostream_iterator< Point > pointOstreamIterator(ostream, " ");
    std::copy(points.begin(), points.end(), std::ostream_iterator< Point >(ostream, " "));
    ostream << "\nShapes: \n";
    std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< Shape >(ostream, "\n"));
    return 0;
  }
}

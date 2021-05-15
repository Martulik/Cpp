#include "task-shape.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cctype>
#include <boost/optional/optional.hpp>
#include "shape.hpp"

namespace shilyaev {
  boost::optional< Shape > readShape(const std::string &input)
  {
    std::istringstream istringstream(input);
    size_t vertices;
    istringstream >> vertices;
    if (vertices < 1) {
      return {};
    }
    Shape shape;
    shape.reserve(vertices);
    std::istream_iterator< Point > istreamIterator(istringstream);
    std::istream_iterator< Point > istreamIteratorEnd;
    std::copy(istreamIterator, istreamIteratorEnd, std::back_inserter(shape));
    if ((!istringstream && !istringstream.eof()) || shape.size() != vertices) {
      return {};
    }
    return shape;
  }

  boost::optional< std::vector< Shape > > readShapes(std::istream &istream)
  {
    std::vector< Shape > shapes;
    std::string line;
    while (std::getline(istream, line)) {
      if (std::all_of(line.begin(), line.end(), static_cast< int (&)(int) >(std::isspace))) {
        continue;
      }
      boost::optional< Shape > shape = readShape(line);
      if (!shape) {
        return {};
      }
      shapes.push_back(std::move(*shape));
    }
    if (istream.fail() && !istream.eof()) {
      return {};
    }
    return shapes;
  }

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

  int runShapeTask()
  {
    boost::optional< std::vector< Shape > > shapes = readShapes(std::cin);
    if (!shapes) {
      std::cerr << "Input error";
      return 1;
    }
    const unsigned int verticesCount = countVertices(*shapes);
    const unsigned int trianglesCount = std::count_if(shapes->begin(), shapes->end(), isTriangle);
    const unsigned int squaresCount = std::count_if(shapes->begin(), shapes->end(), isSquare);
    const unsigned int rectanglesCount = std::count_if(shapes->begin(), shapes->end(), isRectangle);
    shapes->erase(std::remove_if(shapes->begin(), shapes->end(), isPentagon), shapes->end());
    const std::vector< Point > points = createPointsVector(*shapes);
    sortShapes(*shapes);
    std::cout << "Vertices: " << verticesCount
              << "\nTriangles: " << trianglesCount
              << "\nSquares: " << squaresCount
              << "\nRectangles: " << rectanglesCount
              << "\nPoints: ";
    std::ostream_iterator< Point > pointOstreamIterator(std::cout, " ");
    std::copy(points.begin(), points.end(), pointOstreamIterator);
    std::cout << "\nShapes: ";
    for (const auto &shape: *shapes) {
      std::cout << '\n' << shape.size() << ' ';
      std::copy(shape.begin(), shape.end(), pointOstreamIterator);
    }
    return 0;
  }
}

#include "task-polygons.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <boost/optional/optional.hpp>

namespace shilyaev {
  struct Point {
    int x;
    int y;
  };

  using Shape = std::vector< Point >;

  std::ostream &operator<<(std::ostream &ostream, const Point& point)
  {
    ostream << '(' << point.x << "; " << point.y << ')';
    return ostream;
  }

  std::istream &operator>>(std::istream &istream, Point& point)
  {
    try {
      std::string str;
      std::getline(istream, str, '(');
      std::getline(istream, str, ';');
      point.x = std::stoi(str);
      std::getline(istream, str, ')');
      point.y = std::stoi(str);
    } catch (const std::invalid_argument &) {
      istream.setstate(std::ios::failbit);
    }
    return istream;
  }

  boost::optional< Shape > readShape(const std::string &input)
  {
    std::istringstream istringstream(input);
    int vertices;
    istringstream >> vertices;
    if (vertices < 1) {
      return {};
    }
    Shape shape(vertices);
    for (int i = 0; i < vertices; ++i) {
      istringstream >> shape[i];
    }
    if (istringstream.fail()) {
      return {};
    }
    return shape;
  }

  boost::optional< std::vector< Shape > > readShapes(std::istream &istream)
  {
    std::vector< Shape > shapes;
    std::string line;
    while (std::getline(istream, line)) {
      if (line.empty()) {
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

  bool isTriangle(const Shape &shape)
  {
    return shape.size() == 3;
  }

  int calculateDistanceSquared(const Point &a, const Point &b)
  {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  }

  bool isExactSquare(int ab, int bc, int cd, int da, int bd, int ac)
  {
    return ab == bc && ab == cd && ab == da && bd == ac;
  }

  bool isSquare(const Shape &shape)
  {
    if (shape.size() != 4) {
      return false;
    }
    int d01 = calculateDistanceSquared(shape[0], shape[1]);
    int d12 = calculateDistanceSquared(shape[1], shape[2]);
    int d23 = calculateDistanceSquared(shape[2], shape[3]);
    int d30 = calculateDistanceSquared(shape[3], shape[0]);
    int d13 = calculateDistanceSquared(shape[1], shape[3]);
    int d02 = calculateDistanceSquared(shape[0], shape[2]);
    return isExactSquare(d01, d12, d23, d30, d13, d02) ||
           isExactSquare(d01, d13, d23, d02, d12, d30) ||
           isExactSquare(d02, d13, d13, d30, d23, d01);
  }

  bool isExactRectangle(int ab, int bc, int cd, int da, int bd, int ac)
  {
    return ab == cd && bc == da && bd == ac;
  }

  bool isRectangle(const Shape &shape)
  {
    if (shape.size() != 4) {
      return false;
    }
    int d01 = calculateDistanceSquared(shape[0], shape[1]);
    int d12 = calculateDistanceSquared(shape[1], shape[2]);
    int d23 = calculateDistanceSquared(shape[2], shape[3]);
    int d30 = calculateDistanceSquared(shape[3], shape[0]);
    int d13 = calculateDistanceSquared(shape[1], shape[3]);
    int d02 = calculateDistanceSquared(shape[0], shape[2]);
    return isExactRectangle(d01, d12, d23, d30, d13, d02) ||
           isExactRectangle(d01, d13, d23, d02, d12, d30) ||
           isExactRectangle(d02, d13, d13, d30, d23, d01);
  }

  void removePentagons(std::vector< Shape > &shapes)
  {
    shapes.erase(std::remove_if(shapes.begin(), shapes.end(), [](const Shape &shape) {
      return shape.size() == 5;
    }), shapes.end());
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

  void transformShapes(std::vector< Shape > &shapes)
  {
    std::sort(shapes.begin(), shapes.end(), [](const Shape &a, const Shape &b) {
      return getPriority(a) < getPriority(b);
    });
  }

  void printShapes(const std::vector< Shape > &shapes)
  {
    for (const auto &shape: shapes) {
      std::cout << '\n' << shape.size() << ' ';
      std::copy(shape.begin(), shape.end(), std::ostream_iterator< Point >(std::cout, " "));
    }
  }

  int runPolygonsTask()
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
    removePentagons(*shapes);
    const std::vector< Point > points = createPointsVector(*shapes);
    transformShapes(*shapes);
    std::cout << "Vertices: " << verticesCount << '\n'
              << "Triangles: " << trianglesCount << '\n'
              << "Squares: " << squaresCount << '\n'
              << "Rectangles: " << rectanglesCount << '\n'
              << "Points: ";
    std::copy(points.begin(), points.end(), std::ostream_iterator< Point >(std::cout, " "));
    std::cout << "\nShapes: ";
    printShapes(*shapes);
    return 0;
  }
}

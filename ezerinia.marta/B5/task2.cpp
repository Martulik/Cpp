#include "task2.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include "shape.hpp"

namespace ezerinia {
  bool isTriangle(const Shape &shape)
  {
    return shape.size() == 3;
  }

  bool isSquare(const Shape &shape)
  {
    return shape.size() == 4 && isSideEqual(shape);
  }

  bool isRectangle(const Shape &shape)
  {
    return shape.size() == 4 && !isSideEqual(shape);
  }

  bool isPentagon(const Shape &shape)
  {
    return shape.size() == 5;
  }

  bool isMorePentagon(const Shape &shape)
  {
    return shape.size() > 5;
  }

  Point firstPoint(const Shape &shape)
  {
    return shape.front();
  }

  unsigned int sumVertices(unsigned int vertices, const Shape &shape)
  {
    return vertices + shape.size();
  }
}

namespace lab = ezerinia;

void lab::task2(std::istream &in, std::ostream &out)
{
  if (!in) {
    throw std::runtime_error("Read fail");
  }
  std::vector< Shape > shapes((std::istream_iterator< Shape >(in)), std::istream_iterator< Shape >());

  unsigned int sizeWithPentagons = shapes.size();
  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), isPentagon), shapes.end());

  std::vector< Point > points;
  points.reserve(shapes.size());
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points), firstPoint);

  std::sort(shapes.begin(), shapes.end());

  const std::vector< Shape >::iterator &itMorePentagon = std::find_if(shapes.begin(), shapes.end(), isMorePentagon);
  const std::vector< Shape >::iterator &itRectangles = std::find_if(shapes.begin(), itMorePentagon, isRectangle);
  const std::vector< Shape >::iterator &itSquares = std::find_if(shapes.begin(), itRectangles, isSquare);
  const std::vector< Shape >::iterator &itTriangle = std::find_if(shapes.begin(), itSquares, isTriangle);

  unsigned int triangles = 0;
  if (itTriangle != shapes.end()) {
    if (itSquares != shapes.end()) {
      triangles = itSquares - itTriangle;
    } else if (itRectangles != shapes.end()) {
      triangles = itRectangles - itTriangle;
    } else {
      triangles = itMorePentagon - itTriangle;
    }
  }

  unsigned int squares = 0;
  if (itSquares != shapes.end()) {
    if (itRectangles != shapes.end()) {
      squares = itRectangles - itSquares;
    } else {
      squares = itMorePentagon - itSquares;
    }
  }

  unsigned int rectangles = squares;
  if (itRectangles != shapes.end()) {
    rectangles += itMorePentagon - itRectangles;
  }

  unsigned int vertices = std::accumulate(itMorePentagon, shapes.end(), 0, sumVertices);

  vertices += triangles * 3 + rectangles * 4 + (sizeWithPentagons - shapes.size()) * 5;

  out << "Vertices: " << vertices << "\n"
      << "Triangles: " << triangles << "\n"
      << "Squares: " << squares << "\n"
      << "Rectangles: " << rectangles << "\n"
      << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator< Point >(out, " "));
  out << "\nShapes:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< Shape >(out, "\n"));
}

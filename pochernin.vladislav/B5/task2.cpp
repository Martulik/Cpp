#include "tasks.hpp"

#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>

#include "shape.hpp"
#include "functions.hpp"

void pochernin::task2(std::istream& in, std::ostream& out)
{
  std::vector< Shape > shapes;
  std::copy(std::istream_iterator< Shape>(in), std::istream_iterator< Shape >(), std::back_inserter(shapes));

  unsigned int countOfVertices = std::accumulate(shapes.begin(), shapes.end(), 0, pochernin::sumVertices);

  unsigned int countOfTriangles = std::count_if(shapes.begin(), shapes.end(), pochernin::isTriangle);
  unsigned int countOfRectangles = std::count_if(shapes.begin(), shapes.end(), pochernin::isRectangle);
  unsigned int countOfSquares = std::count_if(shapes.begin(), shapes.end(), pochernin::isSquare);

  std::vector< Shape >::iterator removedStart = std::remove_if(shapes.begin(), shapes.end(), pochernin::isPentagon);
  shapes.erase(removedStart, shapes.end());

  std::vector< Point > points;
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points), pochernin::getFirstPoint);

  std::sort(shapes.begin(), shapes.end());

  out << "Verticies: " << countOfVertices << "\n";
  out << "Triangles: " << countOfTriangles << "\n";
  out << "Squares: " << countOfSquares << "\n";
  out << "Rectangles: " << countOfRectangles << "\n";
}

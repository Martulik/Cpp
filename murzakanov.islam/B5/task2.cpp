#include "tasks.hpp"

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

#include "tools.hpp"
#include "shape.hpp"

int murzakanov::task2(std::istream& in, std::ostream& out)
{
  std::vector< murzakanov::Shape > shapes;
  std::istream_iterator< murzakanov::Shape > firstIterator(in);
  std::istream_iterator< murzakanov::Shape > lastIterator;
  std::copy(firstIterator, lastIterator, std::back_inserter(shapes));
  if (in.fail() && !in.eof())
  {
    std::cerr << "Invalid input\n";
    return 1;
  }

  int vertices = std::accumulate(shapes.begin(), shapes.end(), 0, murzakanov::calculateVertices);
  int squares = std::count_if(shapes.begin(), shapes.end(), murzakanov::isSquare);
  int rectangles = std::count_if(shapes.begin(), shapes.end(), murzakanov::isRectangle);
  int triangles = std::count_if(shapes.begin(), shapes.end(), murzakanov::isTriangle);

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), murzakanov::isPentagon), shapes.end());

  std::vector< murzakanov::Point > points;
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points), murzakanov::returnFrontPnt);

  std::sort(shapes.begin(), shapes.end());

  out << "Vertices: " << vertices << "\n";
  out << "Triangles: " << triangles << "\n";
  out << "Squares: " << squares << "\n";
  out << "Rectangles: " << rectangles << "\n";
  out << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator< murzakanov::Point >(out, " "));
  out << "\n";
  out << "Shapes:" << "\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< murzakanov::Shape >(out, "\n"));
  return 0;
}

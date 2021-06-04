#include "tasks.hpp"
#include "point.hpp"

#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <iterator>

void dushechkina::task2(std::istream& in, std::ostream& out)
{
  using iterator = std::istream_iterator< Shape >;
  std::vector< Shape > shape{ iterator(in), iterator() };

  int vertices = std::accumulate(shape.begin(), shape.end(), 0, dushechkina::summarizeVertices);
  int tri = std::count_if(shape.begin(), shape.end(), isTriangle);
  int squ = std::count_if(shape.begin(), shape.end(), isSquare);
  int rec = std::count_if(shape.begin(), shape.end(), isRectangle);

  shape.erase(std::remove_if(shape.begin(), shape.end(), isPentagon), shape.end());
  std::vector< Point > point;
  std::transform(shape.begin(), shape.end(), std::back_inserter(point), dushechkina::getFront);
  std::sort(shape.begin(), shape.end());

  out << "Vertices: " << vertices << "\n";
  out << "Triangles: " << tri << "\n";
  out << "Squares: " << squ << "\n";
  out << "Rectangles: " << rec << "\n";
  out << "Points: ";
  std::copy(point.begin(), point.end(), std::ostream_iterator< Point >(out, " "));
  out << "\n";
  out << "Shapes:" << "\n";
  std::copy(shape.begin(), shape.end(), std::ostream_iterator< Shape >(out, "\n"));
}

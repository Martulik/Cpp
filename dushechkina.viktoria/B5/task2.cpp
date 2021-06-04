#include "tasks.hpp"
#include "point.hpp"

#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <iterator>

void dushechkina::task2(std::istream& in, std::ostream& out)
{
  std::vector< Shape > shape;
  std::istream_iterator< Shape > firstIterator(in);
  std::istream_iterator< Shape > lastIterator;
  std::copy(firstIterator, lastIterator, std::back_inserter(shape));

  if (in.fail() && !in.eof())
  {
    throw std::invalid_argument("Invalid input");
  }

  int vertices = std::accumulate(shape.begin(), shape.end(), 0, dushechkina::summarizeVertices);
  int tri= std::count_if(shape.begin(), shape.end(), isTriangle);
  int rec = std::count_if(shape.begin(), shape.end(), isRectangle);
  int square = std::count_if(shape.begin(), shape.end(), isSquare);

  shape.erase(std::remove_if(shape.begin(), shape.end(), isPentagon), shape.end());
  std::vector< Point > points;
  std::transform(shape.begin(), shape.end(), std::back_inserter(points), dushechkina::getFront);
  std::sort(shape.begin(), shape.end());

  out << "Vertices: " << vertices << "\n";
  out << "Triangles: " << tri << "\n";
  out << "Squares: " << square << "\n";
  out << "Rectangles: " << rec << "\n";
  out << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator< Point >(out, " "));
  out << "\n";
  out << "Shapes:" << "\n";
  std::copy(shape.begin(), shape.end(), std::ostream_iterator< Shape >(out, "\n"));
}

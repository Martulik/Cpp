#include "tasks.hpp"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>

#include "tools.hpp"
#include "shape.hpp"

int murzakanov::task2(std::istream& in, std::ostream& out)
{
  std::istream_iterator< murzakanov::Shape > firstIterator(in);
  std::istream_iterator< murzakanov::Shape > lastIterator;
  std::vector< murzakanov::Shape > shapes(firstIterator, lastIterator);
  if (shapes.size() == 0)
  {
    std::exit(1);
  }
  int vertices = murzakanov::calculateVertices(shapes);
  int triangles = 0;
  int rectangles = 0;
  int squares = 0;
  if (std::all_of(shapes.begin(), shapes.end(), murzakanov::checkIsRectangle))
  {
    rectangles++;
  }
  if (std::all_of(shapes.begin(), shapes.end(), murzakanov::checkIsSquare))
  {
    squares++;
  }
  out << "Vertices: " << vertices << "\n";
  out << "Triangles: " << triangles << "\n";
  out << "Squares: " << squares << "\n";
  out << "Rectangles: " << rectangles << "\n";
  out << "Shapes:" << "\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< murzakanov::Shape >(out, "\n"));
  return 0;
}

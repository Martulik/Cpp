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

  out << rectangles << "\n";
  out << squares << "\n";
  return 0;
}

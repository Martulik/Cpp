#include "tasks.hpp"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>

#include "tools.hpp"
#include "shape.hpp"

size_t returnSize(const murzakanov::Shape shp)
{
  return shp.size();
}

int murzakanov::task2(std::istream& in, std::ostream& out)
{
  std::istream_iterator< murzakanov::Shape > firstIterator(in);
  std::istream_iterator< murzakanov::Shape > lastIterator;
  std::vector< murzakanov::Shape > shapes(firstIterator, lastIterator);
  if (shapes.size() == 0)
  {
    return 0;
  }
  int vertices = murzakanov::calculateVertices(shapes);
  int triangles = 0;
  int rectangles = 0;
  int squares = 0;
  if (std::all_of(shapes.begin(), shapes.end(), murzakanov::checkIsSquare))
  {
    squares++;
    rectangles++;
  }

  if (std::all_of(shapes.begin(), shapes.end(), murzakanov::checkIsRectangle))
  {
    rectangles++;
  }
  std::vector< murzakanov::Point > points;
  for (size_t i = 0; i < shapes.size(); i++)
  {
    points.push_back(shapes[i][0]);
  }
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

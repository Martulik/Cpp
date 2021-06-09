#include "tasks.hpp"

#include <iostream>
#include <numeric>
#include <functional>

#include "shape.hpp"
#include "tools.hpp"

namespace lab = shkurov;

void lab::task2(std::istream& in, std::ostream& out)
{
  std::vector< lab::Shape > shapes;

  using istreamIt = std::istream_iterator< lab::Shape >;
  std::copy(istreamIt(in), istreamIt(), std::back_inserter(shapes));
  if (in.fail() && !in.eof())
  {
    throw std::invalid_argument("");
  }
  unsigned int vertices = std::accumulate(shapes.cbegin(), shapes.cend(), 0, countVertices);

  tupleCount counts = std::accumulate(shapes.cbegin(), shapes.cend(), tupleCount(0, 0, 0), accumFigures);

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), isPentagon), shapes.end());

  std::vector < Point > points(shapes.size());
  std::transform(shapes.cbegin(), shapes.cend(), points.begin(), getPoint);

  auto border = std::partition(shapes.begin(), shapes.end(), isTriangle);
  border = std::partition(border, shapes.end(), isSquare);
  std::partition(border, shapes.end(), isRectangle);

  out << "Vertices: " << vertices << '\n';
  out << "Triangles: " << std::get< 0 >(counts) << '\n';
  out << "Squares: " << std::get< 1 >(counts) << '\n';
  out << "Rectangles: " << std::get< 2 >(counts) << '\n';
  out << "Points: ";
  std::copy(points.cbegin(), points.cend(), std::ostream_iterator< Point >(out, " "));
  out << '\n' << "Shapes:" << '\n';
  std::copy(shapes.cbegin(), shapes.cend(), std::ostream_iterator< Shape >(out, "\n"));
}

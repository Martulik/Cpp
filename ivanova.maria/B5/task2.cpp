#include "task2.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include "point.hpp"

namespace iva = ivanova;

int iva::task2(std::istream &in, std::ostream &out)
{
  if (!in)
  {
    std::cerr << "failed reading";
    exit(1);
  }
  using uint = unsigned int;
  std::vector< Shape > shapes((std::istream_iterator< Shape >(in)), std::istream_iterator< Shape >());
  uint vert = std::accumulate(shapes.begin(), shapes.end(), 0, countVertices);
  uint tri = std::count_if(shapes.begin(), shapes.end(), isTriangle);
  uint sqr = std::count_if(shapes.begin(), shapes.end(), isSquare);
  uint rect = std::count_if(shapes.begin(), shapes.end(), isRect);
  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), isPentagon), shapes.end());
  std::vector< Point > points;
  points.reserve(shapes.size());
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points), getFront);
  std::sort(shapes.begin(), shapes.end(), compare);
  out << "Vertices: " << vert << '\n';
  out << "Triangles: " << tri << '\n';
  out << "Squares: " << sqr << '\n';
  out << "Rectangles: " << rect << '\n';
  out << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator< Point >(out, " "));
  out << "\nShapes:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< Shape >(out, "\n"));
  return 0;
}

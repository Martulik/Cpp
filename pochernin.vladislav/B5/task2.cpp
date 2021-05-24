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



  out << "Verticies: " << countOfVertices << "\n";
  out << "Triangles: " << countOfTriangles << "\n";
}

#include "task2.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <vector>
#include "shape.hpp"

namespace dan = doroshin;

bool shapeOrder(const dan::Shape& lhs, const dan::Shape& rhs)
{
  if(dan::isRectangle(lhs) && dan::isRectangle(rhs)) {
    return dan::isSquare(lhs);
  }
  return lhs.points_.size() < rhs.points_.size();
}

struct StatCounter
{
  int triangles = 0;
  int squares = 0;
  int rectangles = 0;
  int vertices = 0;

  void operator()(const dan::Shape& shape)
  {
    vertices += shape.points_.size();
    triangles += dan::isTriangle(shape);
    rectangles += dan::isRectangle(shape);
    squares += dan::isSquare(shape);
  }
};

int dan::task2(std::istream& in, std::ostream& out, std::ostream& err)
{
  std::vector< dan::Shape > shapes;
  // 1. Input
  std::istream_iterator< dan::Shape > iBegin(in), iEnd;
  std::move(iBegin, iEnd, std::back_inserter(shapes));
  if(in.fail() && !in.eof()) {
    err << "Invalid shape\n";
    return 1;
  }
  // 2+3. Count vertices & shapes
  StatCounter shape_stats = std::for_each(shapes.begin(), shapes.end(), StatCounter());
  // 4. Delete pentagons
  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), dan::isPentagon), shapes.end());
  // 5. Get any point
  std::vector< dan::Point > points;
  points.reserve(shapes.size());
  for(auto&& shape: shapes) {
    points.emplace_back(shape.points_.front());
  }
  // 6. Sort by number of vertices
  std::sort(shapes.begin(), shapes.end(), shapeOrder);
  // 7. Output
  out << "Vertices: " << shape_stats.vertices << '\n'
      << "Triangles: " << shape_stats.triangles << '\n'
      << "Squares: " << shape_stats.squares << '\n'
      << "Rectangles: " << shape_stats.rectangles << '\n';
  out << "Points: ";
  std::ostream_iterator< dan::Point > output_p(out, " ");
  std::copy(points.begin(), points.end(), output_p);
  out << '\n';
  out << "Shapes:\n";
  std::ostream_iterator< dan::Shape > output_s(out, "\n");
  std::copy(shapes.begin(), shapes.end(), output_s);
  return 0;
}


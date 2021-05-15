#include "task2.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#include "shape.hpp"

namespace lab = ezerinia;

void lab::task2(std::istream &in, std::ostream &out)
{
  if (!in) {
    throw std::runtime_error("Read fail");
  }
  std::vector< Shape > shapes((std::istream_iterator< Shape >(in)), std::istream_iterator< Shape >());
  int vertices = 0;
  int triangles = 0;
  int squares = 0;
  int rectangles = 0;

  std::vector< Point > points;
  //for (auto &&shape : shapes) {
  size_t size = shapes.size();
  for (int i = 0; i < size; i++) {
    vertices += shapes[i].size();
    if (shapes[i].size() == 3) {
      triangles++;
    } else if (shapes[i].size() == 4) {
      rectangles++;
      if (isSideEqual(shapes[i])) {
        squares++;
      }
    }
    if (shapes[i].size() == 5) {
      shapes.erase(shapes.begin() + i);
      continue;
    }
    points.push_back(shapes[i].front());
  }

//  shapes.erase(std::remove_if(shapes.begin(), shapes.end(),
//                              [](const Shape &shape) {
//                                return shape.size() == 5;
//                              }), shapes.end());

  std::sort(shapes.begin(), shapes.end());
  out << "Vertices: " << vertices << "\n";
  out << "Triangles: " << triangles << "\n";
  out << "Squares: " << squares << "\n";
  out << "Rectangles: " << rectangles << "\n";
  out << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator< Point >(out, " "));
  out << "\nShapes:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< Shape >(out, "\n"));
}

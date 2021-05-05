#include "task2.hpp"
#include <iostream>
#include <vector>
#include <iterator>

#include <algorithm>

#include "shape.hpp"

void ezerinia::task2()
{
  int vertices = 0;
  if (!std::cin) {
    throw std::runtime_error("Read fail");
  }
  std::vector< Shape > shapes((std::istream_iterator< Shape >(std::cin)), std::istream_iterator< Shape >());

  int triangles = 0;
  int squares = 0;
  int rectangles = 0;

  std::vector< Point > points(shapes.size());

  for (unsigned int i = 0; i < shapes.size(); i++) {
    points.push_back(shapes[i].front());
    vertices += shapes[i].size();
    if (shapes[i].size() == 3) {
      triangles++;
    } else if (shapes[i].size() == 4) {
      if (isSidesEqual(shapes[i])) {
        squares++;
      } else {
        rectangles++;
      }
    } else if (shapes[i].size() == 5) {
      shapes.erase(shapes.begin() + i);
    }
  }

  std::cout << "Vertices: " << vertices << "\n";
  std::cout << "Triangles: " << triangles << "\n";
  std::cout << "Squares: " << squares << "\n";
  std::cout << "Rectangles: " << rectangles << "\n";
  std::cout << "Points: " << points << "\n";

  std::cout << "Shapes:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< Shape >(std::cout, "\n"));

}

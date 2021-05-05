#include "task2.hpp"
#include <iostream>
#include <istream>
#include <vector>
//#include <iterator>
#include <functional>
#include "shape.hpp"

namespace lab = ezerinia;

void lab::task2()
{
  int vertices = 0;
  if (!std::cin) {
    throw std::runtime_error("Read fail");
  }
  std::vector< lab::Shape > shapes;
  //{std::istream_iterator< lab::Shape >{std::cin}, std::istream_iterator< lab::Shape >{}};
  while (std::cin) {
    lab::Shape shape;
    std::cin >> shape;
    shapes.push_back(shape);
  }
  int triangles = 0;
  int squares = 0;
  int rectangles = 0;

  std::vector< lab::Point > points(shapes.size());

  for (int i = 0; i < shapes.size(); i++) {
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
  //std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< lab::Shape >(std::cout, "\n"));
  for (int i = 0; i < shapes.size(); i++) {
    std::cout << shapes[i] << "\n";
  }
}

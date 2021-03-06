#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

namespace dan = doroshin;

/*
  This program makes a composite shape, adding its elements one by one
  Examples:
  >>> 1
    $ ./lab
    circle 1 2 3^D^D
    Result:
    Frame: (1, 2) w: 6 h: 6
    Area: 28.2743
  >>> 2
    $ ./lab
    rectangle 7 1 2 5^D^D
    Result:
    Frame: (7, 1) w: 2 h: 5
    Area: 10
  >>> 3
    $ ./lab
    circle 3 4 5^J
    rectangle 3 4 5 6^D^D
    Result:
    Frame: (1.75, 3) w: 7.5 h: 8
    Area: 58.2743
*/

void print_shape(std::ostream& out, const dan::Shape& s)
{
  dan::rectangle_t frame = s.getFrameRect();
  out << "Frame: (" << frame.pos.x << ", " << frame.pos.y
      << ") w: " << frame.width << " h: " << frame.height << std::endl
      << "Area: " << s.getArea() << std::endl;
}

dan::Circle input_circle(std::istream& in)
{
  double x_pos = 0, y_pos = 0, r = 0;
  in >> x_pos >> y_pos >> r;
  return dan::Circle {{x_pos, y_pos}, r};
}

dan::Rectangle input_rectangle(std::istream& in)
{
  double x_pos = 0, y_pos = 0, w = 0, h = 0;
  in >> x_pos >> y_pos >> w >> h;
  return dan::Rectangle{w, h, {x_pos, y_pos}};
}

std::unique_ptr<dan::Shape> input_shape(std::istream& in)
{
  std::string line_;
  std::getline(in, line_);
  std::istringstream line(line_);

  std::string type;
  line >> type;

  if(type == "circle") {
    dan::Circle c = input_circle(line);
    if(in.fail()) {
      std::cerr << "Incorrect parameters" << std::endl;
      return nullptr;
    }
    return dan::make_shape(c);
  }
  else if(type == "rectangle") {
    dan::Rectangle r = input_rectangle(line);
    if(in.fail()) {
      std::cerr << "Incorrect parameters" << std::endl;
      return nullptr;
    }
    return dan::make_shape(r);
  }
  else {
    std::cerr << "Unknown shape" << std::endl;
    return nullptr;
  }
}

int main()
{
  dan::CompositeShape aggregate;
  while(!std::cin.eof()) {
    std::unique_ptr<dan::Shape> next = input_shape(std::cin);
    std::skipws(std::cin);
    if(!next)
      return 0;
    aggregate.add(std::move(next));
  }
  std::cout << "\nResult:\n";
  print_shape(std::cout, aggregate);
  return 0;
}

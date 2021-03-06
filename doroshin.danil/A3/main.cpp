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
  This program echos the parameters of an inputted shape
  Usage:
    argument - type of the shape to use
      ./lab circle
      ./lab rectangle
      ./lab composite
    stdin - shape parameters
    Circle:
      "x y r" - one line with three floating point values
    Rectangle:
      "x y w h" - one line with four floating point values
    Composite:
      "type (parameters)"
        type - one of circle/rectangle
        parameters - same as above
        Consumes an arbitrary amount of lines. Finishes on EOF.
  Examples:
  >>> 1
    $ ./lab circle
    3 4 5^J
    Circle:
    Frame: (3, 4) w: 10 h: 10
    Area: 78.5398
  >>> 2
    $ ./lab rectangle
    7 1 2 5^J
    Rectangle:
    Frame: (7, 1) w: 2 h: 5
    Area: 10
  >>> 3
    $ ./lab composite
    circle 1 2 3^J
    Circle:
    Frame: (1, 2) w: 6 h: 6
    Area: 28.2743
    rectangle 3 4 5 6^J
    Rectangle:
    Frame: (3, 4) w: 5 h: 6
    Area: 30
    ^D
    Composite:
    Frame: (1.75, 3) w: 7.5 h: 8
    Area: 58.2743
*/

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

void print(std::ostream& out, const dan::Shape& s)
{
  dan::rectangle_t frame = s.getFrameRect();
  out << "Frame: (" << frame.pos.x << ", " << frame.pos.y
      << ") w: " << frame.width << " h: " << frame.height << std::endl
      << "Area: " << s.getArea() << std::endl;
}

void print(std::ostream& out, const dan::Circle& c)
{
  out << "Circle:" << std::endl;
  print(out, static_cast<const dan::Shape&>(c));
}

void print(std::ostream& out, const dan::Rectangle& r)
{
  out << "Rectangle:" << std::endl;
  print(out, static_cast<const dan::Shape&>(r));
}

void print(std::ostream& out, const dan::CompositeShape& s)
{
  out << "Composite:" << std::endl;
  print(out, static_cast<const dan::Shape&>(s));
}

int echo_circle()
{
  std::string line;
  std::getline(std::cin, line);
  std::istringstream in(line);

  dan::Circle c = input_circle(in);
  if(in.fail()) {
    std::cerr << "Incorrect parameters" << std::endl;
    return 1;
  }

  print(std::cout, c);
  return 0;
}

int echo_rectangle()
{
  std::string line;
  std::getline(std::cin, line);
  std::istringstream in(line);

  dan::Rectangle r = input_rectangle(in);
  if(in.fail()) {
    std::cerr << "Incorrect parameters" << std::endl;
    return 1;
  }

  print(std::cout, r);
  return 0;
}

int echo_composite()
{
  dan::CompositeShape shape;
  while(!std::cin.eof()) {
    std::string line;
    std::getline(std::cin, line);
    if(line.empty())
      break;
    std::istringstream in(line);

    std::string type;
    in >> type;

    if(type == "circle") {
      dan::Circle c = input_circle(in);
      if(in.fail()) {
        std::cerr << "Incorrect parameters" << std::endl;
        return 1;
      }
      print(std::cout, c);
      shape.add(dan::make_shape(dan::Circle(c)));
    }
    else if(type == "rectangle") {
      dan::Rectangle r = input_rectangle(in);
      if(in.fail()) {
        std::cerr << "Incorrect parameters" << std::endl;
        return 1;
      }
      print(std::cout, r);
      shape.add(dan::make_shape(dan::Rectangle(r)));
    }
    else if(type.empty())
      break;
    else {
      std::cerr << "Unknown shape" << std::endl;
      return 1;
    }
  }
  print(std::cout, shape);
  return 0;
}

int main(int argc, char* argv[])
{
  if(argc > 1) {
    if(!strcmp(argv[1], "rectangle")) {
      return echo_rectangle();
    }
    else if(!strcmp(argv[1], "circle")) {
      return echo_circle();
    }
    else if(!strcmp(argv[1], "composite")) {
      return echo_composite();
    }
    else
      std::cout << "Unknown shape" << std::endl;
  }
  else
    std::cout << "No arguments given" << std::endl;
  return 0;
}

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

namespace d = doroshin;

d::Circle input_circle(std::istream& in)
{
  double x_pos = 0, y_pos = 0, r = 0;
  in >> x_pos >> y_pos >> r;
  return d::Circle {{x_pos, y_pos}, r};
}

d::Rectangle input_rectangle(std::istream& in)
{
  double x_pos = 0, y_pos = 0, w = 0, h = 0;
  in >> x_pos >> y_pos >> w >> h;
  return d::Rectangle(d::rectangle_t{w, h, {x_pos, y_pos}});
}

void print(std::ostream& out, const d::Shape& s)
{
  d::rectangle_t frame = s.getFrameRect();
  out << "Frame: (" << frame.pos.x << ", " << frame.pos.y
      << ") w: " << frame.width << " h: " << frame.height << std::endl
      << "Area: " << s.getArea() << std::endl;
}

void print(std::ostream& out, const d::Circle& c)
{
  out << "Circle:" << std::endl;
  print(out, static_cast<const d::Shape&>(c));
}

void print(std::ostream& out, const d::Rectangle& r)
{
  out << "Rectangle:" << std::endl;
  print(out, static_cast<const d::Shape&>(r));
}

void print(std::ostream& out, const d::CompositeShape& s)
{
  out << "Composite:" << std::endl;
  print(out, static_cast<const d::Shape&>(s));
}

int echo_circle()
{
  std::string line;
  std::getline(std::cin, line);
  std::istringstream in(line);

  d::Circle c = input_circle(in);
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

  d::Rectangle r = input_rectangle(in);
  if(in.fail()) {
    std::cerr << "Incorrect parameters" << std::endl;
    return 1;
  }

  print(std::cout, r);
  return 0;
}

int echo_composite()
{
  d::CompositeShape shape;
  while(!std::cin.eof()) {
    std::string line;
    std::getline(std::cin, line);
    if(line.empty())
      break;
    std::istringstream in(line);

    std::string type;
    in >> type;

    if(type == "circle") {
      d::Circle c = input_circle(in);
      if(in.fail()) {
        std::cerr << "Incorrect parameters" << std::endl;
        return 1;
      }
      print(std::cout, c);
      shape.add(c);
    }
    else if(type == "rectangle") {
      d::Rectangle r = input_rectangle(in);
      if(in.fail()) {
        std::cerr << "Incorrect parameters" << std::endl;
        return 1;
      }
      print(std::cout, r);
      shape.add(r);
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

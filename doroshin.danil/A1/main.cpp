#include <iostream>
#include <cassert>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

void print_shape(const char* name, const Shape& s)
{
  std::cout << name << ": (" << s.getFrameRect().pos.x << ", " << s.getFrameRect().pos.y
    << ") area: " << s.getArea() << std::endl;
}

bool check_position(const Shape& s, const point_t other)
{
  point_t pos = s.getFrameRect().pos;
  return pos.x == other.x && pos.y == other.y;
}

int main()
{
  const point_t start {3, 4};
  const point_t delta {-1, 6};
  const point_t finish{2, 10};

  Circle c(start, 2);
  print_shape("Circle", c);
  c.move(delta);
  assert(check_position(c, finish));

  const double w = 2, h = 3;
  Rectangle r{w, h, start};
  print_shape("Rectangle", r);
  r.move(delta);
  assert(check_position(r, finish));
  assert(r.getArea() == w * h);

  return 0;
}

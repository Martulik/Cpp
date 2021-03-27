#include <iostream>
#include <cassert>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

namespace dan = doroshin;
using namespace dan::literals;

void print_shape(const char* name, const dan::Shape& s)
{
  std::cout << name << ": (" << s.getFrameRect().pos.x << ", " << s.getFrameRect().pos.y
    << ") area: " << s.getArea() << '\n';
}

bool check_position(const dan::Shape& s, const dan::point_t other)
{
  dan::point_t pos = s.getFrameRect().pos;
  return pos.x == other.x && pos.y == other.y;
}

int main()
{
  const dan::point_t start {3, 4};
  const dan::point_t delta {-1, 6};
  const dan::point_t finish{2, 10};

  dan::Circle c(start, 2_ud);
  print_shape("Circle", c);
  c.move(delta);
  assert(check_position(c, finish));

  const dan::udouble_t w = 2_ud, h = 3_ud;
  dan::Rectangle r{w, h, start};
  print_shape("Rectangle", r);
  r.move(delta);
  assert(check_position(r, finish));
  assert(r.getArea() == w * h);

  return 0;
}

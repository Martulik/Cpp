#include <iostream>
#include <cassert>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

namespace dan = doroshin;
using namespace dan::literals;

void print_shape(const dan::Shape& s)
{
  std::cout << "Shape: (" << s.getFrameRect().pos.x << ", " << s.getFrameRect().pos.y
    << ") area: " << s.getArea() << '\n';
}

bool check_position(const dan::Shape& s, const dan::point_t other)
{
  dan::point_t pos = s.getFrameRect().pos;
  return pos.x == other.x && pos.y == other.y;
}

int main()
{
  const dan::point_t move_to{2, 10};

  const dan::point_t p1{-1, 7}, p2{4, -6}, p3{2, 0}, p4{-8, -3};
  std::unique_ptr< dan::Shape > shapes[] = {
    std::make_unique< dan::Circle >(p1, 3_ud),
    std::make_unique< dan::Rectangle >(2_ud, 5_ud, p2),
    std::make_unique< dan::CompositeShape >
        (dan::Circle(p3, 4_ud), dan::Rectangle(5_ud, 1_ud, p4))
  };

  for(auto& shape: shapes) {
    print_shape(*shape);
    shape->move(move_to, true);
    check_position(*shape, move_to);
  }

  return 0;
}

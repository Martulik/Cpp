
#include <cassert>
#include <iostream>
#include "composite-shape.hpp"

namespace d = doroshin;

void test_move_rel(d::Shape& s, d::point_t vec)
{
  const auto eq = [](const d::rectangle_t& lhs, const d::rectangle_t& rhs) {
    return lhs.height == rhs.height && lhs.width == rhs.width;
  };
  d::rectangle_t orig_frame = s.getFrameRect();
  s.move_rel(vec);
  assert(eq(orig_frame, s.getFrameRect()));
}

void test_move_abs(d::Shape& s, d::point_t vec)
{
  const auto eq = [](const d::rectangle_t& lhs, const d::rectangle_t& rhs) {
    return lhs.height == rhs.height && lhs.width == rhs.width;
  };
  d::rectangle_t orig_frame = s.getFrameRect();
  s.move_rel(vec);
  assert(eq(orig_frame, s.getFrameRect()));
}

void test_move_circle()
{
  d::Circle c{{1, 2}, 3};

  test_move_rel(c, {1, 2});
  test_move_rel(c, {-5, 7});
  test_move_abs(c, {65, -33});
}

void test_move_rectangle()
{
  d::Rectangle r(d::rectangle_t {3, 4, {1, 2}});

  test_move_rel(r, {1, 2});
  test_move_rel(r, {-5, 7});
  test_move_abs(r, {65, -33});
}

void test_move_composite()
{
  d::CompositeShape s {d::Rectangle(d::rectangle_t {2, 3, {-1, 0}}), d::Circle{{1, 1}, 2}};

  test_move_rel(s, {1, 2});
  test_move_rel(s, {-5, 7});
  test_move_abs(s, {65, -33});
}

int main()
{
  test_move_circle();
  test_move_rectangle();
  test_move_composite();
  return 0;
}

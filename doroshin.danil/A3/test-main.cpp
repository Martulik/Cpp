#include <cassert>
#include <iostream>
#include "composite-shape.hpp"

namespace d = doroshin;

void test_move_circle()
{
  const auto eq = [](const d::rectangle_t& lhs, const d::rectangle_t& rhs) {
    return lhs.height == rhs.height && lhs.width == rhs.width;
  };
  d::Circle c{{1, 2}, 3};
  d::rectangle_t orig_frame = c.getFrameRect();
  c.move_rel({1, 2});
  assert(eq(orig_frame, c.getFrameRect()));
  c.move_rel({-5, 7});
  assert(eq(orig_frame, c.getFrameRect()));
  c.move_abs({65, -33});
  assert(eq(orig_frame, c.getFrameRect()));
}

void test_move_rectangle()
{
  const auto eq = [](const d::rectangle_t& lhs, const d::rectangle_t& rhs) {
    return lhs.height == rhs.height && lhs.width == rhs.width;
  };
  d::Rectangle r(d::rectangle_t {3, 4, {1, 2}});
  d::rectangle_t orig_frame = r.getFrameRect();
  r.move_rel({1, 2});
  assert(eq(orig_frame, r.getFrameRect()));
  r.move_rel({-5, 7});
  assert(eq(orig_frame, r.getFrameRect()));
  r.move_abs({65, -33});
  assert(eq(orig_frame, r.getFrameRect()));
}

void test_move_composite()
{
  const auto eq = [](const d::rectangle_t& lhs, const d::rectangle_t& rhs) {
    return lhs.height == rhs.height && lhs.width == rhs.width;
  };
  d::CompositeShape s {d::Rectangle(d::rectangle_t {2, 3, {-1, 0}}), d::Circle{{1, 1}, 2}};
  d::rectangle_t orig_frame = s.getFrameRect();
  s.move_rel({1, 2});
  assert(eq(orig_frame, s.getFrameRect()));
  s.move_rel({-5, 7});
  assert(eq(orig_frame, s.getFrameRect()));
  s.move_abs({65, -33});
  assert(eq(orig_frame, s.getFrameRect()));
}

int main()
{
  test_move_circle();
  test_move_rectangle();
  test_move_composite();
  return 0;
}

#include <cassert>
#include <iostream>
#include "composite-shape.hpp"

#define BOOST_TEST_MODULE test
#include <boost/test/included/unit_test.hpp>

namespace d = doroshin;

void test_move_rel(d::Shape& s, d::point_t vec)
{
  const auto eq = [](const d::rectangle_t& lhs, const d::rectangle_t& rhs) {
    return lhs.height == rhs.height && lhs.width == rhs.width;
  };
  d::rectangle_t orig_frame = s.getFrameRect();
  s.move_rel(vec);
  BOOST_CHECK(eq(orig_frame, s.getFrameRect()));
}

void test_move_abs(d::Shape& s, d::point_t vec)
{
  const auto eq = [](const d::rectangle_t& lhs, const d::rectangle_t& rhs) {
    return lhs.height == rhs.height && lhs.width == rhs.width;
  };
  d::rectangle_t orig_frame = s.getFrameRect();
  s.move_rel(vec);
  BOOST_CHECK(eq(orig_frame, s.getFrameRect()));
}

void test_scale(d::Shape& s, double coeff)
{
  double orig = s.getArea();
  double predicted = coeff * coeff * orig;
  s.scale(coeff);
  double n_area = s.getArea();
  BOOST_CHECK(predicted == n_area);
}

BOOST_AUTO_TEST_CASE(move_circle)
{
  d::Circle c{{1, 2}, 3};

  test_move_rel(c, {1, 2});
  test_move_rel(c, {-5, 7});
  test_move_abs(c, {65, -33});
}

BOOST_AUTO_TEST_CASE(move_rectangle)
{
  d::Rectangle r(d::rectangle_t {3, 4, {1, 2}});

  test_move_rel(r, {1, 2});
  test_move_rel(r, {-5, 7});
  test_move_abs(r, {65, -33});
}

BOOST_AUTO_TEST_CASE(move_composite)
{
  d::CompositeShape s {d::Rectangle(d::rectangle_t {2, 3, {-1, 0}}), d::Circle{{1, 1}, 2}};

  test_move_rel(s, {1, 2});
  test_move_rel(s, {-5, 7});
  test_move_abs(s, {65, -33});
}

BOOST_AUTO_TEST_CASE(scale_circle)
{
  d::Circle c{{0, 0}, 2};
  test_scale(c, 3);
  test_scale(c, 0.5);
}

BOOST_AUTO_TEST_CASE(scale_rectangle)
{
  d::Rectangle r(d::rectangle_t {3, 4, {1, 2}});
  test_scale(r, 5);
  test_scale(r, 0.3);
}

BOOST_AUTO_TEST_CASE(scale_composite)
{
  d::CompositeShape s{d::Rectangle(d::rectangle_t {2, 3, {-1, 0}}), d::Circle{{1, 1}, 2}};
  test_scale(s, 4.5);
  test_scale(s, 0.1);
}

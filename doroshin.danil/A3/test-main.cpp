#include <cassert>
#include <iostream>
#include "composite-shape.hpp"

#define BOOST_TEST_MODULE test
#include <boost/test/included/unit_test.hpp>

namespace dan = doroshin;

bool equal_size(const dan::rectangle_t& lhs, const dan::rectangle_t& rhs)
{
  return lhs.height == rhs.height && lhs.width == rhs.width;
}

void test_move_rel(dan::Shape& s, dan::point_t vec)
{
  dan::rectangle_t orig_frame = s.getFrameRect();
  s.move(vec);
  BOOST_CHECK(equal_size(orig_frame, s.getFrameRect()));
}

void test_move_abs(dan::Shape& s, dan::point_t point)
{
  dan::rectangle_t orig_frame = s.getFrameRect();
  s.move(point, true);
  BOOST_CHECK(equal_size(orig_frame, s.getFrameRect()));
}

void test_scale(dan::Shape& s, double coeff)
{
  double orig = s.getArea();
  double predicted = coeff * coeff * orig;
  s.scale(coeff);
  double n_area = s.getArea();
  BOOST_CHECK(predicted == n_area);
}

BOOST_AUTO_TEST_CASE(move_circle)
{
  dan::Circle c{{1, 2}, 3};

  test_move_rel(c, {1, 2});
  test_move_rel(c, {-5, 7});
  test_move_abs(c, {65, -33});
}

BOOST_AUTO_TEST_CASE(move_rectangle)
{
  dan::Rectangle r{3, 4, {1, 2}};

  test_move_rel(r, {1, 2});
  test_move_rel(r, {-5, 7});
  test_move_abs(r, {65, -33});
}

BOOST_AUTO_TEST_CASE(move_composite)
{
  dan::CompositeShape s;
  s.add(std::make_unique<dan::Rectangle>(2, 3, dan::point_t{-1, 0}));
  s.add(std::make_unique<dan::Circle>(dan::point_t{1, 1}, 2));

  test_move_rel(s, {1, 2});
  test_move_rel(s, {-5, 7});
  test_move_abs(s, {65, -33});
}

BOOST_AUTO_TEST_CASE(scale_circle)
{
  dan::Circle c{{0, 0}, 2};
  test_scale(c, 3);
  test_scale(c, 0.5);
}

BOOST_AUTO_TEST_CASE(scale_rectangle)
{
  dan::Rectangle r{3, 4, {1, 2}};
  test_scale(r, 5);
  test_scale(r, 0.3);
}

BOOST_AUTO_TEST_CASE(scale_composite)
{
  dan::CompositeShape s;
  s.add(std::make_unique<dan::Rectangle>(2, 3, dan::point_t{-1, 0}));
  s.add(std::make_unique<dan::Circle>(dan::point_t{1, 1}, 2));
  test_scale(s, 4.5);
  test_scale(s, 0.1);
}

BOOST_AUTO_TEST_CASE(copy_composite)
{
  dan::CompositeShape src;
  src.add(std::make_unique<dan::Rectangle>(2, 3, dan::point_t{-1, 0}));
  src.add(std::make_unique<dan::Circle>(dan::point_t{1, 1}, 2));

  dan::CompositeShape cpy(src);

  BOOST_CHECK(src.getArea() == cpy.getArea());
  BOOST_CHECK(equal_size(src.getFrameRect(), cpy.getFrameRect()));
  BOOST_CHECK(src.getFrameRect().pos.x == cpy.getFrameRect().pos.x);
  BOOST_CHECK(src.getFrameRect().pos.y == cpy.getFrameRect().pos.y);
}

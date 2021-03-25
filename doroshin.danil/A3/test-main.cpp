#define BOOST_TEST_MODULE test
#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

namespace dan = doroshin;
using namespace dan::literals;

void equal_size(const dan::rectangle_t& lhs, const dan::rectangle_t& rhs)
{
  BOOST_CHECK_EQUAL(lhs.height, rhs.height);
  BOOST_CHECK_EQUAL(lhs.width, rhs.width);
}

void test_move_rel(dan::Shape& s, dan::point_t vec)
{
  dan::rectangle_t orig_frame = s.getFrameRect();
  s.move(vec);
  equal_size(orig_frame, s.getFrameRect());
}

void test_move_abs(dan::Shape& s, dan::point_t point)
{
  dan::rectangle_t orig_frame = s.getFrameRect();
  s.move(point, true);
  equal_size(orig_frame, s.getFrameRect());
}

void test_scale(dan::Shape& s, dan::udouble_t coeff)
{
  const double tolerance = std::numeric_limits<double>::epsilon();
  double orig = s.getArea();
  double predicted = coeff * coeff * orig;
  s.scale(coeff);
  double n_area = s.getArea();
  BOOST_CHECK_CLOSE_FRACTION(predicted, n_area, tolerance);
}

BOOST_AUTO_TEST_CASE(move_circle)
{
  dan::Circle c{{1, 2}, 3_ud};

  test_move_rel(c, {1, 2});
  test_move_rel(c, {-5, 7});
  test_move_abs(c, {65, -33});
}

BOOST_AUTO_TEST_CASE(move_rectangle)
{
  dan::Rectangle r{3_ud, 4_ud, {1, 2}};

  test_move_rel(r, {1, 2});
  test_move_rel(r, {-5, 7});
  test_move_abs(r, {65, -33});
}

BOOST_AUTO_TEST_CASE(move_composite)
{
  dan::CompositeShape s(
      dan::Rectangle{2_ud, 3_ud, dan::point_t{-1, 0}},
      dan::Circle{dan::point_t{1, 1}, 2_ud});

  test_move_rel(s, {1, 2});
  test_move_rel(s, {-5, 7});
  test_move_abs(s, {65, -33});
}

BOOST_AUTO_TEST_CASE(scale_circle)
{
  dan::Circle c{{0, 0}, 2_ud};
  test_scale(c, 3_ud);
  test_scale(c, 0.5_ud);
}

BOOST_AUTO_TEST_CASE(scale_rectangle)
{
  dan::Rectangle r{3_ud, 4_ud, {1, 2}};
  test_scale(r, 5_ud);
  test_scale(r, 0.3_ud);
}

BOOST_AUTO_TEST_CASE(scale_composite)
{
  dan::CompositeShape s(
      dan::Rectangle{2_ud, 3_ud, dan::point_t{-1, 0}},
      dan::Circle{dan::point_t{1, 1}, 2_ud});
  test_scale(s, 4.5_ud);
  test_scale(s, 0.1_ud);
}

BOOST_AUTO_TEST_CASE(copy_composite)
{
  dan::CompositeShape src(
      dan::Rectangle{2_ud, 3_ud, dan::point_t{-1, 0}},
      dan::Circle{dan::point_t{1, 1}, 2_ud});

  dan::CompositeShape cpy(src);

  BOOST_CHECK_EQUAL(src.getArea(), cpy.getArea());
  equal_size(src.getFrameRect(), cpy.getFrameRect());
  BOOST_CHECK_EQUAL(src.getFrameRect().pos.x, cpy.getFrameRect().pos.x);
  BOOST_CHECK_EQUAL(src.getFrameRect().pos.y, cpy.getFrameRect().pos.y);
}

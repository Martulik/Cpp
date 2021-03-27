#include "test-utility.hpp"

namespace dan = doroshin;

void dan::equal_size(const dan::rectangle_t& lhs, const dan::rectangle_t& rhs)
{
  BOOST_CHECK_EQUAL(lhs.height, rhs.height);
  BOOST_CHECK_EQUAL(lhs.width, rhs.width);
}

void dan::test_move_rel(dan::Shape& s, dan::point_t vec)
{
  dan::rectangle_t orig_frame = s.getFrameRect();
  s.move(vec);
  equal_size(orig_frame, s.getFrameRect());
}

void dan::test_move_abs(dan::Shape& s, dan::point_t point)
{
  dan::rectangle_t orig_frame = s.getFrameRect();
  s.move(point, true);
  equal_size(orig_frame, s.getFrameRect());
}

void dan::test_scale(dan::Shape& s, dan::udouble_t coeff)
{
  const double tolerance = std::numeric_limits<double>::epsilon();
  double orig = s.getArea();
  double predicted = coeff * coeff * orig;
  s.scale(coeff);
  double n_area = s.getArea();
  BOOST_CHECK_CLOSE_FRACTION(predicted, n_area, tolerance);
}

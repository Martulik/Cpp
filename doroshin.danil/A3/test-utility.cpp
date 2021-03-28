#include "test-utility.hpp"

namespace dan = doroshin;

void dan::equalSize(const dan::rectangle_t& lhs, const dan::rectangle_t& rhs)
{
  BOOST_CHECK_EQUAL(lhs.height, rhs.height);
  BOOST_CHECK_EQUAL(lhs.width, rhs.width);
}

void dan::testMoveRel(dan::Shape& s, dan::point_t vec)
{
  dan::rectangle_t orig_frame = s.getFrameRect();
  s.move(vec);
  equalSize(orig_frame, s.getFrameRect());
}

void dan::testMoveAbs(dan::Shape& s, dan::point_t point)
{
  dan::rectangle_t orig_frame = s.getFrameRect();
  s.move(point, true);
  equalSize(orig_frame, s.getFrameRect());
}

void dan::testScale(dan::Shape& s, dan::udouble_t coeff)
{
  const double tolerance = std::numeric_limits< double >::epsilon();
  double orig = s.getArea();
  double predicted = coeff * coeff * orig;
  s.scale(coeff);
  double n_area = s.getArea();
  BOOST_CHECK_CLOSE_FRACTION(predicted, n_area, tolerance);
}

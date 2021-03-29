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
  double orig_area1 = s.getArea();
  double orig_area2 = dan::getWidth(s) * dan::getHeight(s);
  double predicted1 = coeff * coeff * orig_area1;
  double predicted2 = coeff * coeff * orig_area2;
  s.scale(coeff);
  double n_area1 = s.getArea();
  double n_area2 = dan::getWidth(s) * dan::getHeight(s);
  BOOST_CHECK_CLOSE_FRACTION(predicted1, n_area1, tolerance);
  BOOST_CHECK_CLOSE_FRACTION(predicted2, n_area2, tolerance);
}

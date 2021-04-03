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

template< typename GetArea >
void testScale(dan::Shape& s, dan::udouble_t coeff, GetArea getArea)
{
  const double tolerance = std::numeric_limits< double >::epsilon();
  double orig_area = getArea(s);
  double predicted = coeff * coeff * orig_area;
  s.scale(coeff);
  double new_area = getArea(s);
  BOOST_CHECK_CLOSE_FRACTION(predicted, new_area, tolerance);
}

void dan::testScaleArea(dan::Shape& shape, dan::udouble_t k)
{
  testScale(shape, k,
    [](const dan::Shape& s) {
      return s.getArea();
    });
}

void dan::testScaleFrame(dan::Shape& shape, dan::udouble_t k)
{
  testScale(shape, k,
    [](const dan::Shape& s) {
      return dan::getHeight(s) * dan::getWidth(s);
    });
}

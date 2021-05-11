#ifndef TEST_FUNCTION_HPP
#define TEST_FUNCTION_HPP

#include <boost/test/unit_test.hpp>
#include "shape.hpp"

namespace razukrantov
{
  void checkWidthHeightArea(Shape& shape, rectangle_t frameRect, double startArea);
  void checkDeltaMove(Shape& shape);
  void checkPointMove(Shape& shape);
  void checkScale(Shape& shape);
}

#endif

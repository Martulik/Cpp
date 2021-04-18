#ifndef TEST_FUNC_HPP
#define TEST_FUNC_HPP

#include <boost/test/unit_test.hpp>
#include "shape.hpp"

namespace almuhidat
{
  void checkScale(almuhidat::Shape &shape);
  void checkMoveToPoint(almuhidat::Shape &shape);
  void checkMoveAbs(almuhidat::Shape &shp);
}
#endif
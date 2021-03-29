#ifndef TEST_FUNC_HPP
#define TEST_FUNC_HPP

#include <boost/test/unit_test.hpp>
#include "shape.hpp"

namespace ivanova
{
  void checkScale(ivanova::Shape *shape);
  void checkMoveToPoint(ivanova::Shape *shape);
  void checkMoveAbs(ivanova::Shape *shp);
}
#endif

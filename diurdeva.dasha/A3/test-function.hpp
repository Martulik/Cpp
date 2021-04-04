#ifndef TEST_FUNCTION_HPP
#define TEST_FUNCTION_HPP

#include <boost/test/unit_test.hpp>
#include "shape.hpp"

namespace diurdeva {
  void checkAreaBeforeScale(diurdeva::Shape &shape);
  void checkConstOptionsBeforeMoving(diurdeva::Shape &shape);
}

#endif

#include <boost/test/included/unit_test.hpp>
#include "shape.hpp"

namespace ezerinia {
  void checkWidthHeightArea(Shape *shape, rectangle_t frameRect, double areaBeforeMove);
  void checkMoveAbs(Shape *shape);
  void checkMovePoint(Shape *shape);
  void checkScale(Shape *shape);
}

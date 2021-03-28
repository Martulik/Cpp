#include <boost/test/included/unit_test.hpp>
#include "shape.hpp"

const double accuracy = std::numeric_limits<double>::epsilon();
const double width = 1.0;
const double height = 2.0;
const double radius = 3.0;
const double negativeValue = -1.0;
const double scaleCoef = 2.0;
const double deltaAbsX = 5.0;
const double deltaAbsY = 10.0;
const ezerinia::point_t StartPos{1.0, -1.0};
const ezerinia::point_t FinishPos{-2.0, 2.0};

namespace ezerinia {

  void checkWidthHeightArea(Shape *shape, rectangle_t frameRect, double areaBeforeMove);

  void checkMoveAbs(Shape *shape);

  void checkMovePoint(Shape *shape);

  void checkScale(Shape *shape);

}
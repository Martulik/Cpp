#include "test-func.hpp"

double epsilon = 0.001;

void almuhidat::checkScale(almuhidat::Shape &shape)
{
  double areaBeforeScale = shape.getArea();
  shape.scale(2);
  BOOST_CHECK_CLOSE(areaBeforeScale * 4, shape.getArea(), epsilon);
}

void almuhidat::checkMoveToPoint(almuhidat::Shape &shape)
{
  almuhidat::rectangle_t rectFrame = shape.getFrameRect();
  double areaBeforeMove = shape.getArea();
  shape.move({1.5, 6.0});
  BOOST_CHECK_CLOSE(shape.getFrameRect().width, rectFrame.width, epsilon);
  BOOST_CHECK_CLOSE(shape.getFrameRect().height, rectFrame.height, epsilon);
  BOOST_CHECK_CLOSE(areaBeforeMove, shape.getArea(), epsilon);
}

void almuhidat::checkMoveAbs(almuhidat::Shape &shp)
{
  almuhidat::rectangle_t rectFrame = shp.getFrameRect();
  double areaBeforeMove = shp.getArea();
  shp.move(-12.0, 8.0);
  BOOST_CHECK_CLOSE(shp.getFrameRect().width, rectFrame.width, epsilon);
  BOOST_CHECK_CLOSE(shp.getFrameRect().height, rectFrame.height, epsilon);
  BOOST_CHECK_CLOSE(areaBeforeMove, shp.getArea(), epsilon);
}
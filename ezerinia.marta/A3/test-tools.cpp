#include "test-tools.hpp"

namespace lab = ezerinia;

void lab::checkWidthHeightArea(Shape *shape, rectangle_t frameRect, double areaBeforeMove)
{
  BOOST_CHECK_EQUAL(getWidth(*shape), frameRect.width);
  BOOST_CHECK_EQUAL(getHeight(*shape), frameRect.height);
  BOOST_CHECK_EQUAL(areaBeforeMove, shape->getArea());
}

void lab::checkMoveAbs(Shape *shape)
{
  ezerinia::rectangle_t frameRect = shape->getFrameRect();
  double areaBeforeMove = shape->getArea();
  shape->move(deltaAbsX, deltaAbsY);
  checkWidthHeightArea(shape, frameRect, areaBeforeMove);
}

void lab::checkMovePoint(Shape *shape)
{
  ezerinia::rectangle_t frameRect = shape->getFrameRect();
  double areaBeforeMove = shape->getArea();
  shape->move(FinishPos);
  checkWidthHeightArea(shape, frameRect, areaBeforeMove);
}

void lab::checkScale(Shape *shape)
{
  double areaBeforeScale = shape->getArea();
  shape->scale(scaleCoef);
  BOOST_CHECK_CLOSE(areaBeforeScale * scaleCoef * scaleCoef, shape->getArea(), accuracy);
}

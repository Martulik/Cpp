#include "test-tools.hpp"

const double accuracy = 1000 * std::numeric_limits< double >::epsilon();
const double scaleCoef = 2.0;
const double deltaAbsX = 5.0;
const double deltaAbsY = 10.0;
const ezerinia::point_t FinishPos{-2.0, 2.0};

namespace lab = ezerinia;

void lab::checkWidthHeightArea(Shape *shape, rectangle_t frameRect, double areaBeforeMove)
{
  BOOST_CHECK_CLOSE(getWidth(*shape), frameRect.width, accuracy);
  BOOST_CHECK_CLOSE(getHeight(*shape), frameRect.height, accuracy);
  BOOST_CHECK_CLOSE(areaBeforeMove, shape->getArea(), accuracy);
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

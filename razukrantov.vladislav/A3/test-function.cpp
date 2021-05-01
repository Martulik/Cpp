#include "test-function.hpp"

namespace razukrantov
{
  const double accuracy = 0.0001;
  const double coef = 2.0;
  const double dx = 5.0;
  const double dy = 10.0;
  const razukrantov::point_t finishPos{-20.0, 20.0};
}

void razukrantov::checkWidthHeightArea(Shape& shape, rectangle_t frameRect, double startArea)
{
  BOOST_CHECK_CLOSE(frameRect.width, getWidth(shape), razukrantov::accuracy);
  BOOST_CHECK_CLOSE(frameRect.height, getHeight(shape), razukrantov::accuracy);
  BOOST_CHECK_CLOSE(startArea, shape.getArea(), razukrantov::accuracy);
}

void razukrantov::checkDeltaMove(Shape& shape)
{
  razukrantov::rectangle_t frameRect = shape.getFrameRect();
  double startArea = shape.getArea();
  shape.move(dx, dy);
  checkWidthHeightArea(shape, frameRect, startArea);
}

void razukrantov::checkPointMove(Shape& shape)
{
  razukrantov::rectangle_t frameRect = shape.getFrameRect();
  double startArea = shape.getArea();
  shape.move(finishPos);
  checkWidthHeightArea(shape, frameRect, startArea);
}

void razukrantov::checkScale(Shape& shape)
{
  double startArea = shape.getArea();
  shape.scale(razukrantov::coef);
  BOOST_CHECK_CLOSE(startArea * razukrantov::coef * razukrantov::coef, shape.getArea(), razukrantov::accuracy);
}

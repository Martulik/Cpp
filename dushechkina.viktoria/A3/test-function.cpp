#include "test-function.hpp"

void dushechkina::checkBeforeScale(dushechkina::Shape& shape)
{
  double area = shape.getArea();
  shape.scale(ratio);
  BOOST_CHECK_CLOSE(area * ratio * ratio, shape.getArea(), TOLERANCE);
}

void dushechkina::checkBeforeCenterMoving(dushechkina::Shape& shape)
{
  double width = getWidth(shape);
  double height = getHeight(shape);
  double area = shape.getArea();
  shape.move(newCenter);
  BOOST_CHECK_CLOSE(getWidth(shape), width, TOLERANCE);
  BOOST_CHECK_CLOSE(getHeight(shape), height, TOLERANCE);
  BOOST_CHECK_CLOSE(shape.getArea(), area, TOLERANCE);
}

void dushechkina::checkBeforeDMoving(dushechkina::Shape& shape)
{
  double width = getWidth(shape);
  double height = getHeight(shape);
  double area = shape.getArea();
  shape.move(X,Y);
  BOOST_CHECK_CLOSE(getWidth(shape), width, TOLERANCE);
  BOOST_CHECK_CLOSE(getHeight(shape), height, TOLERANCE);
  BOOST_CHECK_CLOSE(shape.getArea(), area, TOLERANCE);
}

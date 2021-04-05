#include "test-function.hpp"

#include <boost/test/unit_test.hpp>

void diurdeva::checkConstOptionsBeforeMoving(diurdeva::Shape &shape)
{
  double widthBeforeMove = getWidth(shape);
  double heightBeforeMove = getHeight(shape);
  double area = shape.getArea();
  shape.move(newCenter);
  BOOST_CHECK_CLOSE(getWidth(shape), widthBeforeMove, accuracy);
  BOOST_CHECK_CLOSE(getHeight(shape), heightBeforeMove, accuracy);
  BOOST_CHECK_CLOSE(shape.getArea(), area, accuracy);
}

void diurdeva::checkAreaBeforeScale(diurdeva::Shape &shape)
{
  double areaBeforeScale = shape.getArea();
  shape.scale(factor);
  BOOST_CHECK_CLOSE(areaBeforeScale * factor * factor, shape.getArea(), accuracy);
}

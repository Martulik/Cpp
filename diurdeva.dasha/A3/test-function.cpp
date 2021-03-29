#include "test-function.hpp"

const diurdeva::point_t newCenter = { 3.0, 2.0 };
const double factor = 2.0;
const double accuracy = 0,001;

void diurdeva::checkConstOptionsBeforeMoving(Shape* shape)
{
  double widthBeforeMove = getWidth(*shape);
  double heightBeforeMove = getHeight(*shape);
  double area = shape->getArea();
  shape->move(newCenter);
  BOOST_CHECK_CLOSE(getWidth(*shape), widthBeforeMove, accuracy);
  BOOST_CHECK_CLOSE(getHeight(*shape), heightBeforeMove, accuracy);
  BOOST_CHECK_CLOSE(shape->getArea(), area, accuracy);
}

void checkAreaBeforeScale(diurdeva::Shape* shape)
{
  double areaBeforeScale = shape->getArea();
  shape->scale(factor);
  BOOST_CHECK_CLOSE(area * factor * factor, shape->getArea(), accuracy);
}

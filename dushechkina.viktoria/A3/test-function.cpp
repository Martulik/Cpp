#include "test-function.hpp"

const double X = 3.2;
const double Y = 2.56;
const dushechkina::point_t CENTER = { X, Y };
const double RATIO = 6.4;
const double EPSILON = 0.00001;

void dushechkina::checkBeforeScale(Shape* shape)
{
  double areaBefore = shape->getArea();
  shape->scale(RATIO);
  BOOST_CHECK_CLOSE(areaBefore * RATIO * RATIO, shape->getArea(), EPSILON);
}

void dushechkina::checkBeforeCenterMoving(Shape* shape)
{
  double widthBefore = getWidth(*shape);
  double heightBefore = getHeight(*shape);
  double area = shape->getArea();
  shape->move(CENTER);
  BOOST_CHECK_CLOSE(getWidth(*shape), widthBefore, EPSILON);
  BOOST_CHECK_CLOSE(getHeight(*shape), heightBefore, EPSILON);
  BOOST_CHECK_CLOSE(shape->getArea(), area, EPSILON);
}

void dushechkina::checkBeforeDMoving(Shape* shape)
{
  double widthBefore = getWidth(*shape);
  double heightBefore = getHeight(*shape);
  double area = shape->getArea();
  shape->move(X,Y);
  BOOST_CHECK_CLOSE(getWidth(*shape), widthBefore, EPSILON);
  BOOST_CHECK_CLOSE(getHeight(*shape), heightBefore, EPSILON);
  BOOST_CHECK_CLOSE(shape->getArea(), area, EPSILON);
}
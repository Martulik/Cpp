#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE A3

#include <iostream>
#include <cassert>
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

#include <boost/test/included/unit_test.hpp>

void checkMoveToPoint(ivanova::Shape *shape)
{
  ivanova::rectangle_t rectFrame = shape->getFrameRect();
  double areaBeforeMove = shape->getArea();
  shape->move({1.5, 6.0});
  BOOST_CHECK_EQUAL(shape->getFrameRect().width, rectFrame.width);
  BOOST_CHECK_EQUAL(shape->getFrameRect().height, rectFrame.height);
  BOOST_CHECK_EQUAL(areaBeforeMove, shape->getArea());
}

void checkMoveAbs(ivanova::Shape *shp)
{
  ivanova::rectangle_t rectFrame = shp->getFrameRect();
  double areaBeforeMove = shp->getArea();
  shp->move(-12.0, 8.0);
  BOOST_CHECK_EQUAL(shp->getFrameRect().width, rectFrame.width);
  BOOST_CHECK_EQUAL(shp->getFrameRect().height, rectFrame.height);
  BOOST_CHECK_EQUAL(areaBeforeMove, shp->getArea());
}



void checkScale(ivanova::Shape *shape)
{
  double areaBeforeScale = shape->getArea();
  shape->scale(2);
  BOOST_CHECK_CLOSE(areaBeforeScale * 4, shape->getArea(), 0.0001);
}

BOOST_AUTO_TEST_SUITE(testRectangle)

BOOST_AUTO_TEST_CASE(moveRectangle)
  {
    ivanova::Rectangle rectangle(9.0, 4.7, {-8.3, 6.0});
    checkMoveAbs(&rectangle);
    checkMoveToPoint(&rectangle);
  }

BOOST_AUTO_TEST_CASE(scaleRectangle)
  {
    ivanova::Rectangle rectangle(3.0, 2.0, {7.0, 11.0});
    checkScale(&rectangle);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testCircle)

BOOST_AUTO_TEST_CASE(moveCircle)
  {
    ivanova::Circle circle({2.1, 7.0}, 4.0);
    checkMoveAbs(&circle);
    checkMoveToPoint(&circle);
  }

BOOST_AUTO_TEST_CASE(scaleCircle)
  {
    ivanova::Circle circle({-9.0, 5.0}, 7.0);
    checkScale(&circle);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testCompositeShape)

BOOST_AUTO_TEST_CASE(moveCompositeShape)
{
  ivanova::CompositeShape array;
  std::shared_ptr< ivanova::Shape > rectangle = std::make_shared< ivanova::Rectangle > (8.0, 4.0, ivanova::point_t{0.0, 7.0});
  array.add(rectangle);

  std::shared_ptr< ivanova::Shape > circle = std::make_shared< ivanova::Circle > (ivanova::point_t {8.0, -2.0}, 9.5);
  array.add(circle);

  checkMoveAbs(&array);
  checkMoveToPoint(&array);
}

BOOST_AUTO_TEST_CASE(scaleCompositeShape)
{
  ivanova::CompositeShape array;

  std::shared_ptr< ivanova::Shape > circle0 = std::make_shared< ivanova::Circle >(ivanova::point_t {12.0, -5.0}, 7.0);
  array.add(circle0);

  std::shared_ptr< ivanova::Shape > circle1 = std::make_shared< ivanova::Circle >(ivanova::point_t{-4.0, -1.0}, 3.0);
  array.add(circle1);

  checkScale(&array);
}

BOOST_AUTO_TEST_SUITE_END()

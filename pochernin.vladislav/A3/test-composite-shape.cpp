#include <boost/test/unit_test.hpp>

#include "test-functions.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

using ShapePtr = std::shared_ptr< pochernin::Shape >;

const double width = 100.0;
const double height = 50.0;
const double negativeValue = -1.0;
const pochernin::point_t startPos = {10.0, 20.0};
const size_t capacity = 10;
const double width1 = 23.7;
const double height1 = 13.2;
const pochernin::point_t startPos1 = {-12.4, 221.1};
const double radius2 = 222.32;
const pochernin::point_t startPos2 = {123.0, 11.28};
const double accuracy = 0.0001;

void fillCompositeShape(pochernin::CompositeShape* compositeShape)
{
  ShapePtr shape1 = std::make_shared< pochernin::Rectangle >(width1, height1, startPos1);
  ShapePtr shape2 = std::make_shared< pochernin::Circle >(radius2, startPos2);
  compositeShape->pushBack(shape1);
  compositeShape->pushBack(shape2);
}

BOOST_AUTO_TEST_SUITE(CompositeShape)

BOOST_AUTO_TEST_CASE(ConstWidthHeightAreaWhenMoving)
{
  pochernin::CompositeShape testCompositeShape(std::make_shared< pochernin::Rectangle >(width, height, startPos)); 
  fillCompositeShape(&testCompositeShape);
  pochernin::checkConstWidthHeightArea(&testCompositeShape);
}

BOOST_AUTO_TEST_CASE(QuadraticChangeAreaWhenScale)
{
  pochernin::CompositeShape testCompositeShape(std::make_shared< pochernin::Rectangle >(width, height, startPos));
  fillCompositeShape(&testCompositeShape);
  pochernin::checkQuadraticChangeAreaWhenScale(&testCompositeShape);
}

BOOST_AUTO_TEST_CASE(HandlingIncorrectParameters)
{
  ShapePtr testShapePtr = std::make_shared< pochernin::Rectangle >(width, height, startPos);
  BOOST_CHECK_THROW(pochernin::CompositeShape(testShapePtr, 0), std::invalid_argument);
  pochernin::CompositeShape testCompositeShape(std::make_shared< pochernin::Rectangle >(width, height, startPos));
  BOOST_CHECK_THROW(testCompositeShape.scale(negativeValue), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(HandlingOutOfRange)
{
  pochernin::CompositeShape testCompositeShape(std::make_shared< pochernin::Rectangle >(width, height, startPos));
  BOOST_CHECK_THROW(testCompositeShape.at(100), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(HandlingPopBackLastShape)
{
  pochernin::CompositeShape testCompositeShape(std::make_shared< pochernin::Rectangle >(width, height, startPos));
  BOOST_CHECK_THROW(testCompositeShape.popBack(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(CorrectReserve)
{
  pochernin::CompositeShape testCompositeShape(std::make_shared< pochernin::Rectangle >(width, height, startPos));
  fillCompositeShape(&testCompositeShape);
  double startSize = testCompositeShape.size();
  double startArea = testCompositeShape.getArea();
  testCompositeShape.reserve(capacity);
  BOOST_CHECK_EQUAL(startSize, testCompositeShape.size());
  BOOST_CHECK_EQUAL(capacity, testCompositeShape.capacity());
  BOOST_CHECK_CLOSE(startArea, testCompositeShape.getArea(), accuracy);
}

BOOST_AUTO_TEST_SUITE_END()

#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "test-function.hpp"
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

const diurdeva::point_t pointCenter = { 3.5, 4.0 };
const diurdeva::point_t newCenter = { 3.0, 2.0 };
const double width = 8.0;
const double width2 = 1.0;
const double height = 5.0;
const double height2 = 2.0;
const double radius = 3.0;
const double radius2 = 4.0;
const double negativeOptions = -8.0;
const double index = 200;
const size_t reserveValue = 2;

using shapePtr = std::shared_ptr< diurdeva::Shape >;

void pushShapes(diurdeva::CompositeShape* shape)
{
  shapePtr rectangle = std::make_shared< diurdeva::Rectangle >(width2, height2, pointCenter);
  shape->pushBack(rectangle);

  shapePtr circle = std::make_shared< diurdeva::Circle >(radius2, pointCenter);
  shape->pushBack(circle);
}

BOOST_AUTO_TEST_SUITE(testCompositeShape)

BOOST_AUTO_TEST_CASE(invalidArgumentCompositeShape)
{
  diurdeeva::CompositeShape composite(std::make_shared< diurdeva::Rectangle >(width, height, pointCenter));
  BOOST_CHECK_THROW(composite.scale(negativeOptions), std::invalid_argument);
  BOOST_CHECK_THROW(composite.at(index), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testPopBack)
{
  diurdeva::CompositeShape compositeShape(std::make_shared< diurdeva::Rectangle >(width, height, pointCenter));
  BOOST_CHECK_THROW(compositeShape.pop_back(), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testReserve)
{
  diurdeva::CompositeShape composite(std::make_shared< diurdeva::Circle >(radius, pointCenter));
  composite.reserve(reserveValue);
  BOOST_CHECK_EQUAL(composite.capacity(), reserveValue);
}

BOOST_AUTO_TEST_CASE(moveCompositeShape)
{
  diurdeva::CompositeShape composite(std::make_shared< diurdeva::Rectangle >(width, height, StartPos));
  addShapes(&composite);
  checkConstOptionsBeforeMoving(&composite);
}

BOOST_AUTO_TEST_CASE(scaleCompositeShape)
{
  diurdeva::CompositeShape composite(std::make_shared< lab::Circle >(radius, StartPos));
  addShapes(&composite);
  checkAreaBeforeScale(&composite);
}

BOOST_AUTO_TEST_SUITE_END()

#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <memory>
#include "test-function.hpp"
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

std::unique_ptr< diurdeva::CompositeShape > makeCompositeShape()
{
  auto circle = std::make_unique< diurdeva::Circle >(radius, pointCenter);
  auto rectangle = std::make_unique< diurdeva::Rectangle >(width, height, pointCenter);
  auto shape = std::make_unique< diurdeva::CompositeShape >(std::move(circle));
  shape->pushBack(std::move(rectangle));
  return shape;
}

BOOST_AUTO_TEST_SUITE(testCompositeShape)

BOOST_AUTO_TEST_CASE(invalidArgumentCompositeShape)
{
  BOOST_CHECK_THROW(makeCompositeShape()->scale(negativeOptions), std::invalid_argument);
  BOOST_CHECK_THROW(makeCompositeShape()->at(testIndex), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testPopBack)
{
  diurdeva::CompositeShape compositeShape(std::make_shared< diurdeva::Rectangle >(width, height, pointCenter));
  BOOST_CHECK_THROW(compositeShape.popBack(), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testReserve)
{
  diurdeva::CompositeShape composite(makeCompositeShape());
  composite.reserve(reserveValue);
  BOOST_CHECK_EQUAL(composite.capacity(), reserveValue);
}

BOOST_AUTO_TEST_CASE(moveCompositeShape)
{
  checkConstOptionsBeforeMoving(*makeCompositeShape());
}

BOOST_AUTO_TEST_CASE(scaleCompositeShape)
{
  checkAreaBeforeScale(*makeCompositeShape());
}

BOOST_AUTO_TEST_SUITE_END()

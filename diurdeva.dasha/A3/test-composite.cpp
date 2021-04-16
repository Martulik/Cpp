#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <memory>
#include "test-function.hpp"
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

namespace lab = diurdeva;

std::unique_ptr< lab::CompositeShape > makeCompositeShape()
{
  auto circle = std::make_unique< lab::Circle >(lab::radius, lab::pointCenter);
  auto rectangle = std::make_unique< lab::Rectangle >(lab::width, lab::height, lab::pointCenter);
  auto shape = std::make_unique< lab::CompositeShape >(std::move(circle));
  shape->pushBack(std::move(rectangle));
  return shape;
}

BOOST_AUTO_TEST_SUITE(testCompositeShape)

BOOST_AUTO_TEST_CASE(invalidArgumentCompositeShape)
{
  BOOST_CHECK_THROW(makeCompositeShape()->scale(lab::negativeOptions), std::invalid_argument);
  BOOST_CHECK_THROW(makeCompositeShape()->at(lab::testIndex), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testPopBack)
{
  lab::CompositeShape compositeShape(std::make_shared< lab::Rectangle >(lab::width, lab::height, lab::pointCenter));
  BOOST_CHECK_THROW(compositeShape.popBack(), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testReserve)
{
  lab::CompositeShape composite(makeCompositeShape());
  composite.reserve(lab::reserveValue);
  BOOST_CHECK_EQUAL(composite.capacity(), lab::reserveValue);
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

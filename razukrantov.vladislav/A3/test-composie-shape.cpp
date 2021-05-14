#include <boost/test/unit_test.hpp>
#include "test-function.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace raz = razukrantov;

namespace razukrantov
{
  using shapePtr = std::shared_ptr< Shape >;
  const double width = 5.0;
  const double height = 10.0;
  const double negativeValue = -1.0;
  const point_t startPos = {2.0, 3.0};
  const point_t startPos2 = {3.0, 5.0};
  const double radius = 2.0;
  const size_t testIndex = 1000;
  const double reserveValue = 5.0;

  void fillCompositeShape(CompositeShape& compositeShape)
  {
    shapePtr shape = std::make_shared< raz::Rectangle >(5.0, 10.0, startPos);
    shapePtr shape2 = std::make_shared< raz::Circle >(2.0, startPos2);
    compositeShape.pushBack(shape);
    compositeShape.pushBack(shape2);
  }
}

BOOST_AUTO_TEST_SUITE(CompositeShape)

BOOST_AUTO_TEST_CASE(moveCompositeShape)
{
  raz::CompositeShape composite(std::make_shared< raz::Rectangle >(raz::width, raz::height, raz::startPos));
  fillCompositeShape(composite);
  raz::checkDeltaMove(composite);
  raz::checkPointMove(composite);
}

BOOST_AUTO_TEST_CASE(scaleCompositeShape)
{
  raz::CompositeShape composite(std::make_shared< raz::Rectangle >(raz::width, raz::height, raz::startPos));
  fillCompositeShape(composite);
  checkScale(composite);
}

BOOST_AUTO_TEST_CASE(incorrectParametrsCompositeShape)
{
  raz::CompositeShape composite(std::make_shared< raz::Rectangle >(raz::width, raz::height, raz::startPos));
  BOOST_CHECK_THROW(composite.scale(raz::negativeValue), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(outOfRangeCompositeShape)
{
  raz::CompositeShape composite(std::make_shared< raz::Rectangle >(raz::width, raz::height, raz::startPos));
  BOOST_CHECK_THROW(composite.at(raz::testIndex), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(popBackCompositeShape)
{
  raz::CompositeShape composite(std::make_shared< raz::Rectangle >(raz::width, raz::height, raz::startPos));
  BOOST_CHECK_THROW(composite.popBack(), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(reserveCompositeShape)
{
  raz::CompositeShape composite(std::make_shared< raz::Rectangle >(raz::width, raz::height, raz::startPos));
  composite.reserve(raz::reserveValue);
  BOOST_CHECK_EQUAL(composite.capacity(), raz::reserveValue);
}

BOOST_AUTO_TEST_SUITE_END()

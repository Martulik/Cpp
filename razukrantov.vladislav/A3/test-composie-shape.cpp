#include <boost/test/unit_test.hpp>
#include "test-function.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

using shapePtr = std::shared_ptr< razukrantov::Shape >;

namespace razukrantov
{
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
    shapePtr shape = std::make_shared< razukrantov::Rectangle >(5.0, 10.0, startPos);
    shapePtr shape2 = std::make_shared< razukrantov::Circle >(2.0, startPos2);
    compositeShape.pushBack(shape);
    compositeShape.pushBack(shape2);
  }
}

BOOST_AUTO_TEST_SUITE(CompositeShape)

BOOST_AUTO_TEST_CASE(moveCompositeShape)
{
  razukrantov::CompositeShape composite(std::make_shared< razukrantov::Rectangle >(razukrantov::width, razukrantov::height, razukrantov::startPos));
  fillCompositeShape(composite);
  razukrantov::checkDeltaMove(composite);
  razukrantov::checkPointMove(composite);
}

BOOST_AUTO_TEST_CASE(scaleCompositeShape)
{
  razukrantov::CompositeShape composite(std::make_shared< razukrantov::Rectangle >(razukrantov::width, razukrantov::height, razukrantov::startPos));
  fillCompositeShape(composite);
  checkScale(composite);
}

BOOST_AUTO_TEST_CASE(incorrectParametrsCompositeShape)
{
  razukrantov::CompositeShape composite(std::make_shared< razukrantov::Rectangle >(razukrantov::width, razukrantov::height, razukrantov::startPos));
  BOOST_CHECK_THROW(composite.scale(razukrantov::negativeValue), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(outOfRangeCompositeShape)
{
  razukrantov::CompositeShape composite(std::make_shared< razukrantov::Rectangle >(razukrantov::width, razukrantov::height, razukrantov::startPos));
  BOOST_CHECK_THROW(composite.at(razukrantov::testIndex), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(popBackCompositeShape)
{
  razukrantov::CompositeShape composite(std::make_shared< razukrantov::Rectangle >(razukrantov::width, razukrantov::height, razukrantov::startPos));
  BOOST_CHECK_THROW(composite.popBack(), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(reserveCompositeShape)
{
  razukrantov::CompositeShape composite(std::make_shared< razukrantov::Rectangle >(razukrantov::width, razukrantov::height, razukrantov::startPos));
  composite.reserve(razukrantov::reserveValue);
  BOOST_CHECK_EQUAL(composite.capacity(), razukrantov::reserveValue);
}

BOOST_AUTO_TEST_SUITE_END()

#include <boost/test/unit_test.hpp>
#include <boost/test/execution_monitor.hpp>
#include <stdexcept>
#include "test-func.hpp"
#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

const double width = 9.0;
const double height = 4.7;
const double negativeValue = -10.0;
const ivanova::point_t pos{-8.3, 6.0};
const double radius = 4.0;
const ivanova::point_t ctr = {2.1, 7.0};
const size_t value = 10;
using shared = std::shared_ptr< ivanova::Shape >;

ivanova::CompositeShape makeCompositeShape()
{
    shared circle = std::make_shared< ivanova::Circle >(ctr, radius);
    shared rectangle = std::make_shared< ivanova::Rectangle >(width, height, pos);
    ivanova::CompositeShape shape(circle);
    shape.pushBack(rectangle);
    return shape;
}

BOOST_AUTO_TEST_SUITE(testCompositeShape)

BOOST_AUTO_TEST_CASE(invalidArgumentCompositeShape, *boost::unit_test::expected_failures(1))
{
  BOOST_CHECK_THROW(makeCompositeShape().scale(negativeValue), std::invalid_argument);

}

BOOST_AUTO_TEST_CASE(outOfRange, *boost::unit_test::expected_failures(1))
{
  BOOST_CHECK_THROW(makeCompositeShape().at(value), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(moveCompositeShape)
{
  shared rectangle = std::make_shared< ivanova::Rectangle > (width, height, pos);
  shared circle = std::make_shared< ivanova::Circle > (ctr, radius);
  ivanova::CompositeShape array(rectangle);
  array.pushBack(circle);

  checkMoveAbs(&array);
  checkMoveToPoint(&array);
}

BOOST_AUTO_TEST_CASE(scaleCompositeShape)
{
  shared circle0 = std::make_shared< ivanova::Circle >(ctr, radius);
  shared circle1 = std::make_shared< ivanova::Circle >(ctr, radius);

  ivanova::CompositeShape array(circle0);
  array.pushBack(circle1);
  checkScale(&array);
}

BOOST_AUTO_TEST_CASE(popBackCompositeShape)
{
  shared circle = std::make_shared< ivanova::Circle >(ctr, radius);
  shared rectangle = std::make_shared< ivanova::Rectangle > (width, height, pos);
  ivanova::CompositeShape array(circle);
  array.pushBack(rectangle);
  BOOST_CHECK_NO_THROW(array.popBack());
}

BOOST_AUTO_TEST_CASE(popBackWrongCompositeShape, *boost::unit_test::expected_failures(1))
{
  shared circle = std::make_shared< ivanova::Circle >(ctr, radius);
  ivanova::CompositeShape array(circle);
  BOOST_CHECK_THROW(array.popBack(), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(reserveCompositeShape)
{
  ivanova::CompositeShape array(makeCompositeShape());
  array.reserve(value);
  BOOST_CHECK_EQUAL(array.capacity(), value);
}

BOOST_AUTO_TEST_SUITE_END()

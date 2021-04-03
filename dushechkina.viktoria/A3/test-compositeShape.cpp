#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <memory>
#include "test-function.hpp"
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

namespace vika = dushechkina;

const vika::point_t center = { 1.28, 6.4 };
const vika::point_t newCenter = { 3.2, 1.28 };
const size_t index = 100;
const size_t rValue = 2;
const double neg = -5.0;
const double width1 = 1.28;
const double width2 = 1.6;
const double height1 = 0.16;
const double height2 = 2.56;
const double radius1 = 3.2;
const double radius2 = 6.4;

using shapePtr = std::shared_ptr< vika::Shape >;

void addAllTypesShapes(vika::CompositeShape* shape)
{
  shapePtr circle = std::make_shared< vika::Circle >(center, radius2);
  shape->pushBack(circle);
  shapePtr rectangle = std::make_shared< vika::Rectangle >(width2, height2, newCenter);
  shape->pushBack(rectangle);
}

BOOST_AUTO_TEST_SUITE(CompositeShape)

BOOST_AUTO_TEST_CASE(invalid_Scale_and_At_CompositeShape)
{
  vika::CompositeShape composite(std::make_shared< vika::Rectangle >(width1, height1, center));
  BOOST_CHECK_THROW(composite.at(index), std::out_of_range);
  BOOST_CHECK_THROW(composite.scale(neg), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Reserve)
{
  vika::CompositeShape composite(std::make_shared< vika::Circle >(center, radius1));
  composite.reserve(rValue);
  BOOST_CHECK_EQUAL(composite.capacity(), rValue);
}

BOOST_AUTO_TEST_CASE(PopBack)
{
  vika::CompositeShape compositeShape(std::make_shared< vika::Rectangle >(width1, height1, center));
  BOOST_CHECK_THROW(compositeShape.popBack(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(MoveCompositeShape_InPoint_CorrectWorkMethod)
{
  vika::CompositeShape composite(std::make_shared< vika::Rectangle >(width1, height1, center));
  addAllTypesShapes(&composite);
  checkBeforeCenterMoving(&composite);
}

BOOST_AUTO_TEST_CASE(MoveCompositeShape_XandYoffset_CorrectWorkMethod)
{
  vika::CompositeShape composite(std::make_shared< vika::Rectangle >(width1, height1, center));
  addAllTypesShapes(&composite);
  checkBeforeDMoving(&composite);
}

BOOST_AUTO_TEST_CASE(scaleCompositeShape)
{
  vika::CompositeShape composite(std::make_shared< vika::Circle >(center, radius1));
  addAllTypesShapes(&composite);
  checkBeforeScale(&composite);
}

BOOST_AUTO_TEST_SUITE_END()

#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <memory>
#include "test-function.hpp"
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

namespace vika = dushechkina;

using shapePtr = std::shared_ptr< vika::Shape >;

std::unique_ptr< vika::CompositeShape > makingCompositeShape()
{
  auto circle = std::make_unique< vika::Circle >(vika::center,vika::radius1);
  auto rectangle = std::make_unique< vika::Rectangle >(vika::width1, vika::height1, vika::center);
  auto shape = std::make_unique< vika::CompositeShape >(std::move(circle));
  shape->pushBack(std::move(rectangle));
  return shape;
}


BOOST_AUTO_TEST_SUITE(CompositeShape)

BOOST_AUTO_TEST_CASE(invalid_Scale_and_At_CompositeShape)
{
  BOOST_CHECK_THROW(makingCompositeShape()->scale(vika::neg), std::invalid_argument);
  BOOST_CHECK_THROW(makingCompositeShape()->at(vika::index1), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(Reserve)
{
  vika::CompositeShape composite(makingCompositeShape());
  composite.reserve(vika::rValue);
  BOOST_CHECK_EQUAL(composite.capacity(), vika::rValue);
}

BOOST_AUTO_TEST_CASE(PopBack)
{
  vika::CompositeShape compositeShape(std::make_shared< vika::Rectangle >(vika::width1, vika::height1, vika::center));
  BOOST_CHECK_THROW(compositeShape.popBack(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(MoveCompositeShape_InPoint_CorrectWorkMethod)
{
  checkBeforeCenterMoving(*makingCompositeShape());
}

BOOST_AUTO_TEST_CASE(MoveCompositeShape_XandYoffset_CorrectWorkMethod)
{
  checkBeforeDMoving(*makingCompositeShape());
}

BOOST_AUTO_TEST_CASE(scaleCompositeShape)
{
  checkBeforeScale(*makingCompositeShape());
}

BOOST_AUTO_TEST_SUITE_END()

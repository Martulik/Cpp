#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "test-functions.hpp"
#include "composite-shape.hpp"

namespace lab = borisova;
using exc = std::invalid_argument;

BOOST_AUTO_TEST_SUITE(testCompositeShape)

BOOST_AUTO_TEST_CASE(testParametersComp)
{
  BOOST_CHECK_THROW(lab::CompositeShape comp({}), exc);
}

BOOST_AUTO_TEST_CASE(testAreaAfterMovingComp)
{
  areaAfterMoving(lab::makeComposite());
}

BOOST_AUTO_TEST_CASE(testParamAfterMovingComp)
{
  paramAfterMoving(lab::makeComposite());
}

BOOST_AUTO_TEST_CASE(testScaleComp)
{
  areaAfterScale(lab::makeComposite());
}

BOOST_AUTO_TEST_CASE(testNameComp)
{
  BOOST_REQUIRE_EQUAL(lab::makeComposite()->getName(), "Composite Shape");
}

BOOST_AUTO_TEST_SUITE_END()

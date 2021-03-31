#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <memory>
#include "test-functions.hpp"
#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

namespace lab = borisova;

BOOST_AUTO_TEST_SUITE(testCompositeShape)

borisova::CompositeShape compShape1 =
{
  std::make_shared< lab::Rectangle >(lab::point1, lab::width, lab::param1),
  std::make_shared< lab::Circle >(lab::point2, lab::width),
  std::make_shared< lab::Rectangle >(lab::point2, lab::param2, lab::height),
  std::make_shared< lab::Circle >(lab::point1, lab::height)
};

borisova::CompositeShape compShape2 =
{
  std::make_shared< lab::Circle >(lab::point1, lab::width),
  std::make_shared< lab::Rectangle >(lab::point1, lab::param2, lab::height),
  std::make_shared< lab::Circle >(lab::point2, lab::param1)
};

borisova::CompositeShape compShape3 =
{
  std::make_shared< lab::Rectangle >(lab::point1, lab::width, lab::param1),
  std::make_shared< lab::Circle >(lab::point1, lab::height)
};

borisova::CompositeShape compShape4 =
{
  std::make_shared< lab::Circle >(lab::point1, lab::width),
  std::make_shared< lab::Circle >(lab::point2, lab::param1)
};

BOOST_AUTO_TEST_CASE(testAreaAfterMovingComp)
{
  areaAfterMoving(&compShape1);
}

BOOST_AUTO_TEST_CASE(testParamAfterMovingComp)
{
  paramAfterMoving(&compShape2);
}

BOOST_AUTO_TEST_CASE(testScaleComp)
{
  areaAfterScale(&compShape3);
}

BOOST_AUTO_TEST_CASE(testNameComp)
{
  BOOST_REQUIRE_EQUAL(compShape4.getName(), "Composite Shape");
}

BOOST_AUTO_TEST_SUITE_END()

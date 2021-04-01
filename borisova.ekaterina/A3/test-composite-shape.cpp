#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <memory>
#include "test-functions.hpp"
#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

namespace lab = borisova;
using exc = std::invalid_argument;

BOOST_AUTO_TEST_SUITE(testCompositeShape)

const double width = 11.5;
const double height = 0.01;
const double param1 = 4.12;
const double param2 = 91.004;
const double negParam = -12.91;

const lab::point_t point1{ 0.4, 2.56 };
const lab::point_t point2{ 65.03, 0.99 };

borisova::CompositeShape compShape1 =
{
  std::make_shared< lab::Rectangle >(point1, width, param1),
  std::make_shared< lab::Circle >(point2, width),
  std::make_shared< lab::Rectangle >(point2, param2, height),
  std::make_shared< lab::Circle >(point1, height)
};

borisova::CompositeShape compShape2 =
{
  std::make_shared< lab::Circle >(point1, width),
  std::make_shared< lab::Rectangle >(point1, param2, height),
  std::make_shared< lab::Circle >(point2, param1)
};

borisova::CompositeShape compShape3 =
{
  std::make_shared< lab::Rectangle >(point1, width, param1),
  std::make_shared< lab::Circle >(point1, height)
};

borisova::CompositeShape compShape4 =
{
  std::make_shared< lab::Circle >(point1, width),
  std::make_shared< lab::Circle >(point2, param1)
};

BOOST_AUTO_TEST_CASE(testParametersComp)
{
  BOOST_CHECK_THROW(lab::CompositeShape comp({}), exc);
}

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

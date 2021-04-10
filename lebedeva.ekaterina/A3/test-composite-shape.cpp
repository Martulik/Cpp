#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "test-functions.hpp"

namespace leb = lebedeva;

BOOST_AUTO_TEST_SUITE(CompositeShapeTest)

BOOST_AUTO_TEST_CASE(emptyCompositeShape)
{
  BOOST_CHECK_THROW(leb::CompositeShape composition({}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalidArgumentCompositeShape)
{
  BOOST_CHECK_THROW(leb::makeCompositeShape()->scale(leb::nParameter), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(GetCompositeShapeName)
{
  leb::checkName("Composite Shape", leb::makeCompositeShape()->getName());
}

BOOST_AUTO_TEST_CASE(MoveCompositeShape)
{

  leb::checkMoveAbs(*leb::makeCompositeShape(), leb::newPos);
  leb::checkMoveToPoint(*leb::makeCompositeShape(), leb::newPos);

}

BOOST_AUTO_TEST_CASE(ScaleCompositeShape)
{
  leb::checkScale(*leb::makeCompositeShape(), leb::parameter);
}

BOOST_AUTO_TEST_SUITE_END()

#include <boost/test/unit_test.hpp>
#include "test-function.hpp"
#include "circle.hpp"

namespace lab = diurdeva;

std::unique_ptr< lab::Circle > makeCircle()
{
  return std::make_unique< lab::Circle >(lab::radius, lab::pointCenter);
}

BOOST_AUTO_TEST_SUITE(testCircle)

BOOST_AUTO_TEST_CASE(invalidOptionsCircle)
{
  BOOST_CHECK_THROW(lab::Circle(lab::negativeOptions, lab::pointCenter), std::invalid_argument);
  BOOST_CHECK_THROW(makeCircle()->scale(lab::negativeOptions), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(moveCircle)
{
  checkConstOptionsBeforeMoving(*makeCircle());
}

BOOST_AUTO_TEST_CASE(scaleCircle)
{
  checkAreaBeforeScale(*makeCircle());
}

BOOST_AUTO_TEST_SUITE_END()

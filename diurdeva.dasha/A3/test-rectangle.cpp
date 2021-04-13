#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "test-function.hpp"
#include "rectangle.hpp"

namespace lab = diurdeva;

std::unique_ptr< lab::Rectangle > makeRectangle()
{
  return std::make_unique< lab::Rectangle >(lab::width, lab::height, lab::pointCenter);
}

BOOST_AUTO_TEST_SUITE(testRectangle)

BOOST_AUTO_TEST_CASE(invalidOptionsRectangle)
{
  BOOST_CHECK_THROW(lab::Rectangle(lab::width, lab::negativeOptions, lab::pointCenter), std::invalid_argument);
  BOOST_CHECK_THROW(lab::Rectangle(lab::negativeOptions, lab::height, lab::pointCenter), std::invalid_argument);
  BOOST_CHECK_THROW(makeRectangle()->scale(lab::negativeOptions), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(moveRectangle)
{
  checkConstOptionsBeforeMoving(*makeRectangle());
}

BOOST_AUTO_TEST_CASE(scaleRectangle)
{
  checkAreaBeforeScale(*makeRectangle());
}

BOOST_AUTO_TEST_SUITE_END()

#include <boost/test/unit_test.hpp>

#include <sstream>

#include "shape.hpp"

namespace lab = shkurov;

BOOST_AUTO_TEST_SUITE(point_input)

BOOST_AUTO_TEST_CASE(whitespace)
{
  std::istringstream istr("   (     12 ;    2    )   ");

  lab::Point point;
  istr >> point;

  BOOST_REQUIRE(istr.good());
}

BOOST_AUTO_TEST_CASE(letter)
{
  std::istringstream istr("(f;2)");

  lab::Point point;
  istr >> point;

  BOOST_REQUIRE(istr.fail() && !istr.eof());
}

BOOST_AUTO_TEST_CASE(no_closing_bracket)
{
  std::istringstream istr("(1;2 ");

  lab::Point point;
  istr >> point;

  BOOST_REQUIRE(istr.fail());
}

BOOST_AUTO_TEST_CASE(no_opening_bracket)
{
  std::istringstream istr("1;2)");

  lab::Point point;
  istr >> point;

  BOOST_REQUIRE(istr.fail());
}

BOOST_AUTO_TEST_CASE(good)
{
  std::istringstream istr("(1;2)");

  lab::Point point;
  istr >> point;

  BOOST_REQUIRE(istr.good());
}

BOOST_AUTO_TEST_SUITE_END()

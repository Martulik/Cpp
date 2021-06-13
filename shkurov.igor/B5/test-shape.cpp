#include <boost/test/unit_test.hpp>

#include <sstream>

#include "shape.hpp"
#include "tools.hpp"

namespace lab = shkurov;

BOOST_AUTO_TEST_SUITE(shape_input)

BOOST_AUTO_TEST_CASE(whitespace)
{
  std::istringstream istr("3 (4;-4 )           (23;-5)  (3;4)");

  lab::Shape shape;
  istr >> shape;

  BOOST_REQUIRE(istr.good());
}

BOOST_AUTO_TEST_CASE(alpha_first)
{
  std::istringstream istr("f (4;-4) (23;-5) (3;4)");

  lab::Shape shape;
  istr >> shape;

  BOOST_REQUIRE(istr.fail());
}

BOOST_AUTO_TEST_CASE(invalid_count)
{
  std::istringstream istr("4 (4;-4) (23;-5) (3;4)");

  lab::Shape shape;
  istr >> shape;
  BOOST_REQUIRE(istr.fail());
}

BOOST_AUTO_TEST_CASE(defining_square)
{
  std::istringstream istr("4 (-2;2) (2;2) (2;6) (-2;6)");

  lab::Shape shape;
  istr >> shape;

  BOOST_REQUIRE(lab::isSquare(shape));
  BOOST_REQUIRE(lab::isRectangle(shape));
}

BOOST_AUTO_TEST_CASE(defining_not_square)
{
  std::istringstream istr("4 (-2;2) (2;2) (2;6) (3;10)");

  lab::Shape shape;
  istr >> shape;

  BOOST_REQUIRE(!lab::isSquare(shape));
  BOOST_REQUIRE(lab::isRectangle(shape));
}


BOOST_AUTO_TEST_SUITE_END()

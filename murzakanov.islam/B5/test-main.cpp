#define BOOST_TEST_MODULE B5
#include <sstream>
#include <boost/test/included/unit_test.hpp>
#include "shape.hpp"

BOOST_AUTO_TEST_CASE(WrongShapeInput)
{
  std::string line("3 (das;1) (1;4) (5;2)");
  std::stringstream sin(line);
  murzakanov::Shape shp;
  sin >> shp;
  BOOST_CHECK(sin.fail());
}

BOOST_AUTO_TEST_CASE(WrongPointInput)
{
  std::string line("(152;asdasd)");
  std::stringstream sin(line);
  murzakanov::Point point;
  sin >> point;
  BOOST_CHECK(sin.fail());
}

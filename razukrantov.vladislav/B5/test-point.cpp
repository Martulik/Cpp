#include <sstream>
#include <boost/test/unit_test.hpp>
#include "point.hpp"

BOOST_AUTO_TEST_SUITE(testPoint)

BOOST_AUTO_TEST_CASE(correctInput)
{
  const int x = 10;
  const int y = 5;
  std::istringstream stream("(10; 5)");
  razukrantov::Point point{};
  stream >> point;
  BOOST_CHECK_EQUAL(point.x, x);
  BOOST_CHECK_EQUAL(point.y, y);
  BOOST_CHECK(stream);
}

BOOST_AUTO_TEST_CASE(correctInput2)
{
  const int x = 10;
  const int y = 5;
  std::istringstream stream("  ( 10;  5 )  ");
  razukrantov::Point point{};
  stream >> point;
  BOOST_CHECK_EQUAL(point.x, x);
  BOOST_CHECK_EQUAL(point.y, y);
  BOOST_CHECK(stream);
}

BOOST_AUTO_TEST_CASE(incorrectInput)
{
  std::stringstream stream("(10; a5)");
  razukrantov::Point point{};
  BOOST_CHECK_THROW(stream >> point, std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(output)
{
  razukrantov::Point point{10, 12};
  std::string str = "(10; 12)";
  std::ostringstream out;
  out << point;
  BOOST_CHECK_EQUAL(str, out.str());
}

BOOST_AUTO_TEST_SUITE_END()

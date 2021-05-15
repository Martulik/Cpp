#include <sstream>
#include <boost/test/unit_test.hpp>
#include "shape.hpp"

BOOST_AUTO_TEST_CASE(InputPoint)
{
  const int x = 60;
  const int y = -24;
  std::istringstream istringstream("(60;-24)");
  shilyaev::Point point{};
  istringstream >> point;
  BOOST_CHECK_EQUAL(point.x, x);
  BOOST_CHECK_EQUAL(point.y, y);
  BOOST_CHECK(istringstream);
}

BOOST_AUTO_TEST_CASE(InputPointSpaces)
{
  const int x = 60;
  const int y = -24;
  std::istringstream istringstream("     (  60;    -24   )       ");
  shilyaev::Point point{};
  istringstream >> point;
  BOOST_CHECK_EQUAL(point.x, x);
  BOOST_CHECK_EQUAL(point.y, y);
  BOOST_CHECK(istringstream);
}

BOOST_AUTO_TEST_CASE(InputPointMalformed)
{
  std::istringstream istringstream("(60,-24)");
  shilyaev::Point point{};
  istringstream >> point;
  BOOST_CHECK(istringstream.fail());
}

BOOST_AUTO_TEST_CASE(OutputPointMalformed)
{
  shilyaev::Point point{60, -24};
  std::string expected = "(60; -24)";
  std::ostringstream ostringstream;
  ostringstream << point;
  BOOST_CHECK_EQUAL(expected, ostringstream.str());
}

BOOST_AUTO_TEST_CASE(IsSquare)
{
  BOOST_CHECK(isSquare(shilyaev::Shape{{1, 0}, {0, 0}, {0, 1}, {1, 1}}));
  BOOST_CHECK(isSquare(shilyaev::Shape{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}));
  BOOST_CHECK(!isSquare(shilyaev::Shape{{1, 0}, {0, 0}, {1, 1}, {0, 1}}));
  BOOST_CHECK(!isSquare(shilyaev::Shape{{1, 0}, {0, 0}, {0, 1}, {1, 1}, {1, 0}}));
  BOOST_CHECK(!isSquare(shilyaev::Shape{{2, 0}, {0, 0}, {0, 1}, {2, 1}}));
}

BOOST_AUTO_TEST_CASE(IsRectangle)
{
  BOOST_CHECK(isRectangle(shilyaev::Shape{{1, 0}, {0, 0}, {0, 1}, {1, 1}}));
  BOOST_CHECK(isRectangle(shilyaev::Shape{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}));
  BOOST_CHECK(isRectangle(shilyaev::Shape{{2, 0}, {0, 0}, {0, 1}, {2, 1}}));
  BOOST_CHECK(!isRectangle(shilyaev::Shape{{1, 0}, {0, 0}, {1, 1}, {0, 1}}));
  BOOST_CHECK(!isRectangle(shilyaev::Shape{{1, 0}, {0, 0}, {0, 1}, {1, 1}, {1, 0}}));
}

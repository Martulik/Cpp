#include <boost/test/unit_test.hpp>

#include <sstream>
#include "shape.hpp"

BOOST_AUTO_TEST_SUITE(TestInput)

BOOST_AUTO_TEST_CASE(CorrectInput)
{
  std::istringstream line("4 (2340;10) (198; 4561) (-23;1) (-24;43)\n");
  ferapontov::Shape shp;
  line >> shp;
  BOOST_CHECK(!line.fail());
}

BOOST_AUTO_TEST_CASE(NewLineBeforeNumber)
{
  std::istringstream line("4 (\n2340;10) (198; 4561) (-23;1) (-24;43)");
  ferapontov::Shape shp;
  line >> shp;
  BOOST_CHECK(line.fail());
}

BOOST_AUTO_TEST_CASE(NewLineAfterNumber)
{
  std::istringstream line("4 (2340\n;10) (198; 4561) (-23;1) (-24;43)");
  ferapontov::Shape shp;
  line >> shp;
  BOOST_CHECK(line.fail());
}

BOOST_AUTO_TEST_CASE(NewLineAtTheEnd)
{
  std::istringstream line("4 (2340;10\n) (198; 4561) (-23;1) (-24;43)");
  ferapontov::Shape shp;
  line >> shp;
  BOOST_CHECK(line.fail());
}

BOOST_AUTO_TEST_CASE(NotEnoughParams)
{
  std::istringstream line("4 (2340;10) (198; 4561) (-23;1)");
  ferapontov::Shape shp;
  line >> shp;
  BOOST_CHECK(line.fail());
}

BOOST_AUTO_TEST_SUITE_END()

#include <boost/test/unit_test.hpp>

#include <sstream>

#include "Shape.h"
#include "helpFunctionalObjects.h"

namespace lysenko
{
  void testShapeWithInpData(std::string data)
  {
    std::stringstream in(data);
    lysenko::Shape shp;
    BOOST_CHECK_THROW(in >> shp, std::invalid_argument);
  }

  Shape executeShapeFromData(std::string data)
  {
    std::stringstream in(data);
    lysenko::Shape shp;
    in >> shp;
    return shp;
  }
}

BOOST_AUTO_TEST_SUITE(testShapeInput)

BOOST_AUTO_TEST_CASE(testCorrectionOfRead)
{
  std::string testData = "3 (1;1) (2;2) (3;1)";
  lysenko::Shape shp = lysenko::executeShapeFromData(testData);
  BOOST_CHECK_EQUAL(shp[0].x, 1);
  BOOST_CHECK_EQUAL(shp[0].y, 1);
  BOOST_CHECK_EQUAL(shp[1].x, 2);
  BOOST_CHECK_EQUAL(shp[1].y, 2);
  BOOST_CHECK_EQUAL(shp[2].x, 3);
  BOOST_CHECK_EQUAL(shp[2].y, 1);
}

BOOST_AUTO_TEST_CASE(testNullVertices)
{
  std::string testData = "0 (1;1) (2;2) (3;1)";
  lysenko::testShapeWithInpData(testData);
}

BOOST_AUTO_TEST_CASE(testInvalidVertices)
{
  std::string testData = "fkfk (1;1) (2;2) (3;1)";
  lysenko::testShapeWithInpData(testData);
}

BOOST_AUTO_TEST_CASE(testNewLineInside)
{
  std::string testData = "3\n (1;1) (2;2) (3;1)";
  lysenko::testShapeWithInpData(testData);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testShapeType)

BOOST_AUTO_TEST_CASE(testTriangle)
{
  lysenko::Shape shp { { 1, 1 }, { 2, 2 }, { 3, 1 } };
  BOOST_REQUIRE(isTriangle(shp));
}

BOOST_AUTO_TEST_CASE(testRectangle)
{
  lysenko::Shape rect { { 1, 1 }, { 2, 1 }, { 2, 2 }, { 1, 2 } };
  BOOST_REQUIRE(isRectangle(rect));

  lysenko::Shape polygon{ { 1, 1 }, { 2, 1 }, { 2, 2 }, { 1, 2 }, { 0, 1 } };
  BOOST_CHECK_EQUAL(isRectangle(polygon), false);

  lysenko::Shape sizeFourButNotRect{ { 3, 1 }, { 2, 1 }, { 2, 2 }, { 1, 2 } };
  BOOST_CHECK_EQUAL(isRectangle(sizeFourButNotRect), false);
}

BOOST_AUTO_TEST_CASE(testSquare)
{
  lysenko::Shape shp { { 1, 1 }, { 2, 1 }, { 2, 2 }, { 1, 2 } };
  BOOST_REQUIRE(lysenko::isSquare(shp));

  lysenko::Shape rectButNotSquare{ { 8, 1 }, { 8, 2 }, { 1, 1 }, { 1, 2 } };
  BOOST_CHECK_EQUAL(isSquare(rectButNotSquare), false);
}

BOOST_AUTO_TEST_CASE(testPentagon)
{
  lysenko::Shape shp { { 1, 2 }, { 3, 2 }, { 3, 3 }, { 1, 3 }, { 2, 3 } };
  BOOST_REQUIRE(isPentagon(shp));
}

BOOST_AUTO_TEST_SUITE_END()

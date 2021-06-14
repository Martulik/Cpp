#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include <random>
#include "functions.hpp"
#include "test-variables.hpp"

BOOST_AUTO_TEST_SUITE(TestShape)
BOOST_AUTO_TEST_CASE(myTestCase)
{
  lebedeva::Shape s1 = { { 4434, 2684 }, { 4434, 6612 }, { 3857, 6612 }, { 3857, 2684 } };
  std::vector< lebedeva::Shape > shapes = { s1 };
  lebedeva::ShapesSpecifics info = countShapes(shapes);
  BOOST_TEST(info.squares == 0);
}

BOOST_AUTO_TEST_CASE(myTestCase1)
{
  lebedeva::Shape s1 = { { 6147, 5156 }, { 8036, 3394 }, { 6892, 2168 }, { 5003, 3930 } };
  BOOST_CHECK(!lebedeva::isRectangleAdvanced(s1));
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestExtraTask)
std::random_device gen;

BOOST_AUTO_TEST_CASE(TestRandowQuadrilateral)
{
  lebedeva::Shape quadrilateral = lebedeva::makeQuadrilateral(gen);
  bool isSquare = lebedeva::isSquareAdvanced(quadrilateral);
  bool isRect = lebedeva::isRectangleAdvanced(quadrilateral);
  if (isRect)
  {
    bool isCrossedRect = lebedeva::isCrossedRectangle(quadrilateral);
    if (isCrossedRect)
    {
      BOOST_CHECK(isCrossedRect);
    }
    if (isSquare)
    {
      isSquare = lebedeva::isSquare(quadrilateral);
      if (isSquare)
      {
        BOOST_CHECK(lebedeva::isSquare(quadrilateral));
      }
      isSquare = lebedeva::isCrossedSquare(quadrilateral);
      if (isSquare)
      {
        BOOST_CHECK(isSquare);
      }
    }
  }
}

BOOST_AUTO_TEST_CASE(TestDefaultRect)
{
  lebedeva::Shape tRect = lebedeva::rect;
  BOOST_CHECK(lebedeva::isRectangle(tRect));
  BOOST_CHECK(lebedeva::isRectangleAdvanced(tRect));
  BOOST_CHECK(!lebedeva::isCrossedRectangle(tRect));
}

BOOST_AUTO_TEST_CASE(TestCrossedNotRotatedRect)
{
  lebedeva::Shape tRect = lebedeva::rect;
  lebedeva::makeCrossed(tRect, gen);
  BOOST_CHECK(lebedeva::isRectangle(tRect));
  BOOST_CHECK(lebedeva::isRectangleAdvanced(tRect));
  BOOST_CHECK(lebedeva::isCrossedRectangle(tRect));
}

BOOST_AUTO_TEST_CASE(TestNotCrossedRotatedRect)
{
  lebedeva::Shape rect = lebedeva::rectRotated;
  BOOST_CHECK(lebedeva::isRectangle(rect));
  BOOST_CHECK(lebedeva::isRectangleAdvanced(rect));
  BOOST_CHECK(!lebedeva::isCrossedRectangle(rect));
}

BOOST_AUTO_TEST_CASE(TestCrossedRotatedRect)
{
  lebedeva::Shape rect = lebedeva::rectRotated;
  lebedeva::makeCrossed(rect, gen);
  BOOST_CHECK(lebedeva::isRectangle(rect));
  BOOST_CHECK(lebedeva::isRectangleAdvanced(rect));
  BOOST_CHECK(lebedeva::isCrossedRectangle(rect));
}

BOOST_AUTO_TEST_CASE(TestDefaultSquare)
{
  lebedeva::Shape square = lebedeva::square;
  BOOST_CHECK(lebedeva::isSquare(square));
  BOOST_CHECK(lebedeva::isSquareAdvanced(square));
  BOOST_CHECK(!lebedeva::isCrossedSquare(square));
}

BOOST_AUTO_TEST_CASE(TestCrossedNotRotatedSquare)
{
  lebedeva::Shape square = lebedeva::square;
  lebedeva::makeCrossed(square, gen);
  BOOST_CHECK(lebedeva::isSquareAdvanced(square));
  BOOST_CHECK(lebedeva::isCrossedSquare(square));
}

BOOST_AUTO_TEST_CASE(TestNotCrossedRotatedSquare)
{
  lebedeva::Shape square = lebedeva::squareRotated;
  BOOST_CHECK(lebedeva::isSquare(square));
  BOOST_CHECK(lebedeva::isSquareAdvanced(square));
  BOOST_CHECK(!lebedeva::isCrossedSquare(square));
}

BOOST_AUTO_TEST_CASE(TestCrossedRotatedSquare)
{
  lebedeva::Shape square = lebedeva::squareRotated;
  lebedeva::makeCrossed(square, gen);
  BOOST_CHECK(lebedeva::isSquareAdvanced(square));
  BOOST_CHECK(lebedeva::isCrossedSquare(square));
}
BOOST_AUTO_TEST_SUITE_END()

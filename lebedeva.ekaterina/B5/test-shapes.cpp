#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <random>
#include "functions.hpp"
#include "test-variables.hpp"

BOOST_AUTO_TEST_SUITE(TestShape)
BOOST_AUTO_TEST_CASE(myTestCase)
{
  lebedeva::Shape s1 = { { 4434, 2684 }, { 4434, 6612 }, { 3857, 6612 }, { 3857, 2684 } };
  std::vector< lebedeva::Shape > shapes = { s1 };
  lebedeva::ShapesSpecifics info = countShapes(shapes);
  lebedeva::printInfo(std::cout, info);
  std::cout << '\n';
  lebedeva::printShapes(std::cout, shapes);
  BOOST_TEST(info.squares == 0);
}

BOOST_AUTO_TEST_CASE(myTestCase1)
{
  lebedeva::Shape s1 = { { 6147, 5156 }, { 8036, 3394 }, { 6892, 2168 }, { 5003, 3930 } };
  lebedeva::printPoints(std::cout, s1);
  std::cout << '\n';
  BOOST_TEST(lebedeva::isRectangleAdvanced(s1) == false);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestExtraTask)
std::random_device gen;

BOOST_AUTO_TEST_CASE(TestRandowQuadrilateral)
{
  lebedeva::Shape quadrilateral = lebedeva::makeQuadrilateral(gen);
  std::cout << "\nTest random quadrilateral\n";
  lebedeva::printPoints(std::cout, quadrilateral);
  bool isSquare = lebedeva::isSquareAdvanced(quadrilateral);
  bool isRect = lebedeva::isRectangleAdvanced(quadrilateral);
  std::cout << "\nIs quadrilateral a rectangle? " << (isRect ? "yes\n" : "no\n");
  if (isRect)
  {
    bool isCrossedRect = lebedeva::isCrossedRectangle(quadrilateral);
    std::cout << "\nIs quadrilateral a crossed rectangle? " << (isCrossedRect ? "yes\n" : "no\n");
    if (isCrossedRect)
    {
      BOOST_CHECK_EQUAL(isCrossedRect, true);
    }
    else if (isSquare)
    {
      std::cout << "\nIs quadrilateral a square? " << (isSquare ? "yes\n" : "no\n");
      isSquare = lebedeva::isSquare(quadrilateral);
      if (isSquare)
      {
        BOOST_CHECK_EQUAL(lebedeva::isSquare(quadrilateral), true);
      }
      isSquare = lebedeva::isCrossedSquare(quadrilateral);
      std::cout << "\nIs quadrilateral a crossed square? " << (isSquare ? "yes\n" : "no\n");
      if (isSquare)
      {
        BOOST_CHECK_EQUAL(isSquare, true);
      }
    }
  }
  else
  {
    std::cout << "Something went wrong\n";
  }
}

BOOST_AUTO_TEST_CASE(TestDefaultRect)
{
  lebedeva::Shape tRect = lebedeva::rect;
  BOOST_CHECK_EQUAL(lebedeva::isRectangle(tRect), true);
  BOOST_CHECK_EQUAL(lebedeva::isRectangleAdvanced(tRect), true);
  BOOST_CHECK_EQUAL(lebedeva::isCrossedRectangle(tRect), false);
}

BOOST_AUTO_TEST_CASE(TestCrossedNotRotatedRect)
{
  lebedeva::Shape tRect = lebedeva::rect;
  lebedeva::makeCrossed(tRect, gen);
  BOOST_CHECK_EQUAL(lebedeva::isRectangle(tRect), true);
  BOOST_CHECK_EQUAL(lebedeva::isRectangleAdvanced(tRect), true);
  BOOST_CHECK_EQUAL(lebedeva::isCrossedRectangle(tRect), true);
}

BOOST_AUTO_TEST_CASE(TestNotCrossedRotatedRect)
{
  lebedeva::Shape rect = lebedeva::rectRotated;
  BOOST_CHECK_EQUAL(lebedeva::isRectangle(rect), true);
  BOOST_CHECK_EQUAL(lebedeva::isRectangleAdvanced(rect), true);
  BOOST_CHECK_EQUAL(lebedeva::isCrossedRectangle(rect), false);
}

BOOST_AUTO_TEST_CASE(TestCrossedRotatedRect)
{
  lebedeva::Shape rect = lebedeva::rectRotated;
  lebedeva::makeCrossed(rect, gen);
  BOOST_CHECK_EQUAL(lebedeva::isRectangle(rect), true);
  BOOST_CHECK_EQUAL(lebedeva::isRectangleAdvanced(rect), true);
  BOOST_CHECK_EQUAL(lebedeva::isCrossedRectangle(rect), true);
}

BOOST_AUTO_TEST_CASE(TestDefaultSquare)
{
  lebedeva::Shape square = lebedeva::square;
  BOOST_CHECK_EQUAL(lebedeva::isSquare(square), true);
  BOOST_CHECK_EQUAL(lebedeva::isSquareAdvanced(square), true);
  BOOST_CHECK_EQUAL(lebedeva::isCrossedSquare(square), false);
}

BOOST_AUTO_TEST_CASE(TestCrossedNotRotatedSquare)
{
  lebedeva::Shape square = lebedeva::square;
  lebedeva::makeCrossed(square, gen);
  BOOST_CHECK_EQUAL(lebedeva::isSquareAdvanced(square), true);
  BOOST_CHECK_EQUAL(lebedeva::isCrossedSquare(square), true);
}

BOOST_AUTO_TEST_CASE(TestNotCrossedRotatedSquare)
{
  lebedeva::Shape square = lebedeva::squareRotated;
  BOOST_CHECK_EQUAL(lebedeva::isSquare(square), true);
  BOOST_CHECK_EQUAL(lebedeva::isSquareAdvanced(square), true);
  BOOST_CHECK_EQUAL(lebedeva::isCrossedSquare(square), false);
}

BOOST_AUTO_TEST_CASE(TestCrossedRotatedSquare)
{
  lebedeva::Shape square = lebedeva::squareRotated;
  lebedeva::makeCrossed(square, gen);
  BOOST_CHECK_EQUAL(lebedeva::isSquareAdvanced(square), true);
  BOOST_CHECK_EQUAL(lebedeva::isCrossedSquare(square), true);
}
BOOST_AUTO_TEST_SUITE_END()

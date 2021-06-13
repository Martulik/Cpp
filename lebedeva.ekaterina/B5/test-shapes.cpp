#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <random>
#include "functions.hpp"

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
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestExtraTask)

BOOST_AUTO_TEST_CASE(TestRandowQuadrilateral)
{
  std::random_device gen;
  lebedeva::Shape quadrilateral = lebedeva::makeQuadrilateral(gen);
  lebedeva::printPoints(std::cout, quadrilateral);
  bool isSquare = lebedeva::isSquareAdvanced(quadrilateral);
  bool isRect = lebedeva::isRectangleAdvanced(quadrilateral);
  std::cout << "\nIs quadrilateral a rectangle? " << (isRect ? "yes\n" : "no\n");
  if (isRect)
  {
    if (isSquare)
    {
      std::cout << "\nIs quadrilateral a square? " << (isSquare ? "yes\n" : "no\n");
      BOOST_CHECK_EQUAL(lebedeva::isSquare(quadrilateral), true);
      isSquare = lebedeva::isCrossedSquare(quadrilateral);
      std::cout << "\nIs quadrilateral a crossed square? " << (isSquare ? "yes\n" : "no\n");
      if (isSquare)
      {
        BOOST_CHECK_EQUAL(isSquare, true);
      }
    }
    else
    {
      bool isCrossedRect = lebedeva::isCrossedRectangle(quadrilateral);
      std::cout << "\nIs quadrilateral a crossed rectangle? " << (isCrossedRect ? "yes\n" : "no\n");
      BOOST_CHECK_EQUAL(isCrossedRect, true);
    }
  }
  else
  {
    std::cout << "Something went wrong\n";
  }
}

BOOST_AUTO_TEST_SUITE_END()

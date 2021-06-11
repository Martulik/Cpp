#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include "functions.hpp"

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

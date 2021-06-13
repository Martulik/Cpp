#include <boost/test/unit_test.hpp>
#include <chrono>

#include "point.hpp"
#include "extra-task.hpp"

BOOST_AUTO_TEST_SUITE(testingExtraTask)

BOOST_AUTO_TEST_CASE(correctGenerateFigure)
{
  std::mt19937 rand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
  dushechkina::Shape shape;
  shape = dushechkina::generateFigure(rand);
  BOOST_CHECK(dushechkina::isRectangle(shape));
}

BOOST_AUTO_TEST_CASE(correctWorkFunctionNotSelfInter)
{
  std::istringstream in("4 (0;0) (0;1) (1;1) (1;0)");
  dushechkina::Shape shape;
  in >> shape;
  BOOST_CHECK(dushechkina::isShapeNotSelfInter(shape));
}

BOOST_AUTO_TEST_CASE(correctWorkFunctionDeleteSelfInter)
{
  std::istringstream in("4 (0;1) (0;0) (1;1) (1;0)");
  dushechkina::Shape shape;
  in >> shape;
  dushechkina::changeShapeSelfInter(shape);
  BOOST_CHECK(dushechkina::isShapeNotSelfInter(shape));
}

BOOST_AUTO_TEST_CASE(correctWorkFunctionNotSelfInter)
{
  std::istringstream in("4 (-30; 29) (0; 2) (9; 12) (-21; 39)");
  dushechkina::Shape shape;
  in >> shape;
  BOOST_CHECK(dushechkina::isShapeNotSelfInter(shape));
}

BOOST_AUTO_TEST_CASE(correctWorkFunctionDeleteSelfInter)
{
  std::istringstream in("4 (-30; 29) (-21; 39) (9; 12) (0; 2)");
  dushechkina::Shape shape;
  in >> shape;
  dushechkina::changeShapeSelfInter(shape);
  BOOST_CHECK(dushechkina::isShapeNotSelfInter(shape));
}

BOOST_AUTO_TEST_SUITE_END()

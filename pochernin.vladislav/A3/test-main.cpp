#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>
#include <stdexcept>

#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

const double defaultWidth = 100.0;
const double defaultHeight = 50.0;
const double defaultRadius = 200.0;
const double defaultFactor = 3.0;
const double defaultFactorSquare = defaultFactor * defaultFactor;
const double negativeFactor = -1.0;
const double negativeWidth = -1.0;
const double negativeHeight = -1.0;
const double negativeRadius = -1.0;
const pochernin::point_t startPos = {10.0, 20.0};
const pochernin::point_t finishPos = {100.0, 200.0};
const size_t defaultSize = 10;

BOOST_AUTO_TEST_SUITE(Rectangle)

BOOST_AUTO_TEST_CASE(ConstWidthHeightAreaWhenMoving)
{
  pochernin::Rectangle testRectangle(defaultWidth, defaultHeight, startPos);
  testRectangle.move(finishPos);
  double testRectangleWidth = testRectangle.getFrameRect().width;
  double testRectangleHeight = testRectangle.getFrameRect().height;
  BOOST_CHECK((testRectangleWidth == defaultWidth) && (testRectangleHeight == defaultHeight));
}

BOOST_AUTO_TEST_CASE(QuadraticChangeAreaWhenScale)
{
  pochernin::Rectangle testRectangle(defaultWidth, defaultHeight, startPos);
  const double startArea = testRectangle.getArea();
  testRectangle.scale(defaultFactor);
  const double finishArea = testRectangle.getArea();
  BOOST_CHECK(finishArea == (startArea * defaultFactorSquare));
}

BOOST_AUTO_TEST_CASE(IncorrectWidth)
{
  BOOST_CHECK_THROW(pochernin::Rectangle testRectangle(negativeWidth, defaultHeight, startPos), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(IncorrectHeight)
{
  BOOST_CHECK_THROW(pochernin::Rectangle testRectangle(defaultWidth, negativeHeight, startPos), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(IncorrectFactor)
{
  pochernin::Rectangle testRectangle(defaultWidth, defaultHeight, startPos);
  BOOST_CHECK_THROW(testRectangle.scale(negativeFactor), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Circle)

BOOST_AUTO_TEST_CASE(ConstWidthHeightAreaWnenMoving)
{
  pochernin::Circle testCircle(defaultRadius, startPos);
  testCircle.move(finishPos);
  double testCircleWidth = testCircle.getFrameRect().width;
  double testCircleHeight = testCircle.getFrameRect().height;
  BOOST_CHECK ((testCircleWidth == (defaultRadius * 2.0)) && (testCircleHeight == (defaultRadius * 2.0)));
}

BOOST_AUTO_TEST_CASE(QuadraticChangeAreaWhenScale)
{
  pochernin::Circle testCircle(defaultRadius, startPos);
  const double startArea = testCircle.getArea();
  testCircle.scale(defaultFactor);
  const double finishArea = testCircle.getArea();
  BOOST_CHECK(finishArea == (startArea * defaultFactorSquare));
}

BOOST_AUTO_TEST_CASE(IncorrectRadius)
{
  BOOST_CHECK_THROW(pochernin::Circle testCircle(negativeRadius, startPos), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(IncorrectFactor)
{
  pochernin::Circle testCircle(defaultRadius, startPos);
  BOOST_CHECK_THROW(testCircle.scale(negativeRadius), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CompositeShape)

BOOST_AUTO_TEST_CASE(ShapeConstructorCreate)
{
  pochernin::Shape* testRectangle = new pochernin::Rectangle(defaultWidth, defaultHeight, startPos);
  std::shared_ptr< pochernin::Shape > testRectangleSharedPtr = std::shared_ptr< pochernin::Shape >(testRectangle);
  BOOST_CHECK_NO_THROW(pochernin::CompositeShape testCompositeShape(testRectangleSharedPtr));
  pochernin::CompositeShape testCompositeShape(testRectangleSharedPtr);
  BOOST_REQUIRE_EQUAL(testCompositeShape.size(), 1);
  BOOST_REQUIRE_EQUAL(testCompositeShape.capacity(), 1);
}

BOOST_AUTO_TEST_CASE(CopyConstructorCreate)
{
  pochernin::Shape* testRectangle = new pochernin::Rectangle(defaultWidth, defaultHeight, startPos);
  std::shared_ptr< pochernin::Shape > testRectangleSharedPtr = std::shared_ptr< pochernin::Shape >(testRectangle);
  pochernin::CompositeShape testCompositeShape1(testRectangleSharedPtr);
  BOOST_CHECK_NO_THROW(pochernin::CompositeShape testCompositeShape2(testCompositeShape1));
}

BOOST_AUTO_TEST_CASE(TransferConstructorCreate)
{
  pochernin::Shape* testRectangle = new pochernin::Rectangle(defaultWidth, defaultHeight, startPos);
  std::shared_ptr< pochernin::Shape > testRectangleSharedPtr = std::shared_ptr< pochernin::Shape >(testRectangle);
  pochernin::CompositeShape testCompositeShape1(testRectangleSharedPtr);
  BOOST_CHECK_NO_THROW(pochernin::CompositeShape testCompositeShape2 = std::move(testCompositeShape1));
}

BOOST_AUTO_TEST_CASE(AssigmentOperator)
{
  pochernin::Shape* testRectangle = new pochernin::Rectangle(defaultWidth, defaultHeight, startPos);
  std::shared_ptr< pochernin::Shape > testRectangleSharedPtr = std::shared_ptr< pochernin::Shape >(testRectangle);
  pochernin::CompositeShape testCompositeShape1(testRectangleSharedPtr);
  pochernin::CompositeShape testCompositeShape2(testRectangleSharedPtr);
  BOOST_CHECK_NO_THROW(testCompositeShape1 = testCompositeShape2);
}

BOOST_AUTO_TEST_CASE(TransferAssignmentOperator)
{
  pochernin::Shape* testRectangle = new pochernin::Rectangle(defaultWidth, defaultHeight, startPos);
  std::shared_ptr< pochernin::Shape > testRectangleSharedPtr = std::shared_ptr< pochernin::Shape >(testRectangle);
  pochernin::CompositeShape testCompositeShape1(testRectangleSharedPtr);
  pochernin::CompositeShape testCompositeShape2(testRectangleSharedPtr);
  BOOST_CHECK_NO_THROW(testCompositeShape1 = std::move(testCompositeShape2));
}

BOOST_AUTO_TEST_CASE(AddElements)
{
  std::shared_ptr< pochernin::Shape > testCircle = std::make_shared< pochernin::Circle >(defaultRadius, startPos);
  pochernin::Shape* testRectangle = new pochernin::Rectangle(defaultWidth, defaultHeight, startPos);
  std::shared_ptr< pochernin::Shape > testRectangleSharedPtr = std::shared_ptr< pochernin::Shape >(testRectangle);
  pochernin::CompositeShape testCompositeShape(testRectangleSharedPtr);
  BOOST_CHECK_NO_THROW(testCompositeShape.push_back(testCircle));
  BOOST_REQUIRE_EQUAL(testCompositeShape.size(), 2);
  BOOST_REQUIRE_EQUAL(testCompositeShape.capacity(), 2);
}

BOOST_AUTO_TEST_SUITE_END()

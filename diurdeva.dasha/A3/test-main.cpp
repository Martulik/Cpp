#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

const diurdeva::point_t pointCenter = {3.5, 4.0};
const diurdeva::point_t newCenter = {3.0, 2.0};
const double width = 8.0;
const double height = 5.0;
const double radius = 3;
const double factor = 2.0;
const double negativeWidth = -8.0;
const double negativeHeight = -5.0;
const double negativeRadius = -3.0;
const double negativeFactor = -2.0;

void checkAreaBeforeScale(diurdeva::Shape *shape)
{
  double area = shape->getArea();
  shape->scale(factor);
  BOOST_CHECK_CLOSE(area * factor * factor, shape->getArea(), 0.00001);
}

void ConstOptionsWhenMoving(diurdeva::Shape *shape)
{
  double widthBeforeMove = shape->getFrameRect().width;
  double heightBeforeMove = shape->getFrameRect().height;
  double area = shape->getArea();
  shape->move(newCenter);
  BOOST_CHECK((shape->getFrameRect().width == widthBeforeMove) && (shape->getFrameRect().height == heightBeforeMove) &&
              (area == shape->getArea()));
}

BOOST_AUTO_TEST_SUITE(testRectangle)

  BOOST_AUTO_TEST_CASE(invalidWidth)
  {
    BOOST_CHECK_THROW(diurdeva::Rectangle rectangle(negativeWidth, height, pointCenter), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(invalidHeight)
  {
    BOOST_CHECK_THROW(diurdeva::Rectangle rectangle(negativeHeight, width, pointCenter), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(invalidFactor)
  {
    diurdeva::Rectangle rectangle(width, height, pointCenter);
    BOOST_CHECK_THROW(rectangle.scale(negativeFactor), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(cheakOptionsWhenMoving)
  {
    diurdeva::Rectangle rectangle(width, height, pointCenter);
    ConstOptionsWhenMoving(&rectangle);
  }

  BOOST_AUTO_TEST_CASE(сhangeAreaWhenScale)
  {
    diurdeva::Rectangle rectangle(width, height, pointCenter);
    checkAreaBeforeScale(&rectangle);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testCircle)

  BOOST_AUTO_TEST_CASE(invalidRadius)
  {
    BOOST_CHECK_THROW(diurdeva::Circle circle(negativeRadius, pointCenter), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(invalidFactor)
  {
    diurdeva::Circle circle(radius, pointCenter);
    BOOST_CHECK_THROW(circle.scale(negativeFactor), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(cheakOptionsWhenMoving)
  {
    diurdeva::Circle circle(radius, pointCenter);
    ConstOptionsWhenMoving(&circle);
  }

  BOOST_AUTO_TEST_CASE(сhangeAreaWhenScale)
  {
    diurdeva::Circle circle(radius, pointCenter);
    checkAreaBeforeScale(&circle);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testCompositeShape)

  BOOST_AUTO_TEST_CASE(testComposite)
  {
    std::shared_ptr<diurdeva::Shape> rectangle = std::make_shared<diurdeva::Rectangle>(width, height, pointCenter);
    std::shared_ptr<diurdeva::Shape> circle = std::make_shared<diurdeva::Circle>(radius, pointCenter);
    diurdeva::CompositeShape compositeShape;
    BOOST_CHECK_NO_THROW(compositeShape.addShape(rectangle));
    BOOST_CHECK_NO_THROW(compositeShape.addShape(circle));
    BOOST_REQUIRE_EQUAL(compositeShape.getSize(), 2);
  }

  BOOST_AUTO_TEST_CASE(invalidArgument)
  {
    std::shared_ptr<diurdeva::Shape> rectangle = std::make_shared<diurdeva::Rectangle>(width, height, pointCenter);
    diurdeva::CompositeShape compositeShape;
    compositeShape.addShape((rectangle));
    BOOST_CHECK_THROW(compositeShape[3], std::out_of_range);
    BOOST_CHECK_THROW(compositeShape.scale(-2.0), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(cheakOptionsWhenMoving)
  {
    std::shared_ptr<diurdeva::Shape> rectangle = std::make_shared<diurdeva::Rectangle>(width, height, pointCenter);
    std::shared_ptr<diurdeva::Shape> circle = std::make_shared<diurdeva::Circle>(radius, pointCenter);
    diurdeva::CompositeShape compositeShape;
    BOOST_CHECK_NO_THROW(compositeShape.addShape(rectangle));
    BOOST_CHECK_NO_THROW(compositeShape.addShape(circle));
    ConstOptionsWhenMoving(&compositeShape);
  }

  BOOST_AUTO_TEST_CASE(сhangeAreaWhenScale)
  {
    std::shared_ptr<diurdeva::Shape> rectangle = std::make_shared<diurdeva::Rectangle>(width, height, pointCenter);
    std::shared_ptr<diurdeva::Shape> circle = std::make_shared<diurdeva::Circle>(radius, pointCenter);
    diurdeva::CompositeShape compositeShape;
    BOOST_CHECK_NO_THROW(compositeShape.addShape(rectangle));
    BOOST_CHECK_NO_THROW(compositeShape.addShape(circle));
    checkAreaBeforeScale(&compositeShape);
  }

BOOST_AUTO_TEST_SUITE_END()

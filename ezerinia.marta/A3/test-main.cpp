#define BOOST_TEST_MODULE A3

#include <boost/test/included/unit_test.hpp>
#include <stdexcept>

#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

double accuracy = std::numeric_limits< double >::epsilon();
double width = 9.1;
double height = 74.9;
double radius = 87.7;
double negativeValue = -11.3;
ezerinia::point_t point{46.7, -6.2};

void checkWidthHeightArea(ezerinia::Shape *shape, ezerinia::rectangle_t frameRect, double areaBeforeMove)
{
  BOOST_CHECK_EQUAL(shape->getFrameRect().width, frameRect.width);
  BOOST_CHECK_EQUAL(shape->getFrameRect().height, frameRect.height);
  BOOST_CHECK_EQUAL(areaBeforeMove, shape->getArea());
}

void checkMoveAbs(ezerinia::Shape *shape)
{
  ezerinia::rectangle_t frameRect = shape->getFrameRect();
  double areaBeforeMove = shape->getArea();
  shape->move(111.0, -1.0);
  checkWidthHeightArea(shape, frameRect, areaBeforeMove);
}

void checkMovePoint(ezerinia::Shape *shape)
{
  ezerinia::rectangle_t frameRect = shape->getFrameRect();
  double areaBeforeMove = shape->getArea();
  shape->move({21.0, -12.0});
  checkWidthHeightArea(shape, frameRect, areaBeforeMove);
}

void checkScale(ezerinia::Shape *shape)
{
  double areaBeforeScale = shape->getArea();
  shape->scale(2);
  BOOST_CHECK_CLOSE(areaBeforeScale * 2 * 2, shape->getArea(), accuracy);
}

void addShapes(ezerinia::CompositeShape *shape)
{
  std::shared_ptr< ezerinia::Shape > rectangle
          = std::make_shared< ezerinia::Rectangle >(64.1, 3.1, ezerinia::point_t{2.0, 2.0});
  shape->push_back(rectangle);

  std::shared_ptr< ezerinia::Shape > circle
          = std::make_shared< ezerinia::Circle >(1.0, ezerinia::point_t{1.0, 1.0});
  shape->push_back(circle);

  std::shared_ptr< ezerinia::Shape > circle1
          = std::make_shared< ezerinia::Circle >(60.0, ezerinia::point_t{-22.0, 0.0});
  shape->push_back(circle1);
}

BOOST_AUTO_TEST_SUITE(testCircle)

  BOOST_AUTO_TEST_CASE(moveCircle)
  {
    ezerinia::Circle circle(radius, point);
    checkMoveAbs(&circle);
    checkMovePoint(&circle);
  }

  BOOST_AUTO_TEST_CASE(scaleCircle)
  {
    ezerinia::Circle circle(radius, point);
    checkScale(&circle);
  }

  BOOST_AUTO_TEST_CASE(invalidArgumentCircle)
  {
    BOOST_CHECK_THROW(ezerinia::Circle(negativeValue, point), std::invalid_argument);
    BOOST_CHECK_THROW(ezerinia::Circle(radius, point).scale(negativeValue), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testRectangle)

  BOOST_AUTO_TEST_CASE(moveRectangle)
  {
    ezerinia::Rectangle rectangle(width, height, point);
    checkMoveAbs(&rectangle);
    checkMovePoint(&rectangle);
  }

  BOOST_AUTO_TEST_CASE(scaleRectangle)
  {
    ezerinia::Rectangle rectangle(width, height, point);
    checkScale(&rectangle);
  }

  BOOST_AUTO_TEST_CASE(invalidArgumentRectangle)
  {
    BOOST_CHECK_THROW(ezerinia::Rectangle(width, negativeValue, point), std::invalid_argument);
    BOOST_CHECK_THROW(ezerinia::Rectangle(negativeValue, height, point), std::invalid_argument);
    BOOST_CHECK_THROW(ezerinia::Rectangle(width, height, point).scale(negativeValue), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testCompositeShape)

  BOOST_AUTO_TEST_CASE(moveCompositeShape)
  {
    ezerinia::CompositeShape composite(std::make_shared< ezerinia::Rectangle >(width, height, point));
    addShapes(&composite);
    checkMoveAbs(&composite);
    checkMovePoint(&composite);
  }

  BOOST_AUTO_TEST_CASE(scaleCompositeShape)
  {
    ezerinia::CompositeShape composite(std::make_shared< ezerinia::Circle >(radius, point));
    addShapes(&composite);
    checkScale(&composite);
  }

  BOOST_AUTO_TEST_CASE(invalidArgumentCompositeShape)
  {
    ezerinia::CompositeShape composite(std::make_shared< ezerinia::Rectangle >(width, height, point));
    BOOST_CHECK_THROW(composite.scale(negativeValue), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(outOfRangeCompositeShape)
  {
    ezerinia::CompositeShape composite(std::make_shared< ezerinia::Circle >(radius, point));
    BOOST_CHECK_THROW(composite.at(70000), std::out_of_range);
  }

  BOOST_AUTO_TEST_CASE(deleteLastShapeInCompositeShape)
  {
    ezerinia::CompositeShape composite(std::make_shared< ezerinia::Circle >(radius, point));
    BOOST_CHECK_THROW(composite.pop_back(), std::logic_error);
  }

BOOST_AUTO_TEST_SUITE_END()

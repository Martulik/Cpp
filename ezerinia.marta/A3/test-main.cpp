#define BOOST_TEST_MODULE A3

#include <boost/test/included/unit_test.hpp>
#include <stdexcept>

#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

void checkMoveAbs(ezerinia::Shape *shape)
{
  ezerinia::rectangle_t frameRect = shape->getFrameRect();
  double areaBeforeMove = shape->getArea();
  shape->move(111.0, -1.0);
  BOOST_CHECK(shape->getFrameRect().width == frameRect.width &&
              shape->getFrameRect().height == frameRect.height && areaBeforeMove == shape->getArea());
}

void checkMovePoint(ezerinia::Shape *shape)
{
  ezerinia::rectangle_t frameRect = shape->getFrameRect();
  double areaBeforeMove = shape->getArea();
  shape->move({21.0, -12.0});
  BOOST_CHECK(shape->getFrameRect().width == frameRect.width &&
              shape->getFrameRect().height == frameRect.height && areaBeforeMove == shape->getArea());
}

void checkScale(ezerinia::Shape *shape)
{
  double areaBeforeScale = shape->getArea();
  shape->scale(3);
  BOOST_CHECK_CLOSE(areaBeforeScale * 9, shape->getArea(), 0.00001);
}

void addShapes(ezerinia::CompositeShape *shape)
{
  std::shared_ptr<ezerinia::Shape> rectangle
          = std::make_shared<ezerinia::Rectangle>(2.0, 82.5, ezerinia::point_t{2.0, 2.0});
  shape->pushBack(rectangle);

  std::shared_ptr<ezerinia::Shape> circle
          = std::make_shared<ezerinia::Circle>(1.0, ezerinia::point_t{1.0, 1.0});
  shape->pushBack(circle);

  std::shared_ptr<ezerinia::Shape> circle1
          = std::make_shared<ezerinia::Circle>(60.0, ezerinia::point_t{-22.0, 0.0});
  shape->pushBack(circle1);

  std::shared_ptr<ezerinia::Shape> circle2
          = std::make_shared<ezerinia::Circle>(111.0, ezerinia::point_t{12.0, -61.0});
  shape->pushBack(circle2);
}

BOOST_AUTO_TEST_SUITE(testCircle)

  BOOST_AUTO_TEST_CASE(moveCircle)
  {
    ezerinia::Circle circle(2.0, {2.0, 2.0});
    checkMoveAbs(&circle);
    checkMovePoint(&circle);
  }

  BOOST_AUTO_TEST_CASE(scaleCircle)
  {
    ezerinia::Circle circle(1.0, {1.0, 1.0});
    checkScale(&circle);
  }

  BOOST_AUTO_TEST_CASE(invalidArgumentCircle)
  {
    BOOST_CHECK_THROW(ezerinia::Circle(-0.9, {-73.0, 81.0}), std::invalid_argument);
    BOOST_CHECK_THROW(ezerinia::Circle(73.7, {-53.0, 94.0}).scale(-0.9), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testRectangle)

  BOOST_AUTO_TEST_CASE(moveRectangle)
  {
    ezerinia::Rectangle rectangle(2.0, 555.0, {22.0, -22.0});
    checkMoveAbs(&rectangle);
    checkMovePoint(&rectangle);
  }

  BOOST_AUTO_TEST_CASE(scaleRectangle)
  {
    ezerinia::Rectangle rectangle(23.0, 32.0, {-100.0, 1.0});
    checkScale(&rectangle);
  }

  BOOST_AUTO_TEST_CASE(invalidArgumentRectangle)
  {
    BOOST_CHECK_THROW(ezerinia::Rectangle(14.3, -90.11, {-91.0, 1.0}), std::invalid_argument);
    BOOST_CHECK_THROW(ezerinia::Rectangle(-45.3, 7.01, {-6.0, 2.0}), std::invalid_argument);
    BOOST_CHECK_THROW(ezerinia::Rectangle(64.3, 0.11, {-23.0, 564.0}).scale(-4.4), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testCompositeShape)

  BOOST_AUTO_TEST_CASE(moveCompositeShape)
  {
    ezerinia::CompositeShape composite;
    addShapes(&composite);
    checkMoveAbs(&composite);
    checkMovePoint(&composite);
  }

  BOOST_AUTO_TEST_CASE(scaleCompositeShape)
  {
    ezerinia::CompositeShape composite;
    addShapes(&composite);
    checkScale(&composite);
  }

  BOOST_AUTO_TEST_CASE(invalidArgumentCompositeShape)
  {
    ezerinia::CompositeShape composite;
    addShapes(&composite);
    BOOST_CHECK_THROW(composite[-7], std::invalid_argument);
    BOOST_CHECK_THROW(composite.scale(-100.1), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()

#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE a3
#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

namespace l = lebedeva;

void checkFrameRect(const l::rectangle_t& oldFrameRect, const l::rectangle_t& newFrameRect);

BOOST_AUTO_TEST_SUITE(CircleTest)

  l::point_t newPos = { 3.0, 4.1 };

  BOOST_AUTO_TEST_CASE(GetCircleName)
  {
    l::Circle circ = { { 0.0, 0.0 }, 1 };
    BOOST_CHECK("Circle" == circ.getName());
  }

  BOOST_AUTO_TEST_CASE(MoveCircleToPoint)
  {
    l::point_t oldPos = { 1.0, 1.1 };
    l::Circle circ = { oldPos, 3 };
    l::rectangle_t oldFrameRect = circ.getFrameRect();
    double area = circ.getArea();

    circ.move(newPos);
    checkFrameRect(oldFrameRect, circ.getFrameRect());
    BOOST_CHECK_EQUAL(area, circ.getArea());
  }

  BOOST_AUTO_TEST_CASE(MoveCircleAbs)
  {
    l::point_t oldPos = { 1.0, 1.1 };
    l::Circle circ = { oldPos, 3 };
    l::rectangle_t oldFrameRect = circ.getFrameRect();
    double area = circ.getArea();

    circ.move(newPos.x, -newPos.y);
    checkFrameRect(oldFrameRect, circ.getFrameRect());
    BOOST_CHECK_CLOSE(area, circ.getArea(), 0.000001);
  }

  BOOST_AUTO_TEST_CASE(ScaleCircle)
  {
    l::Circle circ = { { 1.0, 1.1 }, 1 };
    double areaBeforeScale = circ.getArea();

    circ.scale(2);
    BOOST_CHECK_CLOSE(areaBeforeScale * 4, circ.getArea(), 0.000001);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(RectangleTest)

  l::point_t newPos = { 3.0, 4.1 };

  BOOST_AUTO_TEST_CASE(GetRectangleName)
  {
    l::Rectangle rect = { { 0.0, 0.0 }, 1, 2 };
    BOOST_CHECK_EQUAL("Rectangle", rect.getName());
  }

  BOOST_AUTO_TEST_CASE(MoveRectangleToPoint)
  {
    l::Rectangle rect = { { 0.0, 0.1 }, 1, 2 };
    l::rectangle_t oldFrameRect = rect.getFrameRect();
    double area = rect.getArea();

    rect.move(newPos);
    checkFrameRect(oldFrameRect, rect.getFrameRect());
    BOOST_CHECK_EQUAL(area, rect.getArea());
  }

  BOOST_AUTO_TEST_CASE(MoveRectangleAbs)
  {
    l::Rectangle rect = { { 0.0, 0.1 }, 1, 2 };
    l::rectangle_t oldFrameRect = rect.getFrameRect();
    double area = rect.getArea();

    rect.move(newPos.x, -newPos.y);
    checkFrameRect(oldFrameRect, rect.getFrameRect());
    BOOST_CHECK_CLOSE(area, rect.getArea(), 0.000001);
  }

  BOOST_AUTO_TEST_CASE(ScaleRectangle)
  {
    l::Rectangle rect = { { 0.0, 0.0 }, 1, 2 };
    double areaBeforeScale = rect.getArea();

    rect.scale(2);
    BOOST_CHECK_CLOSE(areaBeforeScale * 4, rect.getArea(), 0.000001);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CompositeShapeTest)

  std::shared_ptr< l::Shape > shapeArray[2] =
  {
    std::make_shared< l::Rectangle >(l::point_t({ 0, 0 }), 12, 3),
    std::make_shared< l::Circle >(l::point_t({ 9, 12 }), 3)
  };
  l::point_t newPos = { 3.0, 4.1 };

  BOOST_AUTO_TEST_CASE(GetCollectionAreaTest)
  {
    l::CompositeShape collection(shapeArray, sizeof(shapeArray) / sizeof(shapeArray[0]));

    BOOST_CHECK_CLOSE((collection[0]->getArea() + collection[1]->getArea()), collection.getArea(), 0.000001);
  }

  BOOST_AUTO_TEST_CASE(MoveCompositeShapeToPoint)
  {
    l::CompositeShape collection(shapeArray, sizeof(shapeArray) / sizeof(shapeArray[0]));
    double area = collection.getArea();
    l::rectangle_t oldFrameRect = collection.getFrameRect();

    collection.move(newPos);
    checkFrameRect(oldFrameRect, collection.getFrameRect());
    BOOST_CHECK_CLOSE(area, collection.getArea(), 0.000001);
  }

  BOOST_AUTO_TEST_CASE(MoveAbsCompositeShape)
  {
    l::CompositeShape collection(shapeArray, sizeof(shapeArray) / sizeof(shapeArray[0]));
    double area = collection.getArea();
    l::rectangle_t oldFrameRect = collection.getFrameRect();

    collection.move(newPos.x, newPos.y);
    checkFrameRect(oldFrameRect, collection.getFrameRect());
    BOOST_CHECK_CLOSE(area, collection.getArea(), 0.000001);
  }

  BOOST_AUTO_TEST_CASE(ScaleCompositeShape)
  {
    l::CompositeShape collection(shapeArray, sizeof(shapeArray) / sizeof(shapeArray[0]));
    double areaBeforeScale = collection.getArea();

    collection.scale(2);
    BOOST_CHECK_CLOSE(areaBeforeScale * 4, collection.getArea(), 0.000001);
  }

  BOOST_AUTO_TEST_CASE(AddCompositeShapeToCollection)
  {
    std::shared_ptr< l::Shape > forCollectionArray[2] =
    {
      std::make_shared< l::Circle >(l::point_t({ 2.2, -10.0 }), 2),
      std::make_shared< l::CompositeShape >(shapeArray, sizeof(shapeArray) / sizeof(shapeArray[0]))
    };
    l::CompositeShape collection(forCollectionArray, sizeof(forCollectionArray) / sizeof(forCollectionArray[0]));

    BOOST_CHECK_CLOSE((collection[0]->getArea() + collection[1]->getArea()), collection.getArea(), 0.000001);
  }

BOOST_AUTO_TEST_SUITE_END()

void checkFrameRect(const l::rectangle_t& oldFrameRect, const l::rectangle_t& newFrameRect)
{
  BOOST_CHECK(oldFrameRect.height == newFrameRect.height);
  BOOST_CHECK(oldFrameRect.width == newFrameRect.width);
}

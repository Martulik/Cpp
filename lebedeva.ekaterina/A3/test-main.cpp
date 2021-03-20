#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE a3
#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

namespace leb = lebedeva;

void checkFrameRect(const leb::rectangle_t& oldFrameRect, const leb::rectangle_t& newFrameRect);

BOOST_AUTO_TEST_SUITE(CircleTest)

  leb::point_t newPos = { 3.0, 4.1 };
  leb::point_t oldPos = { 1.0, 1.1 };

  BOOST_AUTO_TEST_CASE(GetCircleName)
  {
    leb::Circle circ = { oldPos, 1 };
    BOOST_CHECK("Circle" == circ.getName());
  }

  BOOST_AUTO_TEST_CASE(MoveCircleToPoint)
  {
    leb::Circle circ = { oldPos, 3 };
    leb::rectangle_t oldFrameRect = circ.getFrameRect();
    double area = circ.getArea();

    circ.move(newPos);
    checkFrameRect(oldFrameRect, circ.getFrameRect());
    BOOST_CHECK_EQUAL(area, circ.getArea());
  }

  BOOST_AUTO_TEST_CASE(MoveCircleAbs)
  {
    leb::Circle circ = { oldPos, 3 };
    leb::rectangle_t oldFrameRect = circ.getFrameRect();
    double area = circ.getArea();

    circ.move(newPos.x, -newPos.y);
    checkFrameRect(oldFrameRect, circ.getFrameRect());
    BOOST_CHECK_CLOSE(area, circ.getArea(), 0.000001);
  }

  BOOST_AUTO_TEST_CASE(ScaleCircle)
  {
    leb::Circle circ = { oldPos, 1 };
    double areaBeforeScale = circ.getArea();

    circ.scale(2);
    BOOST_CHECK_CLOSE(areaBeforeScale * 4, circ.getArea(), 0.000001);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(RectangleTest)

  leb::point_t newPos = { 3.0, 4.1 };
  leb::point_t oldPos = { 0.0, 0.1 };

  BOOST_AUTO_TEST_CASE(GetRectangleName)
  {
    leb::Rectangle rect = { oldPos, 1, 2 };
    BOOST_CHECK_EQUAL("Rectangle", rect.getName());
  }

  BOOST_AUTO_TEST_CASE(MoveRectangleToPoint)
  {
    leb::Rectangle rect = { oldPos, 1, 2 };
    leb::rectangle_t oldFrameRect = rect.getFrameRect();
    double area = rect.getArea();

    rect.move(newPos);
    checkFrameRect(oldFrameRect, rect.getFrameRect());
    BOOST_CHECK_EQUAL(area, rect.getArea());
  }

  BOOST_AUTO_TEST_CASE(MoveRectangleAbs)
  {
    leb::Rectangle rect = { oldPos, 1, 2 };
    leb::rectangle_t oldFrameRect = rect.getFrameRect();
    double area = rect.getArea();

    rect.move(newPos.x, -newPos.y);
    checkFrameRect(oldFrameRect, rect.getFrameRect());
    BOOST_CHECK_CLOSE(area, rect.getArea(), 0.000001);
  }

  BOOST_AUTO_TEST_CASE(ScaleRectangle)
  {
    leb::Rectangle rect = { oldPos, 1, 2 };
    double areaBeforeScale = rect.getArea();

    rect.scale(2);
    BOOST_CHECK_CLOSE(areaBeforeScale * 4, rect.getArea(), 0.000001);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CompositeShapeTest)

  std::shared_ptr< leb::Shape > shapeArray[2] =
  {
    std::make_shared< leb::Rectangle >(leb::point_t({ 3, -2 }), 4, 2),
    std::make_shared< leb::Circle >(leb::point_t({ 1, 2 }), 1)
  };
  leb::point_t newPos = { 3.0, 4.1 };

  BOOST_AUTO_TEST_CASE(GetCompositeShapeName)
  {
    leb::CompositeShape collection(shapeArray, sizeof(shapeArray) / sizeof(shapeArray[0]));
    BOOST_CHECK_EQUAL("Composite Shape", collection.getName());
  }

  BOOST_AUTO_TEST_CASE(GetCollectionAreaTest)
  {
    leb::CompositeShape collection(shapeArray, sizeof(shapeArray) / sizeof(shapeArray[0]));

    BOOST_CHECK_CLOSE((collection[0]->getArea() + collection[1]->getArea()),
      collection.getArea(), 0.000001);
  }

  BOOST_AUTO_TEST_CASE(MoveCompositeShapeToPoint)
  {
    leb::CompositeShape collection(shapeArray, sizeof(shapeArray) / sizeof(shapeArray[0]));
    double area = collection.getArea();
    leb::rectangle_t oldFrameRect = collection.getFrameRect();

    collection.move(newPos);
    checkFrameRect(oldFrameRect, collection.getFrameRect());
    BOOST_CHECK_CLOSE(area, collection.getArea(), 0.000001);
  }

  BOOST_AUTO_TEST_CASE(MoveAbsCompositeShape)
  {
    leb::CompositeShape collection(shapeArray, sizeof(shapeArray) / sizeof(shapeArray[0]));
    double area = collection.getArea();
    leb::rectangle_t oldFrameRect = collection.getFrameRect();

    collection.move(newPos.x, newPos.y);
    checkFrameRect(oldFrameRect, collection.getFrameRect());
    BOOST_CHECK_CLOSE(area, collection.getArea(), 0.000001);
  }

  BOOST_AUTO_TEST_CASE(ScaleCompositeShape)
  {
    leb::CompositeShape collection(shapeArray, sizeof(shapeArray) / sizeof(shapeArray[0]));
    leb::rectangle_t oldFrameRect = collection.getFrameRect();
    double areaBeforeScale = collection.getArea();

    collection.scale(2);
    BOOST_CHECK_CLOSE(areaBeforeScale * 4, collection.getArea(), 0.000001);
    leb::rectangle_t newFrameRect = collection.getFrameRect();
    BOOST_CHECK_CLOSE(oldFrameRect.width * 2, newFrameRect.width, 0.000001);
    BOOST_CHECK_CLOSE(oldFrameRect.height * 2, newFrameRect.height, 0.000001);
    BOOST_CHECK_EQUAL(oldFrameRect.pos.x, newFrameRect.pos.x);
    BOOST_CHECK_EQUAL(oldFrameRect.pos.y, newFrameRect.pos.y);
  }

  BOOST_AUTO_TEST_CASE(AddCompositeShapeToCollection)
  {
    std::shared_ptr< leb::Shape > forCollectionArray[2] =
    {
      std::make_shared< leb::Circle >(leb::point_t({ 2.2, -10.0 }), 2),
      std::make_shared< leb::CompositeShape >(shapeArray,
        sizeof(shapeArray) / sizeof(shapeArray[0]))
    };
    leb::CompositeShape collection(forCollectionArray,
      sizeof(forCollectionArray) / sizeof(forCollectionArray[0]));

    BOOST_CHECK_CLOSE((collection[0]->getArea() + collection[1]->getArea()),
      collection.getArea(), 0.000001);
  }

BOOST_AUTO_TEST_SUITE_END()

void checkFrameRect(const leb::rectangle_t& oldFrameRect, const leb::rectangle_t& newFrameRect)
{
  BOOST_CHECK(oldFrameRect.height == newFrameRect.height);
  BOOST_CHECK(oldFrameRect.width == newFrameRect.width);
}

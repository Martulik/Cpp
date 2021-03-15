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

  BOOST_AUTO_TEST_CASE(GetCircleName)
  {
    l::Circle circ = { { 0.0, 0.0 }, 1 };
    BOOST_CHECK("Circle" == circ.getName());
  }

  BOOST_AUTO_TEST_CASE(MoveCircleToPoint)
  {
    l::point_t oldPos = { 1.0, 1.1 };
    l::Circle circ = { oldPos, 3 };
    l::point_t newPos = { 3.0, 4.1 };
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
    l::point_t newPos = { 3.0, 4.1 };
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

  BOOST_AUTO_TEST_CASE(GetRectangleName)
  {
    l::Rectangle rect = { { 0.0, 0.0 }, 1, 2 };
    BOOST_CHECK_EQUAL("Rectangle", rect.getName());
  }

  BOOST_AUTO_TEST_CASE(MoveRectangleToPoint)
  {
    l::Rectangle rect = { { 0.0, 0.1 }, 1, 2 };
    l::point_t newPos = { 3.0, 4.1 };
    l::rectangle_t oldFrameRect = rect.getFrameRect();
    double area = rect.getArea();

    rect.move(newPos);
    checkFrameRect(oldFrameRect, rect.getFrameRect());
    BOOST_CHECK_EQUAL(area, rect.getArea());
  }

  BOOST_AUTO_TEST_CASE(MoveRectangleAbs)
  {
    l::Rectangle rect = { { 0.0, 0.1 }, 1, 2 };
    l::point_t newPos = { 3.0, 4.1 };
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

  BOOST_AUTO_TEST_CASE(GetCompositeShapeName)
  {
    l::CompositeShape collection;
    BOOST_CHECK_EQUAL("Composite Shape", collection.getName());
  }

  BOOST_AUTO_TEST_CASE(GetNumOfFiguresTest)
  {
    l::CompositeShape collection;
    BOOST_CHECK_EQUAL(0, collection.getNumOfFigures());
  }

  BOOST_AUTO_TEST_CASE(ZeroAreaTest)
  {
    l::CompositeShape collection;
    BOOST_CHECK_EQUAL(0, collection.getArea());
  }

  BOOST_AUTO_TEST_CASE(PushTest)
  {
    l::CompositeShape collection;
    collection.push(std::make_shared< l::Rectangle >(l::point_t({ 0, 0 }), 12, 3));
    collection.push(std::make_shared< l::Circle >(l::point_t({ 9, 12 }), 3));

    BOOST_CHECK_EQUAL(2, collection.getNumOfFigures());
    BOOST_CHECK_CLOSE((collection[0]->getArea() + collection[1]->getArea()), collection.getArea(), 0.000001);
  }

  BOOST_AUTO_TEST_CASE(CollectionPushTest)
  {
    l::CompositeShape collection;
    std::shared_ptr< l::CompositeShape > subCollectionPtr = std::make_shared< l::CompositeShape >();

    subCollectionPtr->push(std::make_shared< l::Rectangle >(l::point_t({ 0, 0 }), 12, 3));
    BOOST_CHECK_EQUAL(1, subCollectionPtr->getNumOfFigures());

    collection.push(std::make_shared< l::Circle >(l::point_t({ 9, 12 }), 3));
    BOOST_CHECK_EQUAL(1, collection.getNumOfFigures());

    collection.push(subCollectionPtr);
    BOOST_CHECK_EQUAL(2, collection.getNumOfFigures());
    BOOST_CHECK_CLOSE((collection[0]->getArea() + collection[1]->getArea()), collection.getArea(), 0.000001);
  }

  BOOST_AUTO_TEST_CASE(MoveCompositeShape)
  {
    l::CompositeShape collection;
    collection.push(std::make_shared< l::Rectangle >(l::point_t({ 5.1, 0 }), 1.0, 2.0));
    collection.push(std::make_shared< l::Rectangle >(l::point_t({ 0, 0 }), 1.0, 2.0));
    double area = collection.getArea();
    l::rectangle_t oldFrameRect = collection.getFrameRect();
    l::point_t newPos = { 3.0, 4.1 };

    collection.move(newPos);
    checkFrameRect(oldFrameRect, collection.getFrameRect());
    BOOST_CHECK_CLOSE(area, collection.getArea(), 0.000001);
  }

  BOOST_AUTO_TEST_CASE(ScaleCompositeShape)
  {
    l::CompositeShape collection;
    collection.push(std::make_shared< l::Rectangle >(l::point_t({ 5.1, 0 }), 1.0, 2.0));
    collection.push(std::make_shared< l::Rectangle >(l::point_t({ 0, 0 }), 1.0, 2.0));
    double areaBeforeScale = collection.getArea();

    collection.scale(2);
    BOOST_CHECK_CLOSE(areaBeforeScale * 4, collection.getArea(), 0.000001);
  }

BOOST_AUTO_TEST_SUITE_END()

void checkFrameRect(const l::rectangle_t& oldFrameRect, const l::rectangle_t& newFrameRect)
{
  BOOST_CHECK(oldFrameRect.height == newFrameRect.height);
  BOOST_CHECK(oldFrameRect.width == newFrameRect.width);
}

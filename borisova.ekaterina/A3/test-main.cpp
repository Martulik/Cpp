#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE A3

#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

double x = 0.4;
double y = 2.56;
double width = 11.5;
double height = 0.01;
double negWidth = -1.5;
double negHeight = -10.01;
double dx = 65.03;
double dy = 0.99;
double extraX = 4.12;
double extraY = 91.004;
double radius = 43.11;
double negRadius = -12.91;

borisova::point_t point1{ x, y };
borisova::point_t point2{ dx, dy };
borisova::point_t point3{ extraX, extraY };

void paramAfterMoving(borisova::Shape* obj, const borisova::point_t& dpos)
{
  double heightBeforeMoving = obj->getFrameRect().height;
  double widthBeforeMoving = obj->getFrameRect().width;
  obj->move(dpos);
  BOOST_REQUIRE_EQUAL(obj->getFrameRect().height, heightBeforeMoving);
  BOOST_REQUIRE_EQUAL(obj->getFrameRect().width, widthBeforeMoving);
}

void areaAfterMoving(borisova::Shape* obj, const borisova::point_t& dpos)
{
  double arBeforeMoving = obj->getArea();
  obj->move(dpos.x, dpos.y);
  BOOST_REQUIRE_EQUAL(obj->getArea(), arBeforeMoving);
}

void areaAfterScale(borisova::Shape* obj, double k)
{
  double arBeforeScale = obj->getArea();
  BOOST_CHECK_NO_THROW(obj->scale(k));
  BOOST_CHECK_CLOSE_FRACTION(obj->getArea(), arBeforeScale*k*k, 0,00001);
  k = -k;
  BOOST_CHECK_THROW(obj->scale(k), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE(testRectangle)

  borisova::Rectangle rect(point1, width, height);
  BOOST_AUTO_TEST_CASE(testParametersRec)
  {
	BOOST_CHECK_THROW(borisova::Rectangle rect1(point1, negWidth, height), std::invalid_argument);
	BOOST_CHECK_THROW(borisova::Rectangle rect2(x, y, width, negHeight), std::invalid_argument);
  }
  BOOST_AUTO_TEST_CASE(testAreaAfterMovingRec)
  {
    areaAfterMoving(&rect, point3);
  }
  BOOST_AUTO_TEST_CASE(testParamAfterMovingRec)
  {
	paramAfterMoving(&rect, point2);
  }
  BOOST_AUTO_TEST_CASE(testScaleRec)
  {
	areaAfterScale(&rect, 2.32);
  }
  BOOST_AUTO_TEST_CASE(testNameRec)
  {
	BOOST_REQUIRE_EQUAL(rect.getName(), "Rectangle");
  }
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testCircle)

  borisova::Circle circle(point2, radius);
  BOOST_AUTO_TEST_CASE(testParametersCir)
  {
	BOOST_CHECK_THROW(borisova::Circle circle1(point1, negRadius), std::invalid_argument);
  }
  BOOST_AUTO_TEST_CASE(testAreaAfterMovingCir)
  {
	areaAfterMoving(&circle, point1);
  }

  BOOST_AUTO_TEST_CASE(testParamAfterMovingCir)
  {
	paramAfterMoving(&circle, point2);
  }

  BOOST_AUTO_TEST_CASE(testScaleCir)
  {
	areaAfterScale(&circle, 5.91);
  }

  BOOST_AUTO_TEST_CASE(testNameCir)
  {
	BOOST_REQUIRE_EQUAL(circle.getName(), "Circle");
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testCompositeShape)

std::shared_ptr< borisova::Shape > testArray[4]
{
  std::make_shared< borisova::Rectangle >(point1, width, height),
  std::make_shared< borisova::Circle >(point1, width),
  std::make_shared< borisova::Rectangle >(point2, width, height),
  std::make_shared< borisova::Circle >(point2, height)
};
  borisova::CompositeShape compShape(testArray, 4);

  BOOST_AUTO_TEST_CASE(testParametersComp)
  {
    BOOST_CHECK_THROW(borisova::CompositeShape comp(testArray, -4), std::invalid_argument);
  }
  BOOST_AUTO_TEST_CASE(testAreaAfterMovingComp)
  {
	areaAfterMoving(&compShape, point1);
  }
  BOOST_AUTO_TEST_CASE(testParamAfterMovingComp)
  {
	paramAfterMoving(&compShape, point2);
  }
  BOOST_AUTO_TEST_CASE(testScaleComp)
  {
	areaAfterScale(&compShape, 5.91);
  }
  BOOST_AUTO_TEST_CASE(testNameComp)
  {
	BOOST_REQUIRE_EQUAL(compShape.getName(), "Composite Shape");
  }

BOOST_AUTO_TEST_SUITE_END()

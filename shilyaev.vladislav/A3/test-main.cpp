#define BOOST_TEST_MODULE A3
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

const double TOLERANCE = 0.001;
const double DEFAULT_RADIUS = 3.3;
const double DEFAULT_WIDTH = 6.0;
const double DEFAULT_HEIGHT = 2.5;
const shilyaev::point_t DEFAULT_CENTER{5.0, -5.6};

void testAbsoluteMove(shilyaev::Shape &shape)
{
  const shilyaev::point_t moveTo{2.0, -2.0};

  const double areaBefore = shape.getArea();
  const shilyaev::rectangle_t frameRectBefore = shape.getFrameRect();
  shape.move(moveTo);
  const double areaAfter = shape.getArea();
  const shilyaev::rectangle_t frameRectAfter = shape.getFrameRect();

  BOOST_CHECK_CLOSE(frameRectAfter.pos.x, moveTo.x, TOLERANCE);
  BOOST_CHECK_CLOSE(frameRectAfter.pos.y, moveTo.y, TOLERANCE);
  BOOST_CHECK_CLOSE(frameRectBefore.height, frameRectAfter.height, TOLERANCE);
  BOOST_CHECK_CLOSE(frameRectBefore.width, frameRectAfter.width, TOLERANCE);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, TOLERANCE);
}

void testRelativeMove(shilyaev::Shape &shape)
{
  const double dx = -3.2;
  const double dy = -4432.2;

  const double areaBefore = shape.getArea();
  const shilyaev::rectangle_t frameRectBefore = shape.getFrameRect();
  shape.move(dx, dy);
  const double areaAfter = shape.getArea();
  const shilyaev::rectangle_t frameRectAfter = shape.getFrameRect();

  BOOST_CHECK_CLOSE(dx, frameRectAfter.pos.x - frameRectBefore.pos.x, TOLERANCE);
  BOOST_CHECK_CLOSE(dy, frameRectAfter.pos.y - frameRectBefore.pos.y, TOLERANCE);
  BOOST_CHECK_CLOSE(frameRectBefore.height, frameRectAfter.height, TOLERANCE);
  BOOST_CHECK_CLOSE(frameRectBefore.width, frameRectAfter.width, TOLERANCE);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, TOLERANCE);
}

void testScale(shilyaev::Shape &shape)
{
  const double scaleFactor = 2.5;

  const double areaBefore = shape.getArea();
  const shilyaev::rectangle_t frameRectBefore = shape.getFrameRect();
  shape.scale(scaleFactor);
  const double areaAfter = shape.getArea();
  const shilyaev::rectangle_t frameRectAfter = shape.getFrameRect();

  BOOST_CHECK_CLOSE(areaBefore * scaleFactor * scaleFactor, areaAfter, TOLERANCE);
  BOOST_CHECK_CLOSE(frameRectBefore.pos.x, frameRectAfter.pos.x, TOLERANCE);
  BOOST_CHECK_CLOSE(frameRectBefore.pos.y, frameRectAfter.pos.y, TOLERANCE);
  BOOST_CHECK_CLOSE(frameRectBefore.width * scaleFactor, frameRectAfter.width, TOLERANCE);
  BOOST_CHECK_CLOSE(frameRectBefore.height * scaleFactor, frameRectAfter.height, TOLERANCE);
}

void testClone(const shilyaev::Shape &shape)
{
  const std::unique_ptr< const shilyaev::Shape > clone(shape.clone());
  const shilyaev::rectangle_t frameRect = shape.getFrameRect();
  const shilyaev::rectangle_t cloneFrameRect = clone->getFrameRect();

  BOOST_CHECK_EQUAL(shape.getArea(), clone->getArea());
  BOOST_CHECK_EQUAL(frameRect.pos.x, cloneFrameRect.pos.x);
  BOOST_CHECK_EQUAL(frameRect.pos.y, cloneFrameRect.pos.y);
  BOOST_CHECK_EQUAL(frameRect.height, cloneFrameRect.height);
  BOOST_CHECK_EQUAL(frameRect.width, cloneFrameRect.width);
}

void testShape(shilyaev::Shape &shape)
{
  testAbsoluteMove(shape);
  testRelativeMove(shape);
  testScale(shape);
  testClone(shape);
}

BOOST_AUTO_TEST_CASE(TestRectangle)
{
  shilyaev::Rectangle rectangle(DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_CENTER);
  testShape(rectangle);
}

BOOST_AUTO_TEST_CASE(TestRectangleArea)
{
  const double expectedArea = DEFAULT_HEIGHT * DEFAULT_WIDTH;
  const shilyaev::Rectangle rectangle(DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_CENTER);

  BOOST_CHECK_CLOSE(rectangle.getArea(), expectedArea, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestRectangleFrameRect)
{
  const shilyaev::rectangle_t expectedFrameRect{DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_CENTER};
  const shilyaev::Rectangle rectangle(DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_CENTER);
  const shilyaev::rectangle_t frameRect = rectangle.getFrameRect();

  BOOST_CHECK_CLOSE(frameRect.pos.x, expectedFrameRect.pos.x, TOLERANCE);
  BOOST_CHECK_CLOSE(frameRect.pos.y, expectedFrameRect.pos.y, TOLERANCE);
  BOOST_CHECK_CLOSE(frameRect.width, expectedFrameRect.width, TOLERANCE);
  BOOST_CHECK_CLOSE(frameRect.height, expectedFrameRect.height, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestCircle)
{
  shilyaev::Circle circle(DEFAULT_RADIUS, DEFAULT_CENTER);
  testShape(circle);
}

BOOST_AUTO_TEST_CASE(TestCircleArea)
{
  const double expectedArea = DEFAULT_RADIUS * DEFAULT_RADIUS * 3.141593;
  const shilyaev::Circle circle(DEFAULT_RADIUS, DEFAULT_CENTER);
  
  BOOST_CHECK_CLOSE(circle.getArea(), expectedArea, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestCircleFrameRect)
{
  const shilyaev::rectangle_t expectedFrameRect{DEFAULT_RADIUS * 2, DEFAULT_RADIUS * 2, DEFAULT_CENTER};
  const shilyaev::Circle circle(DEFAULT_RADIUS, DEFAULT_CENTER);
  const shilyaev::rectangle_t frameRect = circle.getFrameRect();

  BOOST_CHECK_CLOSE(frameRect.pos.x, expectedFrameRect.pos.x, TOLERANCE);
  BOOST_CHECK_CLOSE(frameRect.pos.y, expectedFrameRect.pos.y, TOLERANCE);
  BOOST_CHECK_CLOSE(frameRect.width, expectedFrameRect.width, TOLERANCE);
  BOOST_CHECK_CLOSE(frameRect.height, expectedFrameRect.height, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestCompositeShape)
{
  shilyaev::CompositeShape compositeShape;
  compositeShape.insert(std::make_unique< shilyaev::Circle >(2.0, shilyaev::point_t{2.0, 2.0}));
  compositeShape.insert(std::make_unique< shilyaev::Rectangle >(4.0, 2.0, shilyaev::point_t{-2.0, -1.0}));
  testShape(compositeShape);
}

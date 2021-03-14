#define BOOST_TEST_MODULE A3
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

const double PI = 3.141593;
const double TOLERANCE = 0.001;
const double DEFAULT_RADIUS = 3.3;
const double DEFAULT_WIDTH = 6.0;
const double DEFAULT_HEIGHT = 2.5;
const shilyaev::point_t DEFAULT_CENTER{5.0, -5.6};

void checkPointsClose(const shilyaev::point_t &lhs, const shilyaev::point_t &rhs, double tolerance)
{
  BOOST_CHECK_CLOSE(lhs.x, rhs.x, tolerance);
  BOOST_CHECK_CLOSE(lhs.y, rhs.y, tolerance);
}

void checkSizeClose(const shilyaev::rectangle_t &lhs, const shilyaev::rectangle_t &rhs, double tolerance)
{
  BOOST_CHECK_CLOSE(lhs.width, rhs.width, tolerance);
  BOOST_CHECK_CLOSE(lhs.height, rhs.height, tolerance);
}

void checkRectanglesClose(const shilyaev::rectangle_t &lhs, const shilyaev::rectangle_t &rhs, double tolerance)
{
  checkPointsClose(lhs.pos, rhs.pos, tolerance);
  checkSizeClose(lhs, rhs, tolerance);
}

void testAbsoluteMove(shilyaev::Shape &shape)
{
  const shilyaev::point_t moveTo{2.0, -2.0};

  const double areaBefore = shape.getArea();
  const shilyaev::rectangle_t frameRectBefore = shape.getFrameRect();
  shape.move(moveTo);
  const double areaAfter = shape.getArea();
  const shilyaev::rectangle_t frameRectAfter = shape.getFrameRect();

  checkPointsClose(frameRectAfter.pos, moveTo, TOLERANCE);
  checkSizeClose(frameRectBefore, frameRectAfter, TOLERANCE);
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
  checkSizeClose(frameRectBefore, frameRectAfter, TOLERANCE);
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
  checkPointsClose(frameRectBefore.pos, frameRectAfter.pos, TOLERANCE);
  BOOST_CHECK_CLOSE(frameRectBefore.width * scaleFactor, frameRectAfter.width, TOLERANCE);
  BOOST_CHECK_CLOSE(frameRectBefore.height * scaleFactor, frameRectAfter.height, TOLERANCE);
  BOOST_CHECK_THROW(shape.scale(-scaleFactor), std::invalid_argument);
}

void testClone(const shilyaev::Shape &shape)
{
  const std::unique_ptr< const shilyaev::Shape > clone(shape.clone());
  const shilyaev::rectangle_t frameRect = shape.getFrameRect();
  const shilyaev::rectangle_t cloneFrameRect = clone->getFrameRect();

  BOOST_CHECK_EQUAL(shape.getArea(), clone->getArea());
  checkRectanglesClose(frameRect, cloneFrameRect, TOLERANCE);
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

  checkRectanglesClose(frameRect, expectedFrameRect, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestRectangleInvalidArgument)
{
  BOOST_CHECK_THROW(shilyaev::Rectangle rectangle(-DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_CENTER),
                    std::invalid_argument);
  BOOST_CHECK_THROW(shilyaev::Rectangle rectangle(DEFAULT_WIDTH, -DEFAULT_HEIGHT, DEFAULT_CENTER),
                    std::invalid_argument);
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

  checkRectanglesClose(frameRect, expectedFrameRect, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestCircleInvalidArgument)
{
  BOOST_CHECK_THROW(shilyaev::Circle circle(-DEFAULT_RADIUS, DEFAULT_CENTER), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestCompositeShape)
{
  shilyaev::CompositeShape compositeShape;
  compositeShape.insert(std::make_unique< shilyaev::Circle >(DEFAULT_RADIUS, DEFAULT_CENTER));
  compositeShape.insert(std::make_unique< shilyaev::Rectangle >(DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_CENTER));
  testShape(compositeShape);
}

BOOST_AUTO_TEST_CASE(TestCompositeShapeArea)
{
  const double expectedArea = DEFAULT_RADIUS * DEFAULT_RADIUS * PI + DEFAULT_WIDTH * DEFAULT_HEIGHT;
  shilyaev::CompositeShape compositeShape;
  compositeShape.insert(std::make_unique< shilyaev::Circle >(DEFAULT_RADIUS, DEFAULT_CENTER));
  compositeShape.insert(std::make_unique< shilyaev::Rectangle >(DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_CENTER));
  BOOST_CHECK_CLOSE(compositeShape.getArea(), expectedArea, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestCompositeShapeFrameRect)
{
  const shilyaev::rectangle_t emptyFrameRect{0.0, 0.0, {0.0, 0.0}};
  shilyaev::CompositeShape compositeShape;

  checkRectanglesClose(compositeShape.getFrameRect(), emptyFrameRect, TOLERANCE);

  compositeShape.insert(std::make_unique< shilyaev::Circle >(2.0, shilyaev::point_t{2.0, 2.0}));
  compositeShape.insert(std::make_unique< shilyaev::Rectangle >(4.0, 2.0, shilyaev::point_t{-2.0, -1.0}));
  const shilyaev::rectangle_t expectedFrameRect{8.0, 6.0, {0.0, 1.0}};

  checkRectanglesClose(compositeShape.getFrameRect(), expectedFrameRect, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestCompositeShapeInsert)
{
  const int iterations = 40;
  shilyaev::CompositeShape compositeShape;
  BOOST_CHECK_EQUAL(compositeShape.getSize(), 0);
  for (int i = 1; i <= iterations; ++i) {
    double areaBefore = compositeShape.getArea();
    compositeShape.insert(std::make_unique< shilyaev::Circle >(DEFAULT_RADIUS, DEFAULT_CENTER));
    BOOST_CHECK_EQUAL(compositeShape.getSize(), i);
    BOOST_TEST(compositeShape.getArea() > areaBefore);
  }
}

BOOST_AUTO_TEST_CASE(TestCompositeShapeCopy)
{
  const double dx = 3.0;
  shilyaev::CompositeShape compositeShape;
  compositeShape.insert(std::make_unique< shilyaev::Circle >(DEFAULT_RADIUS, DEFAULT_CENTER));
  compositeShape.insert(std::make_unique< shilyaev::Rectangle >(DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_CENTER));
  shilyaev::CompositeShape compositeShapeCopy;
  compositeShapeCopy = compositeShape;

  BOOST_CHECK_EQUAL(compositeShape.getFrameRect().pos.x, compositeShapeCopy.getFrameRect().pos.x);
  compositeShapeCopy.move(dx, 0.0);
  BOOST_CHECK_CLOSE(compositeShape.getFrameRect().pos.x + dx, compositeShapeCopy.getFrameRect().pos.x, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestCompositeShapeInvalidArgument)
{
  shilyaev::CompositeShape compositeShape;
  BOOST_CHECK_THROW(compositeShape.insert(std::unique_ptr< shilyaev::Shape >(nullptr)), std::invalid_argument);
}

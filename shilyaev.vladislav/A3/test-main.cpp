#define BOOST_TEST_MODULE A3
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

const double PI = 3.141593;
const double TOLERANCE = 0.001;
const double RADIUS = 3.3;
const double WIDTH = 6.0;
const double HEIGHT = 2.5;
const shilyaev::point_t CENTER{5.0, -5.6};

std::unique_ptr< shilyaev::Rectangle > makeRectangle()
{
  return std::make_unique< shilyaev::Rectangle >(WIDTH, HEIGHT, CENTER);
}

std::unique_ptr< shilyaev::Circle > makeCircle()
{
  return std::make_unique< shilyaev::Circle >(RADIUS, CENTER);
}

std::unique_ptr< shilyaev::CompositeShape > makeCompositeShape()
{
  std::unique_ptr< shilyaev::CompositeShape > shape = std::make_unique< shilyaev::CompositeShape >(makeCircle());
  shape->pushBack(makeRectangle());
  return shape;
}

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
  const double dy = -4.2;

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
  testShape(*makeRectangle());
}

BOOST_AUTO_TEST_CASE(TestRectangleArea)
{
  const double expectedArea = HEIGHT * WIDTH;
  BOOST_CHECK_CLOSE(makeRectangle()->getArea(), expectedArea, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestRectangleFrameRect)
{
  const shilyaev::rectangle_t expectedFrameRect{WIDTH, HEIGHT, CENTER};
  checkRectanglesClose(makeRectangle()->getFrameRect(), expectedFrameRect, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestRectangleInvalidArgument)
{
  BOOST_CHECK_THROW(shilyaev::Rectangle rectangle(-WIDTH, HEIGHT, CENTER), std::invalid_argument);
  BOOST_CHECK_THROW(shilyaev::Rectangle rectangle(WIDTH, -HEIGHT, CENTER), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestCircle)
{
  testShape(*makeCircle());
}

BOOST_AUTO_TEST_CASE(TestCircleArea)
{
  const double expectedArea = RADIUS * RADIUS * 3.141593;
  BOOST_CHECK_CLOSE(makeCircle()->getArea(), expectedArea, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestCircleFrameRect)
{
  const shilyaev::rectangle_t expectedFrameRect{RADIUS * 2, RADIUS * 2, CENTER};
  checkRectanglesClose(makeCircle()->getFrameRect(), expectedFrameRect, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestCircleInvalidArgument)
{
  BOOST_CHECK_THROW(shilyaev::Circle circle(-RADIUS, CENTER), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestCompositeShape)
{
  testShape(*makeCompositeShape());
}

BOOST_AUTO_TEST_CASE(TestCompositeShapeArea)
{
  const double expectedArea = RADIUS * RADIUS * PI + WIDTH * HEIGHT;
  BOOST_CHECK_CLOSE(makeCompositeShape()->getArea(), expectedArea, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestCompositeShapeFrameRect)
{
  const shilyaev::rectangle_t expectedFrameRect{
    std::max(WIDTH, RADIUS * 2), std::max(HEIGHT, RADIUS * 2), CENTER
  };
  checkRectanglesClose(makeCompositeShape()->getFrameRect(), expectedFrameRect, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestCompositeShapeArray)
{
  const int iterations = 40;
  shilyaev::CompositeShape compositeShape(makeCircle());
  for (int i = 1; i <= iterations; ++i) {
    double areaBefore = compositeShape.getArea();
    BOOST_CHECK_EQUAL(compositeShape.size(), i);
    compositeShape.pushBack(makeCircle());
    BOOST_TEST(compositeShape.getArea() > areaBefore);
  }
  BOOST_CHECK_THROW(compositeShape.at(iterations + 1), std::out_of_range);
  for (int i = iterations; i >= 1; --i) {
    double areaBefore = compositeShape.getArea();
    compositeShape.popBack();
    BOOST_CHECK_EQUAL(compositeShape.size(), i);
    BOOST_TEST(compositeShape.getArea() < areaBefore);
  }
  BOOST_CHECK_THROW(compositeShape.popBack(), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(TestCompositeShapeInvalidArgument)
{
  std::unique_ptr< shilyaev::Shape > nullptrShape(nullptr);
  BOOST_CHECK_THROW(makeCompositeShape()->pushBack(std::move(nullptrShape)),std::invalid_argument);
}

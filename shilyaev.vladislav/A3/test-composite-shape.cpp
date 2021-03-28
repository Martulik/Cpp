#include <boost/test/unit_test.hpp>
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"
#include "test-common.hpp"
#include "test-shape.hpp"

std::unique_ptr< shilyaev::CompositeShape > makeCompositeShape()
{
  std::unique_ptr< shilyaev::Shape > circle = std::make_unique< shilyaev::Circle >(RADIUS, CENTER);
  std::unique_ptr< shilyaev::Shape > rectangle = std::make_unique< shilyaev::Rectangle >(WIDTH, HEIGHT, CENTER);
  std::unique_ptr< shilyaev::CompositeShape > shape = std::make_unique< shilyaev::CompositeShape >(std::move(circle));
  shape->pushBack(std::move(rectangle));
  return shape;
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
  shilyaev::CompositeShape compositeShape(makeCompositeShape());
  for (int i = 1; i <= iterations; ++i) {
    double areaBefore = compositeShape.getArea();
    BOOST_CHECK_EQUAL(compositeShape.size(), i);
    compositeShape.pushBack(makeCompositeShape());
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

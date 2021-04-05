#include <boost/test/unit_test.hpp>
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"
#include "test-common.hpp"
#include "test-shape.hpp"

std::unique_ptr< shilyaev::CompositeShape > makeCompositeShape()
{
  auto circle = std::make_unique< shilyaev::Circle >(shilyaev::RADIUS, shilyaev::CENTER);
  auto rectangle = std::make_unique< shilyaev::Rectangle >(shilyaev::WIDTH, shilyaev::HEIGHT, shilyaev::CENTER);
  auto shape = std::make_unique< shilyaev::CompositeShape >(std::move(circle));
  shape->pushBack(std::move(rectangle));
  return shape;
}

BOOST_AUTO_TEST_CASE(TestCompositeShape)
{
  testShape(*makeCompositeShape());
}

BOOST_AUTO_TEST_CASE(TestCompositeShapeArea)
{
  const double expectedCircleArea = shilyaev::RADIUS * shilyaev::RADIUS * shilyaev::PI;
  const double expectedRectangleArea = shilyaev::WIDTH * shilyaev::HEIGHT;
  const double expectedArea = expectedCircleArea + expectedRectangleArea;
  BOOST_CHECK_CLOSE(makeCompositeShape()->getArea(), expectedArea, shilyaev::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(TestCompositeShapeFrameRect)
{
  const shilyaev::rectangle_t expectedFrameRect{
    std::max(shilyaev::WIDTH, shilyaev::RADIUS * 2),
    std::max(shilyaev::HEIGHT, shilyaev::RADIUS * 2),
    shilyaev::CENTER
  };
  checkRectanglesClose(makeCompositeShape()->getFrameRect(), expectedFrameRect, shilyaev::TOLERANCE);
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

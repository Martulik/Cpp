#include "test-shape.hpp"
#include <boost/test/unit_test.hpp>
#include "test-common.hpp"
#include "shape.hpp"

void testAbsoluteMove(shilyaev::Shape &shape)
{
  const shilyaev::point_t moveTo{2.0, -2.0};

  const double areaBefore = shape.getArea();
  const shilyaev::rectangle_t frameRectBefore = shape.getFrameRect();
  shape.move(moveTo);
  const double areaAfter = shape.getArea();
  const shilyaev::rectangle_t frameRectAfter = shape.getFrameRect();

  checkPointsClose(frameRectAfter.pos, moveTo, shilyaev::TOLERANCE);
  checkSizeClose(frameRectBefore, frameRectAfter, shilyaev::TOLERANCE);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, shilyaev::TOLERANCE);
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

  BOOST_CHECK_CLOSE(dx, frameRectAfter.pos.x - frameRectBefore.pos.x, shilyaev::TOLERANCE);
  BOOST_CHECK_CLOSE(dy, frameRectAfter.pos.y - frameRectBefore.pos.y, shilyaev::TOLERANCE);
  checkSizeClose(frameRectBefore, frameRectAfter, shilyaev::TOLERANCE);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, shilyaev::TOLERANCE);
}

void testScale(shilyaev::Shape &shape)
{
  const double scaleFactor = 2.5;

  const double areaBefore = shape.getArea();
  const shilyaev::rectangle_t frameRectBefore = shape.getFrameRect();
  shape.scale(scaleFactor);
  const double areaAfter = shape.getArea();
  const shilyaev::rectangle_t frameRectAfter = shape.getFrameRect();

  BOOST_CHECK_CLOSE(areaBefore * scaleFactor * scaleFactor, areaAfter, shilyaev::TOLERANCE);
  checkPointsClose(frameRectBefore.pos, frameRectAfter.pos, shilyaev::TOLERANCE);
  BOOST_CHECK_CLOSE(frameRectBefore.width * scaleFactor, frameRectAfter.width, shilyaev::TOLERANCE);
  BOOST_CHECK_CLOSE(frameRectBefore.height * scaleFactor, frameRectAfter.height, shilyaev::TOLERANCE);
  BOOST_CHECK_THROW(shape.scale(-scaleFactor), std::invalid_argument);
}

void testClone(const shilyaev::Shape &shape)
{
  const std::unique_ptr< const shilyaev::Shape > clone(shape.clone());
  const shilyaev::rectangle_t frameRect = shape.getFrameRect();
  const shilyaev::rectangle_t cloneFrameRect = clone->getFrameRect();

  BOOST_CHECK_EQUAL(shape.getArea(), clone->getArea());
  checkRectanglesClose(frameRect, cloneFrameRect, shilyaev::TOLERANCE);
}

void shilyaev::testShape(shilyaev::Shape &shape)
{
  testAbsoluteMove(shape);
  testRelativeMove(shape);
  testScale(shape);
  testClone(shape);
}

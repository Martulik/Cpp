#include "test-shape.hpp"
#include <boost/test/unit_test.hpp>
#include "test-common.hpp"
#include "shape.hpp"

namespace shilyaev {

  void testAbsoluteMove(Shape &shape)
  {
    const point_t moveTo{2.0, -2.0};

    const double areaBefore = shape.getArea();
    const rectangle_t frameRectBefore = shape.getFrameRect();
    shape.move(moveTo);
    const double areaAfter = shape.getArea();
    const rectangle_t frameRectAfter = shape.getFrameRect();

    checkPointsClose(frameRectAfter.pos, moveTo, TOLERANCE);
    checkSizeClose(frameRectBefore, frameRectAfter, TOLERANCE);
    BOOST_CHECK_CLOSE(areaBefore, areaAfter, TOLERANCE);
  }

  void testRelativeMove(Shape &shape)
  {
    const double dx = -3.2;
    const double dy = -4.2;

    const double areaBefore = shape.getArea();
    const rectangle_t frameRectBefore = shape.getFrameRect();
    shape.move(dx, dy);
    const double areaAfter = shape.getArea();
    const rectangle_t frameRectAfter = shape.getFrameRect();

    BOOST_CHECK_CLOSE(dx, frameRectAfter.pos.x - frameRectBefore.pos.x, TOLERANCE);
    BOOST_CHECK_CLOSE(dy, frameRectAfter.pos.y - frameRectBefore.pos.y, TOLERANCE);
    checkSizeClose(frameRectBefore, frameRectAfter, TOLERANCE);
    BOOST_CHECK_CLOSE(areaBefore, areaAfter, TOLERANCE);
  }

  void testScale(Shape &shape)
  {
    const double scaleFactor = 2.5;

    const double areaBefore = shape.getArea();
    const rectangle_t frameRectBefore = shape.getFrameRect();
    shape.scale(scaleFactor);
    const double areaAfter = shape.getArea();
    const rectangle_t frameRectAfter = shape.getFrameRect();

    BOOST_CHECK_CLOSE(areaBefore * scaleFactor * scaleFactor, areaAfter, TOLERANCE);
    checkPointsClose(frameRectBefore.pos, frameRectAfter.pos, TOLERANCE);
    BOOST_CHECK_CLOSE(frameRectBefore.width * scaleFactor, frameRectAfter.width, TOLERANCE);
    BOOST_CHECK_CLOSE(frameRectBefore.height * scaleFactor, frameRectAfter.height, TOLERANCE);
    BOOST_CHECK_THROW(shape.scale(-scaleFactor), std::invalid_argument);
  }

  void testClone(const Shape &shape)
  {
    const std::unique_ptr< const Shape > clone(shape.clone());
    const rectangle_t frameRect = shape.getFrameRect();
    const rectangle_t cloneFrameRect = clone->getFrameRect();

    BOOST_CHECK_EQUAL(shape.getArea(), clone->getArea());
    checkRectanglesClose(frameRect, cloneFrameRect, TOLERANCE);
  }

  void testShape(Shape &shape)
  {
    testAbsoluteMove(shape);
    testRelativeMove(shape);
    testScale(shape);
    testClone(shape);
  }

}

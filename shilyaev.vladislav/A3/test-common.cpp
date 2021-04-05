#include "test-common.hpp"
#include <boost/test/unit_test.hpp>

void shilyaev::checkPointsClose(const shilyaev::point_t &lhs, const shilyaev::point_t &rhs, double tolerance)
{
  BOOST_CHECK_CLOSE(lhs.x, rhs.x, tolerance);
  BOOST_CHECK_CLOSE(lhs.y, rhs.y, tolerance);
}

void shilyaev::checkSizeClose(const shilyaev::rectangle_t &lhs, const shilyaev::rectangle_t &rhs, double tolerance)
{
  BOOST_CHECK_CLOSE(lhs.width, rhs.width, tolerance);
  BOOST_CHECK_CLOSE(lhs.height, rhs.height, tolerance);
}

void shilyaev::checkRectanglesClose(const shilyaev::rectangle_t &lhs, const shilyaev::rectangle_t &rhs, double tolerance)
{
  checkPointsClose(lhs.pos, rhs.pos, tolerance);
  checkSizeClose(lhs, rhs, tolerance);
}

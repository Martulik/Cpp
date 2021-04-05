#ifndef TEST_COMMON_HPP
#define TEST_COMMON_HPP

#include "base-types.hpp"

namespace shilyaev {

  const double TOLERANCE = 0.001;
  const shilyaev::point_t CENTER{5.0, -5.0};
  const double WIDTH = 6.0;
  const double HEIGHT = 2.5;
  const double PI = 3.14159265358979323846;
  const double RADIUS = 3.3;

  void checkPointsClose(const shilyaev::point_t &lhs, const shilyaev::point_t &rhs, double tolerance);
  void checkSizeClose(const shilyaev::rectangle_t &lhs, const shilyaev::rectangle_t &rhs, double tolerance);
  void checkRectanglesClose(const shilyaev::rectangle_t &lhs, const shilyaev::rectangle_t &rhs, double tolerance);

}

#endif

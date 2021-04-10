#ifndef TEST_VARIABLES_HPP
#define TEST_VARIABLES_HPP

#include <cstddef>
#include "base-types.hpp"

namespace lebedeva
{
  const double width = 4.2;
  const double height = 7.13;
  const double radius = 2;
  const double parameter = 2;
  const double tolerance = 0.000001;

  const double nWidth = -1;
  const double nHeight = -7.3;
  const double nRadius = -4;
  const double nParameter = -1;

  const point_t pos = { 3, 1 };
  const point_t pos1 = { -1.1, -4 };
  const point_t pos2 = { 5, -3.5 };
  const point_t newPos = { -3.0, 4.1 };
}

#endif

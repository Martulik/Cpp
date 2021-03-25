#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

#include "udouble.hpp"

namespace doroshin
{
  struct point_t
  {
    double x, y;
  };

  struct rectangle_t
  {
    udouble_t width, height;
    point_t pos;
  };
}

#endif // BASE_TYPES_HPP

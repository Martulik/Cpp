#ifndef A3_BASIC_TYPES_HPP
#define A3_BASIC_TYPES_HPP

namespace borisova
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
  };
}

#endif

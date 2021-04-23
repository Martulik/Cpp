#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace pozdnyakov
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    point_t pos;
    double width;
    double height;
  };

  double getMinX(rectangle_t rect);
  double getMaxX(rectangle_t rect);
  double getMinY(rectangle_t rect);
  double getMaxY(rectangle_t rect);
}

#endif

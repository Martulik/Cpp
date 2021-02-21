#ifndef BASE_TYPES_H
#define BASE_TYPES_H
struct point_t
{
  double x;
  double y;
  point_t(double i_x, double i_y) : x(i_x), y(i_y) {};
};
struct rectangle_t
{
  point_t pos;
  double width;
  double height;
  rectangle_t(point_t i_pos, double i_width, double i_height) : pos(i_pos), width(i_width), height(i_height) {};
};
#endif

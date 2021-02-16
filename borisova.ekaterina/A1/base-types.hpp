#ifndef BASIC_TYPES_H
#define BASIC_TYPES_H

struct point_t
{
  double x_;
  double y_;
};

struct rectangle_t
{
  double width_;
  double height_;
  point_t pos_;
};

#endif 

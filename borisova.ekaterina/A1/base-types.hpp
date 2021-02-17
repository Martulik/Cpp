#ifndef BASIC_TYPES_H
#define BASIC_TYPES_H

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

#endif 

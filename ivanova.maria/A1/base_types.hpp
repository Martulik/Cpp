#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
struct point_t
{
  int x;
  int y;

  point_t():
   x(0),
   y(0)
   {
   }

  point_t( const int cx, const int cy):
   x(cx),
   y(cy)
   {
   }
};

struct rectangle_t
{
  double width_ ;
  double height_ ;
  point_t pos_ ;

  rectangle_t ():
   width_(0.0),
   height_(0.0),
   pos_({0, 0})
   {
   }

  rectangle_t (const double w, const double h, const point_t p):
   width_(w),
   height_(h),
   pos_(p)
   {
   }
};
#endif

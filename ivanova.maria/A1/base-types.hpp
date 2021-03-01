#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace ivanova {
  struct point_t {
    double x;
    double y;
  };
  struct rectangle_t {
    double width;
    double height;
    ivanova::point_t pos;
  };
}
#endif

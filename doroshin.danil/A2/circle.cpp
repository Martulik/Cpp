#include <cmath>
#include <cassert>
#include "circle.hpp"

namespace doroshin {
  Circle::Circle(point_t pos, double r):
    pos(pos),
    radius(r)
  {
    assert(radius >= 0);
  }

  double Circle::getArea() const
  {
    return M_PI * radius * radius;
  }

  rectangle_t Circle::getFrameRect() const
  {
    return rectangle_t{ 2 * radius, 2 * radius, pos };
  }

  void Circle::move_rel(point_t vec)
  {
    pos.x += vec.x;
    pos.y += vec.y;
  }

  void Circle::move_abs(point_t point)
  {
    pos = point;
  }

  void Circle::scale(double s)
  {
    radius *= fabs(s);
  }
}

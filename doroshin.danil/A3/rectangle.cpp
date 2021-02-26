#include <cmath>
#include <cassert>
#include "rectangle.hpp"

namespace doroshin {
  Rectangle::Rectangle(rectangle_t rect):
    rect(rect)
  {
    assert(rect.width >= 0);
    assert(rect.height >= 0);
  }

  double Rectangle::getArea() const
  {
    return rect.width * rect.height;
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    return rect;
  }

  void Rectangle::move_rel(point_t vec)
  {
    rect.pos.x += vec.x;
    rect.pos.y += vec.y;
  }

  void Rectangle::move_abs(point_t point)
  {
    rect.pos = point;
  }

  void Rectangle::scale(double s)
  {
    rect.width *= fabs(s);
    rect.height *= fabs(s);
  }
}

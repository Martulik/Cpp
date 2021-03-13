#include "rectangle.hpp"

#include <cassert>

namespace savchuk
{
  Rectangle::Rectangle(const point_t& pos, double width, double height):
    rect_({ pos, width, height })
  {
    assert(width > 0 && "The width must be positive");
    assert(height > 0 && "The height must be positive");
  }

  double Rectangle::getArea() const
  {
    return rect_.width * rect_.height;
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    return rect_;
  }

  void Rectangle::move(const point_t& point)
  {
    rect_.pos = point;
  }

  void Rectangle::move(double dx, double dy)
  {
    rect_.pos.x += dx;
    rect_.pos.y += dy;
  }

  void Rectangle::scale(double scaleFactor)
  {
    assert(scaleFactor > 0 && "The scale factor must be positive");
    rect_.width *= scaleFactor;
    rect_.height *= scaleFactor;
  }

  std::unique_ptr< Shape* > Rectangle::clone() const
  {
    Shape* clone = new Rectangle(*this);
    return std::make_unique< Shape* >(clone);
  }
}

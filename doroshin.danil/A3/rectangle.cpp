#include "rectangle.hpp"
#include <algorithm>
#include <cmath>

namespace dan = doroshin;

dan::rectangle_t fromTwoPoints(dan::point_t a, dan::point_t b)
{
  double min_x = std::min(a.x, b.x);
  double max_x = std::max(a.x, b.x);
  double min_y = std::min(a.y, b.y);
  double max_y = std::max(a.y, b.y);

  double x = (max_x + min_x) / 2;
  double y = (max_y + min_y) / 2;
  dan::udouble_t w = dan::udouble_t(max_x - min_x);
  dan::udouble_t h = dan::udouble_t(max_y - min_y);

  return dan::rectangle_t{ w, h, { x, y } };
}

dan::Rectangle::Rectangle(udouble_t w, udouble_t h, point_t pos):
  rect_{ w, h, pos }
{}

dan::Rectangle::Rectangle(point_t a, point_t b):
  rect_(fromTwoPoints(a, b))
{}

double dan::Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

dan::rectangle_t dan::Rectangle::getFrameRect() const
{
  return rect_;
}

void dan::Rectangle::move(point_t vec, bool absolute)
{
  if (absolute) {
    rect_.pos = vec;
  }
  else {
    rect_.pos.x += vec.x;
    rect_.pos.y += vec.y;
  }
}

void dan::Rectangle::scaleImpl(dan::udouble_t s)
{
  rect_.width *= s;
  rect_.height *= s;
}

std::unique_ptr< dan::Shape > dan::Rectangle::copy() const
{
  return std::make_unique< Rectangle >(*this);
}

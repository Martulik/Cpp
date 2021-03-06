#include "rectangle.hpp"
#include <algorithm>
#include <cmath>
#include <cassert>

namespace dan = doroshin;

dan::rectangle_t from_two_points(dan::point_t a, dan::point_t b)
{
  double min_x = std::min(a.x, b.x);
  double max_x = std::max(a.x, b.x);
  double min_y = std::min(a.y, b.y);
  double max_y = std::max(a.y, b.y);

  double x = (max_x + min_x) / 2;
  double y = (max_y + min_y) / 2;
  double w = max_x - min_x;
  double h = max_y - min_y;

  return dan::rectangle_t{w, h, {x, y}};
}

dan::Rectangle::Rectangle(rectangle_t rect):
  rect_(rect)
{
  assert(rect.width >= 0);
  assert(rect.height >= 0);
}

dan::Rectangle::Rectangle(double w, double h, point_t pos):
  rect_{w, h, pos}
{
  assert(rect_.width >= 0);
  assert(rect_.height >= 0);
}

dan::Rectangle::Rectangle(point_t a, point_t b):
  rect_(from_two_points(a, b))
{}

double dan::Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

dan::rectangle_t dan::Rectangle::getFrameRect() const
{
  return rect_;
}

void dan::Rectangle::move_rel(point_t vec)
{
  rect_.pos.x += vec.x;
  rect_.pos.y += vec.y;
}

void dan::Rectangle::move_abs(point_t point)
{
  rect_.pos = point;
}

void dan::Rectangle::scale(double s)
{
  rect_.width *= fabs(s);
  rect_.height *= fabs(s);
}

std::unique_ptr<dan::Shape> dan::make_shape(const Rectangle& r)
{
  Rectangle* ptr = new Rectangle(r);
  return std::unique_ptr<Shape>(ptr);
}

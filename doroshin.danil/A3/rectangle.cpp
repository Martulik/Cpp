#include "rectangle.hpp"
#include <algorithm>
#include <cmath>
#include <cassert>

namespace d = doroshin;

d::rectangle_t from_two_points(d::point_t a, d::point_t b)
{
  double min_x = std::min(a.x, b.x);
  double max_x = std::max(a.x, b.x);
  double min_y = std::min(a.y, b.y);
  double max_y = std::max(a.y, b.y);

  double x = (max_x + min_x) / 2;
  double y = (max_y + min_y) / 2;
  double w = max_x - min_x;
  double h = max_y - min_y;

  return d::rectangle_t{w, h, {x, y}};
}

d::Rectangle::Rectangle(rectangle_t rect):
  rect(rect)
{
  assert(rect.width >= 0);
  assert(rect.height >= 0);
}

d::Rectangle::Rectangle(double w, double h, point_t pos):
  rect{w, h, pos}
{
  assert(rect.width >= 0);
  assert(rect.height >= 0);
}

d::Rectangle::Rectangle(point_t a, point_t b):
  rect(from_two_points(a, b))
{}

double d::Rectangle::getArea() const
{
  return rect.width * rect.height;
}

d::rectangle_t d::Rectangle::getFrameRect() const
{
  return rect;
}

void d::Rectangle::move_rel(point_t vec)
{
  rect.pos.x += vec.x;
  rect.pos.y += vec.y;
}

void d::Rectangle::move_abs(point_t point)
{
  rect.pos = point;
}

void d::Rectangle::scale(double s)
{
  rect.width *= fabs(s);
  rect.height *= fabs(s);
}

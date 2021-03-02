#include "composite-shape.hpp"
#include <cassert>
#include <cmath>
#include <utility>
#include <limits>
#include <algorithm>

namespace d = doroshin;
d::CompositeShape::AnyShape::AnyShape():
  type(Type::Uninitialized)
{}

d::CompositeShape::AnyShape::AnyShape(Circle c):
  type(Type::Circle),
  circle(c)
{}

d::CompositeShape::AnyShape::AnyShape(Rectangle r):
  type(Type::Rectangle),
  rectangle(r)
{}

double d::CompositeShape::AnyShape::getArea() const
{
  double res = 0.0;
  switch (type)
  {
  case Type::Circle:
    res = circle.getArea();
    break;
  case Type::Rectangle:
    res = rectangle.getArea();
    break;
  default:
    assert(!"Missing area case");
  }
  return res;
}

d::rectangle_t d::CompositeShape::AnyShape::getFrameRect() const
{
  rectangle_t res;
  switch (type)
  {
  case Type::Circle:
    res = circle.getFrameRect();
    break;
  case Type::Rectangle:
    res = rectangle.getFrameRect();
    break;
  default:
    assert(!"Missing frame rect case");
  }
  return res;
}

void d::CompositeShape::AnyShape::move_rel(point_t vec)
{
  switch (type)
  {
  case Type::Circle:
    return circle.move_rel(vec);
  case Type::Rectangle:
    return rectangle.move_rel(vec);
  default:
    assert(!"Missing move_rel case");
  }
}

void d::CompositeShape::AnyShape::move_abs(point_t point)
{
  switch (type)
  {
  case Type::Circle:
    return circle.move_abs(point);
  case Type::Rectangle:
    return rectangle.move_abs(point);
  default:
    assert(!"Missing move_abs case");
  }
}

void d::CompositeShape::AnyShape::scale(double s)
{
  switch (type)
  {
  case Type::Circle:
    return circle.scale(s);
  case Type::Rectangle:
    return rectangle.scale(s);
  default:
    assert(!"Missing scale case");
  }
}

d::CompositeShape::AnyShape::AnyShape(const AnyShape& other):
  type(other.type)
{
  switch (type)
  {
  case Type::Circle:
    circle = other.circle;
    break;
  case Type::Rectangle:
    rectangle = other.rectangle;
    break;
  default:
    assert(!"Missing copy-ctr case");
  }
}

d::CompositeShape::AnyShape::AnyShape(const AnyShape&& other) noexcept:
  type(other.type)
{
  switch (type)
  {
  case Type::Circle:
    circle = std::move(other.circle);
    break;
  case Type::Rectangle:
    rectangle = std::move(other.rectangle);
    break;
  default:
    assert(!"Missing move-ctr case");
  }
}

d::CompositeShape::AnyShape& d::CompositeShape::AnyShape::operator=(const AnyShape& other)
{
  type = other.type;
  switch (type)
  {
  case Type::Circle:
    circle = other.circle;
    break;
  case Type::Rectangle:
    rectangle = other.rectangle;
    break;
  default:
    assert(!"Missing copy-operator= case");
  }
  return *this;
}

d::CompositeShape::AnyShape& d::CompositeShape::AnyShape::operator=(const AnyShape&& other) noexcept
{
  type = other.type;
  switch (type)
  {
  case Type::Circle:
    circle = std::move(other.circle);
    break;
  case Type::Rectangle:
    rectangle = std::move(other.rectangle);
    break;
  default:
    assert(!"Missing move-operator= case");
  }
  return *this;
}

d::CompositeShape::AnyShape::~AnyShape()
{
  switch (type)
  {
  case Type::Circle:
    circle.~Circle();
    break;
  case Type::Rectangle:
    rectangle.~Rectangle();
    break;
  default:
    assert(!"Missing destructor case");
  }
}

d::CompositeShape::CompositeShape():
  shapes_(nullptr),
  size_(0)
{}

d::CompositeShape::CompositeShape(std::initializer_list<AnyShape> list):
  size_(list.size())
{
  shapes_ = std::make_unique<AnyShape[]>(size_);
  size_t i = 0;
  for(const AnyShape& shape : list) {
    shapes_[i++] = shape;
  }
}

void d::CompositeShape::add(const AnyShape& shape)
{
  std::unique_ptr<AnyShape[]> new_shapes = std::make_unique<AnyShape[]>(size_ + 1);
  for(size_t i = 0; i < size_; ++i)
    new_shapes[i] = std::move(shapes_[i]);
  new_shapes[size_++] = shape;
  std::swap(shapes_, new_shapes);
}

double d::CompositeShape::getArea() const
{
  assert("Not implemented properly");
  double sum = 0.0;
  for(size_t i = 0; i < size_; ++i) {
    sum += shapes_[i].getArea();
  }
  return sum;
}

d::rectangle_t d::CompositeShape::getFrameRect() const
{
  assert(size_ != 0);
  double min_x = std::numeric_limits<double>::max();
  double max_x = std::numeric_limits<double>::lowest();
  double min_y = std::numeric_limits<double>::max();
  double max_y = std::numeric_limits<double>::lowest();

  for(size_t i = 0; i < size_; ++i) {
    rectangle_t frame = shapes_[i].getFrameRect();
    min_x = std::min(min_x, frame.pos.x - frame.width / 2);
    max_x = std::max(max_x, frame.pos.x + frame.width / 2);
    min_y = std::min(min_y, frame.pos.y - frame.height / 2);
    max_y = std::max(max_y, frame.pos.y + frame.height / 2);
  }

  double width = max_x - min_x;
  double height = max_y - min_y;
  double pos_x = min_x + width / 2;
  double pos_y = min_y + height / 2;
  return {width, height, {pos_x, pos_y}};
}

void d::CompositeShape::move_rel(point_t vec)
{
  for(size_t i = 0; i < size_; ++i) {
    shapes_[i].move_rel(vec);
  }
}

void d::CompositeShape::move_abs(point_t point)
{
  point_t center = getFrameRect().pos;
  for(size_t i = 0; i < size_; ++i) {
    point_t shape = shapes_[i].getFrameRect().pos;
    point_t delta {shape.x - center.x, shape.y - center.y};
    shapes_[i].move_abs({point.x + delta.x, point.y + delta.y});
  }
}

void d::CompositeShape::scale(double s)
{
  point_t center = getFrameRect().pos;
  for(size_t i = 0; i < size_; ++i) {
    point_t shape = shapes_[i].getFrameRect().pos;
    point_t move_vec { s * (center.x - shape.x), s * (center.y - shape.y) };
    shapes_[i].move_rel(move_vec);
    shapes_[i].scale(s);
  }
}

d::CompositeShape::CompositeShape(const CompositeShape& other):
  size_(other.size_)
{
  shapes_ = std::make_unique<AnyShape[]>(size_);
  for(size_t i = 0; i < size_; ++i)
    shapes_[i] = other.shapes_[i];
}

d::CompositeShape& d::CompositeShape::operator=(const CompositeShape& other)
{
  CompositeShape tmp(other);
  swap(*this, tmp);
  return *this;
}

void d::swap(CompositeShape& lhs, CompositeShape& rhs)
{
  std::swap(lhs.size_, rhs.size_);
  std::swap(lhs.shapes_, rhs.shapes_);
}

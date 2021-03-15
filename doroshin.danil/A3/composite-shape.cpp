#include "composite-shape.hpp"
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <utility>
#include <limits>
#include <algorithm>

namespace dan = doroshin;

dan::CompositeShape::CompositeShape():
  shapes_(nullptr),
  size_(0)
{}

void dan::CompositeShape::add(shape_ptr shape)
{
  array_t new_shapes = std::make_unique< shape_ptr[] >(size_ + 1);
  for(size_t i = 0; i < size_; ++i)
    new_shapes[i] = std::move(shapes_[i]);
  new_shapes[size_++] = std::move(shape);
  std::swap(shapes_, new_shapes);
}

double dan::CompositeShape::getArea() const
{
  if(size_ <= 0)
    throw std::out_of_range("CompositeShape is empty");

  double sum = 0.0;
  for(size_t i = 0; i < size_; ++i) {
    sum += shapes_[i]->getArea();
  }
  return sum;
}

dan::rectangle_t dan::CompositeShape::getFrameRect() const
{
  if(size_ <= 0)
    throw std::out_of_range("CompositeShape is empty");

  double min_x = std::numeric_limits< double >::max();
  double max_x = std::numeric_limits< double >::lowest();
  double min_y = std::numeric_limits< double >::max();
  double max_y = std::numeric_limits< double >::lowest();

  for(size_t i = 0; i < size_; ++i) {
    rectangle_t frame = shapes_[i]->getFrameRect();
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

void dan::CompositeShape::move(point_t vec, bool absolute)
{
  if(absolute){
    point_t center = getFrameRect().pos;
    for(size_t i = 0; i < size_; ++i) {
      point_t shape = shapes_[i]->getFrameRect().pos;
      point_t delta {shape.x - center.x, shape.y - center.y};
      shapes_[i]->move({vec.x + delta.x, vec.y + delta.y}, true);
    }
  }
  else {
    for(size_t i = 0; i < size_; ++i) {
      shapes_[i]->move(vec);
    }
  }
}

void dan::CompositeShape::scale(double s)
{
  point_t center = getFrameRect().pos;
  for(size_t i = 0; i < size_; ++i) {
    point_t shape = shapes_[i]->getFrameRect().pos;
    point_t move_vec { s * (center.x - shape.x), s * (center.y - shape.y) };
    shapes_[i]->move(move_vec);
    shapes_[i]->scale(s);
  }
}

void dan::swap(CompositeShape& lhs, CompositeShape& rhs)
{
  std::swap(lhs.size_, rhs.size_);
  std::swap(lhs.shapes_, rhs.shapes_);
}

dan::CompositeShape::CompositeShape(const CompositeShape& other):
  shapes_(std::make_unique<shape_ptr[]>(other.size_)),
  size_(other.size_)
{
  for(size_t i = 0; i < size_; ++i) {
    shapes_[i] = std::unique_ptr<Shape>(other.shapes_[i]->copy());
  }
}

dan::CompositeShape& dan::CompositeShape::operator=(const CompositeShape& other)
{
  CompositeShape temp(other);
  swap(*this, temp);
  return *this;
}

dan::Shape* dan::CompositeShape::copy() const
{
  return new CompositeShape(*this);
}

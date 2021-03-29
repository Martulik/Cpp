#include "composite-shape.hpp"
#include <limits>
#include <algorithm>

namespace dan = doroshin;

double dan::CompositeShape::getArea() const
{
  double sum = 0.0;
  for(size_t i = 0; i < size_; ++i) {
    sum += shapes_[i]->getArea();
  }
  return sum;
}

dan::rectangle_t dan::CompositeShape::getFrameRect() const
{
  double min_x = std::numeric_limits< double >::max();
  double max_x = std::numeric_limits< double >::lowest();
  double min_y = std::numeric_limits< double >::max();
  double max_y = std::numeric_limits< double >::lowest();

  for(size_t i = 0; i < size_; ++i) {
    min_x = std::min(min_x, getX(*shapes_[i]) - getWidth(*shapes_[i]) / 2);
    max_x = std::max(max_x, getX(*shapes_[i]) + getWidth(*shapes_[i]) / 2);
    min_y = std::min(min_y, getY(*shapes_[i]) - getHeight(*shapes_[i]) / 2);
    max_y = std::max(max_y, getY(*shapes_[i]) + getHeight(*shapes_[i]) / 2);
  }

  double width = max_x - min_x;
  double height = max_y - min_y;
  double pos_x = min_x + width / 2;
  double pos_y = min_y + height / 2;
  return {width, height, {pos_x, pos_y}};
}

void dan::CompositeShape::move(point_t vec, bool absolute)
{
  if(absolute) {
    double x = getX(*this);
    double y = getY(*this);
    for(size_t i = 0; i < size_; ++i) {
      point_t delta {getX(*shapes_[i]) - x, getY(*shapes_[i]) - y};
      shapes_[i]->move({vec.x + delta.x, vec.y + delta.y}, true);
    }
  }
  else {
    for(size_t i = 0; i < size_; ++i) {
      shapes_[i]->move(vec);
    }
  }
}

void dan::CompositeShape::scaleImpl(dan::udouble_t s)
{
  for(size_t i = 0; i < size_; ++i) {
    point_t move_vec { s * (getX(*shapes_[i]) - getX(*this)), s * (getY(*shapes_[i]) - getY(*this)) };
    shapes_[i]->move(move_vec);
    shapes_[i]->scale(s);
  }
}

void dan::CompositeShape::swap(CompositeShape& other) noexcept
{
  std::swap(size_, other.size_);
  std::swap(shapes_, other.shapes_);
}

void dan::swap(CompositeShape& lhs, CompositeShape& rhs) noexcept
{
  lhs.swap(rhs);
}

dan::CompositeShape::CompositeShape(const CompositeShape& other):
  shapes_(std::make_unique< ShapePtr[] >(other.size_)),
  size_(other.size_)
{
  for(size_t i = 0; i < size_; ++i) {
    shapes_[i] = other.shapes_[i]->copy();
  }
}

dan::CompositeShape& dan::CompositeShape::operator=(const CompositeShape& other)
{
  CompositeShape temp(other);
  swap(temp);
  return *this;
}

std::unique_ptr< dan::Shape > dan::CompositeShape::copy() const
{
  return std::make_unique< CompositeShape >(*this);
}

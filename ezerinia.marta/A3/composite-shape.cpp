#include "composite-shape.hpp"
#include <stdexcept>
#include <limits>
#include <algorithm>

namespace lab = ezerinia;

lab::CompositeShape::CompositeShape(const CompositeShape &src):
  size_(src.size_),
  capacity_(src.capacity_),
  data_(std::make_unique< shapePtr[] >(src.size_))
{
  for (size_t i = 0; i < size_; i++) {
    data_[i] = src.data_[i]->clone();
  }
}

lab::CompositeShape &lab::CompositeShape::operator=(const CompositeShape &src)
{
  CompositeShape temp(src);
  swap(temp);
  return *this;
}

lab::CompositeShape::CompositeShape(shapePtr src):
  size_(1),
  capacity_(2),
  data_(std::make_unique< shapePtr[] >(capacity_))
{
  if (!src) {
    throw std::invalid_argument("The shape must not be nullptr");
  }
  data_[0] = std::move(src);
}

std::shared_ptr< lab::Shape > lab::CompositeShape::at(size_t index) const
{
  if (index >= size_) {
    throw std::out_of_range("Index outside the array");
  }
  return data_[index];
}

size_t lab::CompositeShape::size() const
{
  return size_;
}

size_t lab::CompositeShape::capacity() const
{
  return capacity_;
}

void lab::CompositeShape::pushBack(shapePtr src)
{
  if (!src) {
    throw std::invalid_argument("The shape must not be nullptr");
  }
  if (capacity_ == size_) {
    reserve(capacity_ * 2);
  }
  data_[size_++] = std::move(src);
}

void lab::CompositeShape::popBack()
{
  if (size_ == 1) {
    throw std::logic_error("The composite shape must contain at least one shape");
  }
  data_[--size_].reset();
}

double lab::CompositeShape::getArea() const
{
  double totalArea = 0.0;
  for (size_t i = 0; i < size_; i++) {
    totalArea += data_[i]->getArea();
  }
  return totalArea;
}

lab::rectangle_t lab::CompositeShape::getFrameRect() const
{
  point_t minXY{std::numeric_limits< double >::max(), std::numeric_limits< double >::max()};
  point_t maxXY{-minXY.x, -minXY.y};
  for (size_t i = 0; i < size_; i++) {
    minXY.x = std::min(minXY.x, getX(*data_[i]) - getWidth(*data_[i]) / 2);
    minXY.y = std::min(minXY.y, getY(*data_[i]) - getHeight(*data_[i]) / 2);
    maxXY.x = std::max(maxXY.x, getX(*data_[i]) + getWidth(*data_[i]) / 2);
    maxXY.y = std::max(maxXY.y, getY(*data_[i]) + getHeight(*data_[i]) / 2);
  }
  point_t pos{(maxXY.x + minXY.x) / 2, (maxXY.y + minXY.y) / 2};
  return {maxXY.x - minXY.x, maxXY.y - minXY.y, pos};
}

void lab::CompositeShape::move(const point_t &point)
{
  move(point.x - getX(*this), point.y - getY(*this));
}

void lab::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; i++) {
    data_[i]->move(dx, dy);
  }
}

void lab::CompositeShape::doScale(double k)
{
  double posOfFrameRectX = getX(*this);
  double posOfFrameRectY = getY(*this);
  for (size_t i = 0; i < size_; i++) {
    double dx = getX(*data_[i]) - posOfFrameRectX;
    double dy = getY(*data_[i]) - posOfFrameRectY;
    data_[i]->move({posOfFrameRectX + dx * k, posOfFrameRectY + dy * k});
    data_[i]->scale(k);
  }
}

void lab::CompositeShape::swap(CompositeShape &src) noexcept
{
  std::swap(size_, src.size_);
  std::swap(capacity_, src.capacity_);
  std::swap(data_, src.data_);
}

void lab::swap(CompositeShape &lhs, CompositeShape &rhs) noexcept
{
  lhs.swap(rhs);
}

std::shared_ptr< lab::Shape > lab::CompositeShape::clone() const
{
  return std::make_shared< CompositeShape >(*this);
}

void lab::CompositeShape::reserve(size_t newCap)
{
  if (newCap > capacity_) {
    shapeArr temp(std::make_unique< shapePtr[] >(newCap));
    for (size_t i = 0; i < size_; i++) {
      temp[i] = std::move_if_noexcept(data_[i]);
    }
    data_.swap(temp);
  }
}

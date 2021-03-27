#include "composite-shape.hpp"
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <memory>

const size_t INITIAL_CAPACITY = 4;
const size_t CAPACITY_INCREASE_FACTOR = 2;

shilyaev::CompositeShape::CompositeShape(std::unique_ptr< shilyaev::Shape > initialShape):
  capacity_(INITIAL_CAPACITY),
  size_(1),
  shapes_(std::make_unique< ValueType[] >(INITIAL_CAPACITY))
{
  if (initialShape == nullptr) {
    throw std::invalid_argument("Shape can't be nullptr");
  }
  shapes_[0] = std::move(initialShape);
}

shilyaev::CompositeShape::CompositeShape(const shilyaev::CompositeShape &source):
  capacity_(source.capacity_),
  size_(source.size_),
  shapes_(std::make_unique< ValueType[] >(source.capacity_))
{
  for (size_t i = 0; i < size_; i++) {
    shapes_[i] = source.shapes_[i]->clone();
  }
}

shilyaev::CompositeShape &shilyaev::CompositeShape::operator=(shilyaev::CompositeShape other)
{
  swap(other);
  return *this;
}

double shilyaev::CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size_; i++) {
    area += shapes_[i]->getArea();
  }
  return area;
}

shilyaev::rectangle_t shilyaev::CompositeShape::getFrameRect() const
{
  double maxX = -std::numeric_limits< double >::max();
  double maxY = -std::numeric_limits< double >::max();
  double minX = std::numeric_limits< double >::max();
  double minY = std::numeric_limits< double >::max();
  for (size_t i = 0; i < size_; i++) {
    maxX = std::max(maxX, getX(*shapes_[i]) + getWidth(*shapes_[i]) / 2);
    maxY = std::max(maxY, getY(*shapes_[i]) + getHeight(*shapes_[i]) / 2);
    minX = std::min(minX, getX(*shapes_[i]) - getWidth(*shapes_[i]) / 2);
    minY = std::min(minY, getY(*shapes_[i]) - getHeight(*shapes_[i]) / 2);
  }
  point_t center = point_t{(maxX + minX) / 2, (maxY + minY) / 2};
  return rectangle_t{maxX - minX, maxY - minY, center};
}

std::unique_ptr< shilyaev::Shape > shilyaev::CompositeShape::clone() const
{
  return std::make_unique< shilyaev::CompositeShape >(*this);
}

void shilyaev::CompositeShape::move(const point_t &pos)
{
  move(pos.x - getX(*this), pos.y -getY(*this));
}

void shilyaev::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; i++) {
    shapes_[i]->move(dx, dy);
  }
}

void shilyaev::CompositeShape::scaleInternal(double factor)
{
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i < size_; i++) {
    shapes_[i]->scale(factor);
    point_t newLocalCenter{center.x + (getX(*shapes_[i]) - center.x) * factor,
                           center.y + (getY(*shapes_[i]) - center.y) * factor};
    shapes_[i]->move(newLocalCenter);
  }
}

void shilyaev::CompositeShape::pushBack(std::unique_ptr< Shape > shape)
{
  if (shape == nullptr) {
    throw std::invalid_argument("Shape can't be nullptr");
  }
  if (size_ >= capacity_) {
    reserve(capacity_ * CAPACITY_INCREASE_FACTOR);
  }
  shapes_[size_++] = std::move(shape);
}

void shilyaev::CompositeShape::popBack()
{
  if (size_ == 1) {
    throw std::out_of_range("CompositeShape can't be empty");
  }
  shapes_[--size_].reset();
}

void shilyaev::CompositeShape::reserve(size_t newCapacity)
{
  if (newCapacity > capacity_) {
    ArrayType newShapes = std::make_unique< ValueType[] >(newCapacity);
    for (size_t i = 0; i < size_; i++) {
      newShapes[i] = std::move(shapes_[i]);
    }
    shapes_ = std::move(newShapes);
    capacity_ = newCapacity;
  }
}

size_t shilyaev::CompositeShape::size() const
{
  return size_;
}

const shilyaev::Shape &shilyaev::CompositeShape::at(size_t index) const
{
  if (index >= size_) {
    throw std::out_of_range("Out of range");
  }
  return *shapes_[index];
}

shilyaev::Shape &shilyaev::CompositeShape::at(size_t index)
{
  if (index >= size_) {
    throw std::out_of_range("Out of range");
  }
  return *shapes_[index];
}

void shilyaev::CompositeShape::swap(shilyaev::CompositeShape &other) noexcept
{
  std::swap(capacity_, other.capacity_);
  std::swap(size_, other.size_);
  std::swap(shapes_, other.shapes_);
}

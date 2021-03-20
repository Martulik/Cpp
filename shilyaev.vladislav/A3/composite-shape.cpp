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
  shapes_(std::make_unique< std::unique_ptr< Shape >[] >(INITIAL_CAPACITY))
{
  if (initialShape == nullptr) {
    throw std::invalid_argument("Shape can't be nullptr");
  }
  shapes_[0] = std::move(initialShape);
}

shilyaev::CompositeShape::CompositeShape(const shilyaev::CompositeShape &source):
  capacity_(source.capacity_),
  size_(source.size_),
  shapes_(std::make_unique< std::unique_ptr< Shape >[] >(source.capacity_))
{
  for (size_t i = 0; i < size_; i++) {
    shapes_[i].reset(source.shapes_[i]->clone());
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
    rectangle_t localFrameRect = shapes_[i]->getFrameRect();
    maxX = std::max(maxX, localFrameRect.pos.x + localFrameRect.width / 2);
    maxY = std::max(maxY, localFrameRect.pos.y + localFrameRect.height / 2);
    minX = std::min(minX, localFrameRect.pos.x - localFrameRect.width / 2);
    minY = std::min(minY, localFrameRect.pos.y - localFrameRect.height / 2);
  }
  point_t center = point_t{(maxX + minX) / 2, (maxY + minY) / 2};
  return rectangle_t{maxX - minX, maxY - minY, center};
}

shilyaev::CompositeShape *shilyaev::CompositeShape::clone() const
{
  return new CompositeShape(*this);
}

void shilyaev::CompositeShape::move(const point_t &pos)
{
  if (size_ > 0) {
    point_t center = getFrameRect().pos;
    move(pos.x - center.x, pos.y - center.y);
  }
}

void shilyaev::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; i++) {
    shapes_[i]->move(dx, dy);
  }
}

void shilyaev::CompositeShape::scale(double factor)
{
  if (factor < 0.0) {
    throw std::invalid_argument("Scale factor can't be negative");
  }
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i < size_; i++) {
    shapes_[i]->scale(factor);
    point_t localCenter = shapes_[i]->getFrameRect().pos;
    point_t newLocalCenter{center.x + (localCenter.x - center.x) * factor,
                           center.y + (localCenter.y - center.y) * factor};
    shapes_[i]->move(newLocalCenter);
  }
}

void shilyaev::CompositeShape::pushBack(std::unique_ptr< Shape > shape)
{
  if (shape == nullptr) {
    throw std::invalid_argument("Shape can't be nullptr");
  }
  if (size_ >= capacity_) {
    increaseCapacity();
  }
  shapes_[size_] = std::move(shape);
  size_++;
}

void shilyaev::CompositeShape::popBack()
{
  if (size_ == 1) {
    throw std::out_of_range("CompositeShape can't be empty");
  }
  shapes_[size_--].reset();
}

size_t shilyaev::CompositeShape::size() const
{
  return size_;
}

void shilyaev::CompositeShape::swap(shilyaev::CompositeShape &other) noexcept
{
  std::swap(capacity_, other.capacity_);
  std::swap(size_, other.size_);
  std::swap(shapes_, other.shapes_);
}

void shilyaev::CompositeShape::increaseCapacity()
{
  size_t newCapacity = capacity_ * CAPACITY_INCREASE_FACTOR;
  std::unique_ptr< std::unique_ptr< Shape >[] > newShapes = std::make_unique< std::unique_ptr< Shape >[] >(newCapacity);
  for (size_t i = 0; i < size_; i++) {
    newShapes[i] = std::move(shapes_[i]);
  }
  shapes_ = std::move(newShapes);
  capacity_ = newCapacity;
}

#include "composite-shape.hpp"
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <memory>

const size_t INITIAL_CAPACITY = 4;
const size_t CAPACITY_INCREASE_FACTOR = 2;

shilyaev::CompositeShape::CompositeShape():
  capacity_(INITIAL_CAPACITY),
  size_(0),
  shapes_(std::make_unique< std::unique_ptr< Shape >[] >(INITIAL_CAPACITY))
{
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

shilyaev::CompositeShape &shilyaev::CompositeShape::operator=(const shilyaev::CompositeShape &other)
{
  if (this != &other) {
    capacity_ = other.capacity_;
    size_ = other.size_;
    shapes_ = std::make_unique< std::unique_ptr< Shape >[] >(other.capacity_);
    for (size_t i = 0; i < size_; i++) {
      shapes_[i].reset(other.shapes_[i]->clone());
    }
  }
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
  if (size_ == 0) {
    return rectangle_t{0.0, 0.0, point_t{0.0, 0.0}};
  }
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
  if (size_ > 0) {
    point_t center = getFrameRect().pos;
    for (size_t i = 0; i < size_; i++) {
      shapes_[i]->scale(factor);
      point_t localCenter = shapes_[i]->getFrameRect().pos;
      point_t newLocalCenter{center.x + (localCenter.x - center.x) * factor,
                             center.y + (localCenter.y - center.y) * factor};
      shapes_[i]->move(newLocalCenter);
    }
  }
}

void shilyaev::CompositeShape::insert(std::unique_ptr< Shape > shape)
{
  if (size_ >= capacity_) {
    increaseCapacity();
  }
  shapes_[size_] = std::move(shape);
  size_++;
}

void shilyaev::CompositeShape::increaseCapacity()
{
  capacity_ *= CAPACITY_INCREASE_FACTOR;
  std::unique_ptr< std::unique_ptr< Shape >[] > old = std::move(shapes_);
  shapes_ = std::make_unique< std::unique_ptr< Shape >[] >(capacity_);
  for (size_t i = 0; i < size_; i++) {
    shapes_[i] = std::move(old[i]);
  }
}

size_t shilyaev::CompositeShape::getSize() const
{
  return size_;
}

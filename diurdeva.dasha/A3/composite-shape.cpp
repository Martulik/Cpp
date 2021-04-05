#include "composite-shape.hpp"
#include <stdexcept>

diurdeva::CompositeShape::CompositeShape(shapePtr shape):
  capacity_(2),
  size_(1),
  shapeArr_(std::make_unique< shapePtr[] >(capacity_))
{
  if (!shape) {
    throw std::invalid_argument("Pointer must be not null");
  }
  shapeArr_[0] = std::move(shape);
}

diurdeva::CompositeShape::CompositeShape(const CompositeShape& other):
  capacity_(other.capacity_),
  size_(other.size_),
  shapeArr_(std::make_unique< shapePtr[] >(other.size_))
{
  for (size_t i = 0; i < size_; i++) {
    shapeArr_[i] = other.shapeArr_[i]->clone();
  }
}

diurdeva::CompositeShape& diurdeva::CompositeShape::operator=(const CompositeShape& other)
{
  CompositeShape temp(other);
  swap(temp);
  return *this;
}

std::shared_ptr< diurdeva::Shape > diurdeva::CompositeShape::at(const size_t index) const
{
  if (index >= size_) {
    throw std::out_of_range("Index goes out of bounds");
  }
  return shapeArr_[index];
}

double diurdeva::CompositeShape::getArea() const
{
  double area = shapeArr_[0]->getArea();
  for (size_t i = 1; i < size_; i++) {
    area += shapeArr_[i]->getArea();
  }
  return area;
}

void diurdeva::CompositeShape::move(const double dX, const double dY)
{
  for (size_t i = 0; i < size_; i++) {
    shapeArr_[i]->move(dX, dY);
  }
}

void diurdeva::CompositeShape::move(const point_t& newCenter)
{
  move(newCenter.x - getX(*this), newCenter.y - getY(*this));
}

diurdeva::rectangle_t diurdeva::CompositeShape::getFrameRect() const
{
  double minX = getX(*shapeArr_[0]) - getWidth(*shapeArr_[0]) / 2;
  double maxX = getX(*shapeArr_[0]) + getWidth(*shapeArr_[0]) / 2;
  double minY = getY(*shapeArr_[0]) - getHeight(*shapeArr_[0]) / 2;
  double maxY = getY(*shapeArr_[0]) + getHeight(*shapeArr_[0]) / 2;
  for (size_t i = 1; i < size_; i++) {
    minX = std::min((getX(*shapeArr_[i]) - getWidth(*shapeArr_[i]) / 2), minX);
    maxX = std::max((getX(*shapeArr_[i]) + getWidth(*shapeArr_[i]) / 2), maxX);
    minY = std::min((getY(*shapeArr_[i]) - getHeight(*shapeArr_[i]) / 2), minY);
    maxY = std::max((getY(*shapeArr_[i]) + getHeight(*shapeArr_[i]) / 2), maxY);
  }
  double width = maxX - minX;
  double height = maxY - minY;
  double x = (minX + maxX) / 2;
  double y = (minY + maxY) / 2;
  return { width, height, {x, y} };
}

std::shared_ptr< diurdeva::Shape > diurdeva::CompositeShape::clone() const
{
  return std::make_shared< CompositeShape >(*this);
}

void diurdeva::CompositeShape::swap(CompositeShape& src) noexcept
{
  std::swap(capacity_, src.capacity_);
  std::swap(size_, src.size_);
  std::swap(shapeArr_, src.shapeArr_);
}

void diurdeva::swap(CompositeShape& src1, CompositeShape& src2) noexcept
{
  src1.swap(src2);
}

void diurdeva::CompositeShape::reserve(size_t newCapacity)
{
  if (newCapacity > capacity_) {
    shapeArray srcArray(std::make_unique< shapePtr[] >(newCapacity));
    CompositeShape srcShape(*this);
    for (size_t i = 0; i < size_; i++) {
      srcArray[i] = std::move_if_noexcept(shapeArr_[i]);
    }
    srcShape.shapeArr_ = std::move_if_noexcept(srcArray);
    srcShape.capacity_ = newCapacity;
    swap(srcShape);
  }

}

void diurdeva::CompositeShape::doScale(const double factor)
{
  point_t centerGetFrameRect = getFrameRect().pos;
  for (size_t i = 0; i < size_; i++) {
    double dX = getX(*shapeArr_[i]) - centerGetFrameRect.x;
    double dY = getY(*shapeArr_[i]) - centerGetFrameRect.y;
    shapeArr_[i]->move({centerGetFrameRect.x + dX * factor, centerGetFrameRect.y + dY * factor });
    shapeArr_[i]->scale(factor);
  }
}

void diurdeva::CompositeShape::pushBack(shapePtr newShape)
{
  if (!newShape) {
    throw std::invalid_argument("Pointer must be not null");
  }
  shapeArray newArray(std::make_unique< shapePtr[] >(size_ + 1));
  if (capacity_ == size_) {
    reserve(capacity_ * 2);
  }
  shapeArr_[size_++] = std::move(newShape);
}

void diurdeva::CompositeShape::popBack()
{
  if (size_ == 1) {
    throw std::out_of_range("Unable to reach the figure");
  }
  shapeArr_[--size_].reset();
}

size_t diurdeva::CompositeShape::size() const
{
  return size_;
}

size_t diurdeva::CompositeShape::capacity() const
{
  return capacity_;
}

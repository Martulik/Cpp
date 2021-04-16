#include "composite-shape.hpp"
#include <stdexcept>

razukrantov::CompositeShape::CompositeShape(shapePtr src):
  size_(1),
  capacity_(2),
  shapeArr_(std::make_unique< shapePtr[] >(capacity_))
{
  if (!src)
  {
    throw std::invalid_argument("The shape cannot be nullptr");
  }
  shapeArr_[0] = std::move(src);
}

razukrantov::CompositeShape::CompositeShape(const CompositeShape& src):
  size_(src.size_),
  capacity_(src.capacity_),
  shapeArr_(std::make_unique< shapePtr[] >(src.capacity_))
{
  for (size_t i = 0; i < size_; i++)
  {
    shapeArr_[i] = src.shapeArr_[i]->clone();
  }
}

razukrantov::CompositeShape& razukrantov::CompositeShape::operator=(const CompositeShape& src)
{
  CompositeShape temp(src);
  swap(temp);
  return (*this);
}

double razukrantov::CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    area += shapeArr_[i]->getArea();
  }
  return area;
}

razukrantov::rectangle_t razukrantov::CompositeShape::getFrameRect() const
{
  double maxX = getX(*shapeArr_[0]) + getWidth(*shapeArr_[0]) / 2;
  double maxY = getY(*shapeArr_[0]) + getHeight(*shapeArr_[0]) / 2;
  double minX = getX(*shapeArr_[0]) - getWidth(*shapeArr_[0]) / 2;
  double minY = getY(*shapeArr_[0]) - getHeight(*shapeArr_[0]) / 2;
  for (size_t i = 1; i < size_; i++)
  {
    maxX = std::max((getX(*shapeArr_[i]) + getWidth(*shapeArr_[i]) / 2), maxX);
    maxY = std::max((getY(*shapeArr_[i]) + getHeight(*shapeArr_[i]) / 2), maxY);
    minX = std::max((getX(*shapeArr_[i]) - getWidth(*shapeArr_[i]) / 2), minX);
    minY = std::max((getY(*shapeArr_[i]) - getHeight(*shapeArr_[i]) / 2), minY);
  }
  double width = maxX - minX;
  double height = maxY - minY;
  double x = (minX + maxX) / 2;
  double y = (minY + maxY) / 2;
  return { width, height, {x,y} };
}

void razukrantov::CompositeShape::move(const point_t& pos)
{
  move(pos.x - getX(*this), pos.y - getY(*this));
}

void razukrantov::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapeArr_[i]->move(dx, dy);
  }
}

std::shared_ptr< razukrantov::Shape > razukrantov::CompositeShape::at(size_t index)
{
  if (index >= size_)
  {
    throw std::out_of_range("index outside the bounds of the array");
  }
  return shapeArr_[index];
}

std::shared_ptr< const razukrantov::Shape > razukrantov::CompositeShape::at(size_t index) const
{
  if (index >= size_)
  {
    throw std::out_of_range("index outside the bounds of the array");
  }
  return shapeArr_[index];
}

std::shared_ptr< razukrantov::Shape > razukrantov::CompositeShape::clone() const
{
  return std::make_shared< CompositeShape >(*this);
}

void razukrantov::CompositeShape::pushBack(shapePtr src)
{
  if (!src)
  {
    throw std::invalid_argument("The shape cannot be nullptr");
  }
  if (capacity_ == size_)
  {
    reserve(capacity_ * 2);
  }
  shapeArr_[size_] = std::move(src);
  size_++;
}

void razukrantov::CompositeShape::popBack()
{
  if (size_ == 1)
  {
    throw std::out_of_range("The composite shape cannot be nullptr");
  }
  size_--;
  shapeArr_[size_].reset();
}

size_t razukrantov::CompositeShape::size() const
{
  return size_;
}

size_t razukrantov::CompositeShape::capacity() const
{
  return capacity_;
}

void razukrantov::CompositeShape::doScale(double k)
{
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i < size_; i++)
  {
    shapeArr_[i]->scale(k);
    double dx = getX(*shapeArr_[i]) - center.x;
    double dy = getY(*shapeArr_[i]) - center.y;
    shapeArr_[i]->move({ center.x + (dx * k), center.y + (dy * k) });
  }
}

void razukrantov::CompositeShape::swap(CompositeShape& src) noexcept
{
  std::swap(size_, src.size_);
  std::swap(capacity_, src.capacity_);
  std::swap(shapeArr_, src.shapeArr_);
}

void razukrantov::swap(CompositeShape& src1, CompositeShape& src2) noexcept
{
  src1.swap(src2);
}

void razukrantov::CompositeShape::reserve(size_t newCap)
{
  if (newCap > capacity_)
  {
    shapeArr srcArray = std::make_unique< shapePtr[] >(newCap);
    CompositeShape srcShape(*this);
    for (size_t i = 0; i < size_; i++)
    {
      srcArray[i] = std::move_if_noexcept(shapeArr_[i]);
    }
    srcShape.shapeArr_ = std::move_if_noexcept(srcArray);
    srcShape.capacity_ = newCap;
    swap(srcShape);
  }
}

#include "composite-shape.hpp"
#include <stdexcept>

murzakanov::CompositeShape::CompositeShape(ShapePtr shp):
  capacity_(2),
  size_(1),
  array_(std::make_unique< ShapePtr[] >(capacity_))
{
  if (shp == nullptr)
  {
    throw std::invalid_argument("Pointer to shape cannot be nullptr");
  }
  array_[size_ - 1] = shp->clone();
}

murzakanov::CompositeShape::CompositeShape(const CompositeShape& other):
  capacity_(other.capacity_),
  size_(other.size_),
  array_(std::make_unique< ShapePtr[] >(other.capacity_))
{
  for (int i = 0; i < size_; i++)
  {
    array_[i] = other.array_[i]->clone();
  }
}

murzakanov::CompositeShape& murzakanov::CompositeShape::operator=(const CompositeShape& src)
{
  if (this == std::addressof(src))
  {
    return *this;
  }
  array_.reset();
  CompositeShape tmp(src);
  swap(tmp);
  return *this;
}
murzakanov::CompositeShape& murzakanov::CompositeShape::operator=(CompositeShape&& src) noexcept
{
  if (!(this == std::addressof(src)))
  {
    array_.reset();
    array_ = std::move(src.array_);
    src.array_ = nullptr;
  }
  return *this;
}

murzakanov::Shape& murzakanov::CompositeShape::at(const int index)
{
  if (index < 0 || index >= size_)
  {
    throw std::invalid_argument("Index out of array");
  }
  return *array_[index];
}

void murzakanov::CompositeShape::addShape(const ShapePtr& shp)
{
  if (shp == nullptr)
  {
    throw std::invalid_argument("Pointer to shape cannot be nullptr");
  }
  if (capacity_ == size_)
  {
    reserve(capacity_ * 2);
  }
  array_[size_] = shp->clone();
  size_++;
}

void murzakanov::CompositeShape::popShape()
{
  if (size_ == 1)
  {
    throw std::logic_error("Composite shape cannot be empty");
  }
  array_[size_ - 1].reset();
  size_--;
}

void murzakanov::CompositeShape::doScale(double coef)
{
  double compositeX = getFrameRect().pos.x;
  double compositeY = getFrameRect().pos.y;
  for (int i = 0; i < size_; i++)
  {
    double dx = getX(array_[i]) - compositeX;
    double dy = getY(array_[i]) - compositeY;
    double xNew = compositeX + dx * coef;
    double yNew = compositeY + dy * coef;
    point_t newPoint = {xNew, yNew};
    array_[i]->move(newPoint);
    array_[i]->scale(coef);
  }
}

std::string murzakanov::CompositeShape::getName() const
{
  return "Composite Shape";
}

double murzakanov::CompositeShape::getArea() const
{
  double totalArea = 0;
  for (int i = 0; i < size_; i++)
  {
    totalArea += array_[i]->getArea();
  }
  return totalArea;
}

murzakanov::rectangle_t murzakanov::CompositeShape::getFrameRect() const
{
  double maxX = getX(array_[0]) + getWidth(array_[0]) / 2;
  double minX = getX(array_[0]) - getWidth(array_[0]) / 2;
  double maxY = getY(array_[0]) + getHeight(array_[0]) / 2;
  double minY = getY(array_[0]) - getHeight(array_[0]) / 2;

  for (int i = 1; i < size_; i++)
  {
    maxX = std::max(maxX, getX(array_[i]) + getWidth(array_[i]) / 2);
    maxY = std::max(maxY, getY(array_[i]) + getHeight(array_[i]) / 2);
    minX = std::min(minX, getX(array_[i]) - getWidth(array_[i]) / 2);
    minY = std::min(minY, getY(array_[i]) - getHeight(array_[i]) / 2);
  }
  return {maxX - minX, maxY - minY, {(maxX + minX) / 2, (maxY + minY) / 2}};
}

void murzakanov::CompositeShape::move(const murzakanov::point_t &point)
{
  double dx = point.x - getFrameRect().pos.x;
  double dy = point.y - getFrameRect().pos.y;
  for (int i = 0; i < size_; i++)
  {
    array_[i]->move(dx, dy);
  }
}

void murzakanov::CompositeShape::move(double dx, double dy)
{
  for (int i = 0; i < size_; i++)
  {
    array_[i]->move(dx, dy);
  }
}

int murzakanov::CompositeShape::size() const
{
  return size_;
}

murzakanov::Shape::ShapePtr murzakanov::CompositeShape::clone() const
{
  return std::make_shared< murzakanov::CompositeShape >(*this);
}

void murzakanov::CompositeShape::reserve(const int newCapacity)
{
  if (capacity_ < newCapacity)
  {
    ArrayType tempArray(std::make_unique< ShapePtr[] >(newCapacity));
    for (int i = 0; i < size_; i++)
    {
      tempArray[i] = std::move(array_[i]);
    }
    capacity_ = newCapacity;
    array_ = std::move(tempArray);
  }
}

void murzakanov::CompositeShape::swap(CompositeShape& other) noexcept
{
  std::swap(capacity_, other.capacity_);
  std::swap(size_, other.size_);
  std::swap(array_, other.array_);
}

#include "composite-shape.hpp"
#include <stdexcept>

namespace curr = lysenko;

curr::CompositeShape::CompositeShape(const curr::CompositeShape& other)
{
  capacity_ = other.capacity_;
  size_ = other.size_;
  array_ = std::make_unique< ShapePtr[] >(capacity_);
  for (size_t i = 0; i < size_; i++)
  {
    array_[i].reset();
    array_[i] = other.array_[i]->clone();
  }
}

curr::CompositeShape& curr::CompositeShape::operator=(const CompositeShape& src)
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


curr::CompositeShape::CompositeShape(ShapePtr src):
  capacity_(1),
  size_(1),
  array_(std::make_unique< ShapePtr [] > (capacity_))
{
  if (src == nullptr)
  {
    throw std::invalid_argument("Composite shape can not contain the pointer on nullptr");
  }
  array_[0] = src->clone();
}

double curr::CompositeShape::getArea() const
{
  double resultArea = 0;
  for (size_t i = 0; i < size_; i++)
  {
    resultArea += array_[i]->getArea();
  }
  return resultArea;
}

double lysenko::getShapesLeftmostAbscissa(std::shared_ptr< const Shape > src)
{
  return getX(src) + getWidth(src) / 2;
}

double lysenko::getShapesRightmostAbscissa(std::shared_ptr< const Shape > src)
{
  return getX(src) - getWidth(src) / 2;
}

double lysenko::getShapesBottomOrdinate(std::shared_ptr< const Shape > src)
{
  return getY(src) - getHeight(src) / 2;
}

double lysenko::getShapesTopOrdinate(std::shared_ptr< const Shape > src)
{
  return getY(src) + getHeight(src) / 2;
}

curr::rectangle_t curr::CompositeShape::getFrameRect() const
{
  ShapePtr current = array_[0];
  double minX = getShapesRightmostAbscissa(current);
  double maxX = getShapesLeftmostAbscissa(current);
  double minY = getShapesBottomOrdinate(current);
  double maxY = getShapesTopOrdinate(current);
  for (size_t i = 1; i < size_; i++)
  {
    current = array_[i];
    minX = std::min(minX, getShapesRightmostAbscissa(current));
    maxX = std::max(maxX, getShapesLeftmostAbscissa(current));
    minY = std::min(minY, getShapesBottomOrdinate(current));
    maxY = std::max(maxY, getShapesTopOrdinate(current));
  }
  return {maxX - minX, maxY - minY, {(minX + (maxX - minX) / 2), (minY + (maxY - minY) / 2)}};
}

void curr::CompositeShape::move(const point_t& newPos)
{
  double dx = newPos.x - getFrameRect().pos.x;
  double dy = newPos.y - getFrameRect().pos.y;
  move(dx, dy);
}

void curr::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    array_[i]->move(dx, dy);
  }
}

std::string curr::CompositeShape::getName() const
{
  return "Composite shape";
}

curr::Shape::ShapePtr curr::CompositeShape::clone() const
{
  return std::make_shared< CompositeShape >(*this);
}

curr::Shape::ShapePtr curr::CompositeShape::at(size_t index)
{
  if (index >= size_)
  {
    throw std::out_of_range("Index out of range");
  }
  return array_[index];
}

void curr::CompositeShape::addShape(const ShapePtr& src)
{
  if (src == nullptr)
  {
    throw std::invalid_argument ("Composite shape can not contain the pointer on nullptr");
  }
  if (size_ == capacity_)
  {
    enlargeCapacity(capacity_ * 2);
  }
  array_[size_] = src->clone();
  size_++;
}

void curr::CompositeShape::popShape()
{
  if (size_ == 1)
  {
    throw std::logic_error("Empty composite shape is illegal");
  }
  array_[size_ - 1].reset();
  size_--;
}

void curr::CompositeShape::swap(CompositeShape& other) noexcept
{
  std::swap(capacity_, other.capacity_);
  std::swap(size_, other.size_);
  std::swap(array_, other.array_);
}

void curr::CompositeShape::enlargeCapacity(size_t newCapacity)
{
  if (capacity_ > newCapacity)
  {
    throw std::invalid_argument("New capacity must be a number larger than old capacity");
  }
  ArrayOfShapes newCapacityOldData(std::make_unique< ShapePtr[] >(newCapacity));
  for (size_t i = 0; i < size_; i++)
  {
    newCapacityOldData[i] = array_[i];
  }
  array_ = std::move(newCapacityOldData);
  capacity_ = newCapacity;
}

void curr::CompositeShape::doScale(double k)
{
  double compositeCenterX = getFrameRect().pos.x;
  double compositeCenterY = getFrameRect().pos.y;
  for (size_t i = 0; i < size_; i++)
  {
    array_[i]->scale(k);
    double dx = compositeCenterX - getX(array_[i]);
    double dy = compositeCenterY - getY(array_[i]);
    array_[i]->move({ compositeCenterX + dx * k, compositeCenterY + dy * k });
  }
}

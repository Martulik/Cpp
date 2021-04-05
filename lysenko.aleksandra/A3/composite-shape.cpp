#include "composite-shape.hpp"

#include <string>

namespace curr = lysenko;

curr::CompositeShape::CompositeShape(const curr::CompositeShape& other)
{
  capacity_ = other.capacity_;
  size_ = other.size_;
  array_ = std::make_unique < ShapePtr[] >(capacity_);
  for (size_t i = 0; i < size_; i++)
  {
    array_[i].reset();
    array_[i] = other.array_[i]->clone();
  }
}

curr::CompositeShape::CompositeShape(CompositeShape&& other) noexcept
{
  capacity_ = std::move(other.capacity_);
  size_ = std::move(other.size_);
  array_ = std::move(other.array_);

  other.capacity_ = 0;
  other.size_ = 0;
  other.array_ = nullptr;
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

curr::CompositeShape& curr::CompositeShape::operator=(CompositeShape&& src) noexcept
{
  if (this == std::addressof(src))
  {
    return *this;
  }
  array_.reset();
  array_ = std::move(src.array_);
  src.array_ = nullptr;
  return *this;
}

curr::CompositeShape::CompositeShape(ShapePtr src) :
  capacity_(1),
  size_(1),
  array_(std::make_unique < ShapePtr[] >(capacity_))
{
  if (&src == nullptr)
  {
    throw "Composite shape can not contain the pointer on nullptr";
  }
  array_[0].reset();
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

double lysenko::getShapesLeftmostAbscissa(Shape::ShapePtr const src)
{
  return getX(*src) + getWidth(*src) / 2;
}

double lysenko::getShapesRightmostAbscissa(Shape::ShapePtr const src)
{
  return getX(*src) - getWidth(*src) / 2;
}

double lysenko::getShapesBottomOrdinate(Shape::ShapePtr const src)
{
  return getY(*src) - getHeight(*src) / 2;
}

double lysenko::getShapesTopOrdinate(Shape::ShapePtr const src)
{
  return getY(*src) + getHeight(*src) / 2;
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
  return { maxX - minX, maxY - minY, {(minX + (maxX - minX) / 2), (minY + (maxY - minY) / 2)} };
}

void curr::CompositeShape::move(const point_t& newPos)
{
  double dx = newPos.x - getX(*this);
  double dy = newPos.y - getY(*this);
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
  return std::make_shared < CompositeShape >(*this);
}
void curr::CompositeShape::addShape(const ShapePtr& src)
{
  if (src == nullptr)
  {
    throw "Composite shape can not contain the pointer on nullptr";
  }
  if (size_ == capacity_)
  {
    enlargeCapacity(capacity_ * 2);
  }
  array_[size_].reset();
  array_[size_] = src->clone();
  size_++;
}

void curr::CompositeShape::popShape()
{
  if (size_ == 1)
  {
    throw "Empty composite shape is illegal";
  }
  ArrayOfShapes reducedData(std::make_unique < ShapePtr[] >(capacity_));
  for (size_t i = 0; i < size_ - 1; i++)
  {
    reducedData[i] = array_[i];
  }
  array_ = std::move(reducedData);
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
    throw "New capacity must be a number larger than old capacity";
  }
  ArrayOfShapes newCapacityOldData(std::make_unique < ShapePtr[] >(newCapacity));
  for (size_t i = 0; i < size_; i++)
  {
    newCapacityOldData[i] = array_[i];
  }
  array_ = std::move(newCapacityOldData);
  capacity_ = newCapacity;
}

void curr::CompositeShape::doScale(double k)
{
  double compositeCenterX = getX(*this);
  double compositeCenterY = getY(*this);
  for (size_t i = 0; i < size_; i++)
  {
    array_[i]->scale(k);
    double dx = compositeCenterX - getX(*array_[i]);
    double dy = compositeCenterY - getY(*array_[i]);
    array_[i]->move({ compositeCenterX + dx * k, compositeCenterY + dy * k });
  }
}

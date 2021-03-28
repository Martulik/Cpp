#include "composite-shape.hpp"
#include <stdexcept>

murzakanov::CompositeShape::CompositeShape(std::shared_ptr< Shape > shp):
  capacity_(2),
  size_(0),
  array_(std::make_unique< std::shared_ptr< Shape >[] >(capacity_))
{
  if (shp == nullptr)
  {
    throw std::invalid_argument("Pointer to shape cannot be nullptr");
  }
  array_[size_].reset(shp->clone());
  size_++;
}

murzakanov::CompositeShape::CompositeShape(const CompositeShape& other):
  capacity_(other.capacity_),
  size_(other.size_),
  array_(std::make_unique< std::shared_ptr< Shape >[] >(other.capacity_))
{
  for (int i = 0; i < size_; i++)
  {
    array_[i].reset(other.array_[i]->clone());
  }
}

murzakanov::CompositeShape::CompositeShape(CompositeShape&& other) noexcept
{
  array_ = std::move(other.array_);
  capacity_ = other.capacity_;
  size_ = other.size_;

  other.size_ = 0;
  other.capacity_ = 0;
  other.array_ = nullptr;
}

murzakanov::CompositeShape& murzakanov::CompositeShape::operator=(const CompositeShape& src)
{
  if (this == std::addressof(src))
  {
    return *this;
  }
  array_.reset();
  size_ = src.size_;
  capacity_ = src.capacity_;
  array_ = std::make_unique< std::shared_ptr< Shape >[] >(src.capacity_);
  for (int i = 0; i < size_; i++)
  {
    array_[i].reset(src.array_[i]->clone());
  }
  return *this;
}
murzakanov::CompositeShape& murzakanov::CompositeShape::operator=(CompositeShape&& src) noexcept
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

murzakanov::Shape& murzakanov::CompositeShape::operator [](const int index)
{
  if (index < 0 || index >= size_)
  {
    throw std::invalid_argument("Index out of array");
  }
  return *array_[index];
}

void murzakanov::CompositeShape::addShape(const std::shared_ptr< Shape >& shp)
{
  if (shp == nullptr)
  {
    throw std::invalid_argument("Pointer to shape cannot be nullptr");
  }
  if (capacity_ == size_)
  {
    std::unique_ptr< std::shared_ptr< Shape >[] >
      tempArray(std::make_unique< std::shared_ptr< Shape >[] >(capacity_ * 2));
    for (int i = 0; i < size_; i++)
    {
      tempArray[i] = std::move(array_[i]);
    }
    capacity_ = capacity_ * 2;
    tempArray[size_].reset(shp->clone());
    array_ = std::move(tempArray);
  }
  else
  {
    array_[size_].reset(shp->clone());
  }
  size_++;
}

void murzakanov::CompositeShape::popShape()
{
  std::unique_ptr< std::shared_ptr< Shape >[] >
    tempArray(std::make_unique< std::shared_ptr< Shape >[] >(capacity_));
  for (int i = 0; i < size_ - 1; i++)
  {
    tempArray[i] = std::move(array_[i]);
  }
  array_ = std::move(tempArray);
  size_--;
}

void murzakanov::CompositeShape::scale(double coef)
{
  if (coef < 0)
  {
    throw std::invalid_argument("Coefficient should be more or equal than zero");
  }
  double dx = 0;
  double xNew = 0;
  double dy = 0;
  double yNew = 0;
  double compositeX = getFrameRect().pos.x;
  double compositeY = getFrameRect().pos.y;
  for (int i = 0; i < size_; i++)
  {
    dx = array_[i]->getFrameRect().pos.x - compositeX;
    dy = array_[i]->getFrameRect().pos.y - compositeY;
    xNew = compositeX + dx * coef;
    yNew = compositeY + dy * coef;
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
  double maxX = array_[0]->getFrameRect().pos.x
    + array_[0]->getFrameRect().width / 2;
  double minX = array_[0]->getFrameRect().pos.x
    - array_[0]->getFrameRect().width / 2;
  double maxY = array_[0]->getFrameRect().pos.y
    + array_[0]->getFrameRect().height / 2;
  double minY = array_[0]->getFrameRect().pos.y
    - array_[0]->getFrameRect().height / 2;


  for (int i = 1; i < size_; i++)
  {
    maxX = std::max(maxX, array_[0]->getFrameRect().pos.x
      + array_[0]->getFrameRect().width / 2);
    maxY = std::max(maxY, array_[i]->getFrameRect().pos.y
      + array_[i]->getFrameRect().height / 2);
    minX = std::min(minX, array_[i]->getFrameRect().pos.x
      - array_[i]->getFrameRect().width / 2);
    minY = std::min(minY, array_[i]->getFrameRect().pos.y
      - array_[i]->getFrameRect().height / 2);
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

murzakanov::CompositeShape* murzakanov::CompositeShape::clone() const
{
  return new CompositeShape(*this);
}

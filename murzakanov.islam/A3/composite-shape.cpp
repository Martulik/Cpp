#include "composite-shape.hpp"
#include <stdexcept>

murzakanov::CompositeShape::CompositeShape(std::shared_ptr< Shape > shp):
  capacity_(2),
  size_(1),
  array_(std::make_unique< std::shared_ptr< Shape >[] >(capacity_))
{
  if (shp == nullptr)
  {
    throw std::invalid_argument("Pointer to shape cannot be nullptr");
  }
  array_[size_ - 1].reset();
  array_[size_ - 1] = shp->clone();
}

murzakanov::CompositeShape::CompositeShape(const CompositeShape& other):
  capacity_(other.capacity_),
  size_(other.size_),
  array_(std::make_unique< std::shared_ptr< Shape >[] >(other.capacity_))
{
  for (int i = 0; i < size_; i++)
  {
    array_[i].reset();
    array_[i] = other.array_[i]->clone();
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
     array_[i].reset();
     array_[i] = src.array_[i]->clone();
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
    array_ = std::move(tempArray);
  }
  array_[size_].reset();
  array_[size_] = shp->clone();
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
  check(coef, "Coefficient should be more or equal than zero");
  double compositeX = getX();
  double compositeY = getY();
  for (int i = 0; i < size_; i++)
  {
    double dx = array_[i]->getX() - compositeX;
    double dy = array_[i]->getY() - compositeY;
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
  double maxX = array_[0]->getX() + array_[0]->getWidth() / 2;
  double minX = array_[0]->getX() - array_[0]->getWidth() / 2;
  double maxY = array_[0]->getY() + array_[0]->getHeight() / 2;
  double minY = array_[0]->getY() - array_[0]->getHeight() / 2;


  for (int i = 1; i < size_; i++)
  {
    maxX = std::max(maxX, array_[0]->getX() + array_[0]->getWidth() / 2);
    maxY = std::max(maxY, array_[i]->getY() + array_[i]->getHeight() / 2);
    minX = std::min(minX, array_[i]->getX() - array_[i]->getWidth() / 2);
    minY = std::min(minY, array_[i]->getY() - array_[i]->getHeight() / 2);
  }

  return {maxX - minX, maxY - minY, {(maxX + minX) / 2, (maxY + minY) / 2}};
}

void murzakanov::CompositeShape::move(const murzakanov::point_t &point)
{
  double dx = point.x - getX();
  double dy = point.y - getY();
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

std::shared_ptr< murzakanov::Shape > murzakanov::CompositeShape::clone() const
{
  return std::make_shared< murzakanov::CompositeShape >(*this);
}

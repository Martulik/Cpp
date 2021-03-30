#include "composite-shape.hpp"

#include <memory>
#include <stdexcept>

#include "base-types.hpp"

pochernin::CompositeShape::CompositeShape(const CompositeShape& src):
  size_(src.size_),
  capacity_(src.capacity_),
  data_(std::make_unique< std::shared_ptr< Shape >[] >(capacity_))
{
  for (size_t i = 0; i < size_; i++)
  {
    data_[i] = src.data_[i];
  }
}

pochernin::CompositeShape::CompositeShape(CompositeShape&& src) noexcept:
  size_(src.size_),
  capacity_(src.capacity_)
{
  data_ = std::move(src.data_);
  src.size_ = 0;
  src.capacity_ = 0;
}

pochernin::CompositeShape::CompositeShape(const std::shared_ptr< Shape > shape, size_t capacity):
  size_(0),
  capacity_(capacity),
  data_(std::make_unique< std::shared_ptr< Shape >[] >(capacity))
{
  if (capacity < 1)
  {
    throw (std::invalid_argument("Empty CompositeShape"));
  }
  data_[0] = shape;
  size_++;
}

std::shared_ptr< pochernin::Shape >& pochernin::CompositeShape::at(size_t index)
{
  if (index >= size())
  {
    throw std::out_of_range("Out of range");
  }
  return data_[index];
}

const std::shared_ptr< pochernin::Shape >& pochernin::CompositeShape::at(size_t index) const
{
  if (index >= size())
  {
    throw std::out_of_range("Out of range");
  }
  return data_[index];
}

pochernin::CompositeShape& pochernin::CompositeShape::operator=(const CompositeShape& src)
{
  if (this == std::addressof(src))
  {
    return *this;
  }

  CompositeShape temp(src);
  swap(temp);
  return *this;
}

pochernin::CompositeShape& pochernin::CompositeShape::operator=(CompositeShape&& src) noexcept
{
  if (this == std::addressof(src))
  {
    return *this;
  }

  size_ = src.size_;
  capacity_ = src.capacity_;
  data_.reset();
  data_ = std::move(src.data_);
  src.size_ = 0;
  src.capacity_ = 0;
  return *this;
}

double pochernin::CompositeShape::getArea() const
{
  double result = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    result += data_[i]->getArea();
  }
  return result;
}

pochernin::rectangle_t pochernin::CompositeShape::getFrameRect() const
{
  if (size_ == 0)
  {
    return {0.0, 0.0, {0.0, 0.0}};
  }
  double mostLeft = pochernin::getX(*data_[0]) - (pochernin::getWidth(*data_[0]) / 2);
  double mostRight = pochernin::getX(*data_[0]) + (pochernin::getWidth(*data_[0]) / 2);
  double mostUp = pochernin::getY(*data_[0]) + (pochernin::getHeight(*data_[0]) / 2);
  double mostDown = pochernin::getY(*data_[0]) - (pochernin::getHeight(*data_[0]) / 2);
  for (size_t i = 1; i < size_; i++)
  {
    mostLeft = std::min(mostLeft, pochernin::getX(*data_[i]) - (pochernin::getWidth(*data_[i]) / 2));
    mostRight = std::max(mostRight, pochernin::getX(*data_[i]) + (pochernin::getWidth(*data_[i]) / 2));
    mostUp = std::max(mostUp, pochernin::getY(*data_[i]) + (pochernin::getHeight(*data_[i]) / 2));
    mostDown = std::min(mostDown, pochernin::getY(*data_[i]) - (pochernin::getHeight(*data_[i]) / 2));
  }
  double width = mostRight - mostLeft;
  double height = mostUp - mostDown;
  return {width, height, {mostRight - (width / 2), mostUp - (height / 2)}};
}

void pochernin::CompositeShape::move(const pochernin::point_t& destination)
{
  double dx = destination.x - pochernin::getX(*this);
  double dy = destination.y - pochernin::getY(*this);;
  for (size_t i = 0; i < size_; i++)
  {
    data_[i]->move(dx, dy);
  }
}

void pochernin::CompositeShape::move(const double dx, const double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    data_[i]->move(dx, dy);
  }
}

void pochernin::CompositeShape::push_back(const std::shared_ptr< Shape > shape)
{
  if (size_ == capacity_)
  {
    capacity_++;
    std::unique_ptr< std::shared_ptr< Shape >[] > newData(std::make_unique< std::shared_ptr< Shape >[] >(capacity_));
    for (size_t i = 0; i < size_; i++)
    {
      newData[i] = std::move(data_[i]);
    }
    data_.reset();
    data_ = std::move(newData);
  }

  data_[size_] = shape;
  size_++;
}

void pochernin::CompositeShape::pop_back()
{
  if (size_ == 0)
  {
    throw std::logic_error("Pop back empty CompositeShape");
  }

  size_--;
  data_[size_].reset();
}

size_t pochernin::CompositeShape::size() const
{
  return size_;
}

size_t pochernin::CompositeShape::capacity() const
{
  return capacity_;
}

void pochernin::CompositeShape::swap(CompositeShape& other) noexcept
{
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
  std::swap(data_, other.data_);
}

void pochernin::CompositeShape::doScale(const double factor)
{
  pochernin::point_t centerPos = getFrameRect().pos;
  for (size_t i = 0; i < size_; i++)
  {
    data_[i]->scale(factor);
    double dx = pochernin::getX(*data_[i]) - centerPos.x;
    double dy = pochernin::getY(*data_[i]) - centerPos.y;
    data_[i]->move({centerPos.x + (dx * factor), centerPos.y + (dy * factor)});
  }
}

void pochernin::swap(CompositeShape& cs1, CompositeShape& cs2) noexcept
{
  cs1.swap(cs2);
}

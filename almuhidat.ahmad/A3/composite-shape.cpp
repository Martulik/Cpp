#include "composite-shape.hpp"
#include <stdexcept>

using shared = std::shared_ptr<almuhidat::Shape >;

almuhidat::CompositeShape::CompositeShape(shared other):
  size_(0),
  capacity_(2),
  data_(std::make_unique< shared[] >(capacity_))
{
  data_[size_] = std::move(other);
  size_++;
}

almuhidat::CompositeShape::CompositeShape(const CompositeShape &src):
  size_(src.size_),
  capacity_(src.capacity_),
  data_(std::make_unique< shared[] >(src.size_))
{
  for (size_t i = 0; i < size_; i++)
  {
    data_[i] = src.data_[i]->clone();
  }
}

shared almuhidat::CompositeShape::operator[](const size_t index) const
{
  if (index > size_)
  {
    throw std::out_of_range("Out of range");
  }
  return data_[index];
}

void almuhidat::CompositeShape::pushBack(shared &source)
{
  if (capacity_ == size_)
  {
    reserve(capacity_ * 2);
  }
  data_[size_++] = std::move_if_noexcept(source);
}

void almuhidat::CompositeShape::popBack()
{
  if (size_ == 1)
  {
    throw std::out_of_range("Array can not be empty");
  }
  data_[size_ - 1].reset();
  size_--;
}

double almuhidat::CompositeShape::getArea() const
{
  double area = 0;
  for (size_t i = 0; i < size_; i++)
  {
    area += data_[i]->getArea();
  }
  return area;
}

almuhidat::rectangle_t almuhidat::CompositeShape::getFrameRect() const
{
  double minX = {getX(*data_[0]) - getWidth(*data_[0]) / 2};
  double minY = {getY(*data_[0]) - getHeight(*data_[0]) / 2};
  double maxX = {getX(*data_[0]) + getWidth(*data_[0]) / 2};
  double maxY = {getY(*data_[0]) + getHeight(*data_[0]) / 2};
  almuhidat::point_t minXY{minX, minY};
  almuhidat::point_t maxXY{maxX, maxY};
  for (std::size_t i = 1; i < size_; i++)
  {
    minXY = {std::min(minXY.x, (getX(*data_[i]) - getWidth(*data_[i]) / 2)),
             std::min(minXY.y, (getY(*data_[i]) - getHeight(*data_[i]) / 2))};
    maxXY = {std::max(maxXY.x, (getX(*data_[i]) + getWidth(*data_[i]) / 2)),
             std::max(maxXY.y, (getY(*data_[i]) + getHeight(*data_[i]) / 2))};
  }
  double width = maxXY.x - minXY.x;
  double height = maxXY.y - minXY.y;
  almuhidat::point_t pos{(maxXY.x + minXY.x) / 2, (maxXY.y + minXY.y) / 2};
  return {width, height, pos};
}

size_t almuhidat::CompositeShape::size() const
{
  return size_;
}

size_t almuhidat::CompositeShape::capacity() const
{
  return capacity_;
}

void almuhidat::CompositeShape::move(const almuhidat::point_t &point)
{
  move(point.x - getX(*this), point.y - getY(*this));
}

void almuhidat::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    data_[i]->move(dx, dy);
  }
}

std::string almuhidat::CompositeShape::getName() const
{
  return "Composite shape";
}

void almuhidat::CompositeShape::scaleShape(double k)
{
  almuhidat::point_t totalPos = getFrameRect().pos;
  for (size_t i = 0; i < size_; i++)
  {
    double dx = getX(*data_[i]) - totalPos.x;
    double dy = getY(*data_[i]) - totalPos.y;
    data_[i]->move({totalPos.x + dx * k, totalPos.y + dy * k});
    data_[i]->scale(k);
  }
}

void almuhidat::CompositeShape::reserve(size_t capacity)
{

  if (capacity > capacity_)
  {
    almuhidat::CompositeShape tempArr(*this);
    std::unique_ptr< shared[] > array(std::make_unique< shared[] >(capacity));
    for (size_t i = 0; i < size_; ++i)
    {
      array[i] = std::move_if_noexcept(data_[i]);
    }
    tempArr.data_ = std::move_if_noexcept(array);
    tempArr.capacity_ = capacity;
    swap(tempArr);
  }
}

void almuhidat::CompositeShape::swap(CompositeShape &other) noexcept
{
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
  std::swap(data_, other.data_);
}

shared almuhidat::CompositeShape::clone() const
{
  return std::make_shared< CompositeShape >(*this);
}

std::shared_ptr< almuhidat::Shape > almuhidat::CompositeShape::at(size_t i)
{
  if (size_ < i)
  {
    throw std::out_of_range("Wrong index");
  }
  return data_[i];
}

std::shared_ptr< const almuhidat::Shape > almuhidat::CompositeShape::at(size_t i) const
{
  if (size_ < i)
  {
    throw std::out_of_range("Wrong index");
  }
  return data_[i];
}
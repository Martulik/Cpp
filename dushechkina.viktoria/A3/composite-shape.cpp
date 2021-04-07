#include "composite-shape.hpp"

#include <stdexcept>
#include <memory>

namespace vika = dushechkina;

vika::CompositeShape::CompositeShape(const CompositeShape& src):
  size_(src.size_),
  capacity_(src.capacity_),
  arr_(std::make_unique< shapePtr[] >(src.size_))
{
  for (size_t i = 0; i < size_; i++)
  {
    arr_[i] = src.arr_[i]->clone();
  }
}

vika::CompositeShape::CompositeShape(shapePtr src):
  size_(1),
  capacity_(2),
  arr_(std::make_unique< shapePtr[] >(capacity_))
{
  if (!src)
  {
    throw std::invalid_argument("The shape cannot be nullptr");
  }
  arr_[0] = std::move(src);
}

vika::CompositeShape& vika::CompositeShape::operator=(const CompositeShape& src)
{
  CompositeShape temp(src);
  swap(temp);
  return *this;
}

double vika::CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    area += arr_[i]->getArea();
  }
  return area;
}

vika::rectangle_t vika::CompositeShape::getFrameRect() const
{
  double left = getX(*arr_[0]) - getWidth(*arr_[0]) / 2;
  double right = getX(*arr_[0]) + getWidth(*arr_[0]) / 2;
  double up = getY(*arr_[0]) - getHeight(*arr_[0]) / 2;
  double down = getY(*arr_[0]) + getHeight(*arr_[0]) / 2;
  for (size_t i = 1; i < size_; i++)
  {
    left = std::min(left, getX(*arr_[i]) - (getWidth(*arr_[i]) / 2));
    right = std::max(right, getX(*arr_[i]) + (getWidth(*arr_[i]) / 2));
    up = std::max(up, getY(*arr_[i]) + (getHeight(*arr_[i]) / 2));
    down = std::min(down, getY(*arr_[i]) - (getHeight(*arr_[i]) / 2));
  }
  double width = right - left;
  double height = up - down;
  return { width, height, {right - (width / 2), up - (height / 2)} };
}

void vika::CompositeShape::move(const point_t& pos)
{
  move(pos.x - getX(*this), pos.y - getY(*this));
}

void vika::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    arr_[i]->move(dx, dy);
  }
}

void vika::CompositeShape::swap(CompositeShape& src) noexcept
{
  std::swap(size_, src.size_);
  std::swap(capacity_, src.capacity_);
  std::swap(arr_, src.arr_);
}


void vika::CompositeShape::reserve(size_t cap)
{
  if (cap > capacity_)
  {
    arr srcArray(std::make_unique< shapePtr[] >(cap));
    CompositeShape tShape(*this);
    for (size_t i = 0; i < size_; i++)
    {
      srcArray[i] = std::move_if_noexcept(arr_[i]);
    }
    tShape.arr_ = std::move_if_noexcept(srcArray);
    tShape.capacity_ = cap;
    swap(tShape);
  }
}

void vika::CompositeShape::popBack()
{
  if (size_ == 1)
  {
    throw std::logic_error("Must contain at least one shape for pop back");
  }
  arr_[--size_].reset();
}

void vika::CompositeShape::pushBack(shapePtr src)
{
  if (!src)
  {
    throw std::invalid_argument("The shape cannot be nullptr");
  }
  if (capacity_ == size_)
  {
    reserve(capacity_ * 2);
  }
  arr_[size_++] = std::move(src);
}

size_t vika::CompositeShape::size() const
{
  return size_;
}

size_t vika::CompositeShape::capacity() const
{
  return capacity_;
}

std::shared_ptr< vika::Shape > vika::CompositeShape::at(size_t index) const
{
  if (index >= size_)
  {
    throw std::out_of_range("The value has gone out of bounds of the array");
  }
  return arr_[index];
}

std::shared_ptr< vika::Shape > vika::CompositeShape::clone() const
{
  return std::make_shared< CompositeShape >(*this);
}

void vika::CompositeShape::doScale(const double ratio)
{
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i < size_; i++)
  {
    double dx = getX(*arr_[i]) - center.x;
    double dy = getY(*arr_[i]) - center.y;
    arr_[i]->move({ center.x + dx * ratio, center.y + dy * ratio });
    arr_[i]->scale(ratio);
  }
}

void dushechkina::swap(CompositeShape& first, CompositeShape& second) noexcept
{
  first.swap(second);
}

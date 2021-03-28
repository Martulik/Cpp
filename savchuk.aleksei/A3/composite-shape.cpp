#include "composite-shape.hpp"

#include <cassert>
#include <algorithm>

namespace lab = savchuk;
using value_type = std::unique_ptr< lab::Shape >;
using this_type = lab::CompositeShape;

lab::CompositeShape::CompositeShape(std::initializer_list< lab::Shape* > src):
  size_(src.size())
{
  assert(size_ == 0 && "The composite shape cannot be empty");
  arr_ = new value_type[size_];
  size_t i = 0;
  std::initializer_list< lab::Shape* >::iterator it = src.begin();
  while (it != src.end())
  {
    assert(*it != nullptr && "The pointer to shape cannot be nullptr");
    arr_[i++] = (*it)->clone();
    ++it;
  }
}

lab::CompositeShape::CompositeShape(const this_type& src):
  size_(src.size_),
  arr_(new value_type[size_])
{
  for (size_t i = 0; i < size_; ++i)
  {
    arr_[i] = src.arr_[i]->clone();
  }
}

lab::CompositeShape::CompositeShape(this_type&& src) noexcept:
  size_(src.size_),
  arr_(src.arr_)
{
  src.arr_ = nullptr;
}

lab::CompositeShape::~CompositeShape()
{
  delete[] arr_;
}

this_type& lab::CompositeShape::operator=(const this_type& rhs)
{
  if (this != std::addressof(rhs))
  {
    size_ = rhs.size_;
    delete[] arr_;
    arr_ = new value_type[size_];
    for (size_t i = 0; i < size_; ++i)
    {
      arr_[i] = rhs.arr_[i]->clone();
    }
  }
  return *this;
}

this_type& lab::CompositeShape::operator=(this_type&& rhs) noexcept
{
  if (this != std::addressof(rhs))
  {
    size_ = rhs.size_;
    delete[] arr_;
    arr_ = rhs.arr_;
    rhs.arr_ = nullptr;
  }
  return *this;
}

double lab::CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size_; ++i)
  {
    area += arr_[i]->getArea();
  }
  return area;
}

lab::rectangle_t lab::CompositeShape::getFrameRect() const
{
  lab::rectangle_t rect = arr_[0]->getFrameRect();
  double maxX = rect.pos.x + rect.width / 2;
  double minX = rect.pos.x - rect.width / 2;
  double maxY = rect.pos.y + rect.height / 2;
  double minY = rect.pos.y - rect.height / 2;
  for (size_t i = 1; i < size_; ++i)
  {
    rect = arr_[i]->getFrameRect();
    maxX = std::max(maxX, rect.pos.x + rect.width / 2);
    minX = std::min(minX, rect.pos.x - rect.width / 2);
    maxY = std::max(maxY, rect.pos.y + rect.height / 2);
    minY = std::min(minY, rect.pos.y - rect.height / 2);
  }
  double width = maxX - minX;
  double height = maxY - minY;
  lab::point_t pos = { minX + width / 2, minY + height / 2 };
  return { pos, width, height };
}

void lab::CompositeShape::move(const lab::point_t& point)
{
  lab::point_t pos = getFrameRect().pos;
  double dx = point.x - pos.x;
  double dy = point.y - pos.y;
  for (size_t i = 0; i < size_; ++i)
  {
    arr_[i]->move(dx, dy);
  }
}

void lab::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; ++i)
  {
    arr_[i]->move(dx, dy);
  }
}

void lab::CompositeShape::doScale(double scaleFactor)
{
  lab::point_t pos = getFrameRect().pos;
  for (size_t i = 0; i < size_; ++i)
  {
    lab::point_t point = (arr_[i]->getFrameRect()).pos;
    double dx = (scaleFactor - 1) * (point.x - pos.x);
    double dy = (scaleFactor - 1) * (point.y - pos.y);
    arr_[i]->move(dx, dy);
    arr_[i]->scale(scaleFactor);
  }
}

std::unique_ptr< lab::Shape > lab::CompositeShape::clone() const
{
  return std::unique_ptr< lab::Shape >(new lab::CompositeShape(*this));
}

#include "composite-shape.hpp"

#include <cassert>
#include <stdexcept>
#include <algorithm>

namespace lab = savchuk;
using value_type = std::unique_ptr< lab::Shape >;
using this_type = lab::CompositeShape;

lab::CompositeShape::CompositeShape(std::initializer_list< lab::Shape* > src):
  size_(src.size()),
  arr_(new value_type[size_])
{
  size_t i = 0;
  std::initializer_list< lab::Shape* >::iterator it = src.begin();
  while (it != src.end())
  {
    lab::Shape* shape = *it;
    assert(shape != nullptr && "The pointer to shape cannot be nullptr");
    arr_[i++] = shape->clone();
    ++it;
  }
}

lab::CompositeShape::CompositeShape(const this_type& src):
  size_(src.size_),
  arr_(new value_type[size_])
{
  for (size_t i = 0; i < size_; ++i)
  {
    lab::Shape* shape = src.arr_[i].get();
    arr_[i] = shape->clone();
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
      lab::Shape* shape = rhs.arr_[i].get();
      arr_[i] = shape->clone();
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
    lab::Shape* shape = arr_[i].get();
    area += shape->getArea();
  }
  return area;
}

lab::rectangle_t lab::CompositeShape::getFrameRect() const
{
  lab::Shape* shape = arr_[0].get();
  lab::rectangle_t rect = shape->getFrameRect();
  double maxX = rect.pos.x + rect.width / 2;
  double minX = rect.pos.x - rect.width / 2;
  double maxY = rect.pos.y + rect.height / 2;
  double minY = rect.pos.y - rect.height / 2;
  for (size_t i = 1; i < size_; ++i)
  {
    shape = arr_[i].get();
    rect = shape->getFrameRect();
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
  lab::point_t pos = (this->getFrameRect()).pos;
  double dx = point.x - pos.x;
  double dy = point.y - pos.y;
  for (size_t i = 0; i < size_; ++i)
  {
    lab::Shape* shape = arr_[i].get();
    shape->move(dx, dy);
  }
}

void lab::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; ++i)
  {
    lab::Shape* shape = arr_[i].get();
    shape->move(dx, dy);
  }
}

void lab::CompositeShape::scale(double scaleFactor)
{
  if (scaleFactor <= 0)
  {
    throw std::invalid_argument("The scale factor must be positive");
  }
  lab::point_t pos = (this->getFrameRect()).pos;
  for (size_t i = 0; i < size_; ++i)
  {
    lab::Shape* shape = arr_[i].get();
    lab::point_t point = (shape->getFrameRect()).pos;
    double dx = (scaleFactor - 1) * (point.x - pos.x);
    double dy = (scaleFactor - 1) * (point.y - pos.y);
    shape->move(dx, dy);
    shape->scale(scaleFactor);
  }
}

std::unique_ptr< lab::Shape > lab::CompositeShape::clone() const
{
  return std::unique_ptr< lab::Shape >(new lab::CompositeShape(*this));
}

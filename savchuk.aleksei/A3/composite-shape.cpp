#include "composite-shape.hpp"

#include <cassert>
#include <utility>
#include <algorithm>
#include <limits>

#include "shape-utility.hpp"

namespace lab = savchuk;
using valueType = std::unique_ptr< lab::Shape >;
using thisType = lab::CompositeShape;

lab::CompositeShape::CompositeShape(std::initializer_list< const lab::Shape* > src):
  size_(src.size())
{
  assert(size_ != 0 && "The composite shape cannot be empty");
  arr_ = new valueType[size_];
  size_t i = 0;
  std::initializer_list< const Shape* >::const_iterator it = src.begin();
  while (it != src.end())
  {
    assert(*it != nullptr && "The pointer to shape cannot be nullptr");
    arr_[i++] = (*it)->clone();
    ++it;
  }
}

lab::CompositeShape::CompositeShape(const thisType& src):
  size_(src.size_),
  arr_(new valueType[size_])
{
  for (size_t i = 0; i < size_; ++i)
  {
    arr_[i] = src.arr_[i]->clone();
  }
}

lab::CompositeShape::CompositeShape(thisType&& src) noexcept:
  size_(src.size_),
  arr_(src.arr_)
{
  src.arr_ = nullptr;
}

lab::CompositeShape::~CompositeShape()
{
  delete[] arr_;
}

thisType& lab::CompositeShape::operator=(const thisType& rhs)
{
  thisType temp(rhs);
  swap(temp);
  return *this;
}

thisType& lab::CompositeShape::operator=(thisType&& rhs) noexcept
{
  thisType temp(rhs);
  swap(temp);
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
  double maxX = std::numeric_limits< double >::lowest();
  double minX = std::numeric_limits< double >::max();
  double maxY = std::numeric_limits< double >::lowest();
  double minY = std::numeric_limits< double >::max();
  for (size_t i = 0; i < size_; ++i)
  {
    maxX = std::max(maxX, getPosX(*arr_[i]) + getWidth(*arr_[i]) / 2);
    minX = std::min(minX, getPosX(*arr_[i]) - getWidth(*arr_[i]) / 2);
    maxY = std::max(maxY, getPosY(*arr_[i]) + getHeight(*arr_[i]) / 2);
    minY = std::min(minY, getPosY(*arr_[i]) - getHeight(*arr_[i]) / 2);
  }
  double width = maxX - minX;
  double height = maxY - minY;
  point_t pos = { minX + width / 2, minY + height / 2 };
  return { pos, width, height };
}

void lab::CompositeShape::move(const lab::point_t& point)
{
  double dx = point.x - getPosX(*this);
  double dy = point.y - getPosY(*this);
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
  double posX = getPosX(*this);
  double posY = getPosY(*this);
  for (size_t i = 0; i < size_; ++i)
  {
    double dx = (scaleFactor - 1) * (getPosX(*arr_[i]) - posX);
    double dy = (scaleFactor - 1) * (getPosY(*arr_[i]) - posY);
    arr_[i]->move(dx, dy);
    arr_[i]->scale(scaleFactor);
  }
}

std::unique_ptr< lab::Shape > lab::CompositeShape::clone() const
{
  return std::make_unique< CompositeShape >(*this);
}

void lab::CompositeShape::swap(thisType& rhs)
{
  std::swap(size_, rhs.size_);
  std::swap(arr_, rhs.arr_);
}

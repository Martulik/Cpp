#include "composite-shape.hpp"

#include <cassert>
#include <utility>
#include <algorithm>

namespace fer = ferapontov;
using ValueType = std::unique_ptr< fer::Shape >;
using ThisType = fer::CompositeShape;

fer::CompositeShape::CompositeShape(std::initializer_list< ValueType > src):
  size_(src.size())
{
  assert(size_ != 0 && "Composite Shape can not be empty");
  arr_ = std::make_unique< ValueType[] >(size_);
  size_t i = 0;
  std::initializer_list< ValueType >::const_iterator it = src.begin();
  while(it != src.end())
  {
    assert(*it && "The pointer to shape can not be nullptr");
    arr_[i++] = (*it)->clone();
    ++it;
  }
}

fer::CompositeShape::CompositeShape(const ThisType& src):
  size_(src.size_),
  arr_(std::make_unique< ValueType[] >(size_))
{
  for(size_t i = 0; i < size_; i++)
  {
    arr_[i] = src.arr_[i]->clone();
  }
}

ThisType& fer::CompositeShape::operator=(const ThisType& src)
{
  ThisType temp(src);
  swap(temp);
  return *this;
}

ThisType& fer::CompositeShape::operator=(ThisType&& src) noexcept
{
  ThisType temp(src);
  swap(temp);
  return *this;
}

std::string fer::CompositeShape::getName() const
{
  return "Composite Shape";
}

double fer::CompositeShape::getArea() const
{
  double area = 0;
  for (size_t i = 0; i < size_; i++)
  {
    area += arr_[i]->getArea();
  }

  return area;
}

fer::rectangle_t fer::CompositeShape::getFrameRect() const
{
  double maxY = getY(*arr_[0]) + getHeight(*arr_[0]) / 2;
  double minY = getY(*arr_[0]) - getHeight(*arr_[0]) / 2;
  double maxX = getX(*arr_[0]) + getWidth(*arr_[0]) / 2;
  double minX = getX(*arr_[0]) - getWidth(*arr_[0]) / 2;

  for (size_t i = 1; i < size_; i++)
  {
    maxX = std::max(maxX, getX(*arr_[i]) + getWidth(*arr_[i]) / 2);
    minX = std::min(minX, getX(*arr_[i]) - getWidth(*arr_[i]) / 2);
    maxY = std::max(maxY, getY(*arr_[i]) + getHeight(*arr_[i]) / 2);
    minY = std::min(minY, getY(*arr_[i]) - getHeight(*arr_[i]) / 2);
  }

  double width = maxX - minX;
  double height = maxY - minY;
  point_t pos = { minX + width / 2, minY + height / 2 };
  return {width, height, pos};
}

void fer::CompositeShape::move(const point_t& pos)
{
  int dx = pos.x - getX(*this);
  int dy = pos.y - getY(*this);
  for (size_t i = 0; i < size_; ++i)
  {
    arr_[i]->move(dx, dy);
  }
}

void fer::CompositeShape::move(const double dx, const double dy)
{
  for (size_t i = 0; i < size_; ++i)
  {
    arr_[i]->move(dx, dy);
  }
}

std::unique_ptr< fer::Shape > fer::CompositeShape::clone() const
{
  return std::make_unique< CompositeShape >(*this);
}

void fer::CompositeShape::swap(ThisType& src)
{
  std::swap(size_, src.size_);
  std::swap(arr_, src.arr_);
}

void fer::CompositeShape::doScale(const double k)
{
  double posX = getX(*this);
  double posY = getY(*this);
  for(size_t i = 0; i < size_; ++i)
  {
    double dx = (k - 1) * (getX(*arr_[i]) - posX);
    double dy = (k - 1) * (getY(*arr_[i]) - posY);
    arr_[i]->move(dx, dy);
    arr_[i]->scale(k);
  }
}

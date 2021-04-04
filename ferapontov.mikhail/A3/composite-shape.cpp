#include "composite-shape.hpp"

#include <cassert>
#include <utility>
#include <algorithm>

namespace fer = ferapontov;
using value_type = std::unique_ptr< fer::Shape >;
using this_type = fer::CompositeShape;

fer::CompositeShape::CompositeShape(std::initializer_list< const Shape* > src):
  size_(src.size())
{
  assert(size_ != 0 && "Composite Shape can not be empty");
  arr_ = new value_type[size_];
  size_t i = 0;
  std::initializer_list< const Shape* >::const_iterator it = src.begin();
  while(it != src.end())
  {
    assert(*it != nullptr && "The pointer to shape can not be nullptr");
    arr_[i++] = (*it)->clone();
    ++it;
  }
}

fer::CompositeShape::~CompositeShape()
{
  delete arr_;
}

double fer::CompositeShape::getArea() const
{
  double area = 0;
  for (size_t i = 0; i <= size_; i++)
  {
    area += arr_[i]->getArea();
  }
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
  for (size_t i = 0; i < size_; ++i)
  {
    arr_[i]->move(pos);
  }
}

void fer::CompositeShape::move(const double dx, const double dy)
{
  for (size_t i = 0; i < size_; ++i)
  {
    arr_[i]->move(dx, dy);
  }
}

void fer::CompositeShape::scale(const double k)
{
  for(size_t i = 0; i< size_; ++i)
  {
    arr_[i]->scale(k);
  }
}
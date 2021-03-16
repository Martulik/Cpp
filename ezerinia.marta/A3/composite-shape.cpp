#include "composite-shape.hpp"
#include <stdexcept>

ezerinia::CompositeShape::CompositeShape():
  size_(0),
  data_(nullptr)
{
}

std::shared_ptr< ezerinia::Shape > ezerinia::CompositeShape::operator[](const std::size_t index) const
{
  if (index >= size_)
  {
    throw std::invalid_argument("Index outside the array");
  }
  return data_[index];
}

void ezerinia::CompositeShape::pushBack(std::shared_ptr< Shape > src)
{
  std::unique_ptr< std::shared_ptr< Shape >[] > temp(std::make_unique< std::shared_ptr< Shape >[] >(size_ + 1));
  for (std::size_t i = 0; i < size_; i++)
  {
    temp[i] = std::move(data_[i]);
  }
  temp[size_] = std::move(src);
  size_++;
  data_ = std::move(temp);
}

double ezerinia::CompositeShape::getArea() const
{
  double totalArea = 0.0;
  for (std::size_t i = 0; i < size_; i++)
  {
    totalArea += data_[i]->getArea();
  }
  return totalArea;
}

ezerinia::rectangle_t ezerinia::CompositeShape::getFrameRect() const
{
  ezerinia::rectangle_t totalFrameRect = data_[0]->getFrameRect();
  ezerinia::point_t minXY = {totalFrameRect.pos.x - totalFrameRect.width / 2,
                             totalFrameRect.pos.y - totalFrameRect.height / 2};
  ezerinia::point_t maxXY = {totalFrameRect.pos.x + totalFrameRect.width / 2,
                             totalFrameRect.pos.y + totalFrameRect.height / 2};
  for (std::size_t i = 1; i < size_; i++)
  {
    rectangle_t temp = data_[i]->getFrameRect();
    minXY = {std::min(minXY.x, (temp.pos.x - temp.width / 2)),
             std::min(minXY.y, (temp.pos.y - temp.height / 2))};
    maxXY = {std::max(maxXY.x, (temp.pos.x + temp.width / 2)),
             std::max(maxXY.y, (temp.pos.y + temp.height / 2))};
  }
  totalFrameRect = {maxXY.x - minXY.x, maxXY.y - minXY.y,
                    {(maxXY.x + minXY.x) / 2, (maxXY.y + minXY.y) / 2}};
  return totalFrameRect;
}

void ezerinia::CompositeShape::move(const ezerinia::point_t &point)
{
  move(point.x - getFrameRect().pos.x, point.y - getFrameRect().pos.y);
}

void ezerinia::CompositeShape::move(double dx, double dy)
{
  for (std::size_t i = 0; i < size_; i++)
  {
    data_[i]->move(dx, dy);
  }
}

void ezerinia::CompositeShape::scale(double k)
{
  if (k < 0.0)
  {
    throw std::invalid_argument("The coefficient of scale must be non-negative");
  }
  point_t posOfFrameRect = getFrameRect().pos;
  for (std::size_t i = 0; i < size_; i++)
  {
    double dx = data_[i]->getFrameRect().pos.x - posOfFrameRect.x;
    double dy = data_[i]->getFrameRect().pos.y - posOfFrameRect.y;
    data_[i]->move({posOfFrameRect.x + dx * k, posOfFrameRect.y + dy * k});
    data_[i]->scale(k);
  }
}

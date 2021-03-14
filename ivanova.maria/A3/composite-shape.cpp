#include "composite-shape.hpp"
#include <cassert>

ivanova::CompositeShape::CompositeShape():
  size_(0),
  data_(nullptr)
{
}

std::shared_ptr< ivanova::Shape > ivanova::CompositeShape::operator [](const size_t index) const
{
  assert(index < size_);
  return data_[index];
}

void ivanova::CompositeShape::add(std::shared_ptr< Shape > source)
{
  std::unique_ptr< std::shared_ptr< Shape >[] > temp(std::make_unique< std::shared_ptr< Shape >[] >(size_ + 1));
  for (size_t i = 0; i < size_; i++)
  {
    temp[i] = std::move(data_[i]);
  }
  temp[size_] = std::move(source);
  size_++;
  data_ = std::move(temp);
}

double ivanova::CompositeShape::getArea() const
{
  assert(size_ > 0);
  double area = 0;
  for (size_t i = 0; i < size_; i++)
  {
    area += data_[i]->getArea();
  }
  return area;
}

ivanova::rectangle_t ivanova::CompositeShape::getFrameRect() const
{
  assert(size_ > 0);
  ivanova::rectangle_t frameRect = data_[0]->getFrameRect();
  double minX = {frameRect.pos.x - frameRect.width / 2};
  double minY = {frameRect.pos.y - frameRect.height / 2};
  double maxX = {frameRect.pos.x + frameRect.width / 2};
  double maxY = {frameRect.pos.y + frameRect.height / 2};
  ivanova::point_t minXY {minX, minY};
  ivanova::point_t maxXY {maxX, maxY};
  for (std::size_t i = 1; i < size_; i++)
  {
    ivanova::rectangle_t temp = data_[i]->getFrameRect();
    minXY = {std::min(minXY.x, (temp.pos.x - temp.width / 2)),
             std::min(minXY.y, (temp.pos.y - temp.height / 2))};
    maxXY = {std::max(maxXY.x, (temp.pos.x + temp.width / 2)),
             std::max(maxXY.y, (temp.pos.y + temp.height / 2))};
  }
  double width = maxXY.x - minXY.x;
  double height = maxXY.y - minXY.y;
  ivanova::point_t pos{(maxXY.x + minXY.x) / 2, (maxXY.y + minXY.y) / 2};
  frameRect = {width, height, pos};
  return frameRect;
}

size_t ivanova::CompositeShape::getSize() const
{
  return size_;
}

void ivanova::CompositeShape::move(const ivanova::point_t &point)
{
  assert(size_ > 0);
  move(point.x - getFrameRect().pos.x, point.y - getFrameRect().pos.y);
}

void ivanova::CompositeShape::move(double dx, double dy)
{
  assert(size_ > 0);
  for (size_t i = 0; i < size_; i++)
  {
    data_[i]->move(dx, dy);
  }
}

std::string ivanova::CompositeShape::getName() const
{
  return "Composite shape";
}

void ivanova::CompositeShape::scale(double k)
{
  assert(size_ > 0 && k > 0);
  ivanova::point_t totalPos = getFrameRect().pos;
  for (size_t i = 0; i < size_; i++)
  {
    double dx = data_[i]->getFrameRect().pos.x - totalPos.x;
    double dy = data_[i]->getFrameRect().pos.y - totalPos.y;
    data_[i]->move({totalPos.x + dx * k, totalPos.y + dy * k});
    data_[i]->scale(k);
  }
}

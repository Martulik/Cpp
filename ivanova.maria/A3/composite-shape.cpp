#include "composite-shape.hpp"
#include <cassert>

using shared = std::shared_ptr<ivanova::Shape>;

ivanova::CompositeShape::CompositeShape(shared other):
  size_(0),
  capacity_(2),
  data_(std::make_unique<shared[]>(capacity_))
{
  data_[size_] = std::move(other);
  size_++;
}

ivanova::CompositeShape::CompositeShape(const CompositeShape &src):
  size_(src.size_),
  capacity_(src.capacity_),
  data_(std::make_unique< shared[] >(src.size_))
{
  for (size_t i = 0; i < size_; i++)
  {
    data_[i] = src.data_[i]->clone();
  }
}

shared ivanova::CompositeShape::operator[](const size_t index) const
{
  assert(index < size_);
  return data_[index];
}

void ivanova::CompositeShape::pushBack(shared &source)
{
  if (capacity_ == size_)
  {
    reserve(capacity_ * 2);
    size_++;
  }
  data_[size_] = std::move_if_noexcept(source);
}

void ivanova::CompositeShape::popBack()
{
  assert(size_ > 1);
  data_[size_--].reset();
}

double ivanova::CompositeShape::getArea() const
{
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
  double minX = {getX(*data_[0]) - getWidth(*data_[0]) / 2};
  double minY = {getY(*data_[0]) - getHeight(*data_[0]) / 2};
  double maxX = {getX(*data_[0]) + getWidth(*data_[0]) / 2};
  double maxY = {getY(*data_[0]) + getHeight(*data_[0]) / 2};
  ivanova::point_t minXY{minX, minY};
  ivanova::point_t maxXY{maxX, maxY};
  for (std::size_t i = 1; i < size_; i++)
  {
    minXY = {std::min(minXY.x, (getX(*data_[i]) - getWidth(*data_[i]) / 2)),
             std::min(minXY.y, (getY(*data_[i]) - getHeight(*data_[i]) / 2))};
    maxXY = {std::max(maxXY.x, (getX(*data_[i]) + getWidth(*data_[i]) / 2)),
             std::max(maxXY.y, (getY(*data_[i]) + getHeight(*data_[i]) / 2))};
  }
  double width = maxXY.x - minXY.x;
  double height = maxXY.y - minXY.y;
  ivanova::point_t pos{(maxXY.x + minXY.x) / 2, (maxXY.y + minXY.y) / 2};
  return {width, height, pos};
}

size_t ivanova::CompositeShape::size() const
{
  return size_;
}

size_t ivanova::CompositeShape::capacity() const
{
  return capacity_;
}

void ivanova::CompositeShape::move(const ivanova::point_t &point)
{
  move(point.x - getX(*this), point.y - getY(*this));
}

void ivanova::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    data_[i]->move(dx, dy);
  }
}

std::string ivanova::CompositeShape::getName() const
{
  return "Composite shape";
}

void ivanova::CompositeShape::scaleShape(double k)
{
  assert(k > 0);
  ivanova::point_t totalPos = getFrameRect().pos;
  for (size_t i = 0; i < size_; i++)
  {
    double dx = getX(*data_[i]) - totalPos.x;
    double dy = getY(*data_[i]) - totalPos.y;
    data_[i]->move({totalPos.x + dx * k, totalPos.y + dy * k});
    data_[i]->scaleShape(k);
  }
}

void ivanova::CompositeShape::reserve(size_t capacity)
{

  if (capacity > capacity_)
  {
    ivanova::CompositeShape tempArr(*this);
    std::unique_ptr< shared[] > array(std::make_unique< shared[] >(capacity));
    for (size_t i = 0; i < size_; ++i)
    {
      array[i] = std::move(data_[i]);
    }
    tempArr.data_ = std::move(array);
    tempArr.capacity_ = capacity;
    swap(tempArr);
  }
}

void ivanova::CompositeShape::swap(CompositeShape &other) noexcept
{
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
  std::swap(data_, other.data_);
}

shared ivanova::CompositeShape::clone() const
{
  return std::make_shared< CompositeShape >(*this);
}

shared ivanova::CompositeShape::at(size_t i) const
{
  assert(i < size_);
  return data_[i];
}

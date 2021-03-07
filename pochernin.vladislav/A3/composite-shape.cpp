#include "composite-shape.hpp"

#include <memory>
#include <stdexcept>

#include "base-types.hpp"

pochernin::CompositeShape::CompositeShape():
  size_(0),
  data_(std::make_unique< std::shared_ptr< Shape >[] >(size_))
{}

pochernin::CompositeShape::CompositeShape(size_t size):
  size_(size),
  data_(std::make_unique< std::shared_ptr< Shape >[] >(size_))
{}

std::shared_ptr< pochernin::Shape >& pochernin::CompositeShape::operator[](size_t index) const
{
  return data_[index];
}

double pochernin::CompositeShape::getArea() const
{
  if (size_ == 0)
  {
    return 0.0;
  }
  double result = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    result += data_[i]->getArea();
  }
  return result;
}

pochernin::rectangle_t pochernin::CompositeShape::getFrameRect() const
{
  if (size_ == 0)
  {
    return {0.0, 0.0, {0.0, 0.0}};
  }
  double mostLeft = data_[0]->getFrameRect().pos.x - (data_[0]->getFrameRect().width / 2);
  double mostRight = data_[0]->getFrameRect().pos.x + (data_[0]->getFrameRect().width / 2);
  double mostUp = data_[0]->getFrameRect().pos.y + (data_[0]->getFrameRect().height / 2);
  double mostDown = data_[0]->getFrameRect().pos.y - (data_[0]->getFrameRect().height / 2);
  for (size_t i = 1; i < size_; i++)
  {
    mostLeft = std::min(mostLeft, data_[i]->getFrameRect().pos.x - (data_[i]->getFrameRect().width / 2));
    mostRight = std::max(mostRight, data_[i]->getFrameRect().pos.x + (data_[i]->getFrameRect().width / 2));
    mostUp = std::max(mostUp, data_[i]->getFrameRect().pos.y + (data_[i]->getFrameRect().height / 2));
    mostDown = std::min(mostDown, data_[i]->getFrameRect().pos.y - (data_[i]->getFrameRect().height / 2));
  }
  double width = mostRight - mostLeft;
  double height = mostUp - mostDown;
  return {width, height, {mostRight - (width / 2), mostUp - (height / 2)}};
}

void pochernin::CompositeShape::move(const pochernin::point_t& destination)
{
  double dx = destination.x - getFrameRect().pos.x;
  double dy = destination.y - getFrameRect().pos.y;
  for (size_t i = 0; i < size_; i++)
  {
    data_[i]->move(dx, dy);
  }
}

void pochernin::CompositeShape::move(const double dx, const double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    data_[i]->move(dx, dy);
  }
}

void pochernin::CompositeShape::scale(const double factor)
{
  if (factor < 0)
  {
    throw(std::invalid_argument("Negative factor"));
  }
  for (size_t i = 0; i < size_; i++)
  {
    data_[i]->scale(factor);
    point_t destination = {data_[i]->getFrameRect().pos.x * factor, data_[i]->getFrameRect().pos.y * factor};
    data_[i]->move(destination);
  }
}

void pochernin::CompositeShape::push_back(const std::shared_ptr<Shape> shape)
{
  std::unique_ptr< std::shared_ptr< Shape >[] > newData(std::make_unique< std::shared_ptr< Shape >[] >(size_ + 1));
  for (size_t i = 0; i < size_; i++)
  {
    newData[i] = std::move(data_[i]);
  }
  newData[size_] = shape;
  size_++;
  data_ = std::move(newData);
}

size_t pochernin::CompositeShape::getSize() const
{
  return size_;
}

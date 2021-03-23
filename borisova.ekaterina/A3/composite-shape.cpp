#include "composite-shape.hpp"
#include <stdexcept>

borisova::CompositeShape::CompositeShape(std::shared_ptr< borisova::Shape > source[], const int size):
  size_(size)
{
  if (size <= 0)
  {
    throw (std::invalid_argument("Negative size of array"));
  }
  data_ = std::make_unique< std::shared_ptr< Shape >[] >(size);
  for (int i = 0; i < size; i++)
  {
    data_[i] = source[i];
  }
}

borisova::CompositeShape::CompositeShape(CompositeShape&& src) noexcept:
  size_(src.size_)
{
  data_ = std::move(src.data_);
  src.size_ = 0;
  src.data_ = nullptr;
}

std::shared_ptr< borisova::Shape > borisova::CompositeShape::operator[] (int index) const
{
  if (!((index <= size_) && (index >= 0)))
  {
    throw (std::invalid_argument("Wrong index"));
  }
  return data_[index];
}

borisova::CompositeShape& borisova::CompositeShape::operator=(CompositeShape&& src) noexcept
{
  size_ = src.size_;
  data_ = std::move(src.data_);
  src.size_ = 0;
  src.data_ = nullptr;
  return *this;
}

double borisova::CompositeShape::getArea() const
{
  double sum = 0;
  for (int i = 0; i < size_; i++)
  {
    sum += data_[i]->getArea();
  }
  return sum;
}

borisova::rectangle_t borisova::CompositeShape::getFrameRect() const
{
  if (size_ == 0)
  {
    throw (std::invalid_argument("Wrong index"));
  }
  borisova::rectangle_t firstFrameRect = data_[0]->getFrameRect();
  double left = firstFrameRect.pos.x - firstFrameRect.width / 2;
  double right = firstFrameRect.pos.x + firstFrameRect.width / 2;
  double top = firstFrameRect.pos.y + firstFrameRect.height / 2;
  double bottom = firstFrameRect.pos.y - firstFrameRect.height / 2;

  for (int i = 0; i < size_; i++)
  {
    borisova::rectangle_t curFrameRect = data_[i]->getFrameRect();

    double leftBorder = curFrameRect.pos.x - curFrameRect.width / 2;
    double rightBorder = curFrameRect.pos.x + curFrameRect.width / 2;
    double topBorder = curFrameRect.pos.y + curFrameRect.height / 2;
    double bottomBorder = curFrameRect.pos.y - curFrameRect.height / 2;

    left = std::min(left, leftBorder);
    right = std::max(right, rightBorder);
    top = std::max(top, topBorder);
    bottom = std::min(bottom, bottomBorder);
  }
  return {right - left, top - bottom, {(right + left) / 2, (top + bottom) / 2}};
}

void borisova::CompositeShape::scale(double k)
{
  if (k <= 0)
  {
    throw (std::invalid_argument("Wrong coefficient"));
  }
  borisova::point_t pos = getFrameRect().pos;
  for (int i = 0; i < size_; i++)
  {
    double dx = data_[i]->getFrameRect().pos.x - pos.x;
    double dy = data_[i]->getFrameRect().pos.y - pos.y;
    data_[i]->move({ pos.x + dx * k, pos.y + dy * k });
    data_[i]->scale(k);
  }
}

void borisova::CompositeShape::move(const double dx, const double dy)
{
  for (int i = 0; i < size_; i++)
  {
    data_[i]->move(dx, dy);
  }
}

void borisova::CompositeShape::move(const borisova::point_t& dpos)
{
  move(dpos.x, dpos.y);
}

std::string borisova::CompositeShape::getName() const
{
  return "Composite Shape";
}

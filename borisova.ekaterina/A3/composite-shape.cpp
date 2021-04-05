#include "composite-shape.hpp"
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"
#include "test-variables.hpp"

namespace lab = borisova;

lab::CompositeShape::CompositeShape(const std::initializer_list < std::shared_ptr< lab::Shape > > source):
  size_(source.size()),
  data_(std::make_unique< std::shared_ptr< Shape >[] >(size_))
{
  int count = 0;
  if (size_ == 0)
  {
    throw (std::invalid_argument("Composite Shape mustn't be empty"));
  }
  for (const std::shared_ptr< Shape > elem: source)
  {
    if (elem == nullptr)
    {
      throw (std::invalid_argument("Element of Composite Shape mustn't be nullptr"));
    }
    data_[count] = elem->clone();
    count++;
  }
}

lab::CompositeShape::CompositeShape(const CompositeShape& src):
  size_(src.size_),
  data_(std::make_unique< std::shared_ptr< Shape >[] >(size_))
{
  for (size_t i = 0; i < size_; ++i)
  {
    data_[i] = src.data_[i]->clone();
  }
}

std::shared_ptr< lab::Shape > lab::CompositeShape::at(size_t indx)
{
  if (indx >= size_)
  {
    throw std::out_of_range("Index out of bounds");
  }
  return data_[indx];
}

std::shared_ptr< const lab::Shape > lab::CompositeShape::at(const size_t indx) const
{
  if (indx >= size_)
  {
    throw std::out_of_range("Index out of bounds");
  }
  return data_[indx];
}

lab::CompositeShape& lab::CompositeShape::operator=(const CompositeShape& src)
{
  CompositeShape temp(src);
  swap(temp);
  return *this;
}

double lab::CompositeShape::getArea() const
{
  double sum = 0;
  for (size_t i = 0; i < size_; i++)
  {
    sum += data_[i]->getArea();
  }
  return sum;
}

lab::rectangle_t lab::CompositeShape::getFrameRect() const
{
  double left = getLeft(*data_[0]);
  double right = getRight(*data_[0]);
  double top = getTop(*data_[0]);
  double bottom = getBottom(*data_[0]);

  for (size_t i = 0; i < size_; i++)
  {
    double leftBorder = getLeft(*data_[i]);
    double rightBorder = getRight(*data_[i]);
    double topBorder = getTop(*data_[i]);
    double bottomBorder = getBottom(*data_[i]);

    left = std::min(left, leftBorder);
    right = std::max(right, rightBorder);
    top = std::max(top, topBorder);
    bottom = std::min(bottom, bottomBorder);
  }
  return {right - left, top - bottom, {(right + left) / 2, (top + bottom) / 2}};
}

void lab::CompositeShape::move(const double dx, const double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    data_[i]->move(dx, dy);
  }
}

void lab::CompositeShape::move(const lab::point_t& dpos)
{
  move(dpos.x, dpos.y);
}

std::string lab::CompositeShape::getName() const
{
  return "Composite Shape";
}

void lab::CompositeShape::swap(CompositeShape& src) noexcept
{
  std::swap(size_, src.size_);
  std::swap(data_, src.data_);
}

std::shared_ptr< lab::Shape > lab::CompositeShape::clone() const
{
  return std::make_shared< CompositeShape >(*this);
}

size_t lab::CompositeShape::getSize() const
{
  return size_;
}

void lab::CompositeShape::doScale(double k)
{
  lab::point_t pos = getFrameRect().pos;
  for (size_t i = 0; i < size_; i++)
  {
    double dx = getX(*data_[i]) - pos.x;
    double dy = getY(*data_[i]) - pos.y;
    data_[i]->move({ pos.x + dx * k, pos.y + dy * k });
    data_[i]->scale(k);
  }
}

void lab::swap(CompositeShape& obj1, CompositeShape& obj2) noexcept
{
  obj1.swap(obj2);
}

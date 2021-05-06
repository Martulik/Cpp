#include "composite-shape.hpp"
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"

pyatizbyantsev::CompositeShape::CompositeShape(const std::initializer_list < std::shared_ptr< pyatizbyantsev::Shape > > source):
  size_(source.size()),
  data_(std::make_unique< std::shared_ptr< Shape >[] >(size_))
{
  int count = 0;
  if (size_ == 0)
  {
    throw (std::invalid_argument("Composite Shape mustn't be empty"));
  }
  for (int count = 0; count < size_; count++)
  {
      const std::shared_ptr< Shape > element = source[count];
  }
//думай утром
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

pyatizbyantsev::CompositeShape::CompositeShape(const CompositeShape& src):
  size_(src.size_),
  data_(std::make_unique< std::shared_ptr< Shape >[] >(size_))
{
  for (size_t i = 0; i < size_; ++i)
  {
    data_[i] = src.data_[i]->clone();
  }
}

std::shared_ptr< pyatizbyantsev::Shape > pyatizbyantsev::CompositeShape::at(size_t indx)
{
  if (indx >= size_)
  {
    throw std::out_of_range("Index out of bounds");
  }
  return data_[indx];
}

std::shared_ptr< const pyatizbyantsev::Shape > pyatizbyantsev::CompositeShape::at(const size_t indx) const
{
  if (indx >= size_)
  {
    throw std::out_of_range("Index out of bounds");
  }
  return data_[indx];
}

pyatizbyantsev::CompositeShape& pyatizbyantsev::CompositeShape::operator=(const CompositeShape& src)
{
  CompositeShape temp(src);
  swap(temp);
  return *this;
}

double pyatizbyantsev::CompositeShape::getArea() const
{
  double sum = 0;
  for (size_t i = 0; i < size_; i++)
  {
    sum += data_[i]->getArea();
  }
  return sum;
}

pyatizbyantsev::rectangle_t pyatizbyantsev::CompositeShape::getFrameRect() const
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

void pyatizbyantsev::CompositeShape::move(const double dx, const double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    data_[i]->move(dx, dy);
  }
}

void pyatizbyantsev::CompositeShape::move(const pyatizbyantsev::point_t& dpos)
{
  move(dpos.x, dpos.y);
}

std::string pyatizbyantsev::CompositeShape::getName() const
{
  return "Composite Shape";
}

void pyatizbyantsev::CompositeShape::swap(CompositeShape& src) noexcept
{
  std::swap(size_, src.size_);
  std::swap(data_, src.data_);
}

// std::shared_ptr< pyatizbyantsev::Shape > pyatizbyantsev::CompositeShape::clone() const
// {
//   return std::make_shared< CompositeShape >(*this);
// }

size_t pyatizbyantsev::CompositeShape::getSize() const
{
  return size_;
}

void pyatizbyantsev::CompositeShape::doScale(double k)
{
  pyatizbyantsev::point_t pos = getFrameRect().pos;
  for (size_t i = 0; i < size_; i++)
  {
    double dx = getX(*data_[i]) - pos.x;
    double dy = getY(*data_[i]) - pos.y;
    data_[i]->move({ pos.x + dx * k, pos.y + dy * k });
    data_[i]->scale(k);
  }
}

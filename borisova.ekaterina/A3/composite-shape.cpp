#include "composite-shape.hpp"
#include <stdexcept>

borisova::CompositeShape::CompositeShape(const std::initializer_list < std::shared_ptr< Shape > > & source):
  size_(source.size()),
  data_(std::make_unique< std::shared_ptr< Shape >[] >(size_))
{
  int count = 0;
  if (size_ == 0)
  {
    throw (std::invalid_argument("Composite Shape mustn't be empty"));
  }
  for (const std::shared_ptr< Shape > & elem : source)
  {
    data_[count] = elem;
    count++;
  }
}

borisova::CompositeShape::CompositeShape(const CompositeShape& src):
size_(src.size_),
data_(std::make_unique< std::shared_ptr< Shape >[] >(size_))
{
  for (size_t i = 0; i < size_; ++i)
  {
    data_[i] = src.data_[i]->clone();
  }
}

borisova::CompositeShape::CompositeShape(CompositeShape&& src) noexcept:
  size_(src.size_),
  data_(std::move(src.data_))
{
}

std::shared_ptr< borisova::Shape > borisova::CompositeShape::at(const size_t index) const
{
  if (index >= size_) {
    throw std::out_of_range("Index out of bounds");
  }
  return data_[index];
}

borisova::CompositeShape& borisova::CompositeShape::operator=(const CompositeShape& src)
{
  CompositeShape temp(src);
  swap(temp);
  return *this;
}

borisova::CompositeShape& borisova::CompositeShape::operator=(CompositeShape&& src) noexcept
{
  CompositeShape temp(src);
  swap(temp);
  return *this;
}

double borisova::CompositeShape::getArea() const
{
  double sum = 0;
  for (size_t i = 0; i < size_; i++)
  {
    sum += data_[i]->getArea();
  }
  return sum;
}

borisova::rectangle_t borisova::CompositeShape::getFrameRect() const
{
  double left = data_[0]->getLeft();
  double right = data_[0]->getRight();
  double top = data_[0]->getTop();
  double bottom = data_[0]->getBottom();

  for (size_t i = 0; i < size_; i++)
  {
    double leftBorder = data_[i]->getLeft();
    double rightBorder = data_[i]->getRight();
    double topBorder = data_[i]->getTop();
    double bottomBorder = data_[i]->getBottom();

    left = std::min(left, leftBorder);
    right = std::max(right, rightBorder);
    top = std::max(top, topBorder);
    bottom = std::min(bottom, bottomBorder);
  }
  return {right - left, top - bottom, {(right + left) / 2, (top + bottom) / 2}};
}

void borisova::CompositeShape::move(const double dx, const double dy)
{
  for (size_t i = 0; i < size_; i++)
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

void borisova::CompositeShape::swap(CompositeShape& src) noexcept
{
  std::swap(size_, src.size_);
  std::swap(data_, src.data_);
}

std::shared_ptr< borisova::Shape > borisova::CompositeShape::clone() const
{
  return std::make_shared< CompositeShape >(*this);
}

size_t borisova::CompositeShape::getSize()
{
  return size_;
}

void borisova::CompositeShape::doScale(double k)
{
  borisova::point_t pos = getFrameRect().pos;
  for (size_t i = 0; i < size_; i++)
  {
    double dx = data_[i]->getX() - pos.x;
    double dy = data_[i]->getY() - pos.y;
    data_[i]->move({ pos.x + dx * k, pos.y + dy * k });
    data_[i]->scale(k);
  }
}

void borisova::swap(CompositeShape& obj1, CompositeShape& obj2) noexcept
{
  obj1.swap(obj2);
}

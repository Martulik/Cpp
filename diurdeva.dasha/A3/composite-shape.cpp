#include "composite-shape.hpp"
#include <stdexcept>

diurdeva::CompositeShape::CompositeShape(std::shared_ptr<Shape> shape):
  size_(1),
  shapeArr_(std::make_unique<std::shared_ptr<Shape>[]>(1))
{
  if (shape == nullptr) {
    throw std::invalid_argument("Pointer must be not null");
  }
  shapeArr_[0] = std::move(shape);
}

diurdeva::CompositeShape::CompositeShape(const CompositeShape &other):
  size_(other.size_),
  shapeArr_(std::make_unique<std::shared_ptr<Shape>[]>(other.size_))
{
  for (size_t i = 0; i < size_; i++) {
    shapeArr_[i] = other.shapeArr_[i];
  }
}

diurdeva::CompositeShape::CompositeShape(CompositeShape &&other) noexcept:
  size_(other.size_),
  shapeArr_(std::move(other.shapeArr_))
{
  other.size_ = 0;
}

diurdeva::CompositeShape &diurdeva::CompositeShape::operator=(const CompositeShape &other)
{
  if (this != std::addressof(other)) {
    size_ = other.size_;
    std::unique_ptr<std::shared_ptr<Shape>[]> newArray(new std::shared_ptr<Shape>[other.size_]);
    for (size_t i = 0; i < size_; i++) {
      newArray[i] = other.shapeArr_[i];
    }
    shapeArr_.swap(newArray);
  }
  return *this;
}

diurdeva::CompositeShape &diurdeva::CompositeShape::operator=(CompositeShape &&other) noexcept
{
  if (this != std::addressof(other)) {
    size_ = other.size_;
    shapeArr_ = std::move(other.shapeArr_);
    other.size_ = 0;
  }
  return *this;
}

std::shared_ptr<diurdeva::Shape> diurdeva::CompositeShape::operator[](const unsigned int index) const
{
  if ((index < 0.0) || (index > size_)) {
    throw std::out_of_range("Composite-shape::operator[]");
  }
  return shapeArr_[index];
}

bool diurdeva::CompositeShape::operator==(const CompositeShape &other)
{
  if (size_ != other.size_) {
    return false;
  }
  for (size_t i = 1; i < size_; i++) {
    if (shapeArr_[i] != other.shapeArr_[i]) {
      return false;
    }
  }
  return true;
}

double diurdeva::CompositeShape::getArea() const
{
  double area = shapeArr_[0]->getArea();
  for (size_t i = 1; i < size_; i++) {
    area += shapeArr_[i]->getArea();
  }
  return area;
}

void diurdeva::CompositeShape::move(double dX, double dY)
{
  for (size_t i = 0; i < size_; i++) {
    shapeArr_[i]->move(dX, dY);
  }
}

void diurdeva::CompositeShape::move(const point_t &newCenter)
{
  point_t center = getFrameRect().pos;
  move(newCenter.x - center.x, newCenter.y - center.y);
}

diurdeva::rectangle_t diurdeva::CompositeShape::getFrameRect() const
{
  if (size_ == 0) {
    return {0.0, 0.0, {0.0, 0.0}};
  }
  rectangle_t frameRect = shapeArr_[0]->getFrameRect();

  double minX = frameRect.pos.x - (frameRect.width / 2);
  double maxX = frameRect.pos.x + (frameRect.width / 2);
  double minY = frameRect.pos.y - (frameRect.height / 2);
  double maxY = frameRect.pos.y + (frameRect.height / 2);
  for (size_t i = 1; i < size_; i++) {
    frameRect = shapeArr_[i]->getFrameRect();
    minX = std::min((frameRect.pos.x - frameRect.width / 2), minX);
    maxX = std::max((frameRect.pos.x + frameRect.width / 2), maxX);
    minY = std::min((frameRect.pos.y - frameRect.height / 2), minY);
    maxY = std::max((frameRect.pos.y + frameRect.height / 2), maxY);
  }
  double width = maxX - minX;
  double height = maxY - minY;
  double x = (minX + maxX) / 2;
  double y = (minY + maxY) / 2;
  return {width, height, {x, y}};
}

void diurdeva::CompositeShape::scale(const double factor)
{
  if (factor < 0.0) {
    throw (std::invalid_argument("Factor < 0"));
  }
  for (size_t i = 0; i < size_; i++) {
    double dX = (shapeArr_[i]->getFrameRect().pos.x - getFrameRect().pos.x) * factor + getFrameRect().pos.x;
    double dY = (shapeArr_[i]->getFrameRect().pos.y - getFrameRect().pos.y) * factor + getFrameRect().pos.y;
    shapeArr_[i]->move({dX, dY});
    shapeArr_[i]->scale(factor);
  }
}

void diurdeva::CompositeShape::push_back(std::shared_ptr<Shape> newShape)
{
  if (newShape == nullptr) {
    throw std::invalid_argument("Pointer must be not null");
  }
  std::unique_ptr<std::shared_ptr<Shape>[]> newArray(std::make_unique<std::shared_ptr<Shape>[]>(size_ + 1));
  for (size_t i = 0; i < size_; i++) {
    newArray[i] = std::move(shapeArr_[i]);
  }
  newArray[size_] = std::move(newShape);
  shapeArr_ = std::move(newArray);
  ++size_;
}

size_t diurdeva::CompositeShape::size() const
{
  return size_;
}

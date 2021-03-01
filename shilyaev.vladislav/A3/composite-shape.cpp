#include "composite-shape.hpp"
#include <limits>
#include <cassert>

shilyaev::CompositeShape::CompositeShape():
  capacity_(INITIAL_CAPACITY),
  size_(0),
  shapes_(new std::shared_ptr<Shape>[INITIAL_CAPACITY])
{
}

shilyaev::CompositeShape::~CompositeShape()
{
  delete[] shapes_;
}

double shilyaev::CompositeShape::getArea() const
{
  //TODO
  double area = 0.0;
  for (size_t i = 0; i < size_; i++) {
    area += shapes_[i]->getArea();
  }
  return area;
}

rectangle_t shilyaev::CompositeShape::getFrameRect() const
{
  double maxX = std::numeric_limits<double>::min();
  double maxY = std::numeric_limits<double>::min();
  double minX = std::numeric_limits<double>::max();
  double minY = std::numeric_limits<double>::max();
  for (size_t i = 0; i < size_; i++) {
    rectangle_t localFrameRect = shapes_[i]->getFrameRect();
    maxX = std::max(maxX, localFrameRect.pos.x + localFrameRect.width / 2);
    maxY = std::max(maxY, localFrameRect.pos.y + localFrameRect.height / 2);
    minX = std::min(minX, localFrameRect.pos.x - localFrameRect.width / 2);
    minY = std::min(minY, localFrameRect.pos.y - localFrameRect.height / 2);
  }
  point_t center = point_t{(maxX + minX) / 2, (maxY + minY) / 2};
  return rectangle_t{maxX - minX, maxY - minY, center};
}

void shilyaev::CompositeShape::move(const point_t &pos)
{
  point_t center = getFrameRect().pos;
  move(pos.x - center.x, pos.y - center.y);
}

void shilyaev::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; i++) {
    shapes_[i]->move(dx, dy);
  }
}

void shilyaev::CompositeShape::scale(double factor)
{
  assert(factor >= 0.0);
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i < size_; i++) {
    shapes_[i]->scale(factor);
    point_t localCenter = shapes_[i]->getFrameRect().pos;
    point_t newLocalCenter{center.x + (localCenter.x - center.x) * factor,
                           center.y + (localCenter.y - center.y) * factor};
    shapes_[i]->move(newLocalCenter);
  }
}

void shilyaev::CompositeShape::insert(std::shared_ptr<Shape> shape)
{
  if (size_ >= capacity_) {
    increaseCapacity();
  }
  shapes_[size_] = std::shared_ptr<Shape>(shape);
  size_++;
}

void shilyaev::CompositeShape::increaseCapacity()
{
  capacity_ *= CAPACITY_INCREASE_FACTOR;
  std::shared_ptr<Shape> *old = shapes_;
  shapes_ = new std::shared_ptr<Shape>[capacity_];
  for (size_t i = 0; i < size_; i++) {
    shapes_[i] = old[i];
  }
  delete[] old;
}

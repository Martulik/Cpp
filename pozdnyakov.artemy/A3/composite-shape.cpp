#include "composite-shape.hpp"
#include <limits>
#include <stdexcept>
#include <algorithm>

namespace poz = pozdnyakov;

poz::CompositeShape::CompositeShape(UniqueShapes shapes, int shapesLen):
  shapes_(std::move(shapes)),
  shapesLen_(shapesLen),
  frame_(0, 0, poz::point_t{0, 0})
{
  if (shapes_ == nullptr)
  {
    throw std::invalid_argument("Invalid argument");
  }
  for (int i = 0; i < shapesLen; i++)
  {
    if (shapes_[i] == nullptr)
    {
      throw std::invalid_argument("Invalid argument");
    }
  }
  double minX = std::numeric_limits< double >::min();
  double maxY = std::numeric_limits< double >::max();
  double minY = minX;
  double maxX = maxY;
  area_ = 0;
  for (int i = 0; i < shapesLen; i++)
  {
    minX = std::max(minX, shapes_[i]->getFrameRect().getMinX());
    maxY = std::max(maxY, shapes_[i]->getFrameRect().getMaxY());
    minY = std::max(minY, shapes_[i]->getFrameRect().getMinY());
    maxX = std::max(maxX, shapes_[i]->getFrameRect().getMaxX());
    area_ += shapes_[i]->getArea();
  }
  double width = (maxX - minX) / 2;
  double height = (maxY - minY) / 2;
  frame_ = poz::Rectangle(width, height, poz::point_t{minX + width, minY + height});
}

double poz::CompositeShape::getArea() const
{
  return area_;
}

poz::rectangle_t poz::CompositeShape::getFrameRect() const
{
  return frame_.getFrameRect();
}

void poz::CompositeShape::move(poz::point_t point)
{
  double dx = point.x - frame_.pos.x;
  double dy = point.y - frame_.pos.y;
  frame_.move(point);
  for (int i = 0; i < shapesLen_; i++)
  {
    shapes_[i]->move(dx, dy);
  }
}

void poz::CompositeShape::move(double dx, double dy)
{
  frame_.move(dx, dy);
  for (int i = 0; i < shapesLen_; i++)
  {
    shapes_[i]->move(dx, dy);
  }
}

void poz::CompositeShape::safeScale(double coef)
{
  area_ *= coef * coef;
  frame_.scale(coef);
  poz::point_t newPoint;
  for (int i = 0; i < shapesLen_; i++)
  {
    newPoint = poz::point_t{shapes_[i]->getFrameRect().pos.x * coef, shapes_[i]->getFrameRect().pos.y * coef};
    shapes_[i]->move(newPoint);
    shapes_[i]->scale(coef);
  }
}

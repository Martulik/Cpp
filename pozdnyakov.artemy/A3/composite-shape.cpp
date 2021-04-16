#include "composite-shape.hpp"
#include "exceptions.hpp"
#include <limits>
#include <algorithm>

pozdnyakov::CompositeShape::CompositeShape(UniqueShapes shapes, int shapesLen):
  shapes_(std::move(shapes)),
  shapesLen_(shapesLen)
{
  if (shapes_ == nullptr)
  {
    throw ShapeArgException();
  }
  for (int i = 0; i < shapesLen; i++)
  {
    if (shapes_[i] == nullptr)
    {
      throw ShapeArgException();
    }
  }
  double minX = std::numeric_limits<double>::min();
  double maxY = std::numeric_limits<double>::max();
  double minY = minX;
  double maxX = maxY;
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
  frame_ = pozdnyakov::rectangle_t{pozdnyakov::point_t{minX + width, minY + height}, width, height};
}

double pozdnyakov::CompositeShape::getArea() const
{
  return area_;
}

pozdnyakov::rectangle_t pozdnyakov::CompositeShape::getFrameRect() const
{
  return frame_;
}

void pozdnyakov::CompositeShape::move(pozdnyakov::point_t point)
{
  double dx = point.x - frame_.pos.x;
  double dy = point.y - frame_.pos.y;
  frame_.pos.x += dx;
  frame_.pos.y += dy;
  for (int i = 0; i < shapesLen_; i++)
  {
    shapes_[i]->move(dx, dy);
  }
}

void pozdnyakov::CompositeShape::move(double dx, double dy)
{
  frame_.pos.x += dx;
  frame_.pos.y += dy;
  for (int i = 0; i < shapesLen_; i++)
  {
    shapes_[i]->move(dx, dy);
  }
}

void pozdnyakov::CompositeShape::safeScale(double coef)
{
  area_ *= coef * coef;
  pozdnyakov::point_t newPoint;
  for (int i = 0; i < shapesLen_; i++)
  {
    newPoint = pozdnyakov::point_t{shapes_[i]->getFrameRect().pos.x * coef, shapes_[i]->getFrameRect().pos.y * coef};
    shapes_[i]->move(newPoint);
    shapes_[i]->scale(coef);
  }
}

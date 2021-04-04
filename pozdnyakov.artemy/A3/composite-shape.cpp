#include "composite-shape.hpp"
#include <limits>
#include "exceptions.hpp"

pozdnyakov::CompositeShape::CompositeShape(pozdnyakov::UniqueShapes shapes, int shapesLen):
  shapes_(std::move(shapes)),
  shapesLen_(shapesLen),
  area_(0)
{
  if (shapes_ == nullptr)
  {
    throw pozdnyakov::ShapeArgException();
  }
  double shapeMinX, shapeMinY, shapeMaxX, shapeMaxY, width, height;
  double maxX = std::numeric_limits<double>::max();
  double maxY = maxX;
  double minX = std::numeric_limits<double>::min();
  double minY = minX;
  for (int i = 0; i < shapesLen; i++)
  {
    shapeMaxX = shapes_[i]->getFrameRect().pos.x + shapes_[i]->getFrameRect().width / 2;
    shapeMaxY = shapes_[i]->getFrameRect().pos.y + shapes_[i]->getFrameRect().width / 2;
    shapeMinX = shapes_[i]->getFrameRect().pos.x - shapes_[i]->getFrameRect().width / 2;
    shapeMinY = shapes_[i]->getFrameRect().pos.y - shapes_[i]->getFrameRect().width / 2;
    if (shapeMaxX > maxX)
    {
      maxX = shapeMaxX;
    }
    else if (shapeMinX < minX)
    {
      minX = shapeMinX;
    }
    if (shapeMaxY > maxY)
    {
      maxY = shapeMaxY;
    }
    else if (shapeMinY < minY)
    {
      minY = shapeMinY;
    }
    area_ += shapes_[i]->getArea();
  }
  width = (maxX - minX) / 2;
  height = (maxY - minY) / 2;
  frame_ = rectangle_t { point_t { minX + width, minY + height }, width, height };
}

double pozdnyakov::CompositeShape::getArea() const
{
  return area_;
}

pozdnyakov::rectangle_t pozdnyakov::CompositeShape::getFrameRect() const
{
  return frame_;
}

void pozdnyakov::CompositeShape::move(point_t point)
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

void pozdnyakov::CompositeShape::scale(double coef)
{
  area_ *= coef * coef;
  point_t newPoint;
  for (int i = 0; i < shapesLen_; i++)
  {
    newPoint = point_t { shapes_[i]->getFrameRect().pos.x * coef, shapes_[i]->getFrameRect().pos.y * coef };
    shapes_[i]->move(newPoint);
    shapes_[i]->scale(coef);
  }
}

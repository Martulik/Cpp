#include "composite_shape.hpp"
#include <limits>
#include "exceptions.hpp"

pozdnyakov::CompositeShape::CompositeShape(pozdnyakov::UniqueShapes shapes, int shapesLen):
  shapes_(std::move(shapes)),
  shapesLen_(shapesLen),
  area_(0)
{
  if (shapes == nullptr)
  {
    throw pozdnyakov::ShapeArgException();
  }
  double maxX, maxY, minX, minY, width, height;
  double shapeMaxX = std::numeric_limits<double>::max();
  double shapeMaxY = shapeMaxX;
  double shapeMinX = std::numeric_limits<double>::min();
  double shapeMinY = shapeMinX;
  for (int i = 0; i < shapesLen; i++)
  {
    shapeMaxX = shapes.get()[i]->getFrameRect().pos.x + shapes.get()[i]->getFrameRect().width / 2;
    shapeMaxY = shapes.get()[i]->getFrameRect().pos.y + shapes.get()[i]->getFrameRect().width / 2;
    shapeMinX = shapes.get()[i]->getFrameRect().pos.x - shapes.get()[i]->getFrameRect().width / 2;
    shapeMinY = shapes.get()[i]->getFrameRect().pos.y - shapes.get()[i]->getFrameRect().width / 2;
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
    area_ += shapes.get()[i]->getArea();
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
  for (int i = 0; i < shapesLen_; i++)
  {
    shapes_.get()[i]->move(dx, dy);
  }
}

void pozdnyakov::CompositeShape::move(double dx, double dy)
{
  for (int i = 0; i < shapesLen_; i++)
  {
    shapes_.get()[i]->move(dx, dy);
  }
}

void pozdnyakov::CompositeShape::scale(double coef)
{
  point_t newPoint;
  for (int i = 0; i < shapesLen_; i++)
  {
    newPoint = point_t { shapes_.get()[i]->getFrameRect().pos.x * coef, shapes_.get()[i]->getFrameRect().pos.y * coef };
    shapes_.get()[i]->move(newPoint);
    shapes_.get()[i]->scale(coef);
  }
}

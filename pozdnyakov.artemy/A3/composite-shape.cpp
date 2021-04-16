#include "composite-shape.hpp"
#include "exceptions.hpp"
#include <limits>
#include <algorithm>

pozdnyakov::CompositeShape::CompositeShape(pozdnyakov::UniqueShapes shapes, int shapesLen)
    : shapes_(std::move(shapes)), shapesLen_(shapesLen)
{
  if (shapes_ == nullptr)
  {
    throw pozdnyakov::ShapeArgException();
  }
  for (int i = 0; i < shapesLen; i++)
  {
    if (shapes[i] == nullptr)
    {
      throw ShapeArgException();
    }
  }
  auto minXCompare = [](pozdnyakov::UniqueShape shape)
  {
    return shape->getFrameRect().getMinX() < shape->getFrameRect().getMinX();
  }
  auto maxXCompare = [](pozdnyakov::UniqueShape shape)
  {
    return shape->getFrameRect().getMaxX() < shape->getFrameRect().getMaxX();
  }
  auto minYCompare = [](pozdnyakov::UniqueShape shape)
  {
    return shape->getFrameRect().getMinY() < shape->getFrameRect().getMinY();
  }
  auto maxYCompare = [](pozdnyakov::UniqueShape shape)
  {
    return shape->getFrameRect().getMaxY() < shape->getFrameRect().getMaxY();
  }
  double minX = std::min_element<minXCompare>(&shapes[0], &shapes[shapesLen]);
  double maxX = std::max_element<maxXCompare>(&shapes[0], &shapes[shapesLen]);
  double minY = std::min_element<minYCompare>(&shapes[0], &shapes[shapesLen]);
  double maxY = std::max_element<maxYCompare>(&shapes[0], &shapes[shapesLen]);
  for (int i = 0; i < shapesLen; i++)
  {
    area_ += shapes_[i]->getArea();
  }
  double width = (maxX - minX) / 2;
  double height = (maxY - minY) / 2;
  frame_ = rectangle_t{point_t{minX + width, minY + height}, width, height};
}

double pozdnyakov::CompositeShape::getArea() const { return area_; }

pozdnyakov::rectangle_t pozdnyakov::CompositeShape::getFrameRect() const { return frame_; }

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

void pozdnyakov::CompositeShape::safeScale(double coef)
{
  area_ *= coef * coef;
  point_t newPoint;
  for (int i = 0; i < shapesLen_; i++)
  {
    newPoint = point_t{shapes_[i]->getFrameRect().pos.x * coef, shapes_[i]->getFrameRect().pos.y * coef};
    shapes_[i]->move(newPoint);
    shapes_[i]->scale(coef);
  }
}

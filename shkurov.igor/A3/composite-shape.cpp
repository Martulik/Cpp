#include "composite-shape.hpp"

#include <stdexcept>
#include <limits>
#include <algorithm>

double shkurov::CompositeShape::getArea() const
{
  double summaryArea = 0.0;
  for (size_t i = 0; i < shapeCount_; i++)
  {
    summaryArea += shapeArray_[i]->getArea();
  }

  return summaryArea;
}

shkurov::rectangle_t shkurov::CompositeShape::getFrameRect() const
{
  double max_x = std::numeric_limits< double >::min();
  double min_x = std::numeric_limits< double >::max();
  double max_y = std::numeric_limits< double >::min();
  double min_y = std::numeric_limits< double >::max();

  for (size_t i = 0; i < shapeCount_; i++)
  {
    max_x = std::max(max_x, shapeArray_[i]->getX() + shapeArray_[i]->getWidth() / 2);
    min_x = std::min(min_x, shapeArray_[i]->getX() - shapeArray_[i]->getWidth() / 2);
    max_y = std::max(max_y, shapeArray_[i]->getY() + shapeArray_[i]->getHeight() / 2);
    min_y = std::min(min_y, shapeArray_[i]->getY() - shapeArray_[i]->getHeight() / 2);
  }

  double width = max_x - min_x;
  double height = max_y - min_y;
  point_t pos{max_x - width / 2, max_y - height / 2};

  return {height, width, pos};
}

void shkurov::CompositeShape::move(const shkurov::point_t& newPos)
{
  move(newPos.x - getX(), newPos.y - getY());
}

void shkurov::CompositeShape::move(const double x, const double y)
{
  for (size_t i = 0; i < shapeCount_; i++)
  {
    shapeArray_[i]->move(x, y);
  }
}

void shkurov::CompositeShape::scaleFigure(double k)
{
  for (size_t i = 0; i < shapeCount_; i++)
  {
    shapeArray_[i]->move((getX() - shapeArray_[i]->getX()) * k,
     (getY() - shapeArray_[i]->getY()) * k);
    shapeArray_[i]->scale(k);
  }
}

const char* shkurov::CompositeShape::getName() const
{
  return "Composite-shape";
}

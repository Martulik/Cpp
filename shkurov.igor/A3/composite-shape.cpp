#include "composite-shape.hpp"

#include <stdexcept>
#include <limits>
#include <algorithm>

namespace lab = shkurov;

double lab::CompositeShape::getArea() const
{
  double summaryArea = 0.0;
  for (size_t i = 0; i < shapeCount_; i++)
  {
    summaryArea += shapeArray_[i]->getArea();
  }

  return summaryArea;
}

lab::rectangle_t lab::CompositeShape::getFrameRect() const
{
  double max_x = std::numeric_limits< double >::min();
  double min_x = std::numeric_limits< double >::max();
  double max_y = std::numeric_limits< double >::min();
  double min_y = std::numeric_limits< double >::max();

  for (size_t i = 0; i < shapeCount_; i++)
  {
    max_x = std::max(max_x, lab::getX(*shapeArray_[i]) + lab::getWidth(*shapeArray_[i]) / 2);
    min_x = std::min(min_x, lab::getX(*shapeArray_[i]) - lab::getWidth(*shapeArray_[i]) / 2);
    max_y = std::max(max_y, lab::getY(*shapeArray_[i]) + lab::getHeight(*shapeArray_[i]) / 2);
    min_y = std::min(min_y, lab::getY(*shapeArray_[i]) - lab::getHeight(*shapeArray_[i]) / 2);
  }

  double width = max_x - min_x;
  double height = max_y - min_y;
  point_t pos{max_x - width / 2, max_y - height / 2};

  return {height, width, pos};
}

void lab::CompositeShape::move(const lab::point_t& newPos)
{
  move(newPos.x - lab::getX(*this), newPos.y - lab::getY(*this));
}

void lab::CompositeShape::move(const double x, const double y)
{
  for (size_t i = 0; i < shapeCount_; i++)
  {
    shapeArray_[i]->move(x, y);
  }
}

void lab::CompositeShape::scaleFigure(double k)
{
  for (size_t i = 0; i < shapeCount_; i++)
  {
    double dx = (lab::getX(*this) - lab::getX(*shapeArray_[i])) * k;
    double dy = (lab::getY(*this) - lab::getY(*shapeArray_[i])) * k;
    shapeArray_[i]->move(dx, dy);
    shapeArray_[i]->scale(k);
  }
}

const char* lab::CompositeShape::getName() const
{
  return "Composite-shape";
}

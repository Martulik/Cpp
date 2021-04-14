#include "composite-shape.hpp"

#include <stdexcept>
#include <limits>
#include <algorithm>

namespace ss = shkurov;

double ss::CompositeShape::getArea() const
{
  double summaryArea = 0.0;
  for (size_t i = 0; i < shapeCount_; i++)
  {
    summaryArea += shapeArray_[i]->getArea();
  }

  return summaryArea;
}

ss::rectangle_t ss::CompositeShape::getFrameRect() const
{
  double max_x = std::numeric_limits< double >::min();
  double min_x = std::numeric_limits< double >::max();
  double max_y = std::numeric_limits< double >::min();
  double min_y = std::numeric_limits< double >::max();

  for (size_t i = 0; i < shapeCount_; i++)
  {
    max_x = std::max(max_x, ss::getX(*shapeArray_[i]) + ss::getWidth(*shapeArray_[i]) / 2);
    min_x = std::min(min_x, ss::getX(*shapeArray_[i]) - ss::getWidth(*shapeArray_[i]) / 2);
    max_y = std::max(max_y, ss::getY(*shapeArray_[i]) + ss::getHeight(*shapeArray_[i]) / 2);
    min_y = std::min(min_y, ss::getY(*shapeArray_[i]) - ss::getHeight(*shapeArray_[i]) / 2);
  }

  double width = max_x - min_x;
  double height = max_y - min_y;
  point_t pos{max_x - width / 2, max_y - height / 2};

  return {height, width, pos};
}

void ss::CompositeShape::move(const ss::point_t& newPos)
{
  move(newPos.x - ss::getX(*this), newPos.y - ss::getY(*this));
}

void ss::CompositeShape::move(const double x, const double y)
{
  for (size_t i = 0; i < shapeCount_; i++)
  {
    shapeArray_[i]->move(x, y);
  }
}

void ss::CompositeShape::scaleFigure(double k)
{
  for (size_t i = 0; i < shapeCount_; i++)
  {
    double dx = (ss::getX(*this) - ss::getX(*shapeArray_[i])) * k;
    double dy = (ss::getY(*this) - ss::getY(*shapeArray_[i])) * k;
    shapeArray_[i]->move(dx, dy);
    shapeArray_[i]->scale(k);
  }
}

const char* ss::CompositeShape::getName() const
{
  return "Composite-shape";
}

#include "composite-shape.hpp"

#include <stdexcept>
#include <limits>
#include <algorithm>

double shkurov::CompositeShape::getArea() const
{
  double summary_area = 0.0;
  for (size_t i = 0; i < shape_count_; i++)
  {
    summary_area += shape_array_[i]->getArea();
  }

  return summary_area;
}

shkurov::rectangle_t shkurov::CompositeShape::getFrameRect() const
{
  double max_x = std::numeric_limits< double >::min();
  double min_x = std::numeric_limits< double >::max();
  double max_y = std::numeric_limits< double >::min();
  double min_y = std::numeric_limits< double >::max();

  for (size_t i = 0; i < shape_count_; i++)
  {
    max_x = std::max(max_x, shape_array_[i]->getX() + shape_array_[i]->getWidth() / 2);
    min_x = std::min(min_x, shape_array_[i]->getX() - shape_array_[i]->getWidth() / 2);
    max_y = std::max(max_y, shape_array_[i]->getY() + shape_array_[i]->getHeight() / 2);
    min_y = std::min(min_y, shape_array_[i]->getY() - shape_array_[i]->getHeight() / 2);
  }

  double width = max_x - min_x;
  double height = max_y - min_y;
  point_t pos{max_x - width / 2, max_y - height / 2};

  return {height, width, pos};
}

void shkurov::CompositeShape::move(const shkurov::point_t& new_pos)
{
  move(new_pos.x - getX(), new_pos.y - getY());
}

void shkurov::CompositeShape::move(const double x, const double y)
{
  for (size_t i = 0; i < shape_count_; i++)
  {
    shape_array_[i]->move(x, y);
  }
}

void shkurov::CompositeShape::scaleFigure(double k)
{
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i < shape_count_; i++)
  {
    shape_array_[i]->move((center.x - shape_array_[i]->getX())
      * k, (center.y - shape_array_[i]->getY()) * k);
    shape_array_[i]->scale(k);
  }
}

const char* shkurov::CompositeShape::getName() const
{
  return "Composite-shape";
}

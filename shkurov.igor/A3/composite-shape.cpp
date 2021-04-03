#include "composite-shape.hpp"

#include <stdexcept>
#include <limits>
#include <algorithm>
#include <iostream>

shkurov::CompositeShape::CompositeShape(std::initializer_list< shkurov::Shape* > shapes):
  shape_count_(shapes.size()),
  shape_array_(new member_ptr[shape_count_])
{
  if (shape_count_ == 0)
  {
    throw std::invalid_argument("Exception: empty initializer list is not allowed");
  }
  std::initializer_list< shkurov::Shape* >::iterator it = shapes.begin();
  size_t i = 0;
  while (it != shapes.end())
  {
    shape_array_[i++]= *it;
    it++;
  }
}

shkurov::CompositeShape::CompositeShape(CompositeShape&& src):
  shape_count_(src.shape_count_),
  shape_array_(std::move(src.shape_array_))
{
  src.shape_count_ = 0;
  src.shape_array_ = nullptr;
}

shkurov::CompositeShape& shkurov::CompositeShape::operator=(CompositeShape&& src)
{
  shape_count_ = src.shape_count_;
  shape_array_ = std::move(src.shape_array_);

  src.shape_count_ = 0;
  src.shape_array_ = nullptr;

  return *this;
}

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
    rectangle_t rect = shape_array_[i]->getFrameRect();
    max_x = std::max(max_x, rect.pos.x + rect.width / 2);
    min_x = std::min(min_x, rect.pos.x - rect.width / 2);
    max_y = std::max(max_y, rect.pos.y + rect.height / 2);
    min_y = std::min(min_y, rect.pos.y - rect.height / 2);
  }

  double width = max_x - min_x;
  double height = max_y - min_y;
  point_t pos{max_x - width / 2, max_y - height / 2};

  return {height, width, pos};
}

void shkurov::CompositeShape::move(const shkurov::point_t& new_pos)
{
  double origin_x = getFrameRect().pos.x;
  double origin_y = getFrameRect().pos.y;
  for (size_t i = 0; i < shape_count_; i++)
  {
    double rel_x = shape_array_[i]->getFrameRect().pos.x - origin_x;
    double rel_y = shape_array_[i]->getFrameRect().pos.y - origin_y;
    point_t rel_pos{new_pos.x + rel_x, new_pos.y + rel_y};
    shape_array_[i]->move(rel_pos);
  }
}

void shkurov::CompositeShape::move(const double x, const double y)
{
  double origin_x = getFrameRect().pos.x;
  double origin_y = getFrameRect().pos.y;
  for (size_t i = 0; i < shape_count_; i++)
  {
    double rel_x = shape_array_[i]->getFrameRect().pos.x - origin_x;
    double rel_y = shape_array_[i]->getFrameRect().pos.y - origin_y;
    shape_array_[i]->move(x + rel_x, y + rel_y);
  }
}

void shkurov::CompositeShape::scale(double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("Exception: Scale coefficient < 0");
  }
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i < shape_count_; i++)
  {
    point_t shape_center = shape_array_[i]->getFrameRect().pos;
    shape_array_[i]->move((center.x - shape_center.x) * k, (center.y - shape_center.y) * k);
    shape_array_[i]->scale(k);
  }
}

const char* shkurov::CompositeShape::getName() const
{
  return "Composite-shape";
}

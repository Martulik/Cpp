// TODO: Где должны быть константы?
# define M_PI           3.14159265358979323846

#include "circle.hpp"


// Вычисление площади.
double Circle::getArea() const
{
  return M_PI* radius_* radius_;
}

// Получение ограничивающего прямоугольника для фигуры.
rectangle_t Circle::getFrameRect() const
{
  double diameter = radius_ * 2.0;
  return rectangle_t(diameter, diameter, pos_);
}

// Перемещение в конкретную точку.
void Circle::move(point_t destination)
{
  pos_ = destination;
}

// Смещение по осям абцисс и ординат.
void Circle::move(double dx, double dy)
{
  pos_.x_ += dx;
  pos_.y_ += dy;
}
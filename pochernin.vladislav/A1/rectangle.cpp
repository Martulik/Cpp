#include "rectangle.hpp"

// Вычисление площади.
double Rectangle::getArea() const 
{
  return width_ * heigth_;
}

// Получение ограничивающего прямоугольника для фигуры.
rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t(width_, heigth_, pos_);
}

// Перемещение в конкретную точку.
void Rectangle::move(point_t destination)
{
  pos_ = destination;
}

// Смещение по осям абцисс и ординат.
void Rectangle::move(double dx, double dy)
{
  pos_.x_ += dx;
  pos_.y_ += dy;
}
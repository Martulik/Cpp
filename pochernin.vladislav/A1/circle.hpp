#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

class Circle : public Shape
{
public:
  // Консутрктор без параметров.
  Circle() : radius_(0), pos_(point_t(0,0)) {}

  // Конструктор с параметрами.
  Circle(const double radius, const point_t pos)
    : radius_(radius),
    pos_(pos)
  {}

  // Вычисление площади.
  virtual double getArea() const override;

  // Получение ограничивающего прямоугольника для фигуры.
  virtual rectangle_t getFrameRect() const override;

  // Перемещение в конкретную точку.
  virtual void move(point_t destination) override;

  // Смещение по осям абцисс и ординат.
  virtual void move(double dx, double dy) override;

private:
  double radius_ = 0;
  point_t pos_ = point_t(0,0);
};

#endif

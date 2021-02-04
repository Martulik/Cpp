#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  // Конструктор без параметров.
  Rectangle() : width_(0), heigth_(0), pos_(point_t()) {}

  // Конструктор с параметрами.
  Rectangle(const double width, const double heigth, const point_t pos)
    : width_(width),
    heigth_(heigth),
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
  // TODO: Надо ли тут инициализировать?
  double width_ = 0;
  double heigth_ = 0;
  point_t pos_ = point_t(0, 0);
};

#endif

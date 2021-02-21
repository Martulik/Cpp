#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.hpp"
class Circle: public Shape
{
public:
  explicit Circle(const point_t center, double rad) : center_(center), rad_(rad) {};
  ~Circle() override {};
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t point) override;
  void move(const double dx, const double dy) override;
private:
  point_t center_;
  double rad_;
};
#endif

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.hpp"
class Circle : public Shape
{
public:
  Circle(double radius, point_t pos);
  Circle(const Circle& other);
  Circle(Circle&& other)noexcept;
  Circle& operator=(const Circle& other);
  Circle& operator=(Circle&& other)noexcept;

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& point) override;
  void move(double dx, double dy) override;

private:
  double radius_;
  point_t pos_;
};

#endif

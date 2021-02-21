#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
const double PI = 3.1415926;

class Circle : public Shape
{
public:
  Circle(const double radius, const point_t pos);

  virtual ~Circle() = default;

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t & pos) override;
  void move(const double dx, const double dy) override;
private:
  double radius_;
  point_t pos_;
};

#endif

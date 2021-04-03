#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(const point_t& pos, double radius);
  Circle(double x, double y, double radius);
  ~Circle() = default;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(const point_t& dpos) override;
  std::string getName() const override;

private:
  point_t position_;
  double radius_;
};

#endif

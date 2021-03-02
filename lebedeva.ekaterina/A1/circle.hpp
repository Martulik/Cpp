#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(const point_t pos, double radius);
  ~Circle() override = default;

  double getArea() const override;
  rectangle_t getFrameRect() const override;

  void move(const point_t& newPos) override;
  void move(const double& dx, const double& dy) override;
  std::string getName() const override;
private:
  point_t pos_;
  double radius_;
};
#endif

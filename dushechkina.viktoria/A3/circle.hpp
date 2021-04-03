#ifndef A3_CIRCLE_HPP
#define A3_CIRCLE_HPP

#include "shape.hpp"

namespace dushechkina
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t& centre, double r);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& pos) override;
    void move(double dx, double dy) override;
    std::shared_ptr< Shape > clone() const override;
  private:
    point_t centre_;
    double r_;
    void doScale(double ratio) override;
  };
}
#endif

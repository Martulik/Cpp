#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace lebedeva
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t pos, double radius);
    ~Circle() override = default;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    std::string getName() const override;
    std::shared_ptr< Shape > clone() const override;

    void move(const point_t& newPos) override;
    void move(double dx, double dy) override;
  private:
    point_t pos_;
    double radius_;
    void doScale(double k) override;
  };
}
#endif

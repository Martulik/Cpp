#ifndef A3_RECTANGLE_HPP
#define A3_RECTANGLE_HPP

#include "shape.hpp"

namespace dushechkina
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(double width, double height, const point_t& pos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& pos) override;
    void move(double dx, double dy) override;
    std::shared_ptr< Shape > clone() const override;
  private:
    rectangle_t unit_;
    void doScale(double ratio) override;
 };
}
#endif

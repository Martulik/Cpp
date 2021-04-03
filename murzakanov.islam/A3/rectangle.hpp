#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <memory>
#include "shape.hpp"
#include "base-types.hpp"

namespace murzakanov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(double width, double height, const point_t& pos_);

    std::string getName() const override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    ShapePtr clone() const override;
  private:
    double width_;
    double height_;
    point_t pos_;

    void doScale(double coef) override;
  };
}

#endif

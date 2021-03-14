#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace ivanova
{
  class Rectangle: public ivanova::Shape
  {
  public:
    Rectangle(double height, double width, ivanova::point_t pos);
    virtual double getArea() const override;
    virtual ivanova::rectangle_t getFrameRect() const override;
    virtual void move(const ivanova::point_t &newPos) override;
    virtual void move(double dx, double dy) override;
    virtual std::string getName() const override;
    virtual void scale(double k) override;

  private:
    double height_;
    double width_;
    ivanova::point_t pos_;
  };

#endif
}

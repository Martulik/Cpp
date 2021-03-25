#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace ezerinia {
  class Rectangle: public Shape {
  public:
    Rectangle(double width, double height, point_t center);
    virtual ~Rectangle() = default;
    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    virtual void move(const point_t &point) override;
    virtual void move(double dx, double dy) override;
    virtual void doScale(std::size_t k) override;
  private:
    double width_;
    double height_;
    point_t center_;
  };
}
#endif

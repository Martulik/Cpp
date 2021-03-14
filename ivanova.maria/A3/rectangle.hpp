#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace ivanova
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(double height, double width, point_t pos);
    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    virtual void move(const point_t &newPos) override;
    virtual void move(double dx, double dy) override;
    virtual std::string getName() const override;
    virtual void scale(double k) override;

  private:
    double height_;
    double width_;
    point_t pos_;
  };

#endif
}

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace pyatizbyantsev
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(double valueHeight, double valueWidth, const point_t& valuePos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    std::string getName() const override;
    void move(const point_t& newPos) override;
    void move(double abscissa, double ordinate) override;

  private:
    void doScale(double scaleCoefficient) override;
    double height_;
    double width_;
    point_t pos_;
  };
}

#endif

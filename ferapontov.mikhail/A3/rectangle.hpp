#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace ferapontov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const double width, const double height, const point_t pos);

    virtual ~Rectangle() = default;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void scale(double k);
    void move(const point_t& pos) override;
    void move(const double dx, const double dy) override;
  private:
    rectangle_t proportions_;
  };
}
#endif

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <memory>

#include "shape.hpp"

namespace savchuk
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t& pos, double width, double height);
    ~Rectangle() = default;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    void scale(double scaleFactor) override;
    std::unique_ptr< Shape* > clone() const override;

  private:
    rectangle_t rect_;
  };
}

#endif

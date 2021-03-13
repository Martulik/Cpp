#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <memory>

#include "shape.hpp"

namespace savchuk
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t& pos, double radius);
    ~Circle() = default;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    void scale(double scaleFactor) override;
    std::unique_ptr< Shape* > clone() const override;

  private:
    point_t pos_;
    double radius_;
  };
}

#endif

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace pochernin
{
  class Circle : public Shape
  {
  public:
    Circle(double radius, const point_t& pos);

    virtual ~Circle() = default;

    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    virtual void move(const point_t& destination) override;
    virtual void move(double dx, double dy) override;
    virtual void scale(double factor) override;

  private:
    rectangle_t figure_;
  };
}

#endif

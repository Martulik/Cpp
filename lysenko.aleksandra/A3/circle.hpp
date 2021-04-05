#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <string>

#include "shape.hpp"

namespace lysenko
{
  class Circle : public Shape
  {
  public:
    Circle(point_t& pos, double radius);

    ~Circle() = default;

    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    virtual void move(const point_t& newPos) override;
    virtual void move(double dx, double dy) override;
    virtual std::string getName() const override;

    virtual ShapePtr clone() const override;

  private:
    point_t pos_;
    double radius_;

    virtual void doScale(double k) override;
  };
}

#endif

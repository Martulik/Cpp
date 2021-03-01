#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include <ostream>
namespace ivanova {
  class Circle : public Shape {
  public:
    Circle(ivanova::point_t ctr, double rad);

    virtual double getArea() const override;
    virtual ivanova::rectangle_t getFrameRect() const;
    virtual void move(const ivanova::point_t &newPos) override;
    virtual void move(double dx, double dy) override;
    virtual std::ostream &fout(std::ostream &out) const;
  private:
    ivanova::point_t ctr_;
    double radius_;
    };
}
#endif

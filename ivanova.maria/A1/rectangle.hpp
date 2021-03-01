#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include <ostream>
namespace ivanova {
  class Rectangle : public Shape {
  public:
    Rectangle();
    Rectangle(double height, double width, ivanova::point_t pos);

    virtual double getArea() const override;
    virtual ivanova::rectangle_t getFrameRect() const override;
    virtual void move(const ivanova::point_t &newPos) override;
    virtual void move(double dx, double dy) override;
    virtual std::ostream &fout(std::ostream &out) const;

  private:
    double height_;
    double width_;
    point_t pos_;
  };
}
#endif

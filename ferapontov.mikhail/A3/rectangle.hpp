#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace ferapontov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(double width, double height, const point_t& pos);

    virtual ~Rectangle() = default;

    std::string getName() const override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& pos) override;
    void move(double dx, double dy) override;
    virtual std::unique_ptr< Shape > clone() const override;
  private:
    rectangle_t rect_;

    void doScale(double k) override;
  };
}
#endif
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace lebedeva
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t pos, double width, double height);
    ~Rectangle() override = default;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    std::string getName() const override;

    void move(const point_t& newPos) override;
    void move(const double& dx, const double& dy) override;
    void scale(const double& k) override;
  private:
    point_t pos_;
    double width_;
    double height_;
  };
}
#endif

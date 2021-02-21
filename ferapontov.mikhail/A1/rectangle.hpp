#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const double width, const double height, const point_t pos);

  virtual ~Rectangle() = default;

  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(const point_t& pos) override;
  virtual void move(const double dx, const double dy) override;
private:
  rectangle_t proportions_;
};
#endif

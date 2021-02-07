#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle();

  Rectangle(const double width, const double height);
  Rectangle(const double width, const double height, const point_t& pos);

  virtual ~Rectangle();

  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(const point_t& destination) override;
  virtual void move(const double dx, const double dy) override;
  virtual void getInfo() const override;

private:
  rectangle_t figure_;
};

#endif

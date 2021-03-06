#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <string>

#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(double width, double height, point_t& pos);

  ~Rectangle() = default;

  virtual double getArea() const override;
  virtual rectangle_t getFrameRect()const override;
  virtual void move(const point_t& newPos) override;
  virtual void move(double dx, double dy) override;
  virtual std::string getName() const override;

private:
  double width_;
  double heigh_;
  point_t pos_;
};

#endif

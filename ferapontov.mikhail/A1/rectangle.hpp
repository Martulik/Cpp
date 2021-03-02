#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(double width, double height, point_t pos);

  virtual ~Rectangle() = default;

  std::string getName() const override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& pos) override;
  void move(double dx, double dy) override;
private:
  rectangle_t rect_;
};
#endif

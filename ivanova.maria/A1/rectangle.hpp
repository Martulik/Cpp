#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include <ostream>

class Rectangle: public Shape
{
public:
  Rectangle();

  Rectangle(double height, double width, point_t pos);

  virtual ~Rectangle();

  virtual double getArea() const override;

  virtual rectangle_t getFrameRect() const override;

  virtual void move(const point_t &newPos) override;

  virtual void move(int dx, int dy) override;

  void outShape () override;

private:
  int height_;
  int width_;
  point_t pos_;
};
#endif

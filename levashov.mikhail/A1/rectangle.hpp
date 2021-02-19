#ifndef rectangle_hpp
#define rectangle_hpp

#include "shape.hpp"

class Rectangle:public Shape
{
public:
  Rectangle(const double width, const double height, const point_t& pos_);

  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(const point_t& destination) override;
  virtual void move(const double dx, const double dy) override;

private:
  double width_;
  double height_;
  point_t pos_;
};

#endif

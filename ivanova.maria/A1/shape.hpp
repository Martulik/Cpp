#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <ostream>
#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() =default;
  virtual double getArea() const =0;
  virtual rectangle_t getFrameRect() const =0;
  virtual void move(const point_t &newPos) = 0;
  virtual void move(double dx, double dy)=0;
protected:
  friend std::ostream &operator <<  (std::ostream& out, Shape& shape)
  {
    return shape.fout(out);
  }
private:
  virtual std::ostream& fout (std::ostream &out) const = 0;
};
#endif

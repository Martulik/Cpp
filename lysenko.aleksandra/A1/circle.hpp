#ifndef CIRCLE
#define CIRCLE

#include "base-types.hpp"
#include "shape.hpp"

class Circle: public Shape {
public:
  Circle(const point_t &pos, const double radius);

  ~Circle() = default;

  virtual double getArea();

  virtual rectangle_t getFrameRect();

  virtual void move(const point_t &newPos);
}

private:
point_t pos_;
double radius_;
};
#endif

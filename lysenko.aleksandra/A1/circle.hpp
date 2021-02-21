#ifndef CIRCLE
#define CIRCLE

#include "base-types.hpp"
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &pos, const double radius);

  ~Circle() = default;

  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(const point_t &newPos) override;
  virtual void move(const double dx, const double dy) override;

private:
  point_t pos_;
  double radius_;
};

#endif


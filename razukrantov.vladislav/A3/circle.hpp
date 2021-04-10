#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace razukrantov
{
  class Circle : public Shape
  {
  public:
    Circle(double rad, const point_t& pos);

	virtual ~Circle() = default;

	double getArea() const override;
	rectangle_t getFrameRect() const override;
	void move(const point_t& center) override;
	void move(double dx, double dy) override;
	void scale(double k) override;

  private:
	double radius_;
	point_t center_;
  };
}

#endif

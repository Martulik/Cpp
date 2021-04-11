#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace razukrantov
{
  class Rectangle : public Shape
  {
  public:
	Rectangle(double width, double height, const point_t& center);

	~Rectangle() = default;

	double getArea() const override;
	rectangle_t getFrameRect() const override;
	void move(const point_t& center) override;
	void move(double dx, double dy) override;

  private:
	double width_;
	double height_;
	point_t center_;
	void doScale(double k) override;
  };
}

#endif

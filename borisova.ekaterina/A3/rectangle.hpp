#ifndef A3_RECTANGLE_HPP
#define A3_RECTANGLE_HPP

#include "shape.hpp"

namespace borisova
{
  class Rectangle : public Shape
  {
  public:
	Rectangle(const point_t& pos, double width, double height);
	Rectangle(double x, double y, double width, double height);
	~Rectangle() = default;
	double getArea() const override;
	rectangle_t getFrameRect() const override;
	void scale(double k) override;
	void move(double dx, double dy) override;
	void move(const point_t& dpos) override;
	std::string getName() const override;

  private:
	rectangle_t parameters_;
  };
}

#endif

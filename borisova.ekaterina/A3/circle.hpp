#ifndef A3_CIRCLE_HPP
#define A3_CIRCLE_HPP

#include "shape.hpp"

namespace borisova
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t& pos, double radius);
    Circle(double x, double y, double radius);
    ~Circle() = default;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(const point_t& dpos) override;
    std::string getName() const override;
    std::shared_ptr< Shape > clone() const override;

  private:
    point_t position_;
    double radius_;
    void doScale(double k) override;
  };
  std::unique_ptr< Shape > makeCircle(const point_t& pos, double radius);
  std::unique_ptr< Shape > makeCircle(double x, double y, double radius);
}

#endif

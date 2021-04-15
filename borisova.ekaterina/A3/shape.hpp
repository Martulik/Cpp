#ifndef A3_SHAPE_HPP
#define A3_SHAPE_HPP

#include <string>
#include <memory>
#include "base-types.hpp"

namespace borisova
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    void scale(double k);
    virtual void move(double dx, double dy) = 0;
    virtual void move(const point_t& dpos) = 0;
    virtual std::string getName() const = 0;
    virtual std::shared_ptr< Shape > clone() const = 0;

  private:
    virtual void doScale(double k) = 0;
  };
  double getX(const Shape & obj);
  double getY(const Shape & obj);
  double getWidth(const Shape & obj);
  double getHeight(const Shape & obj);

  double getLeft(const Shape & obj);
  double getRight(const Shape & obj);
  double getTop(const Shape & obj);
  double getBottom(const Shape & obj);
}

#endif

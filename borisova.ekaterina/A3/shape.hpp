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

    double getX() const;
    double getY() const;
    double getWidth() const;
    double getHeight() const;

    double getLeft() const;
    double getRight() const;
    double getTop() const;
    double getBottom() const;

  private:
    virtual void doScale(double k) = 0;
  };
}

#endif

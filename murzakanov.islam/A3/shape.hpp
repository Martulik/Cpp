#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <memory>
#include "base-types.hpp"

namespace murzakanov
{
  class Shape
  {
  public:
    using ShapePtr = std::shared_ptr < Shape >;

    void scale(double coef);
    virtual std::string getName() const = 0;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual ShapePtr clone() const = 0;
    virtual void move(const point_t& point) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual ~Shape() = default;
  private:
    virtual void doScale(double coef) = 0;
  };
  double getX(const Shape::ShapePtr& shp);
  double getY(const Shape::ShapePtr& shp);
  double getWidth(const Shape::ShapePtr& shp);
  double getHeight(const Shape::ShapePtr& shp);

  void check(double arg, const char* mes);
}

#endif

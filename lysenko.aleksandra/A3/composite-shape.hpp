#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include <string>

#include "shape.hpp"

namespace lysenko
{
  class CompositeShape : public Shape
  {
  public:
    virtual double getArea() const override;
    virtual rectangle_t getFrameRect()const override;
    virtual void move(const point_t& newPos) override;
    virtual void move(double dx, double dy) override;
    virtual std::string getName() const override;

    virtual ShapePtr clone() const override;

  private:
    size_t capacity_;
    size_t size_;
    ArrayOfShapes array_;

    virtual void doScale(double k) override;
  };

  double getShapesLeftmostAbscissa(Shape::ShapePtr const src);
  double getShapesRightmostAbscissa(Shape::ShapePtr const src);
  double getShapesBottomOrdinate(Shape::ShapePtr const src);
  double getShapesTopOrdinate(Shape::ShapePtr const src);
}

#endif


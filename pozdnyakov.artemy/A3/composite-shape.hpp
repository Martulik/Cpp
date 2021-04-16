#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include "shape.hpp"
#include <memory>

using UniqueShapes = std::unique_ptr< std::unique_ptr< pozdnyakov::Shape >[] >;
using UniqueShape = std::unique_ptr< pozdnyakov::Shape >;

namespace pozdnyakov
{
  class CompositeShape: public pozdnyakov::Shape
  {
  public:
    CompositeShape(UniqueShapes shapes, int shapesLen);
    ~CompositeShape() override = default;
    double getArea() const override;
    pozdnyakov::rectangle_t getFrameRect() const override;
    void move(pozdnyakov::point_t point) override;
    void move(double dx, double dy) override;

  private:
    UniqueShapes shapes_;
    int shapesLen_;
    int area_;
    pozdnyakov::rectangle_t frame_;
    void safeScale(double coef) override;
  };
}

#endif

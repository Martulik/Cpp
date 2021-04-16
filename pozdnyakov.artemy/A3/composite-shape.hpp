#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include "shape.hpp"
#include <memory>

namespace pozdnyakov
{
  using UniqueShapes = std::unique_ptr< std::unique_ptr< Shape >[] >;
  using UniqueShape = std::unique_ptr< Shape >;
  class CompositeShape : public pozdnyakov::Shape
  {
  public:
    CompositeShape(UniqueShapes shapes, int shapesLen);
    ~CompositeShape() override = default;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double dx, double dy) override;
    std::unique_ptr< Shape > at(int i);

  private:
    UniqueShapes shapes_;
    int shapesLen_;
    int area_;
    rectangle_t frame_;
    void safeScale(double coef) override;
  };
}

#endif

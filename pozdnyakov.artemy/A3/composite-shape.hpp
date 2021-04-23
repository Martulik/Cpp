#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"
#include "rectangle.hpp"

namespace pozdnyakov
{
  using UniqueShapes = std::unique_ptr< std::unique_ptr< Shape >[] >;
  using UniqueShape = std::unique_ptr< Shape >;

  class CompositeShape: public Shape
  {
  public:
    CompositeShape(UniqueShapes shapes, int shapesLen);
    ~CompositeShape() override = default;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double dx, double dy) override;

  private:
    UniqueShapes shapes_;
    int shapesLen_;
    int area_;
    Rectangle frame_;
    void safeScale(double coef) override;
  };
}

#endif

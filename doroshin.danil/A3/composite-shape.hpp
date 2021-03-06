#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <cstddef>
#include <initializer_list>
#include <memory>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

namespace doroshin
{
  class CompositeShape: public Shape
  {
    using shape_ptr = std::unique_ptr<Shape>;
    using array_t = std::unique_ptr<shape_ptr[]>;

    array_t shapes_;
    size_t size_;

    friend void swap(CompositeShape& lhs, CompositeShape& rhs);
  public:
    CompositeShape();

    void add(shape_ptr);

    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void move_rel(point_t vec) override;
    void move_abs(point_t point) override;
    void scale(double s) override;

    // Implementations of copy move and dest are required
    // because this class manages dynamic resources
    CompositeShape(const CompositeShape&) = delete;
    CompositeShape(CompositeShape&&) noexcept = default;
    CompositeShape& operator=(const CompositeShape&) = delete;
    CompositeShape& operator=(CompositeShape&&) noexcept = default;
    ~CompositeShape() override = default;
  };

  void swap(CompositeShape& lhs, CompositeShape& rhs);
}

#endif // COMPOSITE_SHAPE_HPP

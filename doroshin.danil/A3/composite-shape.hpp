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
    using shape_ptr = std::unique_ptr< Shape >;
    using array_t = std::unique_ptr< shape_ptr[] >;

    array_t shapes_;
    size_t size_;

    friend void swap(CompositeShape& lhs, CompositeShape& rhs);
  public:
    CompositeShape();

    template< typename... Shapes >
    CompositeShape(Shapes...);

    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void move(point_t vec, bool absolute = false) override;
    void scale(double s) override;

    // Implementations of copy move and dest are required
    // because this class manages dynamic resources
    Shape* copy() const override;
    CompositeShape(const CompositeShape&);
    CompositeShape(CompositeShape&&) noexcept = default;
    CompositeShape& operator=(const CompositeShape&);
    CompositeShape& operator=(CompositeShape&&) noexcept = default;
    ~CompositeShape() override = default;
  };


  template< typename... Shapes >
  CompositeShape::CompositeShape(Shapes... shapes):
    shapes_(std::make_unique< shape_ptr[] >(sizeof...(Shapes))),
    size_(sizeof...(Shapes))
  {
    shape_ptr sh[] = { std::unique_ptr< Shape >(shapes.copy())... };
    std::move(sh, sh + size_, shapes_.get());
  }

  void swap(CompositeShape& lhs, CompositeShape& rhs);
}

#endif // COMPOSITE_SHAPE_HPP

#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

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
    CompositeShape() = delete;

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

  namespace details
  {
    template< typename T, typename... Args >
    std::unique_ptr<T[]> make_unique_array(Args&&... args)
    {
      return std::unique_ptr< T[] >(new T[sizeof...(Args)] { std::move(args)... });
    }
  }

  template< typename... Shapes >
  CompositeShape::CompositeShape(Shapes... shapes):
    shapes_(details::make_unique_array< shape_ptr >(
        std::unique_ptr< Shape >(shapes.copy())... )),
    size_(sizeof...(Shapes))
  {
    static_assert(sizeof...(Shapes) > 0, "An empty CompositeShape is illegal");
  }

  void swap(CompositeShape& lhs, CompositeShape& rhs);
}

#endif // COMPOSITE_SHAPE_HPP

#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <cstddef>
#include <initializer_list>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

namespace doroshin {
  class CompositeShape : public Shape
  {
    class AnyShape;

    AnyShape* shapes_;
    size_t size_;

  public:
    CompositeShape();
    CompositeShape(std::initializer_list<AnyShape>);

    // void add(AnyShape);

    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void move_rel(point_t vec) override;
    void move_abs(point_t point) override;
    void scale(double s) override;

    CompositeShape(const CompositeShape&);
    CompositeShape(CompositeShape&&) noexcept;
    CompositeShape& operator=(const CompositeShape&);
    CompositeShape& operator=(CompositeShape&&) noexcept;
    ~CompositeShape() override;

    friend void swap(CompositeShape& lhs, CompositeShape& rhs);
  };

  class CompositeShape::AnyShape : public Shape
  {
    enum class Type {
      Circle,
      Rectangle
    } type;
    union {
      Circle circle;
      Rectangle rectangle;
    };
  public:
    AnyShape() = delete;
    AnyShape(Circle);
    AnyShape(Rectangle);

    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void move_rel(point_t vec) override;
    void move_abs(point_t point) override;
    void scale(double s) override;

    AnyShape(const AnyShape&);
    AnyShape(const AnyShape&&) noexcept;
    AnyShape& operator=(const AnyShape&);
    AnyShape& operator=(const AnyShape&&) noexcept;
    ~AnyShape() override;
  };
}

#endif // COMPOSITE_SHAPE_HPP

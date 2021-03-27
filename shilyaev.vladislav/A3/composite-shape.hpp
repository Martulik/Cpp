#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace shilyaev {
  using ShapePtr = std::unique_ptr< Shape >;
  using ShapeArray = std::unique_ptr< ShapePtr[] >;

  class CompositeShape: public Shape {
  public:
    explicit CompositeShape(ShapePtr initialShape);
    CompositeShape(const CompositeShape &source);
    CompositeShape(CompositeShape &&source) = default;
    CompositeShape &operator=(CompositeShape other);
    CompositeShape &operator=(CompositeShape &&other) = default;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    std::unique_ptr< Shape > clone() const override;
    void move(const point_t &pos) override;
    void move(double dx, double dy) override;
    size_t size() const;
    const Shape &at(size_t index) const;
    Shape &at(size_t index);
    void pushBack(ShapePtr shape);
    void popBack();
    void reserve(size_t newCapacity);
    void swap(CompositeShape &other) noexcept;
  private:
    size_t capacity_;
    size_t size_;
    ShapeArray shapes_;
    void scaleInternal(double factor) override;
  };
}

#endif

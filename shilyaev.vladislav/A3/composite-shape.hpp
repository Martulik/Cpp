#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace shilyaev {
  class CompositeShape: public Shape {
  public:
    using ValueType = std::unique_ptr< Shape >;
    using ArrayType = std::unique_ptr< ValueType[] >;
    explicit CompositeShape(ValueType initialShape);
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
    void pushBack(ValueType shape);
    void popBack();
    void reserve(size_t newCapacity);
    void swap(CompositeShape &other) noexcept;
  private:
    size_t capacity_;
    size_t size_;
    ArrayType shapes_;
    void scaleInternal(double factor) override;
  };
}

#endif

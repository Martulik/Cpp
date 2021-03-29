#ifndef A3_COMPOSITE_SHAPE_HPP
#define A3_COMPOSITE_SHAPE_HPP

#include "shape.hpp"

namespace diurdeva {
  class CompositeShape: public Shape {
  public:
    using shapePtr = std::shared_ptr< Shape >;
    using shapeArray = std::unique_ptr< shapePtr[] >;
    CompositeShape(shapePtr shape);
    CompositeShape(const CompositeShape &shape);
    CompositeShape(CompositeShape &&other) noexcept;
    ~CompositeShape() = default;
    CompositeShape &operator=(const CompositeShape &other);
    CompositeShape &operator=(CompositeShape &&other) noexcept;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &newCenter) override;
    void move(double dX, double dY) override;
    std::shared_ptr< Shape > at(size_t index) const;
    std::shared_ptr< Shape > clone() const override;
    void swap(CompositeShape& src) noexcept;
    void reserve(size_t newCap);
    void pushBack(shapePtr newShape);
    void popBack();
    size_t size() const;
    size_t capacity() const;
  private:
    size_t capacity_;
    size_t size_;
    shapeArray shapeArr_;
    void doScale(double factor) override;
  };
  void swap(CompositeShape& src1, CompositeShape& src2) noexcept;
}

#endif

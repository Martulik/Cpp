#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace ezerinia {
  class CompositeShape: public Shape {
  public:
    using shapePtr = std::shared_ptr< Shape >;
    using shapeArr = std::unique_ptr< shapePtr[] >;
    CompositeShape(const CompositeShape &src);
    CompositeShape(CompositeShape &&) noexcept = default;
    CompositeShape(shapePtr src);
    virtual ~CompositeShape() = default;
    CompositeShape &operator=(const CompositeShape &src);
    CompositeShape &operator=(CompositeShape &&) noexcept = default;
    void pushBack(shapePtr src);
    void popBack();
    std::shared_ptr< Shape > at(size_t index) const;
    size_t size() const;
    void swap(CompositeShape& src) noexcept;
    void reserve(size_t newCap);
    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    virtual void move(const point_t &point) override;
    virtual void move(double dx, double dy) override;
    virtual std::shared_ptr< Shape > clone() const override;
  private:
    size_t size_;
    size_t capacity_;
    shapeArr data_;
    virtual void doScale(double k) override;
  };

  void swap(CompositeShape &lhs, CompositeShape &rhs) noexcept;
}
#endif

#ifndef A3_COMPOSITE_SHAPE_HPP
#define A3_COMPOSITE_SHAPE_HPP

#include "base-types.hpp"
#include "shape.hpp"
#include <memory>

namespace dushechkina
{
  class CompositeShape: public Shape
  {
  public:
    using shapePtr = std::shared_ptr< Shape >;
    using arr = std::unique_ptr< shapePtr[] >;
    CompositeShape(const CompositeShape& src);
    CompositeShape(CompositeShape&&) noexcept = default;
    CompositeShape(shapePtr src);
    virtual ~CompositeShape() = default;
    CompositeShape& operator=(const CompositeShape & src);
    CompositeShape& operator=(CompositeShape&&) noexcept = default;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& pos) override;
    void move(double dx, double dy) override;
    void swap(CompositeShape & src) noexcept;
    void reserve(size_t cap);
    void popBack();
    void pushBack(shapePtr src);
    size_t size() const;
    size_t capacity() const;
    std::shared_ptr< const dushechkina::Shape > at(size_t index) const;
    std::shared_ptr< dushechkina::Shape > at(size_t index);
    std::shared_ptr< Shape > clone() const override;
  private:
    size_t size_;
    size_t capacity_;
    arr arr_;
    void doScale(double ratio) override;
  };
  void swap(CompositeShape& first, CompositeShape& second) noexcept;
}
#endif

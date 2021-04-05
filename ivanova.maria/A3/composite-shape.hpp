#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace ivanova
{
  class CompositeShape: public Shape
  {
  public:
    using shared = std::shared_ptr< ivanova::Shape >;
    CompositeShape(shared other);
    CompositeShape(const CompositeShape &other);
    CompositeShape(CompositeShape &&other) noexcept = default;
    virtual ~CompositeShape() = default;
    shared operator[](const size_t index) const;
    void pushBack(shared &source);
    void popBack();
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    size_t size() const;
    size_t capacity() const;
    void move(const point_t &point) override;
    void move(double dx, double dy) override;
    std::string getName() const override;
    void scaleShape(double k) override;
    void reserve(size_t capacity);
    void swap(CompositeShape &other) noexcept;
    shared clone() const override;
    std::shared_ptr< ivanova::Shape > at(size_t i) const;
    std::shared_ptr< const ivanova::Shape> at(size_t i) const;
  private:
    size_t size_;
    size_t capacity_;
    std::unique_ptr< shared[] > data_;
  };
}
#endif

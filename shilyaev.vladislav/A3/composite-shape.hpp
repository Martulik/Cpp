#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace shilyaev {
  class CompositeShape: public Shape {
  public:
    CompositeShape(std::unique_ptr< Shape > initialShape);
    CompositeShape(const CompositeShape &source);
    CompositeShape(CompositeShape &&source) = default;
    CompositeShape &operator=(CompositeShape other);
    CompositeShape &operator=(CompositeShape &&other) = default;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    CompositeShape *clone() const override;
    void move(const point_t &pos) override;
    void move(double dx, double dy) override;
    void scale(double factor) override;
    size_t getSize() const;
    void insert(std::unique_ptr< Shape > shape);
    void swap(CompositeShape &other) noexcept;
  private:
    size_t capacity_;
    size_t size_;
    std::unique_ptr< std::unique_ptr< Shape >[] > shapes_;
    void increaseCapacity();
  };
}

#endif

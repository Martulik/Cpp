#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <iostream>
#include <memory>
#include "shape.hpp"

namespace ezerinia {
  class CompositeShape: public Shape {
  public:
    CompositeShape(const CompositeShape &) = delete;
    CompositeShape(CompositeShape &&) noexcept = default;
    CompositeShape(std::shared_ptr< Shape > src);
    virtual ~CompositeShape() = default;
    CompositeShape &operator=(const CompositeShape &) = delete;
    CompositeShape &operator=(CompositeShape &&) noexcept = default;
    void push_back(std::shared_ptr< Shape > src);
    void pop_back();
    std::shared_ptr< Shape > at(std::size_t index) const;
    std::size_t size() const;
    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    virtual void move(const point_t &point) override;
    virtual void move(double dx, double dy) override;
    virtual void doScale(std::size_t k) override;
  private:
    std::size_t size_;
    std::unique_ptr< std::shared_ptr< Shape >[] > data_;
  };
}
#endif

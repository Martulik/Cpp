#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <iostream>
#include <memory>
#include "shape.hpp"

namespace ezerinia
{
  class CompositeShape: public Shape
  {
  public:
    CompositeShape(const CompositeShape &) = delete;
    CompositeShape(CompositeShape &&) noexcept = default;
    CompositeShape(std::shared_ptr< Shape > src);
    virtual ~CompositeShape() = default;
    std::shared_ptr< Shape > operator[](const std::size_t index) const;
    CompositeShape &operator=(const CompositeShape &) = delete;
    CompositeShape &operator=(CompositeShape &&) noexcept = default;
    void addShape(std::shared_ptr< Shape > src);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    std::size_t size_;
    std::unique_ptr< std::shared_ptr< Shape >[] > data_;
  };
}
#endif

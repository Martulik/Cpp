#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <cstddef>
#include <initializer_list>
#include <memory>

#include "shape.hpp"

namespace savchuk
{
  class CompositeShape: public Shape
  {
  public:
    using value_type = std::unique_ptr< Shape >;
    using this_type = CompositeShape;

    CompositeShape(std::initializer_list< Shape* >);
    CompositeShape(const this_type&);
    CompositeShape(this_type&&) noexcept;
    ~CompositeShape();

    this_type& operator=(const this_type&);
    this_type& operator=(this_type&&) noexcept;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    std::unique_ptr< Shape > clone() const override;
    void swap(this_type&);

  private:
    size_t size_;
    value_type* arr_;

    void doScale(double scaleFactor) override;
  };
}

#endif

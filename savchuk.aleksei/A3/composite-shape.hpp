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
    using valueType = std::unique_ptr< Shape >;
    using thisType = CompositeShape;

    CompositeShape(std::initializer_list< const Shape* >);
    CompositeShape(const thisType&);
    CompositeShape(thisType&&) noexcept;
    ~CompositeShape();

    thisType& operator=(const thisType&);
    thisType& operator=(thisType&&) noexcept;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    std::unique_ptr< Shape > clone() const override;
    void swap(thisType&);

  private:
    size_t size_;
    valueType* arr_;

    void doScale(double scaleFactor) override;
  };

  void swap(CompositeShape& lhs, CompositeShape& rhs);
}

#endif

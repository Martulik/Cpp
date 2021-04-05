#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include "shape.hpp"

#include <initializer_list>
#include <memory>

namespace ferapontov
{
  class CompositeShape: public Shape
  {
  public:
    using value_type = std::unique_ptr< Shape >;
    using this_type = CompositeShape;

    CompositeShape(std::initializer_list< const Shape* >);
    CompositeShape(const this_type&);
    CompositeShape(this_type&&) = default;

    this_type& operator=(const this_type&);
    this_type& operator=(this_type&&) = default;

    ~CompositeShape();

    std::string getName() const override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& pos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    size_t size_;
    value_type* arr_;
 };
}
#endif

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

    CompositeShape(std::initializer_list< const Shape* > src);
    CompositeShape(const this_type& src);
    CompositeShape(this_type&& src) noexcept = default;

    this_type& operator=(const this_type& src);
    this_type& operator=(this_type&& src) noexcept;

    ~CompositeShape();

    std::string getName() const override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& pos) override;
    void move(double dx, double dy) override;
    std::unique_ptr< Shape > clone() const override;
    void swap(this_type& src);
  private:
    size_t size_;
    value_type* arr_;

    void doScale(double k) override;
 };
}
#endif

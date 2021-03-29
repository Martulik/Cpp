#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include <initializer_list>

#include "shape.hpp"

namespace shkurov
{
  class CompositeShape: public Shape
  {
    using member_ptr = Shape*;
    using array_ptr = std::unique_ptr< member_ptr[] >;
  public:
    CompositeShape(std::initializer_list< Shape* > shape_list);
    CompositeShape(const CompositeShape& src) = delete;
    CompositeShape(CompositeShape&& src);

    CompositeShape& operator=(const CompositeShape& src) = delete;
    CompositeShape& operator=(CompositeShape&& src);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& new_pos) override;
    void move(double x, double y) override;
    void scale(double k) override;
    const char* getName() const override;
  private:
    size_t shape_count_;
    array_ptr shape_array_;
  };
}

#endif

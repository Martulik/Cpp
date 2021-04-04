#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include <iostream>

#include "shape.hpp"

namespace shkurov
{
  class CompositeShape: public Shape
  {
    using member_ptr = std::unique_ptr< Shape >;
    using array_ptr = std::unique_ptr< member_ptr[] >;
  public:
    template< typename... Pointers >
    CompositeShape(Pointers... pointers);
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

    template< typename... Pointers >
    CompositeShape::CompositeShape(Pointers... pointers):
      shape_count_(sizeof...(Pointers)),
      shape_array_(std::make_unique< member_ptr[] >(shape_count_))
    {
      if (shape_count_ == 0)
      {
        throw std::invalid_argument("Exception: empty parameter pack is not allowed");
      }

      std::unique_ptr< shkurov::Shape > temp_collection[] = {std::move(pointers)...};
      for (size_t i = 0; i < shape_count_; i++)
      {
        shape_array_[i] = std::move(temp_collection[i]);
      }
    }

}

#endif

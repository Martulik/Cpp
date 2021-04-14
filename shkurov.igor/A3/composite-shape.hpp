#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include <iostream>
#include <stdexcept>

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
    CompositeShape(CompositeShape&& src) = default;

    CompositeShape& operator=(const CompositeShape& src) = delete;
    CompositeShape& operator=(CompositeShape&& src) = default;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(double x, double y) override;
    const char* getName() const override;
  private:
    size_t shapeCount_;
    array_ptr shapeArray_;

    void scaleFigure(double k) override;
  };

  template< typename... Pointers >
  CompositeShape::CompositeShape(Pointers... pointers):
    shapeCount_(sizeof...(Pointers)),
    shapeArray_(std::make_unique< member_ptr[] >(shapeCount_))
  {
    if (shapeCount_ == 0)
    {
      throw std::invalid_argument("Exception: empty parameter pack is not allowed");
    }

    std::unique_ptr< Shape > tempCollection[] = {std::move(pointers)...};
    for (size_t i = 0; i < shapeCount_; i++)
    {
      if (tempCollection[i] == nullptr)
      {
        throw std::invalid_argument("Exception: nullptr parameters are not allowed");
      }
      shapeArray_[i] = std::move(tempCollection[i]);
    }
  }
}

using CShape = shkurov::CompositeShape;

#endif

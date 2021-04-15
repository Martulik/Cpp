#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"

namespace lebedeva
{
  class CompositeShape: public Shape
  {
  public:
    using ShapePtr = std::shared_ptr< Shape >;

    CompositeShape() = delete;
    CompositeShape(const std::initializer_list < ShapePtr > composition);
    CompositeShape(const CompositeShape& composition);
    CompositeShape(CompositeShape&& composition) noexcept = default;
    CompositeShape& operator=(const CompositeShape& composition);
    CompositeShape& operator=(CompositeShape&& composition) noexcept = default;
    ~CompositeShape() override = default;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    std::string getName() const override;
    std::shared_ptr< Shape > clone() const override;

    void move(const point_t& newPos) override;
    void move(double dx, double dy) override;
  private:
    size_t countElements_;
    std::unique_ptr< ShapePtr [] > data_;
    Rectangle frameRect_;

    void swap(CompositeShape& composition) noexcept;
    void doScale(double k) override;

    Rectangle makeFrameRect() const;
  };
 }

#endif

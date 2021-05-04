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
    using ValueType = std::unique_ptr< Shape >;
    using ThisType = CompositeShape;

    CompositeShape(std::initializer_list< ValueType > src);
    CompositeShape(const ThisType& src);
    CompositeShape(ThisType&& src) noexcept = default;

    ThisType& operator=(const ThisType& src);
    ThisType& operator=(ThisType&& src) noexcept;

    ~CompositeShape() = default;

    std::string getName() const override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& pos) override;
    void move(double dx, double dy) override;
    std::unique_ptr< Shape > clone() const override;
    void swap(ThisType& src);
  private:
    size_t size_;
    std::unique_ptr< ValueType[] > arr_;

    void doScale(double k) override;
  };
}
#endif

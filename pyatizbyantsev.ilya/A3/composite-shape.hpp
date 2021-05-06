#ifndef COMPISITE_SHAPE_HPP
#define COMPISITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace pyatizbyantsev
{
  class CompositeShape: public Shape
  {
  public:
    virtual ~CompositeShape() = default;

    CompositeShape(const std::initializer_list < std::shared_ptr< Shape > > source);
    CompositeShape(const CompositeShape& src);
    CompositeShape(CompositeShape&& src) noexcept = default;
    std::shared_ptr< Shape > at(size_t index);
    std::shared_ptr< const Shape > at(size_t index) const;
    CompositeShape& operator=(const CompositeShape& src);
    CompositeShape& operator=(CompositeShape&& src) noexcept = default;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(const point_t & dpos) override;
    std::string getName() const override;
    void swap(CompositeShape& src) noexcept;
    size_t getSize() const;

  private:
    void doScale(double k) override;
    size_t size_;
    std::unique_ptr< std::shared_ptr< Shape >[] > data_;

  };
}

#endif

#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <cstddef> // size_t
#include <memory>

#include "shape.hpp"

namespace pochernin
{
  class CompositeShape: public Shape
  {
  public:
    CompositeShape(const CompositeShape& src);
    CompositeShape(CompositeShape&& src) noexcept;

    CompositeShape(size_t capacity);

    virtual ~CompositeShape() = default;

    std::shared_ptr< Shape >& at(size_t index);
    const std::shared_ptr< Shape >& at(size_t index) const;
    CompositeShape& operator=(const CompositeShape& src);
    CompositeShape& operator=(CompositeShape&& src) noexcept;

    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    virtual void move(const point_t& destination) override;
    virtual void move(double dx, double dy) override;
    virtual void scale(double factor) override;
    void push_back(const std::shared_ptr< Shape > shape);
    size_t size() const;
    size_t capacity() const;

  private:
    size_t size_;
    size_t capacity_;
    std::unique_ptr< std::shared_ptr< Shape >[] > data_;
  };
}

#endif

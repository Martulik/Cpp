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

    CompositeShape(const std::shared_ptr< Shape > shape, size_t capacity = 1);

    virtual ~CompositeShape() = default;

    std::shared_ptr< Shape >& at(size_t index);
    const std::shared_ptr< Shape >& at(size_t index) const;
    CompositeShape& operator=(const CompositeShape& src);
    CompositeShape& operator=(CompositeShape&& src) noexcept;

    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    virtual void move(const point_t& destination) override;
    virtual void move(double dx, double dy) override;
    void push_back(const std::shared_ptr< Shape > shape);
    void pop_back();
    size_t size() const;
    size_t capacity() const;
    void swap (CompositeShape& other) noexcept;

  private:
    size_t size_;
    size_t capacity_;
    std::unique_ptr< std::shared_ptr< Shape >[] > data_;

    virtual void doScale(double factor) override;
  };

  void swap(CompositeShape& cs1, CompositeShape& cs2) noexcept;
}

#endif

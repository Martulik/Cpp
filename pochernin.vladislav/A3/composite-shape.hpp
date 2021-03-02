#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <stddef.h> // size_t
#include <memory> // unique_ptr

#include "shape.hpp"

namespace pochernin
{
  class CompositeShape: public Shape
  {
  public:
    CompositeShape();

    virtual ~CompositeShape() = default;

    std::shared_ptr<Shape>& operator[](size_t index) const;

    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    virtual void move(const point_t& destination) override;
    virtual void move(double dx, double dy) override;
    virtual void scale(double factor) override;
    void push_back(const std::shared_ptr<Shape> shape);
    size_t getSize() const;

  private:
    size_t size_;
    std::unique_ptr<std::shared_ptr<Shape>[]> data_;
  };
}

#endif

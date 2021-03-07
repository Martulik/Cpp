#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace shilyaev {
  class CompositeShape: public Shape {
  public:
    CompositeShape();
    ~CompositeShape() override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &pos) override;
    void move(double dx, double dy) override;
    void scale(double factor) override;
    void insert(std::unique_ptr<Shape> shape);
  private:
    size_t capacity_;
    size_t size_;
    std::unique_ptr<Shape> *shapes_;
    void increaseCapacity();
  };
}

#endif

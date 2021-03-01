#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

const size_t INITIAL_CAPACITY = 4;
const size_t CAPACITY_INCREASE_FACTOR = 2;

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
    void insert(std::shared_ptr<Shape> shape);
  private:
    size_t capacity_;
    size_t size_;
    std::shared_ptr<Shape> *shapes_;
    void increaseCapacity();
  };
}

#endif

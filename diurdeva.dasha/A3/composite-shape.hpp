#ifndef A3_COMPOSITE_SHAPE_HPP
#define A3_COMPOSITE_SHAPE_HPP

#include "shape.hpp"
#include <memory>

namespace diurdeva {
  class CompositeShape: public Shape {
  public:
    CompositeShape(std::shared_ptr<Shape> shape);
    CompositeShape(const CompositeShape &shape);
    CompositeShape(CompositeShape &&other) noexcept;
    ~CompositeShape() = default;
    CompositeShape &operator=(const CompositeShape &other);
    CompositeShape &operator=(CompositeShape &&other) noexcept;
    std::shared_ptr<Shape> operator[](unsigned int index) const;
    bool operator==(const CompositeShape &other);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &newCenter) override;
    void move(double dX, double dY) override;
    void scale(double factor) override;
    void push_back(std::shared_ptr<Shape> newShape);
    size_t size() const;
  private:
    size_t size_;
    std::unique_ptr<std::shared_ptr<Shape>[]> shapeArr_;
  };
}

#endif

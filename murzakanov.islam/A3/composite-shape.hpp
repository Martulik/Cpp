#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace murzakanov
{
  class CompositeShape: public Shape
  {
  public:
    CompositeShape(const CompositeShape& other);
    CompositeShape(CompositeShape&& other) noexcept;
    explicit CompositeShape(ShapePtr shp);
    ~CompositeShape() override = default;
    Shape& operator [](int index);
    CompositeShape& operator=(const CompositeShape& src);
    CompositeShape& operator=(CompositeShape&& src) noexcept;

    void scale(double coef) override;
    int size() const;
    std::string getName() const override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    ShapePtr clone() const override;
    void addShape(const ShapePtr& shp);
    void popShape();
  private:
    int capacity_;
    int size_;
    ArrayType array_;
  };
}


#endif

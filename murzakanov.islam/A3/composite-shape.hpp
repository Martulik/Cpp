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
    Shape& at(int index);
    CompositeShape& operator=(const CompositeShape& src);
    CompositeShape& operator=(CompositeShape&& src) noexcept;


    int size() const;
    double getArea() const override;
    std::string getName() const override;
    rectangle_t getFrameRect() const override;
    ShapePtr clone() const override;
    void scale(double coef) override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    void reserve(double newCapacity);
    void addShape(const ShapePtr& shp);
    void popShape();
  private:
    int capacity_;
    int size_;
    ArrayType array_;
  };
}


#endif

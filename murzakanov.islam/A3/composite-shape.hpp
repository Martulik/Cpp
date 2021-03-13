#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace murzakanov
{
  class CompositeShape: public Shape
  {
  public:
    CompositeShape();
    explicit CompositeShape(std::shared_ptr< Shape > shp);
    CompositeShape(const CompositeShape& other);
    CompositeShape(CompositeShape&& other) = delete;
    ~CompositeShape() override = default;

    void scale(double coef) override;
    int getSize() const;
    std::string getName() const override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    CompositeShape* clone() const override;
    void addShape(const std::shared_ptr<Shape>& shp);
    Shape& operator [](int index) ;
  private:
    int capacity_;
    int size_;
    std::unique_ptr< std::shared_ptr< Shape >[] > array_;
  };
}


#endif

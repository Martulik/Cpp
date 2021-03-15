#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include "shape.hpp"

namespace lebedeva
{
  class CompositeShape: public Shape
  {
  public:
    CompositeShape();
    ~CompositeShape() override = default;

    std::shared_ptr< Shape >& operator[](const std::size_t& i) const;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    std::string getName() const override;
    std::size_t getNumOfFigures() const;

    void move(const point_t& newPos) override;
    void move(const double& dx, const double& dy) override;
    void scale(const double& k) override;
    void push(Shape::Ptr figurePtr);
  private:
    std::unique_ptr< l::Shape::Ptr [] > data_;
    std::size_t countAllocated_;
    std::size_t countElements_;

    void allocateMemory();
  };
}
#endif

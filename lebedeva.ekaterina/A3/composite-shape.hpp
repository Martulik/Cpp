#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include "shape.hpp"

namespace lebedeva
{
  class CompositeShape: public Shape
  {
  public:
    using shapePtr = std::shared_ptr< Shape >;

    CompositeShape(std::shared_ptr< Shape > composition[], size_t n);
    ~CompositeShape() override = default;

    std::shared_ptr< Shape > operator[](size_t i) const;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    std::string getName() const override;

    void move(const point_t& newPos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    size_t countElements_;
    std::unique_ptr< shapePtr [] > data_;
  };
}
#endif

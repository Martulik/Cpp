#ifndef A3_COMPOSITE_SHAPE_HPP
#define A3_COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace borisova
{
  class CompositeShape : public borisova::Shape
  {
  public:
    CompositeShape(std::shared_ptr< Shape > source[], const int size);
    CompositeShape(const CompositeShape& src) = delete;
    CompositeShape(CompositeShape&& src) noexcept;
    CompositeShape& operator=(const CompositeShape& src) = delete;
    CompositeShape& operator=(CompositeShape&& src) noexcept;
    virtual ~CompositeShape() = default;
    std::shared_ptr< borisova::Shape > operator[] (int index) const;
    double getArea() const override;
    borisova::rectangle_t getFrameRect() const override;
    void scale(double k) override;
    void move(double dx, double dy) override;
    void move(const borisova::point_t & dpos) override;
    std::string getName() const override;

  private:
    int size_;
    std::unique_ptr< std::shared_ptr< Shape >[] > data_;
  };
}
#endif

#ifndef A3_COMPOSITE_SHAPE_HPP
#define A3_COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace borisova
{
  class CompositeShape: public Shape
  {
  public:
    CompositeShape(const std::initializer_list < std::shared_ptr< Shape > > source);
    CompositeShape(const CompositeShape& src);
    CompositeShape(CompositeShape&& src) noexcept = default;
    std::shared_ptr< Shape > at(size_t index);
    std::shared_ptr< const Shape > at(size_t index) const;
    CompositeShape& operator=(const CompositeShape& src);
    CompositeShape& operator=(CompositeShape&& src) noexcept = default;
    virtual ~CompositeShape() = default;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(const point_t & dpos) override;
    std::string getName() const override;
    void swap(CompositeShape& src) noexcept;
    std::shared_ptr< Shape > clone() const override;
    size_t getSize() const;

  private:
    size_t size_;
    std::unique_ptr< std::shared_ptr< Shape >[] > data_;
    void doScale(double k) override;
  };
  void swap(CompositeShape& obj1, CompositeShape& obj2) noexcept;
}
#endif

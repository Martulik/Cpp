#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace ivanova
{
  class CompositeShape: public Shape
  {
  public:
    CompositeShape();

    CompositeShape(const CompositeShape &other) = delete;

    CompositeShape(CompositeShape &&other) noexcept = default;

    virtual ~CompositeShape() = default;

    std::shared_ptr< Shape > operator[](const std::size_t index) const;

    void add(std::shared_ptr< Shape > src);

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    size_t getSize () const;

    void move(const point_t &point) override;

    void move(double dx, double dy) override;

    virtual std::string getName() const override;

    void scale(double k) override;

  private:
    size_t size_;
    std::unique_ptr< std::shared_ptr< Shape >[] > data_;
  };
}
#endif
#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace ivanova
{
class CompositeShape: public Shape
  {
  public:
    CompositeShape(const CompositeShape &other) = delete;
    CompositeShape(CompositeShape &&other) noexcept = default;
    explicit CompositeShape(std::shared_ptr< ivanova::Shape > &other);
    virtual ~CompositeShape() = default;
    std::shared_ptr< Shape > operator[](const size_t index) const;
    void push_back( std::shared_ptr< ivanova::Shape > &source);
    void pop_back();
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    size_t size () const;
    void move(const point_t &point) override;
    void move(double dx, double dy) override;
    std::string getName() const override;
    void scale(double k) override;
  private:
    size_t size_;
    std::unique_ptr<std::shared_ptr< ivanova::Shape >[] > data_;
    size_t capacity_;
  };
}
#endif

#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace pyatizbyantsev
{
  class CompositeShape: public Shape
  {
  public:
    virtual ~CompositeShape() = default;

    template< typename... Shapes >
    CompositeShape(Shapes... shapes);
    CompositeShape(const CompositeShape & src);
    CompositeShape(CompositeShape&& src) noexcept = default;
    CompositeShape& operator=(const CompositeShape& src) = delete;
    CompositeShape& operator=(CompositeShape&& src) noexcept = default;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    std::string getName() const override;
    void move(double abscissa, double ordinate) override;
    void move(const point_t & newPos) override;
    size_t getSize() const;
    std::unique_ptr< Shape > clone() const override;

  private:
    void doScale(double scaleCoefficient) override;

    size_t size_;
    std::unique_ptr< std::unique_ptr< Shape >[] > data_;

  };

  template< typename... Shapes >
  CompositeShape::CompositeShape(Shapes... shapes):
    size_(sizeof...(Shapes)),
    data_(std::make_unique< std::unique_ptr< Shape >[] >(size_))
  {
    if (size_ == 0)
    {
      throw std::invalid_argument("Empty parameter pack");
    }
    //data_ = {std::move(shapes)...};
    std::unique_ptr< Shape > temp[] = { std::move(shapes)... };
    for (size_t i = 0; i < size_; i++)
    {
      if (temp[i] == nullptr)
      {
        throw std::invalid_argument("Nullptr parameters");
      }
      data_[i] = std::move(temp[i]);
    }
  }
}

#endif

#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace razukrantov
{
  class CompositeShape: public Shape
  {
  public:
	using shapePtr = std::shared_ptr< Shape >;
	using shapeArr = std::unique_ptr< shapePtr[] >;

	CompositeShape(shapePtr src);
	CompositeShape(const CompositeShape& src);
	CompositeShape(CompositeShape&& src) noexcept = default;

	virtual ~CompositeShape() = default;

	CompositeShape& operator=(const CompositeShape& src);
	CompositeShape& operator=(CompositeShape&& src) noexcept = default;

	double getArea() const override;
	rectangle_t getFrameRect() const override;
	void move(const point_t& center) override;
	void move(double dx, double dy) override;
	std::shared_ptr< const Shape > at(size_t index) const;
	std::shared_ptr< Shape > at(size_t index);
	std::shared_ptr< Shape > clone() const override;
	void pushBack(shapePtr src);
	void popBack();
	size_t size() const;
	size_t capacity() const;
	void swap(CompositeShape& src) noexcept;
	void reserve(size_t newCap);

  private:
	size_t size_;
	size_t capacity_;
	shapeArr shapeArr_;
	void doScale(double k) override;
  };

  void swap(CompositeShape& src1, CompositeShape& src2) noexcept;
}

#endif

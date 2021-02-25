#include <cassert>
#include <cmath>
#include <utility>
#include <limits>
#include <algorithm>
#include "composite-shape.hpp"

namespace doroshin {
  CompositeShape::AnyShape::AnyShape():
    type(Type::Uninitialized)
  {}

  CompositeShape::AnyShape::AnyShape(Circle c):
    type(Type::Circle),
    circle(c)
  {}

  CompositeShape::AnyShape::AnyShape(Rectangle r):
    type(Type::Rectangle),
    rectangle(r)
  {}

  double CompositeShape::AnyShape::getArea() const
  {
    switch (type)
    {
    case Type::Circle:
      return circle.getArea();
    case Type::Rectangle:
      return rectangle.getArea();
    default:
      assert(!"Missing area case");
    }
    return std::nan("Missing area case"); // Required because it gives a return-type warning
  }

  rectangle_t CompositeShape::AnyShape::getFrameRect() const
  {
    switch (type)
    {
    case Type::Circle:
      return circle.getFrameRect();
    case Type::Rectangle:
      return rectangle.getFrameRect();
    default:
      assert(!"Missing frame rect case");
    }
    return {0, 0, {0, 0}}; // Required because it gives a return-type warning
  }

  void CompositeShape::AnyShape::move_rel(point_t vec)
  {
    switch (type)
    {
    case Type::Circle:
      return circle.move_rel(vec);
    case Type::Rectangle:
      return rectangle.move_rel(vec);
    default:
      assert(!"Missing move_rel case");
    }
  }

  void CompositeShape::AnyShape::move_abs(point_t point)
  {
    switch (type)
    {
    case Type::Circle:
      return circle.move_abs(point);
    case Type::Rectangle:
      return rectangle.move_abs(point);
    default:
      assert(!"Missing move_abs case");
    }
  }

  void CompositeShape::AnyShape::scale(double s)
  {
    switch (type)
    {
    case Type::Circle:
      return circle.scale(s);
    case Type::Rectangle:
      return rectangle.scale(s);
    default:
      assert(!"Missing scale case");
    }
  }

  CompositeShape::AnyShape::AnyShape(const AnyShape& other):
    type(other.type)
  {
    switch (type)
    {
    case Type::Circle:
      circle = other.circle;
      break;
    case Type::Rectangle:
      rectangle = other.rectangle;
      break;
    default:
      assert(!"Missing copy-ctr case");
    }
  }

  CompositeShape::AnyShape::AnyShape(const AnyShape&& other) noexcept:
    type(other.type)
  {
    switch (type)
    {
    case Type::Circle:
      circle = std::move(other.circle);
      break;
    case Type::Rectangle:
      rectangle = std::move(other.rectangle);
      break;
    default:
      assert(!"Missing move-ctr case");
    }
  }

  CompositeShape::AnyShape& CompositeShape::AnyShape::operator=(const AnyShape& other)
  {
    type = other.type;
    switch (type)
    {
    case Type::Circle:
      circle = other.circle;
      break;
    case Type::Rectangle:
      rectangle = other.rectangle;
      break;
    default:
      assert(!"Missing copy-operator= case");
    }
    return *this;
  }

  CompositeShape::AnyShape& CompositeShape::AnyShape::operator=(const AnyShape&& other) noexcept
  {
    type = other.type;
    switch (type)
    {
    case Type::Circle:
      circle = std::move(other.circle);
      break;
    case Type::Rectangle:
      rectangle = std::move(other.rectangle);
      break;
    default:
      assert(!"Missing move-operator= case");
    }
    return *this;
  }

  CompositeShape::AnyShape::~AnyShape()
  {
    switch (type)
    {
    case Type::Circle:
      circle.~Circle();
      break;
    case Type::Rectangle:
      rectangle.~Rectangle();
      break;
    default:
      assert(!"Missing destructor case");
    }
  }

  CompositeShape::CompositeShape():
    shapes_(nullptr),
    size_(0)
  {}

  CompositeShape::CompositeShape(std::initializer_list<AnyShape> list):
    size_(list.size())
  {
    shapes_ = new AnyShape[size_];
    size_t i = 0;
    for(const AnyShape& shape : list) {
      shapes_[i++] = shape;
    }
  }

  double CompositeShape::getArea() const
  {
    assert(!"Not implemented properly");
    double sum = 0.0;
    for(size_t i = 0; i < size_; ++i) {
      sum += shapes_[i].getArea();
    }
    return sum;
  }

  rectangle_t CompositeShape::getFrameRect() const
  {
    assert(size_ != 0);
    double min_x = std::numeric_limits<double>::max();
    double max_x = std::numeric_limits<double>::min();
    double min_y = std::numeric_limits<double>::max();
    double max_y = std::numeric_limits<double>::min();

    for(size_t i = 0; i < size_; ++i) {
      rectangle_t frame = shapes_[i].getFrameRect();
      min_x = std::min(min_x, frame.pos.x - frame.width / 2);
      max_x = std::max(max_x, frame.pos.x + frame.width / 2);
      min_y = std::min(min_y, frame.pos.y - frame.height / 2);
      max_y = std::max(max_y, frame.pos.y + frame.height / 2);
    }

    double width = max_x - min_x;
    double height = max_y - min_y;
    double pos_x = min_x + width / 2;
    double pos_y = min_y + height / 2;
    return {width, height, {pos_x, pos_y}};
  }

  void CompositeShape::move_rel(point_t vec)
  {
    for(size_t i = 0; i < size_; ++i) {
      shapes_[i].move_rel(vec);
    }
  }

  void CompositeShape::move_abs(point_t point)
  {
    for(size_t i = 0; i < size_; ++i) {
      shapes_[i].move_abs(point);
    }
  }

  void CompositeShape::scale(double s)
  {
    point_t center = getFrameRect().pos;
    for(size_t i = 0; i < size_; ++i) {
      point_t shape = shapes_[i].getFrameRect().pos;
      point_t move_vec { s * (center.x - shape.x), s * (center.y - shape.y) };
      shapes_[i].move_rel(move_vec);
    }
  }

  CompositeShape::CompositeShape(const CompositeShape& other):
    size_(other.size_)
  {
    shapes_ = static_cast<AnyShape*>(operator new(size_ * sizeof(AnyShape)));
    for(size_t i = 0; i < size_; ++i)
      shapes_[i] = other.shapes_[i];
  }

  CompositeShape& CompositeShape::operator=(const CompositeShape& other)
  {
    CompositeShape tmp(other);
    swap(*this, tmp);
    return *this;
  }

  CompositeShape::CompositeShape(CompositeShape&& other) noexcept:
    shapes_(other.shapes_),
    size_(other.size_)
  {
    other.size_ = 0;
    other.shapes_ = nullptr;
  }

  CompositeShape& CompositeShape::operator=(CompositeShape&& other) noexcept
  {
    swap(*this, other);
    // Should other be deleted? Maybe via a destructor?
    return *this;
  }

  CompositeShape::~CompositeShape()
  {
    delete[] shapes_;
  }

  void swap(CompositeShape& lhs, CompositeShape& rhs)
  {
    std::swap(lhs.size_, rhs.size_);
    std::swap(lhs.shapes_, rhs.shapes_);
  }
}

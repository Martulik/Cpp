#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <ostream>
#include "base-types.hpp"
namespace ivanova {
  class Shape {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t &newPos) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual friend std::ostream &fout(std::ostream &out) const = 0;
    virtual ~Shape() = default;
  protected:
    std::ostream &operator<<(std::ostream &out, const Shape &shape)
    {
        return shape.fout(out);
    }
  };
}
#endif

#ifndef SHAPE_GENERATOR_HPP
#define SHAPE_GENERATOR_HPP

#include "shape.hpp"

#include <functional>
#include <random>

namespace savchuk
{
  class ShapeGenerator
  {
    public:
      Shape operator()() const;

    private:
      static std::function< int() > boolean_gen_;
      static std::function< int() > int_gen_;

      Shape getSquare(const Point& p1, const Point& p2) const;
      Shape getOctagon(const Point& p1, const Point& p2) const;
  };
}

#endif

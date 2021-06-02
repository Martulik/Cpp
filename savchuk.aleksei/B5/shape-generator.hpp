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
      static const int MAX_COORDINATE = 10'000;
      static const int MIN_COORDINATE = -10'000;

      Shape getSquare(const Point& p1, const Point& p2) const;
      Shape getOctagon(const Point& p1, const Point& p2) const;
  };
}

#endif

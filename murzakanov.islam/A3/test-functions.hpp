#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include <boost/test/unit_test.hpp>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

namespace murzakanov
{
  const double epsilon = 1.0;
  void testMove(murzakanov::Shape::ShapePtr shp);
  void testScale(murzakanov::Shape::ShapePtr shp);
  murzakanov::Shape::ShapePtr makeRect();
  murzakanov::Shape::ShapePtr makeCircle();
  std::shared_ptr< murzakanov::CompositeShape > makeCompositeShp();
}

#endif

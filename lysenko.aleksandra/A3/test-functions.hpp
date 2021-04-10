#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include <boost/test/unit_test.hpp>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace lysenko
{
  const double accuracy = 1.0;
  lysenko::Shape::ShapePtr makeCircle();
  lysenko::Shape::ShapePtr createMyCircle(double radius, point_t pos);
  lysenko::Shape::ShapePtr makeRectangle();
  lysenko::Shape::ShapePtr createMyRectangle(double width, double height, point_t pos);
  std::shared_ptr <lysenko::CompositeShape> makeCompositeShape();

  void testMove(Shape::ShapePtr src);
  void testScale(Shape::ShapePtr src);
}
#endif

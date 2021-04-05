#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include <boost/test/included/unit_test.hpp>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace lysenko
{
  lysenko::Shape::ShapePtr makeCircle();
  lysenko::Shape::ShapePtr makeRectangle();
  std::shared_ptr <lysenko::CompositeShape> makeCompositeShape();

  void testGetFrameRect(Shape::ShapePtr& src);
  void testGetArea(Shape::ShapePtr& src);
  void testMove(Shape::ShapePtr& src);
  void testScale(Shape::ShapePtr& src);
  void testGetName(Shape::ShapePtr& src);
  void testClone(Shape::ShapePtr& src);
}
#endif
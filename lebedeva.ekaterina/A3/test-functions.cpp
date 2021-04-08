#include "test-functions.hpp"

namespace leb = lebedeva;

void leb::checkName(std::string expectedName, std::string name)
{
  BOOST_CHECK_EQUAL(expectedName, name);
}

void leb::checkFrameRect(const rectangle_t& oldFrameRect, const rectangle_t& newFrameRect)
{
  BOOST_CHECK_CLOSE(oldFrameRect.height, newFrameRect.height, tolerance);
  BOOST_CHECK_CLOSE(oldFrameRect.width, newFrameRect.width, tolerance);
}

void leb::checkScale(Shape& shape, const double k)
{
  double areaBeforeScale = shape.getArea();
  shape.scale(k);
  BOOST_CHECK_CLOSE(areaBeforeScale * 4, shape.getArea(), tolerance);
}

void leb::checkMoveToPoint(Shape& shape, const point_t& newPos)
{
  leb::rectangle_t oldFrameRect = shape.getFrameRect();
  double area = shape.getArea();

  shape.move(newPos);
  checkFrameRect(oldFrameRect, shape.getFrameRect());
  BOOST_CHECK_CLOSE(area, shape.getArea(), tolerance);
}

void leb::checkMoveAbs(Shape& figure, const point_t& newPos)
{
  leb::rectangle_t oldFrameRect = figure.getFrameRect();
  double area = figure.getArea();

  figure.move(newPos.x, -newPos.y);
  checkFrameRect(oldFrameRect, figure.getFrameRect());
  BOOST_CHECK_CLOSE(area, figure.getArea(), tolerance);
}

std::unique_ptr< leb::Rectangle > lebedeva::makeRectangle()
{
  return std::make_unique< Rectangle >(pos, width, height);
}

std::unique_ptr< leb::Circle > lebedeva::makeCircle()
{
  return std::make_unique< Circle >(pos, radius);
}

std::unique_ptr< leb::CompositeShape > leb::makeCompositeShape()
{
  CompositeShape subComposition
  {
    std::make_shared< Circle >(pos, radius)
  };

  CompositeShape composition
  {
    std::make_shared< Rectangle >(pos1, width, height),
    std::make_shared< Rectangle >(pos2, height, width),
    std::make_shared< CompositeShape >(std::move(subComposition))
  };

  std::unique_ptr< CompositeShape > shapePtr = std::make_unique< CompositeShape >(std::move(composition));
  return shapePtr;
}

#include "test-functions.hpp"

namespace curr = lysenko;

curr::Shape::ShapePtr lysenko::makeCircle()
{
  double radius = 33.33;
  double defaultRadius = -33.33;
  point_t pos = { 1, 1 };

  BOOST_CHECK_NO_THROW(curr::Shape::ShapePtr myCircle = std::make_shared< curr::Circle >(curr::Circle(pos, radius)));
  BOOST_CHECK_THROW(curr::Shape::ShapePtr myCircle = std::make_shared< curr::Circle >(curr::Circle(pos, defaultRadius)), std::invalid_argument);

  return std::make_shared< curr::Circle >(curr::Circle(pos, radius));
}

curr::Shape::ShapePtr lysenko::makeRectangle()
{
  double width = 1.0;
  double defaultWidth = -1.0;
  double height = 2.0;
  double defaultHeight = -2.0;
  point_t pos{ 33.33, 33.33 };

  BOOST_CHECK_NO_THROW(curr::Shape::ShapePtr myRectangle = std::make_shared< curr::Rectangle >(curr::Rectangle(width, height, pos)));
  BOOST_CHECK_THROW(curr::Shape::ShapePtr myRectangle = std::make_shared< curr::Rectangle >(curr::Rectangle(defaultWidth, height, pos)), std::invalid_argument);
  BOOST_CHECK_THROW(curr::Shape::ShapePtr myRectangle = std::make_shared< curr::Rectangle >(curr::Rectangle(width, defaultHeight, pos)), std::invalid_argument);
  BOOST_CHECK_THROW(curr::Shape::ShapePtr myRectangle = std::make_shared< curr::Rectangle >(curr::Rectangle(defaultWidth, defaultHeight, pos)), std::invalid_argument);

  return std::make_shared< curr::Rectangle >(curr::Rectangle(width, height, pos));
}

std::shared_ptr <lysenko::CompositeShape> makeCompositeShape()
{
  curr::Shape::ShapePtr defaultShape = nullptr;
  curr::Shape::ShapePtr myCircle = curr::makeCircle();
  curr::Shape::ShapePtr myRectangle = curr::makeRectangle();
  BOOST_CHECK_THROW(std::shared_ptr <lysenko::Shape> myComposite = std::make_shared< curr::CompositeShape >(defaultShape), std::invalid_argument);
  BOOST_CHECK_NO_THROW(std::shared_ptr <lysenko::Shape> myComposite = std::make_shared< curr::CompositeShape >(myCircle));
  std::shared_ptr <lysenko::CompositeShape> myComposite = std::make_shared< curr::CompositeShape >(myCircle);
  BOOST_CHECK_THROW(myComposite->popShape(), std::exception);
  myComposite->addShape(myRectangle);
  return myComposite;
}
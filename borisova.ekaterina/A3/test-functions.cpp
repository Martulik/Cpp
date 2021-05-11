#include "test-functions.hpp"
#include <stdexcept>
#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "test-variables.hpp"

namespace lab = borisova;

void lab::paramAfterMoving(std::unique_ptr< Shape > obj)
{
  double heightBeforeMoving = getHeight(*obj);
  double widthBeforeMoving = getWidth(*obj);
  obj->move(dpos);
  BOOST_CHECK_CLOSE(getHeight(*obj), heightBeforeMoving, 0.000001);
  BOOST_CHECK_CLOSE(getWidth(*obj), widthBeforeMoving, 0.000001);
}

void lab::areaAfterMoving(std::unique_ptr< Shape > obj)
{
  double arBeforeMoving = obj->getArea();
  obj->move(dpos.x, dpos.y);
  BOOST_CHECK_CLOSE(obj->getArea(), arBeforeMoving, 0.000001);
}

void lab::areaAfterScale(std::unique_ptr< Shape > obj)
{
  double arBeforeScale = obj->getArea();
  obj->scale(coeff);
  BOOST_CHECK_CLOSE(obj->getArea(), arBeforeScale * coeff * coeff, 0.000001);
  BOOST_CHECK_THROW(obj->scale(-3.2), std::invalid_argument);
}

std::unique_ptr< lab::Shape > lab::makeComposite()
{
  lab::CompositeShape compShape =
  {
    std::make_shared< lab::Rectangle >(lab::point1, lab::width, lab::param1),
    std::make_shared< lab::Circle >(lab::point2, lab::width),
    std::make_shared< lab::Rectangle >(lab::point2, lab::param2, lab::height),
    std::make_shared< lab::Circle >(lab::point1, lab::height)
  };
  auto shape = std::make_unique< lab::CompositeShape >(std::move(compShape));
  return shape;
}

#include "test-functions.hpp"
#include <stdexcept>

void borisova::paramAfterMoving(std::unique_ptr< Shape > obj)
{
  double heightBeforeMoving = getHeight(*obj);
  double widthBeforeMoving = getWidth(*obj);
  obj->move(dpos);
  BOOST_CHECK_CLOSE(getHeight(*obj), heightBeforeMoving, 0.000001);
  BOOST_CHECK_CLOSE(getWidth(*obj), widthBeforeMoving, 0.000001);
}

void borisova::areaAfterMoving(std::unique_ptr< Shape > obj)
{
  double arBeforeMoving = obj->getArea();
  obj->move(dpos.x, dpos.y);
  BOOST_CHECK_CLOSE(obj->getArea(), arBeforeMoving, 0.000001);
}

void borisova::areaAfterScale(std::unique_ptr< Shape > obj)
{
  double arBeforeScale = obj->getArea();
  BOOST_CHECK_NO_THROW(obj->scale(coeff));
  BOOST_CHECK_CLOSE(obj->getArea(), arBeforeScale * coeff * coeff, 0.000001);
  BOOST_CHECK_THROW(obj->scale(-3.2), std::invalid_argument);
}

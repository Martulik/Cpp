#include "test-functions.hpp"
#include <stdexcept>

void borisova::paramAfterMoving(Shape* obj)
{
  double heightBeforeMoving = obj->getHeight();
  double widthBeforeMoving = obj->getWidth();
  obj->move(dpos);
  BOOST_REQUIRE_EQUAL(obj->getHeight(), heightBeforeMoving);
  BOOST_REQUIRE_EQUAL(obj->getWidth(), widthBeforeMoving);
  if (obj->getName() != "Composite Shape")
  {
	delete obj;
  }
}

void borisova::areaAfterMoving(Shape* obj)
{
  double arBeforeMoving = obj->getArea();
  obj->move(dpos.x, dpos.y);
  BOOST_REQUIRE_EQUAL(obj->getArea(), arBeforeMoving);
  if (obj->getName() != "Composite Shape")
  {
  delete obj;
  }
}

void borisova::areaAfterScale(Shape* obj)
{
  double arBeforeScale = obj->getArea();
  BOOST_CHECK_NO_THROW(obj->scale(coeff));
  BOOST_CHECK_CLOSE(obj->getArea(), arBeforeScale * coeff * coeff, 0.0001);
  BOOST_CHECK_THROW(obj->scale(-3.2), std::invalid_argument);
  if (obj->getName() != "Composite Shape")
  {
	delete obj;
  }
}

#include "test-functions.hpp"

namespace curr = lysenko;

BOOST_AUTO_TEST_SUITE(test_composite)

BOOST_AUTO_TEST_CASE(test_move)
{
  curr::testMove(curr::makeCompositeShape());
}

BOOST_AUTO_TEST_CASE(test_scale)
{
  curr::testScale(curr::makeCompositeShape());
}

BOOST_AUTO_TEST_CASE(test_changing_of_shapes_centers_after_scale)
{
  curr::CompositeShape myComposite(curr::makeCircle());
  curr::Shape::ShapePtr myCompositePtr(std::make_unique< curr::CompositeShape >(myComposite));
  double oldCentX= curr::getX(myCompositePtr);
  double oldCentY = curr::getY(myCompositePtr);
  double oldCentXCircle = curr::getX(myComposite.at(0));
  double oldCentYCircle = curr::getY(curr::makeCircle());
  double k = 5.0;
  myComposite.scale(k);
  double newCentXCircle = oldCentXCircle + (oldCentX - oldCentXCircle) * k;
  double newCentYCircle = oldCentYCircle + (oldCentY - oldCentYCircle) * k;
  BOOST_CHECK_CLOSE(newCentXCircle, curr::getX(myCompositePtr), curr::accuracy);
  BOOST_CHECK_CLOSE(newCentYCircle, curr::getY(myCompositePtr), curr::accuracy);
}

BOOST_AUTO_TEST_CASE(test_at)
{
  curr::CompositeShape myComposite(curr::makeCircle());
  BOOST_CHECK_THROW(myComposite.at(-1), std::out_of_range);
  BOOST_CHECK_THROW(myComposite.at(1), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(test_enlargeCapacity_invalid_argument)
{
  BOOST_CHECK_THROW(curr::makeCompositeShape()->enlargeCapacity(1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(test_default_shape)
{
  BOOST_CHECK_THROW(curr::CompositeShape myComposite(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(test_popShape)
{
  curr::CompositeShape myComposite(curr::makeCircle());
  BOOST_CHECK_THROW(myComposite.popShape(), std::logic_error);
}

BOOST_AUTO_TEST_SUITE_END()

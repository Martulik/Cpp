#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(test_composite)

BOOST_AUTO_TEST_CASE(test_move)
{
  lysenko::testMove(lysenko::makeCompositeShape());
}

BOOST_AUTO_TEST_CASE(test_scale)
{
  lysenko::testScale(lysenko::makeCompositeShape());
}

BOOST_AUTO_TEST_CASE(test_changing_of_shapes_centers_after_scale)
{
  lysenko::CompositeShape myComposite(lysenko::makeCircle());
  lysenko::Shape::ShapePtr myCompositePtr(std::make_unique<lysenko::CompositeShape>(myComposite));
  double oldCenterX= lysenko::getX(myCompositePtr);
  double oldCenterY = lysenko::getY(myCompositePtr);
  double oldCenterXCircle = lysenko::getX(myComposite.at(0));
  double oldCenterYCircle = lysenko::getY(lysenko::makeCircle());
  double k = 5.0;
  myComposite.scale(k);
  BOOST_CHECK_CLOSE(oldCenterXCircle + (oldCenterX - oldCenterXCircle) * k, lysenko::getX(myCompositePtr), lysenko::accuracy);
  BOOST_CHECK_CLOSE(oldCenterYCircle + (oldCenterY - oldCenterYCircle) * k, lysenko::getY(myCompositePtr), lysenko::accuracy);
}

BOOST_AUTO_TEST_CASE(test_at)
{
  lysenko::CompositeShape myComposite(lysenko::makeCircle());
  BOOST_CHECK_THROW(myComposite.at(-1), std::invalid_argument);
  BOOST_CHECK_THROW(myComposite.at(1), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(test_enlargeCapacity_invalid_argument)
{
  BOOST_CHECK_THROW(lysenko::makeCompositeShape()->enlargeCapacity(1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(test_default_shape)
{
  BOOST_CHECK_THROW(lysenko::CompositeShape myComposite(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(test_popShape)
{
  lysenko::CompositeShape myComposite(lysenko::makeCircle());
  BOOST_CHECK_THROW(myComposite.popShape(), std::logic_error);
}

BOOST_AUTO_TEST_SUITE_END()

#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(test_circle)

BOOST_AUTO_TEST_CASE(test_move)
{
  lysenko::testMove(lysenko::makeCircle());
}

BOOST_AUTO_TEST_CASE(test_scale)
{
  lysenko::testScale(lysenko::makeCircle());
}

BOOST_AUTO_TEST_CASE(test_changing_of_radius_after_scale)
{
  lysenko::point_t myPos{ 33.33, 33.33 };
  double radius = 33.33;
  lysenko::Shape::ShapePtr myCircle(std::make_shared <lysenko::Circle>(myPos, radius));
  double oldRadius = getWidth(myCircle) / 2;
  myCircle->scale(5);
  BOOST_CHECK_CLOSE(oldRadius * 5, getWidth(myCircle) / 2, lysenko::accuracy);
}

BOOST_AUTO_TEST_CASE(test_invalid_radius)
{
  BOOST_CHECK_THROW(lysenko::Circle myCircle({ 1.0, 1.0}, -33.33), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

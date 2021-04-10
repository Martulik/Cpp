#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(test_rectangle)

BOOST_AUTO_TEST_CASE(test_move)
{
  lysenko::testMove(lysenko::makeRectangle());
}

BOOST_AUTO_TEST_CASE(test_scale)
{
  lysenko::testScale(lysenko::makeRectangle());
}

BOOST_AUTO_TEST_CASE(test_changing_of_weight_and_height_after_scale)
{
  lysenko::point_t myPos{ 33.33, 33.33 };
  double width = 1.0;
  double heigth = 2.0;
  lysenko::Shape::ShapePtr myRectangle(std::make_shared <lysenko::Rectangle>(width, heigth, myPos));
  double oldWidth = getWidth(myRectangle);
  double oldHeight = getHeight(myRectangle);
  myRectangle->scale(5);
  BOOST_CHECK_CLOSE(oldWidth * 5, getWidth(myRectangle), lysenko::accuracy);
  BOOST_CHECK_CLOSE(oldHeight * 5, getHeight(myRectangle), lysenko::accuracy);
}

BOOST_AUTO_TEST_CASE(test_invalid_width)
{
  BOOST_CHECK_THROW(lysenko::createMyRectangle(-1.0, 2.0, {33.33, 33.33}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(test_invalid_height)
{
  BOOST_CHECK_THROW(lysenko::createMyRectangle( 1.0, - 2.0, {33.33, 33.33}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(test_invalid_weight_and_height)
{
  BOOST_CHECK_THROW(lysenko::createMyRectangle(-1.0, -2.0, { 33.33, 33.33 }), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

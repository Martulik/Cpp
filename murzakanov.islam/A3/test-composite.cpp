#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(test_CompositeShape)

  BOOST_AUTO_TEST_CASE(test_move)
  {
    murzakanov::testMove(murzakanov::makeCompositeShp());
  }

  BOOST_AUTO_TEST_CASE(test_scale)
  {
    murzakanov::testScale(murzakanov::makeCompositeShp());
  }

  BOOST_AUTO_TEST_CASE(test_invalid_argument)
  {
    BOOST_CHECK_THROW(murzakanov::CompositeShape({}), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(test_add_shape)
  {
    const murzakanov::point_t newPoint = {3, 4};
    const double newWidth = 3.5;
    const double newHeight = 2.0;
    std::shared_ptr< murzakanov::CompositeShape > newComposite(murzakanov::makeCompositeShp());
    std::shared_ptr< murzakanov::Rectangle > newRectangle(std::make_shared< murzakanov::Rectangle >(newHeight, newWidth, newPoint));
    BOOST_CHECK_NO_THROW(newComposite->addShape(newRectangle));
  }

  BOOST_AUTO_TEST_CASE(test_pop_back_no_throw)
  {
    std::shared_ptr< murzakanov::CompositeShape > composite(murzakanov::makeCompositeShp());
    BOOST_CHECK_NO_THROW(composite->popShape());
  }

  BOOST_AUTO_TEST_CASE(test_pop_back_empty_throw)
  {
    std::shared_ptr< murzakanov::CompositeShape > composite(murzakanov::makeCompositeShp());
    composite->popShape();
    BOOST_CHECK_THROW(composite->popShape(), std::out_of_range);
  }
BOOST_AUTO_TEST_SUITE_END()

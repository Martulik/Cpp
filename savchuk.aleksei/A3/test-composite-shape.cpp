#include <initializer_list>
#include <memory>

#include <boost/test/unit_test.hpp>

#include "test-utility.hpp"
#include "test-values.hpp"

namespace lab = savchuk;

BOOST_AUTO_TEST_SUITE(composite_shape)

BOOST_AUTO_TEST_CASE(move_invariant)
{
  lab::CompositeShape comp = lab::makeComposite();
  lab::checkMoveInvariant(comp, { -1.6, 13.5 });
  lab::checkMoveInvariant(comp, 2.3, -12.6);
}

BOOST_AUTO_TEST_CASE(scale_frame_rectangle)
{
  lab::CompositeShape comp = lab::makeComposite();
  lab::checkScaleFrameRect(comp, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_area)
{
  lab::CompositeShape comp = lab::makeComposite();
  lab::checkScaleArea(comp, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_invalid_argument)
{
  lab::CompositeShape comp = lab::makeComposite();
  lab::checkScaleInvalidArgument(comp, WRONG_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(correct_frame_rectangle)
{
  const lab::point_t POS = { 0, 0 };
  const double SIDE = 1;
  const double RAD = 100;
  const lab::rectangle_t FRAME_RECT = { POS, 2 * RAD, 2 * RAD };
  std::unique_ptr< lab::Shape > r = std::make_unique< lab::Rectangle >(POS, SIDE, SIDE);
  std::unique_ptr< lab::Shape > c = std::make_unique< lab::Circle >(POS, RAD);
  std::initializer_list< std::unique_ptr< lab::Shape > > il{ std::move(r), std::move(c) };
  lab::CompositeShape comp(il);
  lab::checkCorrectFrameRect(comp, FRAME_RECT);
}

BOOST_AUTO_TEST_SUITE_END()

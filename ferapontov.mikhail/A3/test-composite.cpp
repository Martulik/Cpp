#include <boost/test/unit_test.hpp>

#include "test-functions.hpp"

namespace fer = ferapontov;

BOOST_AUTO_TEST_SUITE(TestComposite)

BOOST_AUTO_TEST_CASE(TestMove)
{
  fer::CompositeShape comp = fer::makeComposite();
  fer::test_move(comp, {-1, -1});
  fer::test_move(comp, -1, -1);
}

BOOST_AUTO_TEST_CASE(TestScale)
{
  fer::CompositeShape comp = fer::makeComposite();
  fer::test_scale(comp, 2);
}

BOOST_AUTO_TEST_CASE(TestInvalidArgument)
{
  fer::CompositeShape comp = fer::makeComposite();
  fer::test_invalid_argument(comp, -2);
}

BOOST_AUTO_TEST_SUITE_END()

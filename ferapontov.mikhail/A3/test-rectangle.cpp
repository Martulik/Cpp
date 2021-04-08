#include <boost/test/unit_test.hpp>

#include "test-functions.hpp"

namespace fer = ferapontov;

BOOST_AUTO_TEST_SUITE(TestRectangle)

BOOST_AUTO_TEST_CASE(TestMove)
{
  fer::Rectangle rec = fer::make_rectangle();
  fer::test_move(rec, {-1, -1});
  fer::test_move(rec, -1, -1);
}

BOOST_AUTO_TEST_CASE(TestScale)
{
  fer::Rectangle rec = fer::make_rectangle();
  fer::test_scale(rec, 2);
}

BOOST_AUTO_TEST_CASE(TestInvalidArgument)
{
  fer::Rectangle rec = fer::make_rectangle();
  fer::test_invalid_argument(rec, -2);
}

BOOST_AUTO_TEST_SUITE_END()
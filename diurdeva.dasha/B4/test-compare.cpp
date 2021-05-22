#include <boost/test/unit_test.hpp>
#include "dataStruct.hpp"

BOOST_AUTO_TEST_SUITE(compare)

BOOST_AUTO_TEST_CASE(compareDataStruct)
{
  BOOST_CHECK(diurdeva::compare({ 1, 2, "apple" }, { 3, 2, "apple" }));
  BOOST_CHECK(diurdeva::compare({ 2, 2, "apple" }, { 2, 3, "apple" }));
  BOOST_CHECK(diurdeva::compare({ 1, 2, "app" }, { 1, 2, "apple" }));
  BOOST_CHECK(!diurdeva::compare({ 4, 2, "apple" }, { 4, 2, "apple" }));
}

BOOST_AUTO_TEST_SUITE_END()

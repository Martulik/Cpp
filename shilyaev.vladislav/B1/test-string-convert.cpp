#include <boost/test/unit_test.hpp>
#include "string-convert.hpp"

BOOST_AUTO_TEST_CASE(NaturalInvalidArgument)
{
  BOOST_CHECK_THROW(shilyaev::toNatural(""), std::invalid_argument);
  BOOST_CHECK_THROW(shilyaev::toNatural("435a"), std::invalid_argument);
  BOOST_CHECK_THROW(shilyaev::toNatural("-334"), std::invalid_argument);
  BOOST_CHECK_THROW(shilyaev::toNatural("20 30"), std::invalid_argument);
  BOOST_CHECK_THROW(shilyaev::toNatural("20.30"), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Natural)
{
  BOOST_TEST(shilyaev::toNatural("0") == 0);
  BOOST_TEST(shilyaev::toNatural("435") == 435);
}

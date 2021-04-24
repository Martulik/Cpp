#include <boost/test/unit_test.hpp>
#include "string-convert.hpp"

BOOST_AUTO_TEST_CASE(ToIntInvalidArgument)
{
  BOOST_CHECK(!shilyaev::toNatural(""));
  BOOST_CHECK(!shilyaev::toNatural("435a"));
  BOOST_CHECK(!shilyaev::toNatural("-435"));
  BOOST_CHECK(!shilyaev::toNatural("20 30"));
  BOOST_CHECK(!shilyaev::toNatural("20.30"));
}

BOOST_AUTO_TEST_CASE(ToInt)
{
  BOOST_TEST(*shilyaev::toNatural("0") == 0);
  BOOST_TEST(*shilyaev::toNatural("435") == 435);
}

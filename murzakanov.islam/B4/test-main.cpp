#define BOOST_TEST_MODULE B4
#include <sstream>
#include <boost/test/included/unit_test.hpp>
#include "data-struct.hpp"

BOOST_AUTO_TEST_CASE(WrongInput)
{
  std::stringstream in("1, 125, saldfkj");
  murzakanov::DataStruct data;
  in >> data;
  BOOST_CHECK(in.fail());
}

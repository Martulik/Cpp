#include <boost/test/unit_test.hpp>
#include "functions.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_CASE(test_delete_ws)
{
  std::string str = "q    q  q";
  poz::removeWS(str);
  BOOST_REQUIRE(!str.compare("qqq"));
}

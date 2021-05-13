#include <boost/test/unit_test.hpp>
#include <sstream>
#include "struct.hpp"

namespace iva = ivanova;

BOOST_AUTO_TEST_SUITE(testSort)

  BOOST_AUTO_TEST_CASE(correctInput)
  {
    iva::DataStruct data;
    std::stringstream stream("3,2,string");
    stream >> data;
    BOOST_CHECK_EQUAL(3, data.key1);
    BOOST_CHECK_EQUAL(2, data.key2);
    BOOST_CHECK_EQUAL("string", data.str);
  }

  BOOST_AUTO_TEST_CASE(testOutput)
  {
    iva::DataStruct data;
    std::stringstream stream("3,2,string");
    stream >> data;
    stream << data;
    BOOST_CHECK_EQUAL(stream.str(), "3,2,string");
  }

BOOST_AUTO_TEST_SUITE_END()

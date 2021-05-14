#include <sstream>
#include <boost/test/unit_test.hpp>
#include "dataStruct.hpp"

namespace lab = ezerinia;

BOOST_AUTO_TEST_SUITE(data_struct)

  BOOST_AUTO_TEST_CASE(correct_input_data)
  {
    lab::DataStruct data;
    std::stringstream ss("1,2,str");
    ss >> data;
    BOOST_CHECK_EQUAL(1, data.key1);
    BOOST_CHECK_EQUAL(2, data.key2);
    BOOST_CHECK_EQUAL("str", data.str);
  }

  BOOST_AUTO_TEST_CASE(incorrect_input_data)
  {
    lab::DataStruct data;
    std::stringstream ss("-10,2,str");
    BOOST_CHECK_THROW(ss >> data, std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(miss_comma)
  {
    lab::DataStruct data;
    std::stringstream ss("-1 2,str");
    BOOST_CHECK_THROW(ss >> data, std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(output)
  {
    lab::DataStruct data{1, 2, "str"};
    std::stringstream ss;
    ss << data;
    BOOST_CHECK_EQUAL(ss.str(), "1,2,str\n");
  }

BOOST_AUTO_TEST_SUITE_END()

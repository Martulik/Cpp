#include <boost/test/unit_test.hpp>
#include <iostream>
#include "record_t.hpp"

const std::string inputStr = "478290991632 \"duKZ,FZWdT\"";
const std::string expected = "478290991632 duKZ,FZWdT";

BOOST_AUTO_TEST_SUITE(record_operators)

  BOOST_AUTO_TEST_CASE(input)
  {
    ezerinia::record_t record;
    std::stringstream ss;
    ss << inputStr;
    ss >> record;
    BOOST_CHECK_EQUAL(expected, (record.number + " " + record.name));
  }

  BOOST_AUTO_TEST_CASE(output)
  {
    ezerinia::record_t record{"478290991632", "duKZ,FZWdT"};
    std::stringstream ss;
    ss << record;
    BOOST_CHECK_EQUAL(ss.str(), (record.number + " " + record.name + "\n"));
  }

BOOST_AUTO_TEST_SUITE_END()

#include <boost/test/unit_test.hpp>
#include <iostream>

#include "record.hpp"

std::string input = "538111474758 \"yHcQ TaQjVtKtjn\"";
const std::string output = "538111474758 yHcQ TaQjVtKtjn";

namespace iva = ivanova;

BOOST_AUTO_TEST_SUITE(testRecord)

  BOOST_AUTO_TEST_CASE(testRecordInput)
  {
    iva::Record rec;
    std::stringstream stream;
    stream << input;
    stream >> rec;
    BOOST_CHECK_EQUAL(output, rec.data.first + " " + rec.data.second);
  }

  BOOST_AUTO_TEST_CASE(utestRecordOtput)
  {
    iva::Record record{std::make_pair("478290991632", "duKZ,FZWdT")};
    std::stringstream input;
    input << record;
    BOOST_CHECK_EQUAL(input.str(), (record.data.first + " " + record.data.second + "\n"));
  }

BOOST_AUTO_TEST_SUITE_END()